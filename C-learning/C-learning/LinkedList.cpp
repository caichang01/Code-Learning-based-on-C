#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int Elemtype;

/*存储结构*/
typedef struct LNode
{
	Elemtype data;
	struct LNode *Next;
}LNode, *LinkList;

/*初始化线性表*/
void	InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!L)
	{
		exit(OVERFLOW);
	}
	(*L)->Next = NULL;
}

/*销毁线性表*/
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

/*清空线性表*/
void ClearList(LinkList L)
{
	LinkList p = L->Next;
	L->Next = NULL;
	DestroyList(&p);
}

/*判断是否为空*/
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

/*获取长度*/
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

/*根据位置获取元素*/
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

/*查找指定元素的位置*/
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

/*获取前驱元素*/
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

/*获取后继元素*/
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

/*插入元素*/
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

/*删除元素并返回值*/
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

/*访问元素*/
void visit(Elemtype e)
{
	printf("%d ", e);
}

/*遍历线性表*/
void TraverseList(LinkList L, void(*visit)(Elemtype))
{
	LinkList p = L->Next;
	while (p)
	{
		visit(p->data);
		p = p->Next;
	}
}

/*反转单链表*/
LinkList ReverseList(LinkList L)
{
	if (L == NULL || L->Next == NULL)
	{
		return L;
	}
	LinkList p = L;
	LinkList q = L->Next;
	L->Next = NULL;
	LinkList r;
	while (q)
	{
		r = q->Next;
		q->Next = p;
		p = q;
		q = r;
	}
	L = p;
	return L;
}

/*主函数测试*/
int main()
{
	LinkList L, temp;
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

	for (i = 0; i < 10; i++)
	{
		InsertElem(L, i + 1, i);
	}//对单链表予以赋值

	printf("List:");
	TraverseList(L, visit);//遍历单链表
	printf("\n");

	/*反转单链表并遍历*/
	printf("The list is reversed to:");
	L = ReverseList(L);
	temp = L;
	//TraverseList(L, visit);
	for ( i = 0; i < 10; i++)//单链表反转后，头指针变为尾指针，新的头指针对应的数据不再为空，因此无法再使用之前的遍历函数
	{
		visit(temp->data);
		temp = temp->Next;
	}
	printf("\n");
}