def solution(angle):
    answer = 0
    if(0 < angle < 90):
        answer = 1
    elif(angle == 90):
        answer = 2
    elif(90 < angle < 180):
        answer = 3
    elif(angle == 180):
        answer = 4
    return answer