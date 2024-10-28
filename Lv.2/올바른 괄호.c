#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    /* Input: 괄호 문자열 s */

    int cnt = 0;
    int len = strlen(s);

    /* 1. 괄호 확인 */
    /* 1.1. '('일 때 cnt + 1, ')'일 때 cnt - 1 */
    /* 1.2. cnt가 음수일 경우 ( 보다 )가 더 많이 나온 것으로 잘못된 괄호 */
    for(int i = 0; i < len; i++){
        if(s[i] == '(') cnt++;
        else{
            cnt--;
            if(cnt < 0) return false;
        }
    }
    
    /* Output: cnt가 0일 경우 짝이 맞는 옳은 괄호 */
    return (cnt == 0) ? true : false;
}