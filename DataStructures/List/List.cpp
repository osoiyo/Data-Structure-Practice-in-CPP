#include "List.h"

/*
* ˳���
*/

// ��ʼ��
Status InitList_Sq(Sqlist& L)
{
	L.elem = new ElemType[LIST_INIT_SIZE];
	if (!L.elem) exit(OVERFLOW2);
	L.length = 0;
	return OK;
}

// ����
Status DestroyList(Sqlist& L)
{
	if (L.elem) delete L.elem;
	L.elem = NULL;
	return OK;
}

// ��
int GetLength(Sqlist L)
{
	return L.length;
}

// �п�
Status isEmpty(Sqlist L)
{
	return L.length == 0 ? TRUE : FALSE;
}

// ȡԪ��
Status GetElem(Sqlist L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) {
		return OVERFLOW2;
	}

	e = L.elem[i - 1];
	return OK;
}

// ��λԪ�أ������±�
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

// ����Ԫ��, ��i��Ԫ��֮ǰ
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

	// �ӵ�i�����±� i-1�������һ�����±� length-1�������������ƶ�һλ
	for (int j = L.length-1; j >= i-1; j--)
	{
		L.elem[j + 1] = L.elem[j]; 
	}
	L.elem[i - 1] = e;
	L.length++;

	return OK;
}

// ɾ��Ԫ��
Status ListDelete_Sq(Sqlist& L, int i)
{
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	// �� ��i [i-1] ��Ԫ�ص����һ��[length-1]Ԫ�أ�������ǰһλ
	for (int j = i - 1; j <= L.length - 1; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;

	return OK;
}

// ����
void TraverseList(Sqlist L)
{
	if (L.elem == NULL)
	{
		std::cout << "������" << std::endl;
		return;
	}
	std::cout << "���� List�����ȣ� " << L.length << std::endl;
	for (int i = 0; i < L.length; i++)
	{
		std::cout << L.elem[i] << " ";
	}
	std::cout << std::endl;
}

