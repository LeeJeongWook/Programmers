import math

def get_divisor(num):
    divisor = set()
    
    for i in range(1, int(math.sqrt(num))+1):
        if num % i == 0:
            divisor.add(i)
            divisor.add(num // i)
            
    return len(divisor)

def solution(number, limit, power):
    answer = 0
    num = 0
    for i in range(1, number+1):
        num = get_divisor(i)
        if limit < num:
            num = power
        answer += num
    
    return answer