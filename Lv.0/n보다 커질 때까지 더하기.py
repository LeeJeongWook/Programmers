def solution(numbers, n):
    answer = 0
    sum = 0
    
    for num in numbers:
        sum += num
        print(sum)
        if(n < sum):
            answer = sum
            break

    return answer