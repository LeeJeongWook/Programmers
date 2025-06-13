def solution(a, b):
    answer = 0
    tmp1 = str(a) + str(b)
    tmp2 = str(b) + str(a)
    
    if(int(tmp1) > int(tmp2) or int(tmp1) == int(tmp2)):
        answer = int(tmp1)
    elif(int(tmp1) < int(tmp2)):
        answer = int(tmp2)
        
    return answer