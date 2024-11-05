#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    /* Input: 문자열 t, 문자열 p */
    int answer = 0;
    int p_idx;
    int t_len = strlen(t);
    int p_len = strlen(p);
    bool flag = false;
    
    /* 1. 문자열 t를 문자열 p 길이만큼 순차적으로 자르기 */
    /* 2. 자른 문자열의 자릿수마다 비교 */
    for(int i = 0; i <= t_len - p_len; i++){
        p_idx = 0;
        flag = false;
        for(int j = i; j < i + p_len; j++){
            /* 2.1. 같을 경우 계속 탐색 */
            if(t[j] == p[p_idx]) flag = true;
            /* 2.2. 작을 경우 answer + 1 */
            else if(t[j] < p[p_idx]){
                flag = false;
                answer++;
                break;
            }
            /* 2.3. 클 경우 다음 문자열 탐색 */
            else if(t[j] > p[p_idx]){
                flag = false;
                break;
            }
            p_idx++;
        }
        /* 2.4. 자른 문자열이 모드 같을 경우 answer + 1 */
        if(flag) answer++;
    }
    
    /* Output: 부분 문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수 */
    return answer;
}