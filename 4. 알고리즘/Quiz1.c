/* 숫자 애너그램 찾기

ㅁ 지시문
    '애너그램'이란 문자를 재배열하여 다른 뜻을 가진 단어로 바꾸는 것
    예를 들면 영어의 'tea와 'eat'과 같이, 각 단어를 구성하는 알파벳의 구성은 같지만 뜻은 다른 두 단어를 말한다.
    문자 대신 숫자를 이용해서 애너그램을 찾는 프로그램을 만드는 것이 목표!
    
    입력 : 5자리의 숫자 1쌍
    출력 : 애너그램일 경우 "True", 아닐 경우 "False"
    
    입력받는 부분은 따로 구현하지 않고 프로그램 내부에 배열로 선언하는 것으로 가정, 숫자는 중복가능 */

#include <stdio.h>
#include <cs50.h>
#define SIZE 5

string is_anagram(int arr1[], int arr2[]);
void bubblesort(int arr[]);

int main(void) {
    int user_input1[SIZE] = {1,2,3,4,5};
    int user_input2[SIZE] = {5,2,3,2,1};
    
    printf("입력값: 12345, 52321\n");
    printf("출력값: %s\n", is_anagram(user_input1, user_input2));
}

string is_anagram(int arr1[], int arr2[]){
    bubblesort(arr1); 
    bubblesort(arr2);

    for (int i = 0; i < SIZE; i++){
        if (arr1[i] != arr2[i])
            return "False";
    }

    return "True";
}

void bubblesort(int arr[]) {
    int temp = 0; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
