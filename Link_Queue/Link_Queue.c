//
// Created by 陈宇轩 on 2024/8/4.
//

#include "Link_Queue.h"
#include<stdlib.h>
#include<stdio.h>

SqQueue * InitQueue(void)
{
    SqQueue *q= calloc(1,sizeof(*q));
    return q;
}

int QueueIsEmpty(SqQueue * q){
    if(!q||!q->front||q->num==0)
    {
        return True;
    }
    else
        return False;
}

int GetHead(SqQueue * q, QElemType * d){
    if(QueueIsEmpty(q))//队列为空取队头元素失败
    {
        return -1;
    }
    *d=q->front->data;
    return 1;
}

int DeQueue(SqQueue * q, QElemType * d){
    if(QueueIsEmpty(q))
    {
        return -1;//出队失败
    }
    if(q->num==1)
    {
        *d=q->front->data;
        free(q->front);
        q->front=q->rear=NULL;
        return 1;
    }
    *d=q->front->data;
    node *f=q->front;
    q->front=q->front->next;
    free(f);
    q->num--;
    return 1;
}

int EeQueue(SqQueue * q, QElemType d){
    if(!q)
        return -1;
    node *t= calloc(1,sizeof(*t));
    t->data=d;
    if(q->num==0)
    {
        q->front=q->rear=t;
//        q->rear=t;
        q->num++;
    }
    else//尾插法
    {
        q->rear->next=t;
        q->rear=t;
        q->num++;
    }
    return 1;
}

int QueueLength(SqQueue * q){
    if(QueueIsEmpty(q))
        return 0;
    else
        return q->num;
}

void ClearQueue(SqQueue * q){
    if(!q||!q->front)
        return;
    node *p=q->front,*f;
    while(p)
    {
        f=p;
        p=p->next;
        free(f);
    }
    q->front=q->rear=NULL;
}

void DestroyQueue(SqQueue * q){
    if(!q||!q->front)
        return;
    node *p=q->front,*f;
    while(p)
    {
        f=p;
        p=p->next;
        free(f);
    }
    q->front=q->rear=NULL;
    free(q);
}