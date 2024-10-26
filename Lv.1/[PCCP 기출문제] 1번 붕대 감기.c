#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len�� �迭 bandage�� �����Դϴ�.
// attacks_rows�� 2���� �迭 attacks�� �� ����, attacks_cols�� 2���� �迭 attacks�� �� �����Դϴ�.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    /* Input: �ش밨��(bandage[], bandage_len), ���� ü��(health), ���� �ð�/���ط�(attacks, attacks_rows, attacks_cols) */

    int answer = 0;
    int time = 0;   // �ش밨�� �����ð�
    int attack_idx = 0; // ���� �ε���
    int max_health = health;    // �ִ�ü�� ����
    int length = attacks[attacks_rows - 1][0];  // ������ ������ ���� �ð�
    bool flag = false;  // �ش밨�� ���� ����
    
    for(int i = 1; i <= length; i++){
        /* 1. ���Ϳ��� ���ݹ��� �� */
        if(i == attacks[attack_idx][0]){
            /* 1.1. ���ط� ��ŭ ü�� ���� */
            health -= attacks[attack_idx][1];
            /* 1.2. ���ӽð� �ʱ�ȭ �� �ش밨�� ��� */
            time = 0;
            flag = false;
            if(attack_idx < attacks_rows-1)
                attack_idx++;   //���� ���� �ε���
        }
        
        /* 2. �ش밨�� �������� �� */
        if(flag){
            /* 2.1. ���ӽð� ���� �� �ʴ� ȸ���� ��ŭ ȸ�� */
            time++;
            health += bandage[1];
            
            /* 2.2. ���ӽð� ������ �߰�ȸ���� ��ŭ �߰�ȸ�� */
            if(time == bandage[0]){
                health += bandage[2];
                time = 0;
            }
        }
        
        /* 3. ���� ü�� Ȯ�� */
        /* 3.1. ü���� 0������ �� ����(-1)�� ó�� �� ���� */
        if(health <= 0){
            answer = -1;
            return answer;
        }
        /* 3.2. ü���� ������ ��, �ش밨�� ���� */
        else if(0 < health && health < max_health)
            flag = true;
        
        /* 3.3. ü���� �ִ�ü�� �̻��� ��� ü�� = �ִ�ü�� */
        else if(max_health <= health){
            flag = false;
            health = max_health;
        }
    }

    /* Output: ������ ������ ���� ���� ���� ü�� */
    answer = health;
    return answer;
}