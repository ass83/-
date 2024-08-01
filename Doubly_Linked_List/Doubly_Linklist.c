//
// Created by 陈宇轩 on 2024/8/1.
//

#include "Doubly_Linklist.h"
#include<stdio.h>
#include "stdlib.h"


head *Create_list(void)
{
    head *h= calloc(1,sizeof(*h));
    h->front=h->rear=NULL;
    h->len=0;
    LElemtype x;
    scanf("%d",&x);
    while(x!=0)
    {
        Add_Node(h,x);
        scanf("%d",&x);
    }
    return h;
}
void Add_Node(head*h,LElemtype t)
{
    if(!h)
    {
        return;
    }
    node * x= calloc(1,sizeof(*x));
    x->data=t;x->next=x->pre=NULL;
    if(h->len==0)//链表中还没有其他元素
    {
        h->rear=h->front=x;
        h->len++;
        return;
    }
    node *p=h->front;
    while(p)//找位置
    {
        if(x->data<p->data)//找到插入位置了
        {
            if(p==h->front)//插入的位置是最前面
            {
                x->next=p;
                p->pre=x;
                h->front=x;
                h->len++;
                return;
            }
            else//中间位置
            {
                x->next=p;
                x->pre=p->pre;
                p->pre->next=x;
                p->pre=x;
                h->len++;
                return;
            }
        }
        else
        {
            p=p->next;
        }
    }
//    循环结束没找位置就要插入尾端
    x->pre=h->rear;
    h->rear->next=x;
    h->rear=x;
    h->len++;
    return;
}
void delete_x(head*h,LElemtype t)
{
    if(!h||!h->front)//链表为空或者链表不存在
    {
        return;
    }

//    找到第一个要删除的位置并且删除节点
    node *p=h->front;
    while(p)
    {
        if(p->data==t)
        {
            if(h->len==1)
            {
                h->front=h->rear=NULL;
                free(p);
                return;
            }
            if(p==h->front)
            {
                h->front=p->next;
                h->front->pre=NULL;
                free(p);
                h->len--;
                return;
            }
            else if(p==h->rear)
            {
                h->rear=p->pre;
                h->rear->next=NULL;
                h->len--;
                free(p);
                return;
            }
            else
            {
                p->pre->next=p->next;
                p->next->pre=p->pre;
                h->len--;
                free(p);
                return;
            }
        }
        else
        {
            p=p->next;
        }
    }
}
void delete_All_x(head*h,LElemtype t)
{
    if(!h||!h->front)//链表为空或者链表不存在
    {
        return;
    }

//    找到第一个要删除的位置并且删除节点
    node *p=h->front;
    while(p)
    {
        if(p->data==t)
        {
            if(h->len==1)
            {
                h->front=h->rear=NULL;
                free(p);
                return;
            }
            if(p==h->front)
            {
                h->front=p->next;
                h->front->pre=NULL;
                free(p);
                h->len--;
                p=h->front->next;
                continue;
            }
            else if(p==h->rear)
            {
                h->rear=p->pre;
                h->rear->next=NULL;
                h->len--;
                free(p);
                return;
            }
            else
            {
                node *pr=p->pre;
                p->pre->next=p->next;
                p->next->pre=p->pre;
                h->len--;
                free(p);
                p=pr->next;
                continue;
            }
        }
        else
        {
            p=p->next;
        }
    }
}
void output(head* h)
{
    if(!h||!h->front)//链表不存在或者链表为空
    {
        return;
    }
    node *p=h->front;
    printf("正序输出：");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

    printf("逆序输出：");
    p=h->rear;
    while(p)
    {
        printf("%d",p->data);
        p=p->pre;
    }
    printf("\n");

}
void distroy_list(head* h)
{
    while(!h)//链表不存在
    {
        return;
    }
    node *p=h->front,*pr=h->front;
    while(p)
    {
        pr=p;
        p=p->next;
        pr->next=p->next;
        free(p);
        h->len--;
        p=pr->next;
    }
    free(pr);
    h->front=h->rear=NULL;
    free(h);
}