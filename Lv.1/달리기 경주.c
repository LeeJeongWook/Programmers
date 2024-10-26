#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define players_MAX 50000
// players_len�� �迭 players�� �����Դϴ�.
// callings_len�� �迭 callings�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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