#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    int p_idx;
    int t_len = strlen(t);
    int p_len = strlen(p);
    bool flag = false;
    
    for(int i = 0; i <= t_len - p_len; i++){
        p_idx = 0;
        flag = false;
        for(int j = i; j < i + p_len; j++){
            if(t[j] == p[p_idx]) flag = true;
            else if(t[j] < p[p_idx]){
                flag = false;
                answer++;
                break;
            }
            else if(t[j] > p[p_idx]){
                flag = false;
                break;
            }
            p_idx++;
        }
        if(flag) answer++;
    }
    
    return answer;
}