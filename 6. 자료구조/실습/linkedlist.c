#include <stdio.h>
#include <stdlib.h>

//연결 리스트의 기본 단위가 되는 node 구조체를 정의
typedef struct node
{
    //node 안에서 정수형 값이 저장되는 변수를 number로 지정
    int number; 

    //다음 node의 주소를 가리키는 포인터를  *next로 지정
    struct node *next;
}
node;

turn 1;
    }

    // n의 number와 next의 값을 각각 저장
    n->number = 2;
    n->next = NULL;

    // list가 가리키는 것은 첫 번째 node 
    //이 node의 다음 node를 n 포인터로 지정
    list->next = n;

    // 다시 한 번 n 포인터에 새로운 메모리를 할당하고 number과 next의 값을 저장
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    // 현재 list는 첫번째 node를 가리키고, 이는 두번째 node와 연결되어 있다. 
    // 따라서 세 번째 node를 더 연결하기 위해 첫 번째 node (list)의 
    // 다음 node(list->next)의 다음 node(list->next->next)를 n 포인터로 지정
    list->next->next = n;

    // list에 연결된 node를 처음부터 방문하면서 각 number 값을 출력
    // 마지막 node의 next에는 NULL이 저장되어 있을 것이기 때문에 이것이 for 루프의 종료 조건
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // 메모리를 해제해주기 위해 list에 연결된 node들을 처음부터 방문하면서 free
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
