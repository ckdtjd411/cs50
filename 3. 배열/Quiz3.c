/*
    큐 : 먼저 들어온 데이터가 먼저 나가는 구조로
         뒤(rear)에서 새로운 데이터가 추가되고 앞(front)에서 데이터가 하나씩 삭제된다.
    front는 큐의 첫 번째 요소를 가리키고 rear는 큐의 마지막 요소를 가리킨다.
    데이터가 삽입되면 rear를 하나 증가하고 그 위치에 데이터가 저장되며
    삭제할 때는 front를 하나 증가하고 front가 가리키는 위치에 있는 데이터를 삭제한다.
    그런데, front와 rear이 계속 증가만 하기 떄문에 언젠가는 배열의 끝에 도달하여 배열의 앞부분이 비어 있더라도 사용하지 못하게 된다.
    따라서 주기적으로 모든 요소들을 왼쪽으로 이동시켜야 함! 하지만 이것은 복잡
    
    ㅁ 그래서 큐를 원형으로 생각해보자 ㅁ
    front와 rear의 값이 배열의 끝 SIZE-1에 도달하면 다음에 증가되는 값은 0이 되도록 한다.
    * 배열이 원형으로 처음과 끝이 연결되어 있는 것처럼 보이는 효과 *
    원형 큐에서는 front는 항상 첫 번째 요소의 하나 앞을, rear는 마지막 요소를 가리킨다.
    처음 front, rear는 0이고 삽입 시에는 rear가 먼저 증가되고 증가된 위치에 새로운 데이터가 삽입
    삭제 시에는 front가 먼저 증가된 다음 증가된 위치에서 데이터를 삭제

    front와 rear의 값이 같으면 원형 큐가 비어 있음을 의미
    원형 큐에서는 하나의 자리는 항상 비워두는데 포화 상태와 공백 상태를 구별하기 위해서.
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#define SIZE 10     // 큐 크기

int counter = 1;    // 대기번큐
int queue[SIZE];    // 대기열 큐
int front, rear;    // front는 삭제와 관련, rear는 삽입과 관련
 
void insert();      // 대기표 뽑기
void delete();      // 대기인원 호출
void display();     // 현재 대기열 출력
int isEmpty();      // 큐가 비었는지 확인
int isFull();       // 큐가 가득찼는지 확인

int main(void) {
    while (true){
        printf("1. 대기표 뽑기  2. 대기인원 호출   3. 대기열 확인  4. 종료\n");
        printf("1 ~ 4 중의 하나를 선택해주세요. : ");

        int select = 0;
        scanf("%d", &select);

        switch (select) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("영업 끝!\n");
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}


/* rear에는 마지막으로 저장된 데이터의 위치, front는 저장된 데이터의 바로 앞을 가리킴
   (rear + 1) % SIZE : rear이 배열크기의 SIZE-1의 위치로 오면 0을 가리키게 하기 위해서.
    EX) SIZE를 5로 정의하면 rear의 값은 0 -> 1 -> 2 -> 3-> 4 -> 0 으로 변화된다.  */
void insert() {
    // 큐가 가득 찼는지 확인
    if (isFull()) {     // ifFull 함수의 반환값이 있다면(= 0이 아니라면)
        printf("Queue가 꽉 찼습니다.\n");
        return ;
    }
    printf("대기번호 : %d\n", counter);
    // 데이터를 삽입할 위치로 이동
    rear = (rear + 1) % SIZE;
    // 데이터 저장
    queue[rear] = counter;
    // 대기번호 증가
    counter++;
}

void delete() {
    // 큐가 비었는지 확인
    if (isEmpty()) {    // isEmpty 함수의 반환값이 있다면(= 0이 아니라면)
        printf("Queue가 비었습니다.\n");
        return ;
    }
    // 데이터가 저장된 다음 위치로 이동
    front = (front + 1) % SIZE;
    printf("대기번호 %d 호출\n", queue[front]);
}

void display() {
    printf("대기열 : ");
    // front + 1 로 시작해 1씩 증가해가며 SIZE를 초과하면 0으로 변화
    // i가 rear의 다음 위치를 가리키면(가장 최근에 삽입된 데이터를 저장한 다음 위치를 가리키면) 종료
    for (int i = (front + 1) % SIZE; i != (rear + 1) % SIZE; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int isEmpty() {
    return (front == rear);     // 같으면 0이 아닌 값, 다르면 0을 반환
}

int isFull() {
    return ((rear + 1) % SIZE == front);    // 같으면 0이 아닌 값, 다르면 0을 반환
}
