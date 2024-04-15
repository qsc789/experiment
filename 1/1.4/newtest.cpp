#include"test.h"
LTNode* res = ListInit();
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void add(LTNode* plist1, LTNode* plist2,int n)
{
	int f=0;
	int t = 1;
	LTNode* tail1 = plist1->prev;
	LTNode* tail2 = plist2->prev;
	while (tail1 != plist1 && tail2 != plist2)
	{
		int val = tail1->data + tail2->data + f;
		ListPushBack(res, val % 10000);
		f = val / 10000;
		tail1 = tail1->prev;
		tail2 = tail2->prev;
	}
	while (tail1 != plist1)
	{
		int val = tail1->data + f;
		ListPushBack(res, val % 10000);
		f = val / 10000;
		tail1 = tail1->prev;
	}
	while (tail2 != plist2)
	{
		int val = tail2->data * plist2->data;
		ListPushBack(res, val % 10000);
		f = val / 10000;
		tail2 = tail2->prev;
	}
	if (f > 0)
	{
		ListPushBack(res,f);
	}
	
}
void subtract(LTNode* plist1, LTNode* plist2)
{
	LTNode* cur1 = plist1->prev;
	LTNode* cur2 = plist2->prev;
	int borrow = 0; // ½èÎ»
	int difference;

	while (cur1 != plist1 || cur2 != plist2) {
		int digit1 = (cur1 != plist1) ? cur1->data : 0;
		int digit2 = (cur2 != plist2) ? cur2->data : 0;
		difference = digit1 - digit2 - borrow;

		if (difference < 0&&cur1!=plist1&&cur2!=plist2) {
			difference += 10000;
			borrow = 1;
		}
		else if (difference < 0 && (cur1 == plist1|| cur2 == plist2))
		{
			//cout << '-';
			difference += 10000;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		ListPushBack(res,difference);

		if (cur1 != plist1) {
			cur1 = cur1->prev;
		}
		if (cur2 != plist2) {
			cur2 = cur2->prev;
		}
	}

}
void printres()
{
	LTNode* p1 = res;
	LTNode* p2 = res->prev;
	int t = 1;
	int erase = 1;
	while (p2 != p1)
	{
		if (p2->data == 0 && erase == 1)
		{
			p2 = p2->prev;
			continue;
		}
		else
		{
			erase = 0;
		}
		if (p2->next != p1)
		{
            printf("%4.4d",p2->data);
		}
		else
		{
			cout << p2->data;
		}
		if (p2->prev != p1)
		{
			cout << ',';
		}
		p2 = p2->prev;
	}
}