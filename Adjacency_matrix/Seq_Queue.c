//
// Created by 陈宇轩 on 2024/8/1.
//

#include "Seq_Queue.h"
#include "stdio.h"
#include<stdlib.h>
#include<stdbool.h>
SqQueue * InitQueue(void)
{
    SqQueue *q= calloc(1,sizeof(*q));
    q->elem= calloc(MAX_SqQueue_NUM,sizeof(QElemType));
    q->num=0;
    q->front=q->rear=0;
    return q;
}
void DestroyQueue(SqQueue * q)
{
    if(!q)
        return;
    free(q->elem);
    free(q);
}
void ClearQueue(SqQueue * q)
{
    if(!q)
        return;
    free(q->elem);
}
bool QueueIsEmpty(SqQueue * q)
{
    if(!q||!q->elem||q->num==0)
        return true;
    else
        return false;
}
int QueueLength(SqQueue * q)
{
    return q->num;
}
int GetHead(SqQueue * q, QElemType * d)
{
    if(QueueIsEmpty(q))
        return 0;//表示失败
    *d=q->elem[q->front];
    return 1;
}
int DeQueue(SqQueue * q, QElemType * d)
/*返回--0--入队失败
 *   --1--入队成功
 */
{
    if(!q||!q->elem||q->num==0)//队列不存在或者队列为空
    {
        return 0;
    }
    *d=q->elem[q->front++];
    q->num--;
    if(q->front==MAX_SqQueue_NUM)
    {
        q->front=0;
    }
    return 1;
}
int EeQueue(SqQueue * q, QElemType d)
/*返回--0--入队失败
 *   --1--入队成功
 */
{
    if (!q || !q->elem || q->num == MAX_SqQueue_NUM)//队列满或队列不存在
    {
        return 0;
    }
    q->elem[q->rear++] = d;
    q->num++;
    if (q->rear == MAX_SqQueue_NUM)
    {
        q->rear = 0;
    }
    return 1;
}