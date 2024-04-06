#include"test.h"
void SeqListInit(SL* ps)
{
	SeqListPushBack(ps, "NULL", -1, -1);
}
void SeqListPushBack(SL* ps, string name, int x, int y)
{
	city temp;
	temp.CityName = name;
	temp.x = x;
	temp.y = y;
	(ps->a).push_back(temp);
}

void SeqListInsert(SL* ps, int pos,string str, int x,int y)
{
	//int end = ps->size - 1;
	city temp;
	temp.CityName = "NULL";
	temp.x = 0;
	temp.y = 0;
	(ps->a).push_back(temp);
	int num = (ps->a).size() - pos;
	vector<city>::iterator it;
	for (it = (ps->a).end()-1; num >1; num--)
	{
		it->CityName = (it - 1)->CityName;
		it->x = (it - 1)->x;
		it->y = (it - 1)->y;
		it--;
	}
	
	for (it = (ps->a).begin()+1; pos >1; pos--)
	{
		it++;
	}
	it->CityName = str;
	it->x = x;
	it->y = y;
}
void SeqListDelete(SL* ps, int pos)
{
	vector<city>::iterator it;
	for (it = (ps->a).begin()+1; pos > 1; pos--)
	{
		it++;
	}
	while (it < (ps->a).end()-1)
	{
		it->CityName = (it + 1)->CityName;
		it->x = (it + 1)->x;
		it->y = (it + 1)->y;
		it++;
	}
	(ps->a).pop_back();

}
void SeqListFindByName(SL* ps, string str)
{
	for (vector<city>::iterator it = (ps->a).begin()+1; it < (ps->a).end(); it++)
	{
		if (it->CityName == str)
		{
			cout << str << ' ' << it->x << ' ' << it->y << endl;
			return;
		}
	}
	cout << "Not Exist" << endl;
	return;
}
void SeqListFindByPlace(SL* ps, int x, int y)
{
	for (vector<city>::iterator it = (ps->a).begin()+1; it < (ps->a).end(); it++)
	{
		if (it->x == x && it->y == y)
		{
			cout << it->CityName << ' ' << it->x << ' ' << it->y << endl;
			return;
		}
	}
	cout << "Not Exist" << endl;
	return;
}
void SeqListPrint(SL* ps)
{
	for (vector<city>::iterator it = (ps->a).begin()+1; it < (ps->a).end(); it++)
	{
		cout << it->CityName << ' ' << it->x << ' ' << it->y << endl;
	}
}