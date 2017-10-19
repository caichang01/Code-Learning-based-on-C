#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10//初始化表长
#define INCREMENT_SIZE 5//分配增量

typedef int Status;
typedef int Elemtype;

typedef struct
{
	Elemtype *elem;//存储空间基址
	int length;//当前长度
	int size;//当前分配的表长大小
}SqList;

/*初始化一个空的线性表*/
Status InitList(SqList *L)
{
	L->elem = (Elemtype *)malloc(INIT_SIZE * sizeof(Elemtype));
	if (!L->elem)
	{
		return ERROR;
	}
	L->length = 0;
	L->size = INIT_SIZE;
	return OK;
}

/*销毁线性表*/
Status DestroyList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	return OK;
}

/*清空线性表*/
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/*判断线性表是否为空*/
Status isEmpty(const SqList L)
{
	if (0 == L.length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*获取长度*/
Status getLength(const SqList L)
{
	return L.length;
}

/*根据位置获取元素*/
Status GetElem(const SqList L, int i, Elemtype *e)
{
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}
	*e = L.elem[i - 1];
	return OK;
}

/*比较两个元素是否相等*/
Status compare(Elemtype e1, Elemtype e2)
{
	if (e1 == e2)
	{
		return 0;
	}
	else if (e1 < e2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

/*查找元素*/
Status FindElem(const SqList L, Elemtype e, Status(*compare)(Elemtype, Elemtype)
{
	int i;
	for ( i = 0; i < L.length; i++)
	{
		if (!(*compare)(L.elem[i], e)
		{
			return i + 1;
		}
	}
	if (i >= L.length)
	{
		return ERROR;
	}
}

/*查找前驱元素*/
Status PreElem(const SqList L, Elemtype cur_e, Elemtype *pre_e)
{
	int i;
	for ( i = 0; i < L.length; i++)
	{
		if (cur_e == L.elem[i])
		{
			if (i != 0)
			{
				*pre_e = L.elem[i - 1];
			}
			else
			{
				return ERROR;
			}
		}
	}
	if (i >= L.length)
	{
		return ERROR;
	}
}

/*查找后驱元素*/
Status  NextElem(const SqList L, Elemtype cur_e, Elemtype *next_e)
{
	int i;
	for ( i = 0; i < L.length; i++)
	{
		if (cur_e == L.elem[i])
		{
			if (i != 0)
			{
				*next_e = L.elem[i - 1];
			}
			else
			{
				return ERROR;
			}
		}
	}
	if (i >= L.length)
	{
		return ERROR;
	}
}

/*插入元素*/
Status InsertElem(SqList *L, int i, Elemtype e)
{
	Elemtype *new;
	if (i < 1 || i > L->length + 1)
	{
		return ERROR;
	}
	if (L->length >= L->size)
	{
		new = (Elemtype*)
	}
}
int main()
{
		
}