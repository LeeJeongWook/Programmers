#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FOOD_MAX 9000
// food_len�� �迭 food�� �����Դϴ�.
char* solution(int food[], size_t food_len) {
    /* Input: ���� �迭(food[], food_len) */
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int idx = 0;
    char* answer = (char*)malloc(FOOD_MAX * sizeof(char));
    
    /* 1. �� ������ 2�� ������ ���� */
    for(int i = 0; i < food_len; i++)
        food[i] /= 2;
    
    /* 2. ���� ���� ���� ��ġ */
    for(int i = 1; i < food_len; i++){
        for(int j = 0; j < food[i]; j++){
            answer[idx++] = i + '0';
        }
    }

    /* 3. ��� �� ��ġ */
    answer[idx++] = '0';
    
    /* 4. ���� ���� ���� ��ġ */
    for(int i = food_len - 1; i > 0; i--){
        for(int j = 0; j < food[i]; j++){
            answer[idx++] = i + '0';
        }
    }
    /* Output: ��ȸ�� ���� ������ ��ġ */
    return answer;
}