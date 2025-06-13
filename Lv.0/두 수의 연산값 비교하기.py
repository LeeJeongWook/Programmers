def solution(a, b):
    num_1 = int(str(a) + str(b))
    num_2 = 2 * a * b
    if(num_1 < num_2):
        answer = num_2
    elif(num_1 >= num_2):
        answer = num_1
        
    return answer