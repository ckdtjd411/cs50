/* 뒤에서 k번째 노드는 무엇일까요?

[지시문]
연결리스트의 응용 문제
연결리스트가 하나 주어졋을 때 해당 연결 리스트의 뒤에서 k번째 노드의 값을 출력
연결리스트는 이미 만들어져 있다고 가정 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data)
{
    Node* node = (Node*)malloc(sizeof(node));
    node->data = data;
    node->next = NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = node;
}

int getLastNode(Node* head, int k)
{
    int size = 0;
    int result = 0;
    Node* pt = head;
    while (pt->next != NULL)
    {
        size += sizeof(head);
        pt = pt->next;
    }

    int count = size/sizeof(head);

    while (head->next != NULL)
    {
        head = head->next;
        if (k == count)
        {
            result = head->data;
            break;
        }
        count--;
    }
    return result;
}

void printList(Node* head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}

int main(void)
{
    Node* head = (Node*)malloc(sizeof(Node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    printf("%dth last node is %d\n", 2, getLastNode(head, 2));
}
