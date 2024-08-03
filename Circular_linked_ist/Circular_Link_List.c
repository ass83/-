//
// Created by 陈宇轩 on 2024/8/3.
//

#include "Circular_Link_List.h"
#include"stdlib.h"
#include<stdio.h>



head *Create_list(void){
    head *h= calloc(1,sizeof(*h));
    return h;
}
void Add_Node(head* h,LElemtype x){
    if(!h){
        return;
    }
    node*t= calloc(1,sizeof(*t));
    t->data=x;
    if(h->len==0){
        //拆入第一个元素
        h->rear=h->front=t;
        h->front->pre=t;
        h->rear->next=t;
        h->len++;
        return;
    }
    node *p=h->front;
    do{
        if(p->data>t->data)//找到了插入位置
        {
            if(p==h->front)//第一个位置
            {
                t->next=p;
                p->pre=t;
                t->pre=h->rear;
                h->rear->next=t;
                h->len++;
                h->front=t;
                return;
            }
            else//中间位置
            {
                t->next=p;
                t->pre=p->pre;
                p->pre->next=t;
                p->pre=t;
                h->len++;
                return;
            }
        }
        p=p->next;
    }while(p!=h->front);
//    循环结束没有找到插入位置就是插入在尾端
    t->pre=h->rear;
    t->next=h->front;
    h->rear->next=t;
    h->front->pre=t;
    h->rear=t;
    h->len++;
}
void output(head* h){
    if(!h||h->len==0)
    {
        return;
    }
    node *p=h->front;
    printf("正序输出：");
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=h->front);
    printf("\n");
    p=h->rear;
    printf("逆序输出：");
    do{
        printf("%d ",p->data);
        p=p->pre;
    }while(p!=h->rear);
    printf("\n");
}
void delete_x(head*h,LElemtype x){
    if(!h||h->len==0)
    {
        return;
    }
    node *p=h->front;
    do{
        if(p->data==x)//找打要删除的元素啦
        {
            if(h->len==1)//删除该元素是链表中最后一个元素
            {
                h->front=h->rear=NULL;
                free(p);
                h->len--;
                return;
            }
            if(p==h->front)//删除第一个位置
            {
                h->front=p->next;
                h->front->pre=h->rear;
                h->rear->pre=h->front;
                h->len--;
                free(p);
                return;
            }
            else if(p==h->rear)//删除在最后一个位置
            {
                h->rear=h->rear->pre;
                h->rear->next=h->front;
                h->front->pre=h->rear;
                h->len--;
                free(p);
                return;
            }
            else//删除的是中间位置元素
            {
                p->pre->next=p->next;
                p->next->pre=p->pre;
                h->len--;
                free(p);
                return;
            }
        }
        else//还没找到就需要往后移动p
        {
            p=p->next;
        }
    }while(p!=h->front);
}
void delete_All_x(head*h,LElemtype x){
    if(!h||h->len==0)
    {
        return;
    }
    node *p=h->front,*q;
    int flag;
    do{
        if(p->data==x)//找到要删除的元素啦
        {
            if(h->len==1)//删除该元素是链表中最后一个元素
            {
                h->front=h->rear=NULL;
                free(p);
                h->len--;
                return;
            }
            if(p==h->front)//删除第一个位置
            {
                h->front=h->front->next;
                h->front->pre=h->rear;
                h->rear->next=h->front;
                h->len--;
                free(p);
                p=h->front;
                flag=1;
                continue;
            }
            else if(p==h->rear)//删除在最后一个位置
            {
                h->rear=h->rear->pre;
                h->rear->next=h->front;
                h->front->pre=h->rear;
                h->len--;
                free(p);
                return;
            }
            else//删除的是中间位置元素
            {
                q=p->next;
                p->pre->next=p->next;
                p->next->pre=p->pre;
                h->len--;
                free(p);
                p=q;
                continue;
            }
        }
        else//还没找到就需要往后移动p
        {
            p=p->next;
        }
        flag=0;
    }while(p!=h->front||flag==1);
}
void distroy_list(head* h){
    if(!h)
    {
        return;
    }
    node *p=h->front;
    node * fre;
    do {
        fre=p;
        p=p->next;
        free(fre);
    }while(p!=h->front);
    free(h);
}