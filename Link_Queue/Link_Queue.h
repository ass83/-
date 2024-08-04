//
// Created by 陈宇轩 on 2024/8/4.
//

#ifndef LINK_QUEUE_LINK_QUEUE_H
#define LINK_QUEUE_LINK_QUEUE_H


typedef int QElemType;

#define True 1
#define False 0
//顺序队列类型
typedef struct node
{
    QElemType data;
    struct node* next;
}node;


typedef struct Queue
{

    node * rear; //记录队尾指针
    node * front; //记录队头指针
    int num; //保存队中元素个数
}SqQueue;

SqQueue * InitQueue(void);

void DestroyQueue(SqQueue * q);

void ClearQueue(SqQueue * q);

int QueueIsEmpty(SqQueue * q);

int QueueLength(SqQueue * q);

int GetHead(SqQueue * q, QElemType * d);

int DeQueue(SqQueue * q, QElemType * d);

int EeQueue(SqQueue * q, QElemType d);

#endif //LINK_QUEUE_LINK_QUEUE_H
