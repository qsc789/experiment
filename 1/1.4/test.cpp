#include"test.h"
string num1, num2;
LTNode* plist1 = ListInit();
LTNode* plist2 = ListInit();
long long a;
string ans;
int main()
{
	int temp = 0;
	int front = 0;
	LTNode* res = ListInit();
	cin >> num1 >> num2;
	int n1 = num1.length();
	int n2 = num2.length();
	int flag1;
	if (num1[0] == '-')
	{
		plist1->data = -1;
		flag1 = 1;
	}
	else
	{
		plist1->data = 1;
		flag1 = 0;
	}
	for (int i = flag1; i < n1; i++)
	{
		if (num1[i] != ',')
		{
			temp = temp * 10 + (num1[i] - '0');
		}
		else if(num1[i]==',')
		{
			ListPushBack(plist1, temp);
			temp = 0;
		}

	}

	ListPushBack(plist1, temp);
	temp = 0;
	int flag2;
	if (num2[0] == '-')
	{
		plist2->data = -1;
		flag2 = 1;
	}
	else
	{
		plist2->data = 1;
		flag2 = 0;
	}
	for (int i = flag2; i < n2; i++)
	{
		if (num2[i] != ',')
		{
			temp = temp * 10 + (num2[i] - '0');
		}
		else if (num2[i] == ',')
		{
			ListPushBack(plist2, temp);
			temp = 0;
		}

	}

	ListPushBack(plist2, temp);
	temp = 0;
	//¼Ó·¨
	if (flag1 == flag2)
	{
		if (flag1== 1)
		{
			res->data = -1;
			cout << '-';
           add(plist1, plist2,1);
		}
		else
		{
			res->data = 1;
			add(plist1, plist2, 0);
		}
		
	}
	else
	{
		if (flag1 == 1 && flag2 == 0)
		{
           subtract(plist2, plist1);
		}
		else
		{
			subtract(plist1, plist2);
		}
		
	}
	printres();
	
	
	
}