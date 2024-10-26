#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    /* Input: 붕대감기(bandage[], bandage_len), 현재 체력(health), 공격 시간/피해량(attacks, attacks_rows, attacks_cols) */

    int answer = 0;
    int time = 0;   // 붕대감기 시전시간
    int attack_idx = 0; // 몬스터 인덱스
    int max_health = health;    // 최대체력 저장
    int length = attacks[attacks_rows - 1][0];  // 몬스터의 마지막 공격 시간
    bool flag = false;  // 붕대감기 시전 여부
    
    for(int i = 1; i <= length; i++){
        /* 1. 몬스터에게 공격받을 때 */
        if(i == attacks[attack_idx][0]){
            /* 1.1. 피해량 만큼 체력 감소 */
            health -= attacks[attack_idx][1];
            /* 1.2. 연속시간 초기화 및 붕대감기 취소 */
            time = 0;
            flag = false;
            if(attack_idx < attacks_rows-1)
                attack_idx++;   //다음 몬스터 인덱스
        }
        
        /* 2. 붕대감기 시전중일 때 */
        if(flag){
            /* 2.1. 연속시간 증가 및 초당 회복량 만큼 회복 */
            time++;
            health += bandage[1];
            
            /* 2.2. 연속시간 성공기 추가회복량 만큼 추가회복 */
            if(time == bandage[0]){
                health += bandage[2];
                time = 0;
            }
        }
        
        /* 3. 현재 체력 확인 */
        /* 3.1. 체력이 0이하일 때 죽음(-1)로 처리 및 종료 */
        if(health <= 0){
            answer = -1;
            return answer;
        }
        /* 3.2. 체력이 깎여있을 때, 붕대감기 시전 */
        else if(0 < health && health < max_health)
            flag = true;
        
        /* 3.3. 체력이 최대체력 이상일 경우 체력 = 최대체력 */
        else if(max_health <= health){
            flag = false;
            health = max_health;
        }
    }

    /* Output: 몬스터의 마지막 공격 직후 현재 체력 */
    answer = health;
    return answer;
}