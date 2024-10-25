#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    int max_health = health;
    int attack_idx = 0;
    int length = attacks[attacks_rows - 1][0];
    int time = 0;
    bool flag = false;
    
    for(int i = 1; i <= length; i++){
        //몬스터에게 공격받을 떄
        if(i == attacks[attack_idx][0]){
            health -= attacks[attack_idx][1];
            if(attack_idx < attacks_rows-1)
                attack_idx++;   //다음 몬스터 인덱스
            if(flag){
                time = 0;  //연속성공 초기화
                flag = false;
            }
        }
        
        if(flag){
            time++;
            health += bandage[1];
            
            if(time == bandage[0]){
                health += bandage[2];
                time = 0;
            }
        }
        
        if(health <= 0){
            answer = -1;
            return answer;
        }
        else if(0 < health && health < max_health)
            flag = true;
            
        else if(max_health <= health) //체력이 최대치일때
            flag = false;
    }
    answer = health;
    return answer;
}