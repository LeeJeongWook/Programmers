#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// park_len�� �迭 park�� �����Դϴ�.
// routes_len�� �迭 routes�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    /* Input: ���� (park[], park_len), ������ ��� (routes[], routes_len) */

    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(2 * sizeof(int));
    
    char* token;
    int park_column, idx, idx_i, idx_j;
    char direct;
    bool flag = true;
    
    /* 1. ������ ���α��� ��� */
    park_column = strlen(park[0]);
    
    /* 2. �������� �������� Ž�� */
    for(int i = 0; i < park_len; i++){
        for(int j = 0; j < park_column; j++){
            if(park[i][j] == 'S'){
                idx_i = i;
                idx_j = j;
            }
        }
    }
    
    /* 3. ��å ��� ���� */
    for(int i = 0; i < routes_len; i++){
        /* 3.1. �̵� ����, �̵� �Ÿ� Parsing */
        flag = true;
        token = strtok(routes[i]," ");
        direct = token[0];
        token = strtok(NULL," ");
        idx = atoi(token);
        
        /* 3.2. �̵� ���� ��� Ȯ�� */
        /* 3.2.1. ���� ������ ���ų� ��ֹ��� ���� ��� �̵� ���� ���� ��� ���� */
        /* 3.2.2. �̵� ���� �з� �� �̵��Ÿ���ŭ �̵� */
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
    
    /* Output: ��� ��� ���� �� [���� ��ǥ, ���� ��ǥ] */
    answer[0] = idx_i;
    answer[1] = idx_j;
    
    return answer;
}