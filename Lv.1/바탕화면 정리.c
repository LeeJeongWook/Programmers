#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// wallpaper_len은 배열 wallpaper의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    /* Input: 바탕화면의 상태(wallpaper[], wallpaper_len) */
    
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(4 * sizeof(int));
    
    int min_i = 50, min_j = 50, max_i = 0, max_j = 0;

    /* 1. wallpaper의 가로 길이 구하기 */
    int wallpaper_len_2 = strlen(wallpaper[0]);

    /* 2. wallpaper에서 '#'인 위치 탐색 */
    /* 2.1. 최대/최소 세로, 최대/최소 가로 좌표 저장 */
    for(int i = 0; i < wallpaper_len; i++){
        for(int j = 0; j < wallpaper_len_2; j++){
            if(wallpaper[i][j] == '#'){
                if(i < min_i) min_i = i;
                if(i > max_i) max_i = i;
                if(j < min_j) min_j = j;
                if(j > max_j) max_j = j;
            }
        }
    }
    
    /* 2.2. 드래그 시작점(최소 세로좌표, 최소 가로좌표), 드래그 끝점(최대 세로좌표, 최대 가로좌표) */
    answer[0] = min_i;
    answer[1] = min_j;
    answer[2] = ++max_i;
    answer[3] = ++max_j;

    /* Output: [최소 세로좌표, 최소 가로좌표, 최대 세로좌표, 최대 가로좌표] */
    return answer;
}