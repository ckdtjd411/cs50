/* 메모리와 OverFlow 개념 정리 

지시문
1) 수업에서 언급되었던 Heap overflow와 stack overflow에 대해서 어떤 경우에 발생이 되는지 서술해주세요.
2) Strcpy와 strncpy의 차이점을 서술해보세요. (어떤 것을 추천하는지와 그 이유에 대해서 서술해주세요.)
3) 메모리 초기화, 복사, 이동, 비교와 같은 함수가 라이브러리에 있습니다
    사용방법을 숙지하고, 간단하게 코드로 구현 후 정상적으로 동작이 되는지 확인해보세요.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stackoverflow(int a) {
    if (a < 0)
        return ;
    stackoverflow(a++);
}

void heapoverflow() {
    unsigned int addrdif;
    char* buf1 = (char*)malloc(sizeof(char) * 8);
    char* buf2 = (char*)malloc(sizeof(char) * 8);
 
    addrdif = (unsigned int)buf2 - (unsigned int)buf1;
    memset(buf2, 'A', 7);
    buf2[7] = '\0';
    printf("buf2: %s\n", buf2);
 
    memset(buf1, 'B', (unsigned int)(addrdif + 4));
    printf("buf2: %s\n", buf2);
}

int main(void) {
    int a = 1;
    //stackoverflow(a);
    //heapoverflow();
    for (int i = 0; i < 100000000; i++) {
        int *ptr = (int *)malloc(sizeof(int));
    }
}
