def solution(num_list):
    answer = []
    odd_cnt = 0
    even_cnt = 0
    for num in num_list:
        if(num % 2):
            odd_cnt = odd_cnt + 1
        else:
            even_cnt = even_cnt + 1
    answer.append(even_cnt)
    answer.append(odd_cnt)
    return answer