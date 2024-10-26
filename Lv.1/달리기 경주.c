#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define players_MAX 50000
// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(players_len * sizeof(char*));
    char* tmp;
    
    
    for(int i = 0; i < players_len; i++){
        answer[i] = players[i];
    }
    
    for(int i = 0; i < callings_len; i++){
        for(int j = 1; j < players_len; j++){
            if(!strcmp(callings[i], answer[j])){
                tmp = answer[j-1];
                answer[j-1] = answer[j];
                answer[j] = tmp;
            }
        }
    }
    
    return answer;
}