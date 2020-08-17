/* 연결리스트로 Stack 만들기

[지시문]
연결리스트를 이용해서 Stack을 구현 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, int data)
{
    StackNode *new = createStackNode(data);
    
    // root가 가리키는 주소가 없다면 (= 연결된 노드가 없다면)
    if (*root == NULL)
    {
        // 생성한 노드를 가리킨다. main함수에서 root의 주소를 전달받았기 때문에 그 주소로 가서(*root) new 주소를 저장한다.
        *root = new;
        printf("%d pushed to stack\n", data);
        return;
    }

    // 생성된 노드의 next는 root가 현재 가리키고 있는 노드의 주소를 가진다.
    // (= 생성된 노드는 가장 최근에 생성된 노드를 가리킨다)
    new->next = *root;
    // 기존의 root가 가리키고 있던 노드 대신 새로 생성한 노드의 주소를 가리킨다.
    *root = new;
    
    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root)
{
    if (isEmpty(*root))
        return -9999;
    int popped = 0;

    // root가 가리키는 주소를 저장한 포인터 변수 target 생성
    StackNode* target = *root;
    // target이 가리키는 data 저장
    popped = target->data;
    // 다음 노드의 주소를 root가 가리킴
    *root = target->next;
    // 노드 메모리 할당 해제
    free(target);

    return popped;
}

int peek(StackNode** root)
{
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main(void) 
{
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);
    
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}
