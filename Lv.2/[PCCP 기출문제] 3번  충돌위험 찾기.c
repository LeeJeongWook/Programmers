#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
}coordinate;

// points_rows는 2차원 배열 points의 행 길이, points_cols는 2차원 배열 points의 열 길이입니다.
// routes_rows는 2차원 배열 routes의 행 길이, routes_cols는 2차원 배열 routes의 열 길이입니다.
int solution(int** points, size_t points_rows, size_t points_cols, int** routes, size_t routes_rows, size_t routes_cols) {
    bool flag = true;
    int answer = 0;
    int idx = 0;
    int marked[100][100];
    int sx, sy, ex, ey;
    
    coordinate co_arr[10000];    // 좌표 최대값 : 100*100
        
    for(int i = 0; i < routes_rows; i++){
        for(int j = 0; j < routes_cols - 1; j++){
            // printf("%d: ", routes[i][j]);
            // printf("%d %d  ", points[routes[i][j] - 1][0], points[routes[i][j] - 1][1]);
            co_arr[j].start_x = points[routes[i][j] - 1][0];
            co_arr[j].start_y = points[routes[i][j] - 1][1];
            co_arr[j].end_x = points[routes[i][j+1] - 1][0];
            co_arr[j].end_y = points[routes[i][j+1] - 1][1];
            // printf("%d ", co_arr[j].start_x);
            // printf("%d / ", co_arr[j].start_y);
            // printf("%d ", co_arr[j].end_x);
            // printf("%d", co_arr[j].end_y);
            // printf("\n");
        }
    }
    while(flag){
        flag = false;
        memset(marked, 0, sizeof(marked));
        for(int j = 0; j < routes_cols - 1; j++){
            sx = co_arr[j].start_x;
            sy = co_arr[j].start_y;
            ex = co_arr[j].end_x;
            ey = co_arr[j].end_y;

            if(sx != ex){
                if(sx < ex)
                    sx++;
                else
                    sx--;
            }
            else if(sy != ey){
                if(sy < ey)
                    sy++;
                else
                    sy--;
            }
            marked[sx - 1][sy - 1]++;
            
            if((sx != ex) || (sy != ey))
                flag = true;
        }

        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 100; k++){
                if(marked[j][k] > 1){
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}