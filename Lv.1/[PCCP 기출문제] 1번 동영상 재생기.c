#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Func: 문자열 "MM:SS"를 초(s) 단위로 계산하여 반환 */
int convert2sec(char* video_len){
    int sec = 0;
    char* token;    // 문자열을 나누기 위한 포인터
    /* 1. ":" 를 기준으로 "MM:SS"중 MM를 초(s) 단위로 변환 */
    token = strtok(video_len, ":");
    if(token != NULL)
        sec += atoi(token) * 60;
    
    /* 2. "MM:SS"중 SS를 초(s) 단위로 변환 */
    token = strtok(NULL, ":");
    if(token != NULL)
        sec += atoi(token);
    
    /* 3. MM + SS를 초(s) 단위로 반환 */
    return sec;
}

// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    /*============================*/
    /*            Input           */
    /* 동영상의 길이 video_len,    */
    /* 기능 수행 전 재생위치 pos,  */
    /* 오프닝 시작점 op_start,     */
    /* 오프닝 끝지점 op_end,       */
    /* 사용자 입력 commands[],     */
    /* 사용자 입력 수 commands_len */
    /*============================*/
    char* answer = (char*)malloc(6 * sizeof(char));
    memset(answer, '\0', 6 * sizeof(char));
    
    char tmp[5];
    int video_len_sec, pos_sec, op_start_sec, op_end_sec;
    
    /* 1. 각 Input으로 주어진 문자열 "MM:SS"를 초(s) 단위로 계산하여 반환 */
    video_len_sec = convert2sec(video_len);
    pos_sec = convert2sec(pos);
    op_start_sec = convert2sec(op_start);
    op_end_sec = convert2sec(op_end);
    
    /* 2. commands 입력에 따른 동작 */
    for(int i = 0; i < commands_len; i++){
        /* 2.1. 현재 재생 위치가 오프닝 구간에 존재할 경우 pos = op_end */
        if(op_start_sec <= pos_sec && pos_sec <= op_end_sec)
            pos_sec = op_end_sec;
        /* 2.2. prev 명령 입력 */
        if(!strcmp(commands[i], "prev")){
            if(pos_sec < 10)
                pos_sec = 0;
            else
                pos_sec -= 10;
        }
        /* 2.3. next 명령 입력 */
        else if(!strcmp(commands[i], "next")){
            if(pos_sec > (video_len_sec - 10))
                pos_sec = video_len_sec;
            else
                pos_sec += 10;
        }
        /* 2.4. 현재 재생 위치가 오프닝 구간에 존재할 경우 pos = op_end */
        if(op_start_sec <= pos_sec && pos_sec <= op_end_sec)
            pos_sec = op_end_sec;
    }
    
    /* 3. 동영상의 위치(초)를 문자열 "MM:SS"로 계산하여 반환 */
    sprintf(tmp, "%02d", pos_sec / 60);
    strcat(answer, tmp);
    strcat(answer, ":");
    sprintf(tmp, "%02d", pos_sec % 60);
    strcat(answer, tmp);

    /* Output: 명령 입력 후 동영상의 위치 */
    printf("answer: %s", answer);
    
    
    return answer;
}