import math

def solution(n):
    answer = 0
    if(math.sqrt(n) % 1):
        answer = 2
    else:
        answer = 1
    return answer