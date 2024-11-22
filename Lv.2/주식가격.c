#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100000

int top = -1;

/* Func: 자료구조 Stack */
void push(int* ans, int value){
    if(top < MAX - 1) ans[++top] = value;
    return;
}

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    /* Input: 주식가격(prices[], prices_len) */
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(prices_len * sizeof(int));
    int count;
    
    /* 1. 주식 가격이 떨어지는 지점 탐색 */
    for(size_t i = 0; i < prices_len; i++){
        count = 0;
        /* 1.1. 주식 가격이 떨어지지 않는동안 count + 1 */
        for(size_t j = i + 1; j < prices_len; j++){
            if(prices[i] <= prices[j])
                count++;
            else{
                count++;
                break;
            }
        }
        /* 1.2. 주식 가격이 떨어진다면 count값 push */
        push(answer, count);
    }
    
    /* Output: 가격이 떨어지지 않는 기간(초) */
    return answer;
}