def solution(num_list):
    even = ''
    odd = ''
    for i in num_list:
        if(i % 2):
            odd += str(i)
        else:
            even += str(i)
    answer = int(odd) + int(even)
    
    return answer