#include"test.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		STDataType* temp =(STDataType*) realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (temp == NULL)
		{
			cout << "realloc fail" << endl;
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
void StackPrint(ST ps)
{
	assert(&ps);
	while (!StackEmpty(&ps))
	{
		cout << StackTop(&ps).num<<' '<< StackTop(&ps).time << endl;
		StackPop(&ps);
	}
}
