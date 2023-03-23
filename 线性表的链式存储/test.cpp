#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node;
typedef struct Node ;
typedef struct Node* LinkList;
//表的创建(头插法)
void CreateListHead(LinkList&L, int m[], int n) {
	LinkList p;
	int i;
	L = new Node;
	L->next = NULL;
	for (i = 0; i < n; i++) {
		p = new Node;
		p->data = m[i];
		p->next = L->next;
		L->next = p;
	}
}
//表的创建（尾插法）
void CreateListTail(LinkList& L, int m[], int n) {
	LinkList p, t;
	L = new Node;
	t = L;//先将t指向头结点
	for (int i = 0; i < n; i++) {
		p = new Node;
		p->data = m[i];
		t->next = p;
		t = p;
	}
	t->next = NULL;

}
//插入
Status ListInsert(LinkList& L, int i,ElemType e) {
	LinkList p, t;
	p = L;
	int cnt = 1;
	//扫描
	while (p&&cnt<i)
	{
		p = p->next;
		cnt++;
	}
	if (p == NULL || cnt != i)
		return ERROR;
	t = new Node;
	t->data = e;
	t->next = p->next;
	p->next = t;
	return OK;
}
//删除
Status ListDelete(LinkList& L, int i) {
	LinkList p, q;
	p = L;
	int cnt = 1;
	while (p&&cnt<i)
	{
		p = p->next;
		cnt++;
	}
	if (p->next == NULL || cnt != i||p==NULL)
		return ERROR;
	q = p->next;
	p->next = q->next;
	delete(q);
	return OK;
}
//获取元素
Status GetElem(LinkList L, int i,ElemType *e) {
	LinkList p;
	p = L->next;
	int cnt = 1;
	while (p&&cnt<i)
	{
		p = p->next;
		cnt++;
	}
	if (cnt == i)
		*e = p->data;
	else
		return ERROR;
	return OK;
}
//表的打印
Status Output(LinkList L) {
	LinkList p;
	p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}
int main()
{
	LinkList L;
	int i, k, j, n, e, m[1000];
	printf("请输入要存储元素的总个数：");
	cin >> n;
	printf("请输入各个元素的值：");
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	CreateListTail(L, m, n);
	printf("此时链表的各元素如下:\n");
	Output(L);
	printf("请输入要获取第j个元素并返回到e值中(输入j的值):");
	cin>>j;
	GetElem(L, j, &e);
	printf("此时e的值为第j个元素值:%d\n", e);
	printf("请输入在第k个元素前插入一个元素e1:");
	int e1;
	cin>>k>>e1;
	ListInsert(L, k, e1);
	printf("此时链表的各元素如下:\n");
	Output(L);
	printf("请输入要删除链表中的第几个元素:");
	int l;
	cin>>l;
	ListDelete(L, l);
	printf("此时链表的各元素如下:\n");
	Output(L);
	return 0;
}
