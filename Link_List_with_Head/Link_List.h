//
// Created by 陈宇轩 on 2024/8/1.
//

#ifndef LINK_LIST_WITH_HEAD_LINK_LIST_H
#define LINK_LIST_WITH_HEAD_LINK_LIST_H
typedef int LElemtype;
typedef struct Lnode
{
    LElemtype data;
    struct Lnode* next;
}Lnode;

typedef struct Head
{
    Lnode *first;//指向第一个节点
    Lnode *last;//指向最后那个元素
    int len;//链表元素个数
}head;

head * Create_Head(void);
void Add_Node(head * L,LElemtype x);
void output_LINK_LIST(head * L);
void Delete_x(head * H,LElemtype x);
void Delete_All_x(head * l,LElemtype x);
void disstroy_linklist(head * );


#endif //LINK_LIST_WITH_HEAD_LINK_LIST_H
