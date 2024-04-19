#include"temp.h"
int n = 0;
int main()
{
	cout << "输入停车场容量：";
	cin >> n;
	ST st;
	ST stemp;
	StackInit(&st, n);
	StackInit(&stemp, 20);
	Queue qtemp, qtemp1;
	Queue q;
	QueueInit(&qtemp);
	QueueInit(&qtemp1);
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
		QueuePush(&q, temp);
	}
	int m = QueueSize(q);
	for (int i = 1; i<=m; i++)
	{

		if (QueueFront(&q).now == 'A')
		{
			QDataType temp = QueueFront(&q);
			if (!StackFull(&st))
			{
				StackPush(&st, temp);
			}
			else
			{
				QueuePush(&qtemp, temp);
			}

		}
		else
		{
			while (!StackEmpty(&st) && QueueFront(&q).num != StackTop(&st).num)
			{
				point t;
				t = StackTop(&st);
				StackPop(&st);
				StackPush(&stemp, t);
			}
			if (StackEmpty(&st))
			{
				while (QueueFront(&q).num != QueueFront(&qtemp).num)
				{
					point t;
					t = QueueFront(&qtemp);
					QueuePop(&qtemp);
					QueuePush(&qtemp1, t);
				}
				QueuePop(&qtemp);
				while (!QueueEmpty(&qtemp))
				{
					point t;
					t = QueueFront(&qtemp);
					QueuePop(&qtemp);
					QueuePush(&qtemp1, t);
				}
				while (!QueueEmpty(&qtemp1))
				{
					point t;
					t = QueueFront(&qtemp1);
					QueuePop(&qtemp1);
					QueuePush(&qtemp, t);
				}

			}
			else
			{
				StackPop(&st);
				if (!QueueEmpty(&qtemp))
				{
                   StackPush(&st, QueueFront(&qtemp));
				}
				
				while (!StackEmpty(&stemp))
				{
					StackPush(&st, StackTop(&stemp));
					StackPop(&stemp);
				}
				if (!StackFull(&st) && !QueueEmpty(&qtemp))
				{
					StackPush(&st, QueueFront(&qtemp));
					QueuePop(&qtemp);
				}
				if (!QueueEmpty(&qtemp))
				{
					while (!QueueEmpty(&q))
					{
						point temp = QueueFront(&q);
						QueuePush(&qtemp, temp);
						QueuePop(&q);
					}
					while (!QueueEmpty(&qtemp))
					{
						point temp = QueueFront(&qtemp);
						QueuePush(&q, temp);
						QueuePop(&qtemp);
					}
				}
				
			}



		}
		printf("第%d次操作后：\n", i);
		StackPrint(st);
		QueuePop(&q);
	}

	return 0;
}