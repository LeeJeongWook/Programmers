def solution(nums):
    answer = 0
    pick = len(nums) // 2
    my_set = set()
    
    for i in nums:
        my_set.add(i)
    
    if len(my_set) < pick:
        answer = len(my_set)
    else:
        answer = pick
    
    return answer