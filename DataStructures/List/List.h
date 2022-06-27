#pragma once

#include <iostream>

#include "../common.h"

#define LIST_INIT_SIZE 100

typedef struct {
	ElemType *elem;
	int length;
} Sqlist;

Status InitList_Sq(Sqlist& L);
Status DestroyList(Sqlist& L);
void TraverseList(Sqlist L);
int GetLength(Sqlist L);
int isEmpty(Sqlist L);
int GetElem(Sqlist L, int i, ElemType& e);
int LocateElem(Sqlist L, ElemType e);
Status ListInsert_Sq(Sqlist& L, int i, ElemType e);
Status ListDelete_Sq(Sqlist& L, int i);
