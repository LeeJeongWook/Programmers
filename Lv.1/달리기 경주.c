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

/* Func: player_arr name�� ������������ ���� */
int Compare( const void* a, const void *b){
    return strcmp(((player*)a)->name, ((player*)b)->name);
}

/* Func: ȣ��� ������ �ε��� ����Ž�� */
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

// players_len�� �迭 players�� �����Դϴ�.
// callings_len�� �迭 callings�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char **solution(const char *players[], size_t players_len, const char *callings[], size_t callings_len){
    /* Input: ���� �̸� (players[], players_len), �ؼ����� �θ��� �̸� (callings[], callings_len) */

    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char **answer = (char **)malloc(players_len * sizeof(char *));
    char *tmp;

    /* 1. answer[]�� players[]���� / ����ü �迭 player_arr�� name, index�� ���� */
    for(int i = 0; i < players_len; i++){
        answer[i] = players[i];
        player_arr[i].name = players[i];
        player_arr[i].index = i;
    }

    /* 2. ����ü �迭 plater_arr�� name������ ���� */
    qsort(player_arr, players_len, sizeof(player), Compare);

    /* 3. �ؼ����� �θ��� �̸��� */
    for(int i = 0; i < callings_len; i++){
        /* 3.1. �ؼ����� �θ��� �̸��� ���� ����Ž�� */
        int idx = Search(callings[i], players_len);

        /* 3.2. �ؼ����� �θ� ������ index ���� */
        int player_pos = player_arr[idx].index;
        
        /* 3.3. �ؼ����� �θ� ������ �տ��ִ� ���� ��ġ ���� */
        tmp = answer[player_pos - 1];
        answer[player_pos - 1] = answer[player_pos];
        answer[player_pos] = tmp;
        
        /* 3.4. �ؼ����� �ν� ������ ���� ����, ������ ������ ���� ���� ���� */
        player_arr[idx].index--;
        idx = Search(answer[player_pos], players_len);
        player_arr[idx].index++;
    }

    /* Output: ���ְ� ������ �� �������� ���� ��� */
    return answer;
}