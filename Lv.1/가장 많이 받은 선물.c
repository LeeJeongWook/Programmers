#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {

    /* Input: 친구들의 이름(friends[]), 친구들 수(friends_len), 선물 기록(gifts[]), 선물 기록 수(gifts_len) */

    int answer = 0;
    char* token;
    
    int index[friends_len];
    int next_month[friends_len];
    int record[friends_len][friends_len];
    memset(index, 0, sizeof(index));
    memset(next_month, 0, sizeof(next_month));
    memset(record, 0, sizeof(record));

    /* 1. 선물 기록을 2차원 배열 record에 저장 및 선물지수 계산 */
    for(int i = 0; i < gifts_len; i++){
        int tmp_i, tmp_j;

        /* 1.1. gist[i]의 앞부분 : 선물을 준 사람, 선물 지수 + 1 */
        token = strtok(gifts[i], " ");
        for(int j = 0; j < friends_len; j++){
            if(!strcmp(token, friends[j])){
                tmp_i = j;
                index[j] ++;
            }
        }
        
        /* 1.2. gist[i]의 뒷부분 : 선물을 받은 사람, 선물 지수 - 1 */
        token = strtok(NULL, " ");
        for(int j = 0; j < friends_len; j++){
            if(!strcmp(token, friends[j])){
                tmp_j = j;
                index[j]--;
            }
        }

        /* 1.3. 2차원 배열 record에 입력(문제 예시 테이블과 동일) */
        record[tmp_i][tmp_j]++;
    }

    /* 2. record를 통해 다음달에 받을 선물 계산  */
    for(int i = 0; i < friends_len - 1; i++){
        for(int j = i + 1; j < friends_len; j++){
            /* 2.1. 선물의 횟수로 비교, 선물을 많이한 사람은 다음달 선물(next_month) + 1 */
            if(record[i][j] < record[j][i])
                next_month[j]++;

            else if(record[i][j] > record[j][i])
                next_month[i]++;
            
            /* 2.2. 선물의 횟수가 같을 때 선물지수로 비교 */
            else{
                /* 2.2.1. 선물 지수가 높은 사람은 다음달 선물(next_month) + 1 */
                if(index[i] < index[j])
                    next_month[j]++;
                else if(index[i] > index[j])
                    next_month[i]++;
            }
        }
    }
    
    /* 3. 가장 많은 선물을 받는 친구가 받게되는 선물의 수 찾기 */
    for(int i = 0; i < friends_len; i++){
        if(answer < next_month[i])
            answer = next_month[i];
    }
    
    /* Output: 가장 많은 선물을 받는 친구가 받게되는 선물의 수 */
    return answer;
}