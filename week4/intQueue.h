#include <stdio.h>
#define size 130

typedef struct
{
    int queue[size];
    int front;
    int rear;

}que;

void push(que* pq, int item)
{
    if ((pq->front == 0 && pq->rear == size - 1) || (pq->front == pq->rear + 1))
    {
        printf("queue is full");
        return;
    }

    else if (pq->rear ==  -1)
    {
        pq->rear++;
        pq->front++;
    }

    else if (pq->rear == size - 1 && pq->front > 0)
    {
        pq->rear = 0;
    }

    else
    {
        pq->rear++;
    }

    pq->queue[pq->rear] = item;
}

int isEmpty(que* pq)
{
    if (pq->front ==  -1)
        return 1;
    else
        return 0;
}

int pop(que* pq)
{
    int toReturn;
   
    if (pq->front ==  -1)
        toReturn = -1;
        // printf("Queue is empty");
    
    else if (pq->front == pq->rear)
    {
        toReturn = pq->queue[pq->front];
        // printf("\n%d deleted", pq->queue[pq->front]);
        pq->front =  -1;
        pq->rear =  -1;
    }

    else if (pq->front == size-1) 
    {
        toReturn = pq->queue[pq->front];
        // printf("\n%d deleted", pq->queue[pq->front]);
        pq->front = 0;
    }
    
    else
    {
        toReturn = pq->queue[(pq->front)++];
        // printf("\n%d deleted", pq->queue[(pq->front)++]);
    }

    return toReturn;
}

