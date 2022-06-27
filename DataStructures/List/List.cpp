#include "List.h"

/*
* 顺序表
*/

// 初始化
Status InitList_Sq(Sqlist& L)
{
	L.elem = new ElemType[LIST_INIT_SIZE];
	if (!L.elem) exit(OVERFLOW2);
	L.length = 0;
	return OK;
}

// 销毁
Status DestroyList(Sqlist& L)
{
	if (L.elem) delete L.elem;
	L.elem = NULL;
	return OK;
}

// 表长
int GetLength(Sqlist L)
{
	return L.length;
}

// 判空
Status isEmpty(Sqlist L)
{
	return L.length == 0 ? TRUE : FALSE;
}

// 取元素
Status GetElem(Sqlist L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) {
		return OVERFLOW2;
	}

	e = L.elem[i - 1];
	return OK;
}

// 定位元素，返回下标
int LocateElem(Sqlist L, ElemType e)
{
	for (int i = 1; i <= L.length; i++)
	{
		if (L.elem[i-1] == e)
		{
			return i;
		}
	}
	return 0;
}

// 插入元素, 第i个元素之前
Status ListInsert_Sq(Sqlist& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	if (L.length+1 >= LIST_INIT_SIZE)
	{
		return OVERFLOW2;
	}

	// 从第i个（下标 i-1）到最后一个（下标 length-1），挨个往后移动一位
	for (int j = L.length-1; j >= i-1; j--)
	{
		L.elem[j + 1] = L.elem[j]; 
	}
	L.elem[i - 1] = e;
	L.length++;

	return OK;
}

// 删除元素
Status ListDelete_Sq(Sqlist& L, int i)
{
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	// 从 第i [i-1] 个元素到最后一个[length-1]元素，依次往前一位
	for (int j = i - 1; j <= L.length - 1; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;

	return OK;
}

// 遍历
void TraverseList(Sqlist L)
{
	if (L.elem == NULL)
	{
		std::cout << "已销毁" << std::endl;
		return;
	}
	std::cout << "遍历 List，长度： " << L.length << std::endl;
	for (int i = 0; i < L.length; i++)
	{
		std::cout << L.elem[i] << " ";
	}
	std::cout << std::endl;
}

