//
// Created by 陈宇轩 on 2024/8/3.
//

#include "Link_Stack.h"
#include<stdlib.h>
stack * InitStack(void)
{
    stack * s= calloc(1,sizeof(*s));
    return s;
}
int stackIsEmpty(stack *s){
    if(!s||!s->top||s->num==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackLnegth(stack *s){
    return  s->num;
}
int GetTop(stack *s,SElemType *x)
{
    if(stackIsEmpty(s))
    {
        return -1;
    }
    *x=s->top->data;
    return 1;
}
int pop(stack *s,SElemType *x){
    if(stackIsEmpty(s))
    {
       return -1;
    }
    node *f;
    if(s->num==1)//栈中仅有一个元素
    {
        *x=s->top->data;
        free(s->top);
        s->top=s->bottom=NULL;
        s->num--;
        return 1;
    }
    //从头端出栈
    f=s->top;
    *x=s->top->data;
    s->top=s->top->next;
    free(f);
    s->num--;
    return 1;
}
int push(stack *s,SElemType x){
    if(!s)
    {
        return -1;
    }
    node *t= calloc(1,sizeof(*t));
    t->data=x;
    if(s->num==0)
    {
        s->bottom=s->top=t;
        s->num++;
        return 1;
    }
    //头插法
    t->next=s->top;
    s->top=t;
    s->num++;
    return 1;
}
void DestroyStack(stack * s)
{
    if(stackIsEmpty(s))
    {
        return;
    }
    node *p=s->top,*f;
    while(p)
    {
        f=p;
        free(f);
        p=p->next;
    }
    free(s);
}
void ClearStack(stack * s){
    if(stackIsEmpty(s))
    {
        return;
    }
    node *p=s->top,*f;
    while(p)
    {
        f=p;
        free(f);
        p=p->next;
    }
}