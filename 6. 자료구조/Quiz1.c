/* 배열로 Stack 만들기

[지시문]
Stack을 배열을 이용해서 구현 */

#include <stdio.h>
#include <stdlib.h>

// 사용자 정의 구조체 Stack
typedef struct stack 
{
    int top;        // 현재 stack의 array 배열의 마지막 인덱스를 가리키는 변수
    int capacity;   // 배열의 크기
    int *array;     // 배열의 주소를 가리킬 int 타입 포인터
} Stack;

Stack* createStack(int capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    // main함수에서 전달한 capacity를 저장 (= 배열의 크기)
    stack->capacity = capacity;
    // top은 배열을 가리키는 인덱스, 배열의 인덱스는 0부터 시작하므로 -1로 초기화한다. (아무것도 없는 상태)
    stack->top = -1;
    // capacity * sizeof(int) 크기의 공간을 할당 (= 배열 생성)
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

// 배열이 가득찼는지 확인하는 함수
int isFull(Stack* stack)
{
    /* 배열의 가장 최근에 저장된 배열의 위치(top)가 배열의 크기와 같다면 배열이 가득찬 것.
    배열의 인덱스는 0부터 99 이므로 capacity(100)에서 -1 해준다.
    연산값을 반환해준다 (참이면 1, 거짓이면 0 반환) */
    return stack->top == stack->capacity-1;
}

// 배열이 비었는지 확인하는 함수
int isEmpty(Stack* stack)
{
    // 배열의 인덱스를 가리키는 top이 -1이면 저장된 데이터가 없다는 뜻
    // 연산값을 반환해준다 (참이면 1, 거짓이면 0 반환)
    return stack->top == -1;
}

// 배열에 요소를 추가하는 함수
void push(Stack* stack, int item)
{
    // 배열이 가득 차있으면 추가할 수 없으므로 확인
    if (isFull(stack))
        return;
    // ++(stack->top), 현재 top이 가리키고 있는 배열의 인덱스에 1을 더한 위치에 item을 저장
    // 현재 stack->top의 위치에는 값이 저장되어 있으므로 다음 인덱스의 위치에 값을 저장해야 한다.
    stack->array[++(stack->top)] = item;
    printf("%d pushed to stack\n", item);
}

// 배열의 가장 위에 있는 요소를 삭제하는 함수
int pop(Stack* stack)
{
    // 데이터를 삭제하기 전 비어있는지 확인
    if (isEmpty(stack))
        return -9999;
    
    // 현재 top이 가리키고 있는 배열의 값을 반환해주고 top을 1감소시킨다.
    return stack->array[(stack->top--)];
}

// 가장 위에 있는 항목을 반환하는 함수
int peek(Stack* stack)
{
    return stack->array[stack->top];
}

int main(void)
{
    Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    
    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
}
