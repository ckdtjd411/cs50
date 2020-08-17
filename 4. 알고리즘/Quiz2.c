/* 친구들과 최단거리에 있는 집 구하기

ㅁ 지시문
    친구들의 집에서 거리가 가장 가까운 집을 구해서 이사를 가고자 한다.
    모두 같은 거리에 살고 있으므로 친구들의 집 위치를 수직선 상에 표현할 수 있고, 그 때 집은 항상 정수점 위에만 있다고 가정
    이 떄, 어느 위치에 있는 집으로 이사를 가야 모든 친구들의 집까지의 거리의 합이 최소가 될 수 있는지를 출력하는 프로그램 작성
    시간복잡도(Big O)가 얼마나 되는지, 어떻게 하면 시간복잡도를 최소화할 수 있을지
    집이 있을 수 있는 위치는 한자리 정수로만 구성

    입력값 : 한 개 이상의 정수
    출력값 : 거리의 합이 최소인 위치의 값

    입력받는 부분은 따로 구현하지 않고 프로그램 내부에 배열로 선언하는 것으로 가정하고, 숫자에는 중복 허용 */

#include <stdio.h>
#include <stdlib.h> // abs 함수 사용, 절대값
#include <math.h>   // round 함수 사용, 반올림
#define SIZE 7      // 배열 크기

int calc_mean(int arr[]);           // 평균값으로 계산
int calc_median(int arr[]);         // 중앙값으로 계산
void bubblesort(int arr[]);         // 정렬

int main(void) {
    int location[SIZE] = {9, 6, 2, 1, 2, 3, 6};
    int mean = calc_mean(location);
    int median = calc_median(location);

    int mean_sum = 0;
    int median_sum = 0;
    
    for (int i = 0; i < SIZE; i++) {
        mean_sum += abs(location[i] - mean);
        median_sum += abs(location[i] - median);
    }
    printf("평균값(%d)일 때 거리의 합 : %d\n중앙값(%d)일 때 거리의 합 : %d\n", mean, mean_sum, median, median_sum);

    if (mean_sum > median_sum) 
        printf("위치 : %d\n", median);
    else
        printf("위치 : %d\n", mean);

}

int calc_mean(int arr[]) {
    int result = 0;
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    result = round(sum / SIZE);
    return result;
}

int calc_median(int arr[]) {
    int result = 0;
    bubblesort(arr);
    if (SIZE % 2 == 0) {
        result = round((arr[SIZE/2 - 1] + arr[SIZE/2]) / 2);
    }
    else
        result = arr[SIZE/2];
    return result;
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
