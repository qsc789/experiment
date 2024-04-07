#include"test.h"
int n,m;
int main()
{
	SLTNode* plist = NULL;
	cout << "输入n:";
	cin >> n;
	cout << "依次输入" << n << "个密码:";
	for(int i=1;i<=n;i++)
	{
		int num;
		cin >> num;
		SListPushBack(&plist, i, num);
	}
	cout << "输入m:";
	cin >> m;

	//头尾相接
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