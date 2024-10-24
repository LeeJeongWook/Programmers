#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/* Func: level�� �ҿ�ð� Ȯ�� */
bool Time(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit, int level) {
    long long time = 0;
    long long prev_time = 0;    // diffs[0]�� prev_time�� 0
    /* 1. ���� �ذ� �ҿ�ð� ��� */
    for(int i = 0; i < diffs_len; i++){
        if(diffs[i] <= level)
            time += times[i];
        else
            time += ((times[i] + prev_time) * (diffs[i] - level)) + times[i];
        
        prev_time = times[i];
        /* 1.1. time <= limit�� ��� false */
        if(time > limit) return false;
    }
    /* 1.2. time > limit�� ��� true */
    return true;
}

int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    int answer = INT_MAX;
    long long low = 1;
    long long high = 1e15;
    /* Input: ���� ���̵� diffs[], diffs_len, ���� �ҿ�ð� times[], times_len, ���ѽð� limit */

    /* 1. 2�� Ž���� �̿��� level�� �ҿ� �ð� Ȯ�� */
    while(low <= high){
        /* 1.1. �߰��� mid ��� */
        int mid = (low + high) / 2;

        /* 1.2. level�� �ҿ�ð� Ȯ�� */
        if(Time(diffs, diffs_len, times, times_len, limit, mid)){
            /* 1.2.1. time <= limit�� ��� �ִ밪 = mid - 1 */
            high = mid - 1;
            if(mid < answer)
            answer = mid;
        }
        else /* 1.2.2. time > limit�� ��� �ּҰ� = mid + 1 */
            low = mid + 1;
    }

    /* Output: ������ ��� �ذ��ϱ� ���� level�� �ּҰ� */
    return answer;
}