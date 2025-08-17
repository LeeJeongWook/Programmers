import heapq

def solution(k, score):
    answer = []
    rank = []

    for s in score:
        if len(rank) < k:
            heapq.heappush(rank, s)
        else:
            if s > rank[0]:
                heapq.heappushpop(rank, s)
        
        answer.append(rank[0])

    return answer