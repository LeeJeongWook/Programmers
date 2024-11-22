#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100000

int top = -1;

/* Func: �ڷᱸ�� Stack */
void push(int* ans, int value){
    if(top < MAX - 1) ans[++top] = value;
    return;
}

// prices_len�� �迭 prices�� �����Դϴ�.
int* solution(int prices[], size_t prices_len) {
    /* Input: �ֽİ���(prices[], prices_len) */
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(prices_len * sizeof(int));
    int count;
    
    /* 1. �ֽ� ������ �������� ���� Ž�� */
    for(size_t i = 0; i < prices_len; i++){
        count = 0;
        /* 1.1. �ֽ� ������ �������� �ʴµ��� count + 1 */
        for(size_t j = i + 1; j < prices_len; j++){
            if(prices[i] <= prices[j])
                count++;
            else{
                count++;
                break;
            }
        }
        /* 1.2. �ֽ� ������ �������ٸ� count�� push */
        push(answer, count);
    }
    
    /* Output: ������ �������� �ʴ� �Ⱓ(��) */
    return answer;
}