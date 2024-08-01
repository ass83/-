//
// Created by 陈宇轩 on 2024/8/1.
//

#include "Link_List.h"
#include<stdio.h>
#include "stdlib.h"
head * Create_Head(void)
{
    head *h= calloc(1,sizeof (*h));
    h->last=h->first=NULL;
    h->len=0;
    return h;
}

void Add_Node(head * h,LElemtype x)
{
    if(!h)//head is NULL
    {
        return;
    }
    Lnode *p= calloc(1,sizeof(*p));
    p->next=NULL;
    p->data=x;
    if(h->len==0)//add is the first one
    {
        h->first=h->last=p;
        h->len++;
        return;
    }
    Lnode* t=h->first,*pr=h->first;
    while(t)//find insert seat
    {
        if(t->data>p->data)//find that seat
        {
            if(t==h->first)//insert in the head
            {
                p->next=t;
                h->first=p;
                h->len++;
                return;
            }
            else//insert in the middle
            {
                pr->next=p;
                p->next=t;
                h->len++;
                return;
            }
        }
        else// move t
        {
            pr=t;
            t=t->next;
        }
    }
    //没找到插入位置插入在最尾端
    pr->next=p;
    h->last=p;
    h->len++;
    return;
}
void output_LINK_LIST(head * L)
{
    if(!L||!L->first)
    {
        printf("链表不存在或链表为空\n");
        return;
    }
    Lnode *p=L->first;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void Delete_x(head * H,LElemtype x)//删除链表中元素为x的节点
{
    if(!H||!H->first)//链表为空或者链表不存在
    {
        return;
    }

//    找到第一个要删除的位置并且删除节点
Lnode *p=H->first,*pr=H->first;
    while(p)
    {
        if(p->data==x)// find that elem
        {
            if(H->len==1)// only one elem in the list
            {
                H->first=H->last=NULL;
                H->len--;
                free(p);
                return ;
            }
            else//H->len>=1
            {
                if(p==H->first)//删除第一个位置
                {
                    H->first=p->next;
                    H->len--;
                    p->next=NULL;
                    free(p);
                    return;
                }
                else if(p==H->last)//删除在最末尾
                {
                    pr->next=NULL;
                    H->last=pr;
                    free(p);
                    H->len--;
                    return;
                }
                else//删除在中间位置
                {
                    pr->next=p->next;
                    H->len--;
                    free(p);
                    return;
                }
            }
        }
        else//move forward
        {
            pr=p;
            p=p->next;
        }
    }
}
void Delete_All_x(head * l,LElemtype x)//delete all x elem in that list
{
    if(!l||!l->first)//链表为空或者链表不存在
    {
        return;
    }

//    找到第一个要删除的位置并且删除节点
    Lnode *p=l->first,*pr=l->first;
    while(p)
    {
        if(p->data==x)// find that elem
        {
            if(l->len==1)// only one elem in the list
            {
                l->first=l->last=NULL;
                l->len--;
                free(p);
                return ;
            }
            else//l->len>=1
            {
                if(p==l->first)//删除第一个位置
                {
                    l->first=p->next;
                    l->len--;
                    p->next=NULL;
                    free(p);
                    p=l->first;
                    continue;
                }
                else if(p==l->last)//删除在最末尾
                {
                    pr->next=NULL;
                    l->last=pr;
                    free(p);
                    l->len--;
                    return;
                }
                else//删除在中间位置
                {
                    pr->next=p->next;
                    l->len--;
                    free(p);
                    p=pr->next;
                    continue;
                }
            }
        }
        else//move forward
        {
            pr=p;
            p=p->next;
        }
    }
}
void disstroy_linklist(head * h)
{
    while(!h)//链表不存在
    {
        return;
    }
    Lnode *p=h->first,*pr=h->first;
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
    h->first=h->last=NULL;
    free(h);
}