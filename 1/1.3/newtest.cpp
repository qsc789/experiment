#include"test.h"
SLTNode* BuyListNode(int num,SLTDataType data)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		cout << " malloc fail" << endl;
		exit(-1);
	}
	newnode->num = num;
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLTNode* phead)
{
	SLTNode* temp = phead;
	SLTNode* cur = phead;
	cout << cur->num << ' ';
	cur = cur->next;
	while (cur!=temp)
	{
		cout << cur->num << ' ';
		cur = cur->next;
	}
}
void SListPushBack(SLTNode** pphead, int num, SLTDataType data)
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(num, data);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	if (*pphead == pos)
	{
		//ͷɾ
		SLTNode* cur = *pphead;
		*pphead = (*pphead)->next;
		SLTNode* tail = *pphead;
		while (tail->next != cur)
		{
			tail = tail->next;
		}
		tail->next = cur->next;
		free(cur);
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != pos)
		{
			tail = tail->next;
		}
		tail->next = pos->next;
		free(pos);
	}
}