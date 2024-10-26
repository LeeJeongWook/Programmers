#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// #define DBG

struct t_players
{
    char *name;
    size_t index;
};
struct t_players p1[50001]; // 이름순 정렬
struct t_players pt;        // temp

size_t g_players_len;

int qsort_compare( const void* a, const void *b) {
    return strcmp( ((struct t_players*)a)->name, ((struct t_players*)b)->name );
}

int where_name(char *fname)
{
    int left = 0;
    int right = g_players_len;
    int pos;
    int cmp;

    pos = (left + right) / 2;
    while ((cmp = strcmp(p1[pos].name, fname)) != 0)
    {
        if (cmp < 0)
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
char **solution(const char *players[], size_t players_len, const char *callings[], size_t callings_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char **answer = (char **)malloc(players_len * sizeof(char *));
    char *back;
    size_t i;
    size_t cnt;

    g_players_len = players_len;

    for (i = 0; i < players_len; i++)
    {
        answer[i] = players[i];

        p1[i].name = players[i];
        p1[i].index = i;
    }

    qsort( p1, players_len, sizeof(struct t_players), qsort_compare);



    for (cnt = 0; cnt < callings_len; cnt++)
    {
        int where = where_name(callings[cnt]);


        int ans_pos = p1[where].index; // 실제 배열 위치를 찾아서,
        // 배열와 앞의 값과 뒤의 값을 교체
        back = answer[ans_pos - 1];
        answer[ans_pos - 1] = answer[ans_pos];
        answer[ans_pos] = back;
        // p1의 필요한 값에 업데이트
        p1[where].index--;
        where = where_name(answer[ans_pos]);
        p1[where].index++;
    }


    return answer;
}