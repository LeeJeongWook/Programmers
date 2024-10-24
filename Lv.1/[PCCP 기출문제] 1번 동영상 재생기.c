#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Func: ���ڿ� "MM:SS"�� ��(s) ������ ����Ͽ� ��ȯ */
int convert2sec(char* video_len){
    int sec = 0;
    char* token;    // ���ڿ��� ������ ���� ������
    /* 1. ":" �� �������� "MM:SS"�� MM�� ��(s) ������ ��ȯ */
    token = strtok(video_len, ":");
    if(token != NULL)
        sec += atoi(token) * 60;
    
    /* 2. "MM:SS"�� SS�� ��(s) ������ ��ȯ */
    token = strtok(NULL, ":");
    if(token != NULL)
        sec += atoi(token);
    
    /* 3. MM + SS�� ��(s) ������ ��ȯ */
    return sec;
}

// commands_len�� �迭 commands�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.

    /*============================*/
    /*            Input           */
    /* �������� ���� video_len,    */
    /* ��� ���� �� �����ġ pos,  */
    /* ������ ������ op_start,     */
    /* ������ ������ op_end,       */
    /* ����� �Է� commands[],     */
    /* ����� �Է� �� commands_len */
    /*============================*/
    char* answer = (char*)malloc(6 * sizeof(char));
    memset(answer, '\0', 6 * sizeof(char));
    
    char tmp[5];
    int video_len_sec, pos_sec, op_start_sec, op_end_sec;
    
    /* 1. �� Input���� �־��� ���ڿ� "MM:SS"�� ��(s) ������ ����Ͽ� ��ȯ */
    video_len_sec = convert2sec(video_len);
    pos_sec = convert2sec(pos);
    op_start_sec = convert2sec(op_start);
    op_end_sec = convert2sec(op_end);
    
    /* 2. commands �Է¿� ���� ���� */
    for(int i = 0; i < commands_len; i++){
        /* 2.1. ���� ��� ��ġ�� ������ ������ ������ ��� pos = op_end */
        if(op_start_sec <= pos_sec && pos_sec <= op_end_sec)
            pos_sec = op_end_sec;
        /* 2.2. prev ��� �Է� */
        if(!strcmp(commands[i], "prev")){
            if(pos_sec < 10)
                pos_sec = 0;
            else
                pos_sec -= 10;
        }
        /* 2.3. next ��� �Է� */
        else if(!strcmp(commands[i], "next")){
            if(pos_sec > (video_len_sec - 10))
                pos_sec = video_len_sec;
            else
                pos_sec += 10;
        }
        /* 2.4. ���� ��� ��ġ�� ������ ������ ������ ��� pos = op_end */
        if(op_start_sec <= pos_sec && pos_sec <= op_end_sec)
            pos_sec = op_end_sec;
    }
    
    /* 3. �������� ��ġ(��)�� ���ڿ� "MM:SS"�� ����Ͽ� ��ȯ */
    sprintf(tmp, "%02d", pos_sec / 60);
    strcat(answer, tmp);
    strcat(answer, ":");
    sprintf(tmp, "%02d", pos_sec % 60);
    strcat(answer, tmp);

    /* Output: ��� �Է� �� �������� ��ġ */
    printf("answer: %s", answer);
    
    
    return answer;
}