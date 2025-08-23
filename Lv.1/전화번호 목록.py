def solution(phone_book):
    answer = True
    
    my_hash = {}
    
    for number in phone_book:
        my_hash[number] = 1
    
    for number in phone_book:
        prefix = ""
        for num in number:
            prefix += num
            
            if prefix in my_hash and prefix != number:
                return False
    
    return answer