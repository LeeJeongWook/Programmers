#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define players_MAX 50000

typedef struct{
    int index;
    char *name;
}player;

player player_arr[players_MAX];

/* Func: player_arr name을 오름차순으로 정렬 */
int Compare( const void* a, const void *b){
    return strcmp(((player*)a)->name, ((player*)b)->name);
}

/* Func: 호명된 선수의 인덱스 이진탐색 */
int Search(char* name, size_t players_len){
    int left = 0;
    int right = players_len;
    int pos, tmp_pos;

    pos = (left + right) / 2;
    while ((tmp_pos = strcmp(player_arr[pos].name, name)) != 0){
        if (tmp_pos < 0)
            left = pos;
        else
            right = pos;

        pos = (left + right) / 2;
    }

    return pos;
}

// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char **solution(const char *players[], size_t players_len, const char *callings[], size_t callings_len){
    /* Input: 선수 이름 (players[], players_len), 해설진이 부르는 이름 (callings[], callings_len) */

    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char **answer = (char **)malloc(players_len * sizeof(char *));
    char *tmp;

    /* 1. answer[]에 players[]복사 / 구조체 배열 player_arr에 name, index로 저장 */
    for(int i = 0; i < players_len; i++){
        answer[i] = players[i];
        player_arr[i].name = players[i];
        player_arr[i].index = i;
    }

    /* 2. 구조체 배열 plater_arr를 name순으로 정렬 */
    qsort(player_arr, players_len, sizeof(player), Compare);

    /* 3. 해설진이 부르는 이름들 */
    for(int i = 0; i < callings_len; i++){
        /* 3.1. 해설진이 부르는 이름의 선수 이진탐색 */
        int idx = Search(callings[i], players_len);

        /* 3.2. 해설진이 부른 선수의 index 저장 */
        int player_pos = player_arr[idx].index;
        
        /* 3.3. 해설진이 부른 선수와 앞에있는 선수 위치 변경 */
        tmp = answer[player_pos - 1];
        answer[player_pos - 1] = answer[player_pos];
        answer[player_pos] = tmp;
        
        /* 3.4. 해설진이 부슨 선수의 순위 감소, 순위가 떨어진 선수 순위 증가 */
        player_arr[idx].index--;
        idx = Search(answer[player_pos], players_len);
        player_arr[idx].index++;
    }

    /* Output: 경주가 끝났을 때 선수들의 순위 명단 */
    return answer;
}