#include"test.h"

int main()
{
	map<char, int> mp1;
	map<char, char> mp2;
	mp1.insert(make_pair('(', 1));
	mp1.insert(make_pair('[', 1));
	mp1.insert(make_pair('{', 1));
	mp2.insert(make_pair('(', ')'));
	mp2.insert(make_pair('[', ']'));
	mp2.insert(make_pair('{', '}'));
	ST st;
	StackInit(&st);

	string str;
	cout << "输入字符串：";
	cin >> str;
	int flag = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (mp1[str[i]] == 1)
		{
			StackPush(&st, str[i]);
		}
		else
		{
			if (StackEmpty(&st))
			{
				flag = 0;
				break;
			}
			char a = StackTop(&st);
			StackPop(&st);
			if (mp2[a] == str[i])
			{
				continue;
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}
	if (!StackEmpty(&st))
	{
		flag = 0;
	}
	if (flag == 1)
	{
		cout << "Valid" << endl;
	}
	else
	{
		cout << "Invalid" << endl;
	}


	return 0;
}