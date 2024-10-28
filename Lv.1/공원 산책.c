#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    /* Input: 공원 (park[], park_len), 수행할 명령 (routes[], routes_len) */

    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
    
    char* token;
    int park_column, idx, idx_i, idx_j;
    char direct;
    bool flag = true;
    
    /* 1. 공원의 세로길이 계산 */
    park_column = strlen(park[0]);
    
    /* 2. 공원에서 시작지점 탐색 */
    for(int i = 0; i < park_len; i++){
        for(int j = 0; j < park_column; j++){
            if(park[i][j] == 'S'){
                idx_i = i;
                idx_j = j;
            }
        }
    }
    
    /* 3. 산책 명령 실행 */
    for(int i = 0; i < routes_len; i++){
        /* 3.1. 이동 방향, 이동 거리 Parsing */
        flag = true;
        token = strtok(routes[i]," ");
        direct = token[0];
        token = strtok(NULL," ");
        idx = atoi(token);
        
        /* 3.2. 이동 방향 경로 확인 */
        /* 3.2.1. 공원 밖으로 가거나 장애물을 만날 경우 이동 없이 다음 명령 수행 */
        /* 3.2.2. 이동 방향 분류 및 이동거리만큼 이동 */
        switch (direct){
            case 'N':
                if(idx_i - idx < 0) break;
                
                for(int j = idx_i - 1; j >= idx_i - idx; j--){
                    if(park[j][idx_j] == 'X'){
                        flag = false;
                        break;
                    }
                }
                if(flag) idx_i -= idx;
                break;
                
            case 'S':
                if(park_column <= idx_i + idx) break;
                
                for(int j = idx_i + 1; j <= idx_i + idx; j++){
                    if(park[j][idx_j] == 'X'){
                        flag = false;
                        break;
                    }
                }
                if(flag) idx_i += idx;
                break;
                
            case 'W':
                if(idx_j - idx < 0) break;
                
                for(int j = idx_j - 1; j >= idx_j - idx; j--){
                    if(park[idx_i][j] == 'X'){
                        flag = false;
                        break;
                    }
                }
                if(flag) idx_j -= idx;
                break;
                
            case 'E':
                if(park_column <= idx_j + idx) break;
                
                for(int j = idx_j + 1; j <= idx_j + idx; j++){
                    if(park[idx_i][j] == 'X'){
                        flag = false;
                        break;
                    }
                }
                if(flag) idx_j += idx;
                break;
        }
    }
    
    /* Output: 모든 명령 수행 후 [세로 좌표, 가로 좌표] */
    answer[0] = idx_i;
    answer[1] = idx_j;
    
    return answer;
}