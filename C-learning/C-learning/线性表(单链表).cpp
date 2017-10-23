#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int Elemtype;

/*�洢�ṹ*/
typedef struct LNode
{
	Elemtype data;
	struct LNode *Next;
}LNode, *LinkList;

/*��ʼ�����Ա�*/
void	InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		exit(OVERFLOW);
	}
	(*L)->Next = NULL;
}

/*�������Ա�*/
void DestroyList(LinkList *L)
{
	LinkList temp;
	while (*L)
	{
		temp = (*L)->Next;
		free(*L);
		*L = temp;
	}
}

/*������Ա�*/
void ClearList(LinkList L)
{
	LinkList p = L->Next;
	L->Next = NULL;
	DestroyList(&p);
}

/*�ж��Ƿ�Ϊ��*/
Status isEmpty(LinkList L)
{
	if (L->Next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*��ȡ����*/
int GetLength(LinkList L)
{
	int i = 0;
	LinkList p = L->Next;
	while (p)
	{
		i++;
		p = p->Next;
	}
	return i;
}

/*����λ�û�ȡԪ��*/
Status GetElem(LinkList L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p = L->Next;
	while (p && j < 1)
	{
		j++;
		p = p->Next;
	}
	if (!p || j > 1)
	{
		return ERROR;
	}
	*e = p->data;
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

/*����ָ��Ԫ�ص�λ��*/
int FindElem(LinkList L, Elemtype e, Status(*compare)(Elemtype, Elemtype))
{
	int i = 0;
	LinkList p = L->Next;
	while (p)
	{
		i++;
		if (!compare(p->data, e))
		{
			return i;
		}
		p = p->Next;
	}
	return 0;
}

/*��ȡǰ��Ԫ��*/
Status PreElem(LinkList L, Elemtype cur_e, Elemtype *pre_e)
{
	LinkList q, p = L->Next;
	while (p->Next)
	{
		q = p->Next;
		if (q->data == cur_e)
		{
			*pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return ERROR;
}

/*��ȡ���Ԫ��*/
Status NextElem(LinkList L, Elemtype cur_e, Elemtype *next_e)
{
	LinkList p = L->Next;
	while (p->Next)
	{
		if (p->data == cur_e)
		{
			*next_e = p->Next->data;
			return OK;
		}
		p = p->Next;
	}
	return ERROR;
}

/*����Ԫ��*/
Status InsertElem(LinkList L, int i, Elemtype e)
{
	int j = 0;
	LinkList s, p = L;
	while (p && j < i - 1)
	{
		j++;
		p = p->Next;
	}
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->Next = p->Next;
	p->Next = s;
	return OK;
}

/*ɾ��Ԫ�ز�����ֵ*/
Status DeleteElem(LinkList L, int i, Elemtype *e)
{
	int j = 0;
	LinkList q, p = L;
	while (p->Next && j < i - 1)
	{
		j++;
		p = p ->Next;
	}
	if (p->Next || j > i - 1)
	{
		return ERROR;
	}
	q = p->Next;
	p->Next = q->Next;
	*e = q->data;
	free(q);
	return OK;
}

/*����Ԫ��*/
void visit(Elemtype e)
{
	printf("%d ", e);
}

/*�������Ա�*/
void TraverseList(LinkList L, void(*visit)(Elemtype))
{
	LinkList p = L->Next;
	while (p)
	{
		visit(p->data);
		p = p->Next;
	}
}

/*����������*/
int main()
{
	LinkList L;
	InitList(&L);
	Elemtype e;
	int i;
	if (L)
	{
		printf("Init success!\n");
	}

	if (isEmpty(L))
	{
		printf("List is empty!\n");
	}

	for ( i = 0; i < 10; i++)
	{
		InsertElem(L, i + 1, i);
	}
	
	if (GetElem(L, 1, &e))
	{
		printf("The first element is %d\n", e);
	}

	printf("The length is %d\n", GetLength(L));

	printf("The 5 at %d\n",FindElem(L, 5, *compare));

	PreElem(L, 6, &e);
	printf("The 6's previous element is %d\n", e);

	NextElem(L, 6, &e);
	printf("The 6's next element is %d\n", e);

	DeleteElem(L, 1, &e);
	printf("Delete first element is %d\n", e);

	printf("List:");
	TraverseList(L, visit);

	DestroyList(&L);
	if (!L)
	{
		printf("\nDestroy success!\n");
	}
}