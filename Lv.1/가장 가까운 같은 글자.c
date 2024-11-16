#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // strlen �Լ� ����� ���� ��� ����

int s_idx[26] = {-1}; // �ʱⰪ�� -1�� �����Ͽ� ó�� ���� �� �Ǻ�

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* s) {
    /* Input: ���ڿ�(s) */
    int s_len = strlen(s);
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(s_len * sizeof(int));
    memset(answer, 0, s_len * sizeof(int));
    
    /* 1. �ʱⰪ(-1) ���� */
    for (int i = 0; i < 26; i++)
        s_idx[i] = -1;
    
    /* 2. ���ڿ��� ���������� Ž�� */
    for (int i = 0; i < s_len; i++) {
        /* 2.1. ������ �ε��� ��� */
        int idx = s[i] - 'a';

        /* 2.2. ���ڰ� ó�� ������ �� answer = -1 */
        if(s_idx[idx] == -1)
            answer[i] = -1;
        /* 2.3. ���ڰ� ������ ������ �� answer = ���� �ε��� - ���� �ε��� */
        else
            answer[i] = i - s_idx[idx];

        /* 2.4. ���� ������ �ε����� s_idx�� ������Ʈ */
        s_idx[idx] = i;
    }

    return answer;
}
