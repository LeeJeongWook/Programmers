#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // strlen 함수 사용을 위한 헤더 파일

int s_idx[26] = {-1}; // 초기값을 -1로 설정하여 처음 등장 시 판별

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    /* Input: 문자열(s) */
    int s_len = strlen(s);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(s_len * sizeof(int));
    memset(answer, 0, s_len * sizeof(int));
    
    /* 1. 초기값(-1) 설정 */
    for (int i = 0; i < 26; i++)
        s_idx[i] = -1;
    
    /* 2. 문자열을 순차적으로 탐색 */
    for (int i = 0; i < s_len; i++) {
        /* 2.1. 문자의 인덱스 계산 */
        int idx = s[i] - 'a';

        /* 2.2. 문자가 처음 나왔을 때 answer = -1 */
        if(s_idx[idx] == -1)
            answer[i] = -1;
        /* 2.3. 문자가 이전에 나왔을 때 answer = 현재 인덱스 - 이전 인덱스 */
        else
            answer[i] = i - s_idx[idx];

        /* 2.4. 현재 문자의 인덱스를 s_idx에 업데이트 */
        s_idx[idx] = i;
    }

    return answer;
}
