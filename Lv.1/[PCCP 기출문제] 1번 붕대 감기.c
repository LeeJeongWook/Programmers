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
    int time = 0;
    bool flag = false;
    
    for(int i = 1; i <= length; i++){
        //���Ϳ��� ���ݹ��� ��
        if(i == attacks[attack_idx][0]){
            health -= attacks[attack_idx][1];
            if(attack_idx < attacks_rows-1)
                attack_idx++;   //���� ���� �ε���
            if(flag){
                time = 0;  //���Ӽ��� �ʱ�ȭ
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
            
        else if(max_health <= health) //ü���� �ִ�ġ�϶�
            flag = false;
    }
    answer = health;
    return answer;
}