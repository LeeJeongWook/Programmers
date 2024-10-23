#include <stdio.h>
#include <string.h>

#define LEN_INPUT 10

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    for(int i = 0; i < strlen(s1); i++){
        if(64 < s1[i] && s1[i] < 91)
            s1[i] += 32;
        else
            s1[i] -= 32;
    }
    printf("%s", s1);
    return 0;
}