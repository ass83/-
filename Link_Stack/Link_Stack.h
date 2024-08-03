//
// Created by 陈宇轩 on 2024/8/3.
//

#ifndef LINK_STACK_LINK_STACK_H
#define LINK_STACK_LINK_STACK_H
typedef int SElemType;
typedef struct Snode
{
    SElemType data;
    struct Snode *next;
}node;

typedef struct Stack
{
    node *top;
    node *bottom;
    int num;
}stack;

stack * InitStack(void);
int stackIsEmpty(stack *s);
int StackLnegth(stack *s);
int GetTop(stack *s,SElemType *x);
int pop(stack *s,SElemType *x);
int push(stack *s,SElemType x);
void ClearStack(stack * s);
void DestroyStack(stack * s);


#endif //LINK_STACK_LINK_STACK_H
