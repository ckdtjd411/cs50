/* 포인터를 이중으로 활용해보자

2차원 배열(5x5)을 선언한 후 포인터로 하여서 순서대로 출력하는 코드를 작성 */
#include <stdio.h>

int main(void) {
    // 2차원 배열 선언 및 초기화
    int arr[6][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15},
                       {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}};
    // 배열의 전체 크기를 배열의 자료형으로 나누면 배열의 전체 원소 개수
    int n = sizeof(arr)/sizeof(int);
    // int arr[행][열]   
    int row = sizeof(arr)/sizeof(arr[0]);   // 배열의 크기를 한 행으로 나누면 행의 개수
    int col = sizeof(arr[0])/sizeof(int);   // 한 행의 크기를 하나의 요소로 나누면 열의 개수

    // int[col]의 주소를 가리키는 포인터
    int (*p)[col] = arr;

    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", *(*(p+i)+j));
            //printf("%d\t", *(p[i]+j));
            //printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}
