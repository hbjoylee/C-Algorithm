//
//  LinkList.h
//  LinkList
//
//  Created by JackLi on 14-9-2.
//  Copyright (c) 2014年 JackLi. All rights reserved.
//

#ifndef LinkList_LinkList_h
#define LinkList_LinkList_h
typedef struct node * LinkList;
struct node { int item; LinkList next;};
typedef LinkList Node;
void initNodes(int);
LinkList newNode(int);
void freeNode(LinkList);
void insertNext(LinkList,LinkList);
LinkList deleteNext(LinkList);
LinkList Next(LinkList);
int Item(LinkList);
#endif
