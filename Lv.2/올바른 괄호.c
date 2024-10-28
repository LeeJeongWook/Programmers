#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
bool solution(const char* s) {
    /* Input: ��ȣ ���ڿ� s */

    int cnt = 0;
    int len = strlen(s);

    /* 1. ��ȣ Ȯ�� */
    /* 1.1. '('�� �� cnt + 1, ')'�� �� cnt - 1 */
    /* 1.2. cnt�� ������ ��� ( ���� )�� �� ���� ���� ������ �߸��� ��ȣ */
    for(int i = 0; i < len; i++){
        if(s[i] == '(') cnt++;
        else{
            cnt--;
            if(cnt < 0) return false;
        }
    }
    
    /* Output: cnt�� 0�� ��� ¦�� �´� ���� ��ȣ */
    return (cnt == 0) ? true : false;
}