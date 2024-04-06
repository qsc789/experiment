#include"test.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (temp == NULL)
		{
			cout << "realloc fail" << endl;
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcapacity;
	}
	
}
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(pos <= ps->size && pos > 0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListDelete(SL* ps, int pos)
{
	assert(pos <= ps->size && pos > 0);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
	
}
int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 1; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListPrint(SL* ps)
{
	for (int i = 1; i < ps->size; i++)
	{
		cout << ps->a[i] << ' ';
	}
	cout << endl;
}