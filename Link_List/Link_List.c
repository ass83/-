//
// Created by 陈宇轩 on 2024/8/1.
//

#include "Link_List.h"
#include<stdlib.h>
#include<stdio.h>

Linklist insert_link_list(Linklist L,Linklist N)
{
    if(!L)
    {
        return NULL;
    }
    if(!N)
    {
        return L;
    }
    Linklist p=L;
    Linklist pr=p;
    while(p)//找位置
    {
        if(N->val<p->val)
        {
            if(p==L)//第一个元素插入元素前
            {
                N->next=L;
                L=N;
                return L;
            }
            else//中间元素
            {
                pr->next=N;
                N->next=p;
                return L;
            }
        }
        pr=p;
        p=p->next;
    }
//    没有找到插入位置
    pr->next=N;
    return L;
}
Linklist Creat_Linklist(void)
{


    LElemtype x;
    scanf("%d",&x);
    Linklist L=NULL;
    while(x!=0)
    {
        Linklist t= calloc(1,sizeof(*t));
        t->val=x;t->next=NULL;
        if(!L)
            L=t;
        else
            L=insert_link_list(L,t);
        scanf("%d",&x);
    }
    return L;
}
void visit_linklist(Linklist l)
{
    if(!l)
    {
        return;
    }
    Linklist p=l;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
Linklist delete_repeat_x(Linklist L,LElemtype x)
{
    if(!L)
    {
        return L;
    }
    Linklist p=L,pr=L;
    while(p)
    {
        if(p->val==x)//找到了要删除的元素
        {
            if(p==L)//delete the first one
            {
                L=L->next;
                free(p);
                p=pr=L;
                continue;
            }
            else//delete that middle
            {
                pr->next=p->next;
                free(p);
                p=pr->next;
            }
        }
        else//没找打就要移动p
        {
            pr=p;p=p->next;
        }
    }
    return L;
}
Linklist find_last(Linklist L)
{
    Linklist p=L;
    while(p->next)
    {
        p=p->next;
    }
    return p;
}
int count_node(Linklist L)
{
    int count=0;
    Linklist p=L;
    while(p)
    {
        p=p->next;
        count ++;
    }
    return count;
}
Linklist inverted_linklist_recursive(Linklist L)//递归逆置一个单链表
{
    if(!L->next)
    {
        return L;
    }
    Linklist p=inverted_linklist(L->next);
    L->next->next=L;
    L->next=NULL;
    return p;
}
Linklist inverted_linklist(Linklist L)
{
    Linklist head=L,rear,stop;
    while(head->next)
    {
        head = head->next;
    }//找到尾指针

    rear=head;//rear指向链表尾部
    head=L;//head指向链表头部

    while(head!=rear)
    {
        L=L->next;
        head->next=rear->next;
        rear->next=head;
        head=L;
    }
    return L;

}

Linklist meger_linklist(Linklist des,Linklist sor)
{
    Linklist t=sor;
    Linklist p;
    while(t)
    {
        p=t;
        t=t->next;
        p->next=NULL;
        des=insert_link_list(des,p);
    }
    return des;
}