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
struct t_players p1[50001]; // �̸��� ����
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

// players_len�� �迭 players�� �����Դϴ�.
// callings_len�� �迭 callings�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char **solution(const char *players[], size_t players_len, const char *callings[], size_t callings_len)
{
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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


        int ans_pos = p1[where].index; // ���� �迭 ��ġ�� ã�Ƽ�,
        // �迭�� ���� ���� ���� ���� ��ü
        back = answer[ans_pos - 1];
        answer[ans_pos - 1] = answer[ans_pos];
        answer[ans_pos] = back;
        // p1�� �ʿ��� ���� ������Ʈ
        p1[where].index--;
        where = where_name(answer[ans_pos]);
        p1[where].index++;
    }


    return answer;
}