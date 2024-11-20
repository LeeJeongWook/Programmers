#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    /* Input: 콜라를 받기 위한 병 수(a), 마트가 주는 병 수(b), 빈 병의 개수(n) */
    int answer = 0;
    
    while(1){
        /* 1. 현재 가진 빈 병으로 받을 수 있는 병 수 더하기 */
        answer += (n / a) * b;
        /* 2. 빈 병 수 = 1번 + 나머지 병 */
        n = ((n / a) * b) + (n % a);
        /* 3. 보유 중인 빈 병이 a개 미만일 때 까지 반복 */
        if(n < a) break;
    }
    
    /* Output: 받을 수 있는 콜라의 병 수 */
    return answer;
}