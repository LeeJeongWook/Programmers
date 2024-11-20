#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Func: 최대공약수를 return하는 함수 */
int gcd(int a, int b){  //Greatest Common Divisor, 최대공약수
    int tmp;
    /* 1. b가 0이 될 때 까지 a = b, b = a % b */
    while(b != 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

/* Func: 최소공배수를 return하는 함수 */
int lcm(int a, int b){  //Least Common Multiple, 최소공배수
    /* 1. 최소공배수 = a * b / 최대공약수(gcd) */
    return (a * b) / gcd(a, b);
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    /* Input: n개의 숫자를 담은 배열(arr[], arr_len) */
    int answer = arr[0];
    /* 1. 0번 인덱스 부터 순차적으로 최소 공배수 구하기 */
    for(size_t i = 1; i < arr_len; i++)
        answer = lcm(answer, arr[i]);
    
    /* Output: n개의 수들의 최소공배수 */
    return answer;
}