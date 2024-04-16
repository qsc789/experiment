#include"test.h"

int main()
{
	ST st;
	ST stemp;
	StackInit(&st);
	StackInit(&stemp);
	char now;
	int num, time;
	while (1)
	{
		cin >> now >> num >> time;
		if (now == 'E')
		{
			break;
		}
		point temp;
		temp.now = now;
		temp.num = num;
		temp.time = time;
		if (now == 'A')
		{
			StackPush(&st, temp);
		}
		else
		{
			while (num != StackTop(&st).num)
			{
				point t;
				t = StackTop(&st);
				StackPop(&st); 
				StackPush(&stemp, t);
			}
			StackPop(&st);
			while (!StackEmpty(&stemp))
			{
				StackPush(&st, StackTop(&stemp));
				StackPop(&stemp);
			}
		}
		StackPrint(st);
	}
	
	return 0;
}