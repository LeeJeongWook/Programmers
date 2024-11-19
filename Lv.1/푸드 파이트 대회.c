#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FOOD_MAX 9000
// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    /* Input: 음식 배열(food[], food_len) */
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int idx = 0;
    char* answer = (char*)malloc(FOOD_MAX * sizeof(char));
    
    /* 1. 각 음식을 2로 나누어 저장 */
    for(int i = 0; i < food_len; i++)
        food[i] /= 2;
    
    /* 2. 좌측 선수 음식 배치 */
    for(int i = 1; i < food_len; i++){
        for(int j = 0; j < food[i]; j++){
            answer[idx++] = i + '0';
        }
    }

    /* 3. 가운데 물 배치 */
    answer[idx++] = '0';
    
    /* 4. 우측 선수 음식 배치 */
    for(int i = food_len - 1; i > 0; i--){
        for(int j = 0; j < food[i]; j++){
            answer[idx++] = i + '0';
        }
    }
    /* Output: 대회를 위한 음식의 배치 */
    return answer;
}