#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {
    int answer = 0;
    
    int records[friends_len];
    memset(records, 0, sizeof(records));
    
    char* token;
    char* give[gifts_len];
    char* take[gifts_len];
    
    for(int i = 0; i < gifts_len; i++){
        token = strtok(gifts[i], " ");
        give[i] = token;
        
        for(int j = 0; j < friends_len; j++)
            if(!strcmp(token, friends[j]))
                records[j] ++;
        
        token = strtok(NULL, " ");
        take[i] = token;
        
        for(int j = 0; j < friends_len; j++)
            if(!strcmp(token, friends[j]))
                records[j]--;
    }
    
    
    for(int i = 0; i < friends_len; i++){
        printf("%d ", records[i]);
    }
    printf("\n\n");
    // for(int i = 0; i < gifts_len; i++){
    //     printf("%s ", give[i]);
    // }
    // printf("\n");
    // for(int i = 0; i < gifts_len; i++){
    //     printf("%s ", take[i]);
    // }
    
    return answer;
}