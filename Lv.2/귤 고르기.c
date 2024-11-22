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

// tangerine_len�� �迭 tangerine�� �����Դϴ�.
int solution(int k, int tangerine[], size_t tangerine_len) {
    /* Input: ���� ����(k), ���� ũ��(tangerine[], tangerine_len) */
    int answer = 0;
    int max = 0;
    int cnt = 0;

    /* 1. ���� ũ�⺰ ���� �ľ� */
    for(size_t i = 0; i < tangerine_len; i++){
        /* 1.1. ũ�⺰ ������ ���� ���� ū ������ �ľ� */
        if(max < tangerine[i]) max = tangerine[i];
        t_size[tangerine[i]].idx = tangerine[i];
        t_size[tangerine[i]].amount++;
    }
    
    /* 2. ���� ũ�⺰ ���� ���� ������������ ���� */
    qsort(t_size, max + 1, sizeof(size), compareAmount);
    
    /* 3. k���� ä�� �� ���� ũ�� ������ �ľ� */
    for(int i = 0; i < max + 1; i++){
        if(k <= cnt) break;
        answer++;
        cnt += t_size[i].amount;
    }
    
    /* Output: �� k���� �� �� ũ�Ⱑ ���� �ٸ� ������ �� */
    return answer;
}