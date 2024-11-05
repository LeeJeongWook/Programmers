#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* s) {
    /* Input: 2���� ���ڿ� s */
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int count = 0, len, one_cnt, zero_cnt = 0;
    char str[150000];
    
    strcpy(str, s);
    len = strlen(str);
    
    while(1){
        count++;
        one_cnt = 0;
        /* 1. 2���� ���ڿ����� '0'�� '1'�� ���� �ľ� */
        for(int i = 0; i < len; i++){
            if(str[i] == '0') zero_cnt++;
            else one_cnt++;
        }
        /* 2. '1'�� �Ѱ� �ִٸ� �ݺ��� ���� */
        if(one_cnt == 1) break;
        
        /* 3. '1'�� ���̸� 2���� ���ڿ��� ���� �� 1.�� �ݺ� */
        len = 0;
        while(one_cnt){
            str[len++] = one_cnt % 2 + '0';
            one_cnt /= 2;
        }
    }
    
    answer[0] = count;
    answer[1] = zero_cnt;
    /* Output: ���� ��ȯ�� Ƚ��, ���ŵ� 0�� ���� */
    return answer;
}