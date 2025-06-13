def solution(n, numlist):
    answer = []
    for i in numlist:
        if(not(i % n)):
            answer.append(i)
    return answer