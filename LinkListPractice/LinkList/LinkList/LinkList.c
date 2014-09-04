//
//  LinkList.c
//  LinkList
//
//  Created by JackLi on 14-9-2.
//  Copyright (c) 2014年 JackLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
LinkList freelist;//定长空闲链表，避免多次分配内存操作
void initNodes(int N)
{
    int i;
    freelist = malloc((N + 1) * (sizeof *freelist));
    for (i = 0; i < N+1; i++)
    {
        freelist[i].next = &freelist[i+1];
    }
    freelist[N].next = NULL;
}

LinkList newNode(int i)
{
    LinkList x = deleteNext(freelist);//从分配的链表中摘取一个节点
    x->item = i;
    x->next = x;
    return x;
}

//将不用的节点接到freelist上
void freeNode(LinkList x)
{
    insertNext(freelist, x);
}

//t接到x后面
void insertNext(LinkList x,LinkList t)
{
    t->next = x->next;
    x->next = t;
}

LinkList deleteNext(LinkList x)
{
    LinkList t = x->next;
    x->next = t->next;
    return t;
}

LinkList Next(LinkList x)
{
    return x->next;
}

int Item(LinkList x)
{
    return x->item;
}
