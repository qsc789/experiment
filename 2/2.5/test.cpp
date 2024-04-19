#include"test.h"
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
		temp.trueTime = time;
		QueuePush(&q, temp);
	}
	int m = QueueSize(q);
	for (int i = 1; i <= m; i++)
	{
		printf("第%d次操作后：\n", i);
		point p = QueueFront(&q);
		QueuePop(&q);
		if (p.now == 'A')
		{
			QDataType temp = p;
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
			while (!StackEmpty(&st) && p.num != StackTop(&st).num)
			{
				point t;
				t = StackTop(&st);
				StackPop(&st);
				StackPush(&stemp, t);
			}
			if (StackEmpty(&st))
			{
				while (p.num != QueueFront(&qtemp).num)
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
				point cur = StackTop(&st);
				p.trueTime = cur.time;
				StackPop(&st);
				

				while (!StackEmpty(&stemp))
				{
					StackPush(&st, StackTop(&stemp));
					StackPop(&stemp);
				}
				if (!StackFull(&st) && !QueueEmpty(&qtemp))
				{
					point cur = QueueFront(&qtemp);
					cur.trueTime = p.time;
					cur.time = p.time;
					StackPush(&st, cur);
					QueuePop(&qtemp);
				}
				

			}
			cout << p.num << "号车离开,停留了" << p.time - p.trueTime << "分钟,收费" << (int)(10*(p.time - p.trueTime)) << "元" << endl;


		}
		
		StackPrint(st);
		
	}

	return 0;
}