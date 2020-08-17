#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void) {
    string dayOfWeek = get_string("요일을 입력하세요: ");
    
    if (strcmp(dayOfWeek, "월요일") == 0)
        printf("%s: 청국장\n", dayOfWeek);
    else if (strcmp(dayOfWeek, "화요일") == 0)
        printf("%s: 비빔밥\n", dayOfWeek);
    else if (strcmp(dayOfWeek, "수요일") == 0)
        printf("%s: 된장찌개\n", dayOfWeek);
    else if (strcmp(dayOfWeek, "목요일") == 0)
        printf("%s: 칼국수\n", dayOfWeek);
    else if (strcmp(dayOfWeek, "금요일") == 0)
        printf("%s: 냉면\n", dayOfWeek);
    else if (strcmp(dayOfWeek, "토요일") == 0)
        printf("%s: 소불고기\n", dayOfWeek);
    else if (strcmp(dayOfWeek, "일요일") == 0)
        printf("%s: 오삼불고기\n", dayOfWeek);
    else 
        printf("잘못된 입력입니다.\n");
}
