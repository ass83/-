//
// Created by 陈宇轩 on 2024/8/1.
//

#ifndef LINK_LIST_LINK_LIST_H
#define LINK_LIST_LINK_LIST_H
typedef int LElemtype;

typedef struct Node
{
    LElemtype val;
    struct Node *next;
}Lnode;
typedef Lnode * Linklist;
Linklist insert_link_list(Linklist F,Linklist N);
Linklist Creat_Linklist(void);

void visit_linklist(Linklist H);
Linklist delete_repeat_x(Linklist L,LElemtype x);
Linklist find_last(Linklist L);
int count_node(Linklist L);
Linklist inverted_linklist(Linklist L);
Linklist inverted_linklist_recursive(Linklist L);
Linklist meger_linklist(Linklist des,Linklist sor);

#endif //LINK_LIST_LINK_LIST_H
