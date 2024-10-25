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
    
    for(int i = 1; i <= length; i++){
        /* 몬스터가 공격할 때 */
        if(i == attacks[attack_idx][0]){
        }
        
        
        if(health < max_health){
            
        }
    }
    
    return answer;
}