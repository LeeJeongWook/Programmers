#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(const char* t, const char* p) {
    /* Input: ���ڿ� t, ���ڿ� p */
    int answer = 0;
    int p_idx;
    int t_len = strlen(t);
    int p_len = strlen(p);
    bool flag = false;
    
    /* 1. ���ڿ� t�� ���ڿ� p ���̸�ŭ ���������� �ڸ��� */
    /* 2. �ڸ� ���ڿ��� �ڸ������� �� */
    for(int i = 0; i <= t_len - p_len; i++){
        p_idx = 0;
        flag = false;
        for(int j = i; j < i + p_len; j++){
            /* 2.1. ���� ��� ��� Ž�� */
            if(t[j] == p[p_idx]) flag = true;
            /* 2.2. ���� ��� answer + 1 */
            else if(t[j] < p[p_idx]){
                flag = false;
                answer++;
                break;
            }
            /* 2.3. Ŭ ��� ���� ���ڿ� Ž�� */
            else if(t[j] > p[p_idx]){
                flag = false;
                break;
            }
            p_idx++;
        }
        /* 2.4. �ڸ� ���ڿ��� ��� ���� ��� answer + 1 */
        if(flag) answer++;
    }
    
    /* Output: �κ� ���ڿ��� ��Ÿ���� ���� p�� ��Ÿ���� ������ �۰ų� ���� ���� ������ Ƚ�� */
    return answer;
}