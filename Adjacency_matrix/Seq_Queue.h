//
// Created by 陈宇轩 on 2024/8/1.
//

#ifndef SEQ_STACK_SEQ_QUEUE_H
#define SEQ_STACK_SEQ_QUEUE_H
//队中元素的类型
typedef int QElemType;

#define MAX_SqQueue_NUM 100
#include "stdbool.h"
//顺序队列类型
typedef struct SqQueue
{
    //QElemType elem[100];
    QElemType * elem; //指向连续的存储空间，用来存储队中元素
    int rear; //记录队尾下标
    int front; //记录队头下标

    int num; //保存队中元素个数
    //......
}SqQueue;

SqQueue * InitQueue(void);
void DestroyQueue(SqQueue * q);
void ClearQueue(SqQueue * q);
bool QueueIsEmpty(SqQueue * q);
int QueueLength(SqQueue * q);
int GetHead(SqQueue * q, QElemType * d);
int DeQueue(SqQueue * q, QElemType * d);
int EeQueue(SqQueue * q, QElemType d);



#endif //SEQ_STACK_SEQ_QUEUE_H
