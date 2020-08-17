// 학점 계산 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

const int NUMBER_OF_GRADES = 9;
const int SCORES[NUMBER_OF_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const string GRADES[NUMBER_OF_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

void print_info();
string calculate_grade(int score);

int main(void)
{
    print_info();
    int score = 0;

    while(true)
    {
        //printf("성적을 입력하세요 (0 ~ 100) : ");
        score = get_int("성적을 입력하세요 (0 ~ 100) : ");
        if (score == -1)
        {
            printf("학점 프로그램을 종료합니다.\n");
            return 0;
        }
        else if (score < 0 || score > 100)  // 유효성 체크 (0 ~ 100) 사이의 입력
        {
            printf("** %d 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", score);
            continue;
        } else {
            printf("학점은 %s 입니다.\n", calculate_grade(score));
        }
    }
}

// 프로그램 정보 출력
void print_info()
{
    printf("학점 프로그램\n");
    printf("종료를 원하면 \"-1\" 를 입력\n");
    printf("[학점 테이블]\n");
    printf("점수 : ");
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        printf("%-6d", SCORES[i]);
    }
    printf("\n");
    printf("학점 : ");
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        printf("%-6s", GRADES[i]);
    }
    printf("\n");
}

// 학점 계산 함수
string calculate_grade(int score)
{
    string grade = NULL;
    
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        if (score >= SCORES[i])
        {
            grade = GRADES[i];
            break;
        }   
    }
    return grade;
}
