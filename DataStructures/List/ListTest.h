#pragma once
#include "List.h"

void ListTest()
{
	Sqlist L;

	InitList_Sq(L);
	TraverseList(L);

	ListInsert_Sq(L, 1, 'a');
	ListInsert_Sq(L, 1, 'b');
	ListInsert_Sq(L, 1, 'c');
	ListInsert_Sq(L, 1, 'd');
	ListInsert_Sq(L, 1, 'e');
	TraverseList(L);

	ListDelete_Sq(L, 3);
	TraverseList(L);

	ElemType e;
	GetElem(L, 2, e);
	std::cout << "2. " << e << std::endl;

	int e_index = LocateElem(L, e);
	std::cout << "e_index: " << e_index << std::endl;

	DestroyList(L);
	TraverseList(L);

}
