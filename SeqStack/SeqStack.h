//
// Created by 陈宇轩 on 2024/8/3.
//

#ifndef SEQSTACK_SEQSTACK_H
#define SEQSTACK_SEQSTACK_H
#define  max_size 100
typedef int SElemtype;

typedef struct SeqStack
{
  int top;
  int bottom;
  SElemtype *data;
  int num;
}stack;

stack * InitStack(void);
void clearStack(stack *);
int StackIsEmpty(stack *);
int StackLength(stack *);
int  Get_top(stack *,SElemtype *x);
int pop(stack *s,SElemtype *x);
int push(stack *,SElemtype x );
void distroy_Stack(stack *s);
#endif //SEQSTACK_SEQSTACK_H
