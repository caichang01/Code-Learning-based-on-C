#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10//��ʼ����
#define INCREMENT_SIZE 5//��������

typedef int Status;
typedef int Elemtype;

typedef struct
{
	Elemtype *elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int size;//��ǰ����ı���С
}SqList;

/*��ʼ��һ���յ����Ա�*/
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

/*�������Ա�*/
Status DestroyList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	return OK;
}

/*������Ա�*/
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/*�ж����Ա��Ƿ�Ϊ��*/
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

/*��ȡ����*/
Status getLength(const SqList L)
{
	return L.length;
}

/*����λ�û�ȡԪ��*/
Status GetElem(const SqList L, int i, Elemtype *e)
{
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}
	*e = L.elem[i - 1];
	return OK;
}

/*�Ƚ�����Ԫ���Ƿ����*/
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

/*����Ԫ��*/
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

/*����ǰ��Ԫ��*/
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

/*���Һ���Ԫ��*/
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

/*����Ԫ��*/
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