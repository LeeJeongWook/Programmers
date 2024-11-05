#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Func: �������� ���� */
int ascending(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

/* Func: �������� ���� */
int descending(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

// A_len�� �迭 A�� �����Դϴ�.
// B_len�� �迭 B�� �����Դϴ�.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    /* Input: �迭 A(A[], A_len), �迭 B(B[], B_len) */
    int answer = 0;
    
    /* 1. �迭 A�� ������������ ���� */
    qsort(A, A_len, sizeof(int), ascending);
    /* 2. �迭 B�� ������������ ���� */
    qsort(B, B_len, sizeof(int), descending);
    
    /* 3. �迭 A, B�� �ε��� ������� ���� ���� ���� */
    for(int i = 0; i < A_len; i++)
        answer += A[i] * B[i];
    
    /* Output: ������ �ּڰ� */
    return answer;
}