#include"test.h"

int main()
{
	ST st;
	StackInit(&st);
	for (int i = 1; i <= 10; i++)
	{
		int num = 0;
		cout << "输入生产日期：";//如20240101
		cin >> num;
		if (StackEmpty(&st))
		{
			StackPush(&st, num);
		}
		else
		{
			int n[10] = { 0 };
			int i = 0;
			while (!StackEmpty(&st)&&num < StackTop(&st))
			{
				n[i] = StackTop(&st);
				i++;
				StackPop(&st);
			}
			
			StackPush(&st, num);
			for (int m = i - 1; m >= 0; m--)
			{
				StackPush(&st, n[m]);
			}

		}
		StackPrint(st);
	}

	return 0;
}