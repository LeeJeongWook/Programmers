#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int idx;
    int amount;
}size;

size t_size[100000001];

int compareAmount(const void* a, const void* b){
    return ((size*)b)->amount - ((size*)a)->amount;
}

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    /* Input: 귤의 개수(k), 귤의 크기(tangerine[], tangerine_len) */
    int answer = 0;
    int max = 0;
    int cnt = 0;

    /* 1. 귤의 크기별 갯수 파악 */
    for(size_t i = 0; i < tangerine_len; i++){
        /* 1.1. 크기별 정렬을 위한 가장 큰 사이즈 파악 */
        if(max < tangerine[i]) max = tangerine[i];
        t_size[tangerine[i]].idx = tangerine[i];
        t_size[tangerine[i]].amount++;
    }
    
    /* 2. 귤의 크기별 갯수 기준 내림차순으로 정렬 */
    qsort(t_size, max + 1, sizeof(size), compareAmount);
    
    /* 3. k개를 채울 때 까지 크기 종류수 파악 */
    for(int i = 0; i < max + 1; i++){
        if(k <= cnt) break;
        answer++;
        cnt += t_size[i].amount;
    }
    
    /* Output: 귤 k개를 고를 때 크기가 서로 다른 종류의 수 */
    return answer;
}