#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Func: �ִ������� return�ϴ� �Լ� */
int gcd(int a, int b){  //Greatest Common Divisor, �ִ�����
    int tmp;
    /* 1. b�� 0�� �� �� ���� a = b, b = a % b */
    while(b != 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

/* Func: �ּҰ������ return�ϴ� �Լ� */
int lcm(int a, int b){  //Least Common Multiple, �ּҰ����
    /* 1. �ּҰ���� = a * b / �ִ�����(gcd) */
    return (a * b) / gcd(a, b);
}

// arr_len�� �迭 arr�� �����Դϴ�.
int solution(int arr[], size_t arr_len) {
    /* Input: n���� ���ڸ� ���� �迭(arr[], arr_len) */
    int answer = arr[0];
    /* 1. 0�� �ε��� ���� ���������� �ּ� ����� ���ϱ� */
    for(size_t i = 1; i < arr_len; i++)
        answer = lcm(answer, arr[i]);
    
    /* Output: n���� ������ �ּҰ���� */
    return answer;
}