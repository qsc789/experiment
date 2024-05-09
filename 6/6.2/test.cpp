#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>

using namespace std;
int a[100];
int pos[100];
string num;
int BinarySearch(int flag)
{
	int left = 0;
	int right = num.size() - 1;
	int mid = (left + right) / 2;
	while (a[mid] != flag&&left<=right)
	{
		if (a[mid] > flag)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
		mid = (left + right) / 2;
	}
	if (a[mid] == flag)
	{
		return mid;
	}
	return -1;

}
int main()
{
	
	int flag;
	cout << "输入整数串：";
	cin >> num;
	cout << "输入待查键：";
	cin >> flag;
	for (int i = 0; i < num.size(); i++)
	{
		a[i] = num[i] - '0';
		pos[num[i] - '0'] = i;
	}
	sort(a, a + num.size());
	int n = BinarySearch(flag);
	if(n==-1)
	cout <<"位置为："<< n << endl;
	else
	{
		cout << "位置为：" << pos[flag]+1 << endl;
	}
	return 0;
}
