//
// Created by 陈宇轩 on 2024/8/3.
//

#ifndef CIRCULAR_LINKED_IST_CIRCULAR_LINK_LIST_H
#define CIRCULAR_LINKED_IST_CIRCULAR_LINK_LIST_H

typedef  int LElemtype;

typedef struct DOUBLE_NODE//节点类型
{
    LElemtype data;
    struct DOUBLE_NODE *next;
    struct DOUBLE_NODE *pre;
}node;

typedef struct head_node
{
    int len;
    node * front;
    node *rear;
}head;

head *Create_list(void);
void Add_Node(head* ,LElemtype );
void delete_x(head*,LElemtype );
void delete_All_x(head*,LElemtype);
void output(head* L);
void distroy_list(head* L);


#endif //CIRCULAR_LINKED_IST_CIRCULAR_LINK_LIST_H
