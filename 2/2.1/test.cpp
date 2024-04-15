#include"test.h"
void TestStack1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	//printf("%d", StackTop(&st));
	StackDestroy(&st);
}
void TestStack2()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	/*printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);*/
	StackPush(&st, 5);
	StackPush(&st, 6);


	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);//��һ��
	}

	StackDestroy(&st);
}

void test3()
{
	Queue q;
	QueueInit(&q);
	/*QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);*/
	//printf("%d\n", QueueBack(&q));
	QueuePush(&q, 10);
	QueuePush(&q, 20);

	QueueDestroy(&q);
}
int main()
{
	//TestStack1();
	//TestStack2();
	test3();
	return 0;
}