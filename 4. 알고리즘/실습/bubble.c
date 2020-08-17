#include <stdio.h>
#define SIZE 15

int main(void) {
    int arr[SIZE] = {9, 11, 4, 14, 1, 8, 10, 5, 0, 12, 6, 13, 3, 2, 7};
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
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
