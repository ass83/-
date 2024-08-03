//
// Created by 陈宇轩 on 2024/8/3.
//

#include "SeqStack.h"
#include "stdio.h"
#include "stdlib.h"

stack * InitStack(void){
    stack *s= calloc(1,sizeof(*s));
    s->data= calloc(max_size,sizeof(*s->data));
    return s;
}

int StackIsEmpty(stack *s){
    if(!s||!s->data||s->top==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackLength(stack *s){
    return s->num;
}
int  Get_top(stack *s,SElemtype *x){
/*
* 返回-1-------获取失败
*     1-------获取成功
*/
    if(StackIsEmpty(s))
    {
        return -1;
    }
    else
    {   int index=s->top-1;
        *x=s->data[index];
        return 1;
    }
}
int pop(stack *s,SElemtype *x){
    if(StackIsEmpty(s)){
        return -1;//出栈失败
    }
    else{
        *x=s->data[--s->top];
        s->num--;
        return 1;//出栈成功
    }
}
int push(stack *s,SElemtype x ){
    if(!s||!s->data||s->num== max_size)
    {
        return -1;
    }
    else
    {
        s->data[s->top++]=x;
        s->num++;
        return 1;
    }
}
void distroy_Stack(stack *s){
    if(!s)
    {
        return;
    }
    free(s->data);
    free(s);
}
void clearStack(stack *s){
    if(!s||!s->data)
    {
        return;
    }
    free(s->data);
}