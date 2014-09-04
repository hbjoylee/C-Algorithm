//
//  main.c
//  LinkList
//
//  Created by JackLi on 14-9-2.
//  Copyright (c) 2014年 JackLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkList.h"

//约瑟夫环问题
void JosephusProblem_Solution() {
    int i, N = 9, M = 5;
    Node t, x;
    initNodes(N);
    for (i = 2, x = newNode(1); i <= N; i++)
    {
        t = newNode(i);
        insertNext(x, t);
        x = t;
    }
    while(x != Next(x))
    {
        for (i = 1; i < M; i++)
            x = Next(x);
        freeNode(deleteNext(x));
    }
    printf("%d\n", Item(x));
}

void printList(LinkList list)
{
    while(list)
    {
        printf("%d ", list->item);
        list = list->next;
    }
}

LinkList moveMaxToEnd(LinkList list)
{
    LinkList start = list;
    LinkList p = start;
    int max = p->item;
    LinkList maxP = p;//最大值位置
    LinkList maxPrev = p;
    LinkList end = p;
    p = p->next;
    while(p)
    {
        if(p->item > max)
        {
            max = p->item;
            maxP = p;
            maxPrev = end;
        }
        end = p;
        p = p->next;
    }
    if(maxP == start)
    {
        start = maxP->next;
        end->next = maxP;
        maxP->next = NULL;
    }
    else if(maxP == end)
    {
        //do nothing
    }
    else
    {
        maxPrev->next = maxP->next;
        end->next = maxP;
        maxP->next = NULL;
    }
    return start;
}

int main(int argc, const char * argv[])
{
    srand(time(NULL));
    int i;
    LinkList freelist = malloc((10) * (sizeof *freelist));
    int first[] = {99,1,2,4,5,6,7,0,44,23};
    int end[] = {23,1,2,4,5,6,7,0,44,99};
    int mid[] = {23,1,2,4,5,99,7,0,44,6};
    for (i = 0; i < 9; i++)
    {
        freelist[i].next = &freelist[i+1];
        freelist[i].item = mid[i];
    }
    freelist[9].next = NULL;
    freelist[9].item = mid[9];
    printList(freelist);
    printf("\n");
    printList(moveMaxToEnd(freelist));
    return 0;
}

