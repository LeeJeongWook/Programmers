#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len�� �迭 bandage�� �����Դϴ�.
// attacks_rows�� 2���� �迭 attacks�� �� ����, attacks_cols�� 2���� �迭 attacks�� �� �����Դϴ�.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    int max_health = health;
    int attack_idx = 0;
    int length = attacks[attacks_rows - 1][0];
    
    for(int i = 1; i <= length; i++){
        /* ���Ͱ� ������ �� */
        if(i == attacks[attack_idx][0]){
        }
        
        
        if(health < max_health){
            
        }
    }
    
    return answer;
}