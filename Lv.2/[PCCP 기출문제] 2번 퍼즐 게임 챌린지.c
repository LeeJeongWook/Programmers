#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/* Func: level별 소요시간 확인 */
bool Time(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit, int level) {
    long long time = 0;
    long long prev_time = 0;    // diffs[0]의 prev_time은 0
    /* 1. 퍼즐 해결 소요시간 계산 */
    for(int i = 0; i < diffs_len; i++){
        if(diffs[i] <= level)
            time += times[i];
        else
            time += ((times[i] + prev_time) * (diffs[i] - level)) + times[i];
        
        prev_time = times[i];
        /* 1.1. time <= limit일 경우 false */
        if(time > limit) return false;
    }
    /* 1.2. time > limit일 경우 true */
    return true;
}

int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = INT_MAX;
    long long low = 1;
    long long high = 1e15;
    /* Input: 퍼즐 난이도 diffs[], diffs_len, 퍼즐 소요시간 times[], times_len, 제한시간 limit */

    /* 1. 2진 탐색을 이용한 level별 소요 시간 확인 */
    while(low <= high){
        /* 1.1. 중간값 mid 계산 */
        int mid = (low + high) / 2;

        /* 1.2. level별 소요시간 확인 */
        if(Time(diffs, diffs_len, times, times_len, limit, mid)){
            /* 1.2.1. time <= limit일 경우 최대값 = mid - 1 */
            high = mid - 1;
            if(mid < answer)
            answer = mid;
        }
        else /* 1.2.2. time > limit일 경우 최소값 = mid + 1 */
            low = mid + 1;
    }

    /* Output: 퍼즐을 모두 해결하기 위한 level의 최소값 */
    return answer;
}