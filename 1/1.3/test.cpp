#include"test.h"
int n,m;
int main()
{
	SLTNode* plist = NULL;
	cout << "����n:";
	cin >> n;
	cout << "��������" << n << "������:";
	for(int i=1;i<=n;i++)
	{
		int num;
		cin >> num;
		SListPushBack(&plist, i, num);
	}
	cout << "����m:";
	cin >> m;

	//ͷβ���
	SLTNode* tail = plist;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = plist;

	SLTNode* temp = plist;
	while (plist != NULL)
	{
		SLTNode* cur = temp;
		for (int i = 1; i < m; i++)
		{
			cur = cur->next;
		}
		cout << cur->num << ' ';
		m = cur->data;
		temp = cur->next;
		SListErase(&plist, cur);

	}

}