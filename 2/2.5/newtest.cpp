#include"temp.h"

void StackInit(ST* ps,int n)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * n);
	ps->top = 0;
	ps->capacity = n;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	//free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//if (ps->top == ps->capacity)
	//{

	//	int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
	//	STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
	//	if (temp == NULL)
	//	{
	//		//cout << "realloc fail" << endl;
	//		exit(-1);
	//	}
	//	ps->a = temp;
	//	ps->capacity = newCapacity;
	//}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
bool StackFull(ST* ps)
{
	if (ps->top == ps->capacity )
	{
		return true;
	}
	return false;
}
void StackPrint(ST ps)
{
	assert(&ps);
	while (!StackEmpty(&ps))
	{
		//printf("%d %d\n", , );
		cout << StackTop(&ps).num << ' ' << StackTop(&ps).time << endl;
		StackPop(&ps);
	}
}
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	pq->tail->next = NULL;
//	while (cur != NULL)
//	{
//      QueueNode* next = cur->next;
//	  free(cur);
//	  cur = next;
//	}
//	pq->head = NULL;
//	pq->tail = NULL;
//}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->temp = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
		newnode->next = pq->head;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
		//pq->tail->next = pq->head;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	//free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq -> tail->temp;
//}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
QDataType QueueFront(Queue* pq)
{
	return (pq->head)->temp;
}
int QueueSize(Queue pq)
{
	int num = 0;
	while (!QueueEmpty(&pq))
	{
		num++;
		QueuePop(&pq);
	}
	return num;
}