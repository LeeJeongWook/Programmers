#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* num;
int num_len;
int arr[3];
int answer = 0;

/* Func: 번호 3개를 선택하여 조합했을때의 합 비교 */
void combination(int n, int cnt){
    int sum = 0;
    /* 1. 3명 모두 선정했을 때 3명 번호의 합을 구한다 */
    if(cnt == 3){
        for(int i = 0; i < 3; i++)
            sum += arr[i];
        /* 1.1. 3명 번호의 합이 0인 경우 answer + 1 */
        if(!sum) answer++;
        return;
    }
    /* 2. 3명이 선정될 때 까지 함수 재귀호출 */
    for(int i = n; i < num_len; i++){
        arr[cnt] = num[i];
        combination(i + 1, cnt + 1);
    }
}

// number_len은 배열 number의 길이입니다.
int solution(int number[], size_t number_len) {
    /* Input: 학생들의 번호를 나타내는 정수 배열(number[], number_len) */

    /* Input데이터 복사 */
    num = (int*)malloc(number_len * sizeof(int));
    memcpy(num, number, number_len * sizeof(int));
    num_len = number_len;
    
    /* 1. 번호 3개를 선택하여 조합했을때의 합 비교 */
    combination(0, 0);
    
    /* Output: 삼총사를 만들 수 있는 방법의 수 */
    return answer;
}