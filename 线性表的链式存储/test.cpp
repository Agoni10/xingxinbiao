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
//��Ĵ���(ͷ�巨)
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
//��Ĵ�����β�巨��
void CreateListTail(LinkList& L, int m[], int n) {
	LinkList p, t;
	L = new Node;
	t = L;//�Ƚ�tָ��ͷ���
	for (int i = 0; i < n; i++) {
		p = new Node;
		p->data = m[i];
		t->next = p;
		t = p;
	}
	t->next = NULL;

}
//����
Status ListInsert(LinkList& L, int i,ElemType e) {
	LinkList p, t;
	p = L;
	int cnt = 1;
	//ɨ��
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
//ɾ��
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
//��ȡԪ��
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
//��Ĵ�ӡ
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
	printf("������Ҫ�洢Ԫ�ص��ܸ�����");
	cin >> n;
	printf("���������Ԫ�ص�ֵ��");
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	CreateListTail(L, m, n);
	printf("��ʱ����ĸ�Ԫ������:\n");
	Output(L);
	printf("������Ҫ��ȡ��j��Ԫ�ز����ص�eֵ��(����j��ֵ):");
	cin>>j;
	GetElem(L, j, &e);
	printf("��ʱe��ֵΪ��j��Ԫ��ֵ:%d\n", e);
	printf("�������ڵ�k��Ԫ��ǰ����һ��Ԫ��e1:");
	int e1;
	cin>>k>>e1;
	ListInsert(L, k, e1);
	printf("��ʱ����ĸ�Ԫ������:\n");
	Output(L);
	printf("������Ҫɾ�������еĵڼ���Ԫ��:");
	int l;
	cin>>l;
	ListDelete(L, l);
	printf("��ʱ����ĸ�Ԫ������:\n");
	Output(L);
	return 0;
}
