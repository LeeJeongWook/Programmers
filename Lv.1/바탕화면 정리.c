#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// wallpaper_len�� �迭 wallpaper�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    /* Input: ����ȭ���� ����(wallpaper[], wallpaper_len) */
    
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(4 * sizeof(int));
    
    int min_i = 50, min_j = 50, max_i = 0, max_j = 0;

    /* 1. wallpaper�� ���� ���� ���ϱ� */
    int wallpaper_len_2 = strlen(wallpaper[0]);

    /* 2. wallpaper���� '#'�� ��ġ Ž�� */
    /* 2.1. �ִ�/�ּ� ����, �ִ�/�ּ� ���� ��ǥ ���� */
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
    
    /* 2.2. �巡�� ������(�ּ� ������ǥ, �ּ� ������ǥ), �巡�� ����(�ִ� ������ǥ, �ִ� ������ǥ) */
    answer[0] = min_i;
    answer[1] = min_j;
    answer[2] = ++max_i;
    answer[3] = ++max_j;

    /* Output: [�ּ� ������ǥ, �ּ� ������ǥ, �ִ� ������ǥ, �ִ� ������ǥ] */
    return answer;
}