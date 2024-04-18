#include"test.h"

int main()
{
	ST st;
	ST stemp;
	StackInit(&st);
	StackInit(&stemp);
	Queue q;
	QueueInit(&q);
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
		QueuePush(&q,temp);
	}
	
	for(int i=1;!QueueEmpty(&q);i++)
	{
		if (QueueFront(&q).now == 'A')
		{
			QDataType temp = QueueFront(&q);
			
			StackPush(&st, temp);
		}
		else
		{
			while (QueueFront(&q).num != StackTop(&st).num)
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
		printf("第%d次操作后：\n",i);
		StackPrint(st);
		QueuePop(&q);
	}
	
	return 0;
}