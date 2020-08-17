#include <stdio.h>
#define SIZE 500000 // 최대 N의 크기

int main(int arge, char*argv[]) {
    // 총 개수가 몇 개인지 저장하는 변수
    int n;

    // 파일의 첫 줄을 입력으로 받아 정수형 변수 n에 저장
    scanf("%d", &n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE];
    // K를 제외한 N-1개의 수
    int lengthOfPartArr = n-1;  
    
    // partArr 배열에 파일에 저장된 숫자들을 저장
    for(int i=0; i < lengthOfPartArr; i++){
        // 파일의 둘째 줄을 입력으로 공백 기준으로 구분하여 수들을 하나씩 배열에 저장
        scanf("%d", &partArr[i]);
    }
    // TODO: n과 partArr를 이용하여, K를 구하라

    // 1부터 n까지의 합을 저장할 변수, 타입명이 long인 이유 : 큰 수를 저장하기 위해, 연산의 값이 크기 때문에 이를 저장할 수 있는 큰 자료형을 사용
    long sum_to_n = 0;
    // 숫자 K를 제외한 n까지의 합을 저장할 변수
    long sum = 0;           

    // 1부터 n까지의 합을 sum_to_n에 저장
    for(int i=1; i <= n; i++){
        sum_to_n += i;
    }

    // partArr 배열에 저장된 모든 요소의 합을 sum에 저장 (K를 제외한 모든 합)
    for(int i=0; i < lengthOfPartArr; i++){
        sum += partArr[i];
    }

    // 1부터 N까지의 합에서 K를 제외한 1부터 N까지의 합을 빼면 K를 구할 수 있다!
    printf("K = %.ld\n", sum_to_n - sum);       // %.ld는 long 자료형에 대한 형식 지정자
}
