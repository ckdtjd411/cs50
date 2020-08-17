/* 배열로 Queue 만들어보기

[지시문]
Queue를 구현! */

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1;
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->array[(queue->size)++] = item;

    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return -9999;
    int item = 0;

    item = queue->array[(queue->front)++];
    (queue->size)--;

    return item;
}

int main(void)
{
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->size]);

    return 0;
}
