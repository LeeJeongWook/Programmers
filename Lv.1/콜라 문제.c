#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    /* Input: �ݶ� �ޱ� ���� �� ��(a), ��Ʈ�� �ִ� �� ��(b), �� ���� ����(n) */
    int answer = 0;
    
    while(1){
        /* 1. ���� ���� �� ������ ���� �� �ִ� �� �� ���ϱ� */
        answer += (n / a) * b;
        /* 2. �� �� �� = 1�� + ������ �� */
        n = ((n / a) * b) + (n % a);
        /* 3. ���� ���� �� ���� a�� �̸��� �� ���� �ݺ� */
        if(n < a) break;
    }
    
    /* Output: ���� �� �ִ� �ݶ��� �� �� */
    return answer;
}