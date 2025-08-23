from collections import Counter

def solution(participant, completion):
    count1 = Counter(participant)
    count2 = Counter(completion)
    
    answer = count1 - count2
    
    answer = list(answer.keys())[0]
    
    return answer