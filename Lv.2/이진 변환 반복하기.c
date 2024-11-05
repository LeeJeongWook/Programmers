#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    /* Input: 2진수 문자열 s */
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int count = 0, len, one_cnt, zero_cnt = 0;
    char str[150000];
    
    strcpy(str, s);
    len = strlen(str);
    
    while(1){
        count++;
        one_cnt = 0;
        /* 1. 2진수 문자열에서 '0'과 '1'의 개수 파악 */
        for(int i = 0; i < len; i++){
            if(str[i] == '0') zero_cnt++;
            else one_cnt++;
        }
        /* 2. '1'이 한개 있다면 반복문 종료 */
        if(one_cnt == 1) break;
        
        /* 3. '1'의 길이를 2진수 문자열로 저장 후 1.번 반복 */
        len = 0;
        while(one_cnt){
            str[len++] = one_cnt % 2 + '0';
            one_cnt /= 2;
        }
    }
    
    answer[0] = count;
    answer[1] = zero_cnt;
    /* Output: 이진 변환의 횟수, 제거된 0의 개수 */
    return answer;
}