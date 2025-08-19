def solution(name, yearning, photo):
    answer = []
    my_dict = {}
    for i in range(len(name)):
        my_dict[name[i]] = yearning[i]
    
    for friends in photo:
        score = 0
        for name in friends:
            if name in my_dict:
                score += my_dict[name]
        answer.append(score)
                
    return answer