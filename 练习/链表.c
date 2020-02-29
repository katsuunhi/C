#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
Status InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
void CreateList_H(LinkList &L, int n)
{
	LinkList p;
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i<n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = L->next; L->next = p;
	}
}
void PrintfList(LinkList L)
{
	cout << "链表中存储的数据为：" << endl;
	while (L->next != NULL)
	{
		cout << L->data << "";
		L = L->next;
	}
	cout << endl;
}
Status ListInsert(LinkList &L, int i, ElemType e)
{
	LinkList p, s;
	p = L; int j = 0;
	while (p && (j<i - 1))
	{
		p = p->next; ++j;
	}
	if (!p || j>i - 1) return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next; p->next = s;
	return OK;
}

int main()
{
	int i;
	ElemType e;
	LNode *L;
	cout << "请输入数据" << endl;
	InitList(L);
	CreateList_H(L, 5);


	ListInsert(L, 5, e);
	PrintfList(L);
	return 0;
}

