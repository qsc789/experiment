#include"test.h"

int main()
{
	int num = 0;
	cout << "输入十进制数：";
	cin >> num;
	cout << "八进制数为：";
	ST st;
	StackInit(&st);
	while (num != 0)
	{
		StackPush(&st, num % 8);
		num /= 8;
	}
	while (!StackEmpty(&st))
	{
		cout << StackTop(&st);
		StackPop(&st);
	}
	StackDestroy(&st);
	return 0;
}