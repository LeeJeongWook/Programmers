#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// friends_len�� �迭 friends�� �����Դϴ�.
// gifts_len�� �迭 gifts�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {

    /* Input: ģ������ �̸�(friends[]), ģ���� ��(friends_len), ���� ���(gifts[]), ���� ��� ��(gifts_len) */

    int answer = 0;
    char* token;
    
    int index[friends_len];
    int next_month[friends_len];
    int record[friends_len][friends_len];
    memset(index, 0, sizeof(index));
    memset(next_month, 0, sizeof(next_month));
    memset(record, 0, sizeof(record));

    /* 1. ���� ����� 2���� �迭 record�� ���� �� �������� ��� */
    for(int i = 0; i < gifts_len; i++){
        int tmp_i, tmp_j;

        /* 1.1. gist[i]�� �պκ� : ������ �� ���, ���� ���� + 1 */
        token = strtok(gifts[i], " ");
        for(int j = 0; j < friends_len; j++){
            if(!strcmp(token, friends[j])){
                tmp_i = j;
                index[j] ++;
            }
        }
        
        /* 1.2. gist[i]�� �޺κ� : ������ ���� ���, ���� ���� - 1 */
        token = strtok(NULL, " ");
        for(int j = 0; j < friends_len; j++){
            if(!strcmp(token, friends[j])){
                tmp_j = j;
                index[j]--;
            }
        }

        /* 1.3. 2���� �迭 record�� �Է�(���� ���� ���̺�� ����) */
        record[tmp_i][tmp_j]++;
    }

    /* 2. record�� ���� �����޿� ���� ���� ���  */
    for(int i = 0; i < friends_len - 1; i++){
        for(int j = i + 1; j < friends_len; j++){
            /* 2.1. ������ Ƚ���� ��, ������ ������ ����� ������ ����(next_month) + 1 */
            if(record[i][j] < record[j][i])
                next_month[j]++;

            else if(record[i][j] > record[j][i])
                next_month[i]++;
            
            /* 2.2. ������ Ƚ���� ���� �� ���������� �� */
            else{
                /* 2.2.1. ���� ������ ���� ����� ������ ����(next_month) + 1 */
                if(index[i] < index[j])
                    next_month[j]++;
                else if(index[i] > index[j])
                    next_month[i]++;
            }
        }
    }
    
    /* 3. ���� ���� ������ �޴� ģ���� �ްԵǴ� ������ �� ã�� */
    for(int i = 0; i < friends_len; i++){
        if(answer < next_month[i])
            answer = next_month[i];
    }
    
    /* Output: ���� ���� ������ �޴� ģ���� �ްԵǴ� ������ �� */
    return answer;
}