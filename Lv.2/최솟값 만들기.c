#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Func: 오름차순 정렬 */
int ascending(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

/* Func: 내림차순 정렬 */
int descending(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    /* Input: 배열 A(A[], A_len), 배열 B(B[], B_len) */
    int answer = 0;
    
    /* 1. 배열 A를 오름차순으로 정렬 */
    qsort(A, A_len, sizeof(int), ascending);
    /* 2. 배열 B를 내림차순으로 정렬 */
    qsort(B, B_len, sizeof(int), descending);
    
    /* 3. 배열 A, B를 인덱스 순서대로 곱한 값을 누적 */
    for(int i = 0; i < A_len; i++)
        answer += A[i] * B[i];
    
    /* Output: 누적된 최솟값 */
    return answer;
}