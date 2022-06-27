#pragma once

#include <iostream>
#include "../common.h"

typedef struct LNode{
	ElemType data;
	struct LNode* next;
} LNode, *LinkList;

Status InitList_L(LinkList& L);
Status ListEmpty(LinkList L);
Status DestroyList_L(LinkList& L);
Status ClearList(LinkList& L);
int ListLength_L(LinkList L);
Status GetElem_L(LinkList L, int i, ElemType& e);
LNode* LocateElem_L(LinkList L, ElemType e);
Status ListInsert_L(LinkList& L, int i, ElemType e);
Status ListDelete_L(LinkList& L, int i, ElemType& e);


