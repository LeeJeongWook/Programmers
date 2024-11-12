#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* num;
int num_len;
int arr[3];
int answer = 0;

/* Func: ��ȣ 3���� �����Ͽ� ������������ �� �� */
void combination(int n, int cnt){
    int sum = 0;
    /* 1. 3�� ��� �������� �� 3�� ��ȣ�� ���� ���Ѵ� */
    if(cnt == 3){
        for(int i = 0; i < 3; i++)
            sum += arr[i];
        /* 1.1. 3�� ��ȣ�� ���� 0�� ��� answer + 1 */
        if(!sum) answer++;
        return;
    }
    /* 2. 3���� ������ �� ���� �Լ� ���ȣ�� */
    for(int i = n; i < num_len; i++){
        arr[cnt] = num[i];
        combination(i + 1, cnt + 1);
    }
}

// number_len�� �迭 number�� �����Դϴ�.
int solution(int number[], size_t number_len) {
    /* Input: �л����� ��ȣ�� ��Ÿ���� ���� �迭(number[], number_len) */

    /* Input������ ���� */
    num = (int*)malloc(number_len * sizeof(int));
    memcpy(num, number, number_len * sizeof(int));
    num_len = number_len;
    
    /* 1. ��ȣ 3���� �����Ͽ� ������������ �� �� */
    combination(0, 0);
    
    /* Output: ���ѻ縦 ���� �� �ִ� ����� �� */
    return answer;
}