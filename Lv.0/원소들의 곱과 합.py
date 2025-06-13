def solution(num_list):
    mul = 1
    sum = 0
    
    for i in num_list:
        mul = mul * i
        sum = sum + i
    sum = sum ** 2
    if(mul < sum):
        answer = 1
    else:
        answer = 0
        
    return answer