def solution(cards1, cards2, goal):
    answer = "Yes"
    
    for s in goal:
        if (len(cards1) != 0) and (s == cards1[0]):
            cards1.remove(s)
        elif (len(cards2) != 0) and (s == cards2[0]):
            cards2.remove(s)
        else:
            answer = "No"
            break
            
    return answer