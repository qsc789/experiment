#include"test.h"
int main()
{
	SL ps;
	SeqListInit(&ps);
	//头结点
	SeqListPushBack(&ps, 0);
	//尾插构建单链表
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	SeqListPushBack(&ps, 6);
	SeqListPrint(&ps);
	//插入
	int pos = 0, val = 0;
	cout << "输入插入值的下标：";
	cin >> pos;
	cout << "输入值：";
	cin >> val;
	SeqListInsert(&ps, pos, val);
	SeqListPrint(&ps);
	//删除
	cout << "输入删除值的下标：";
	int flag = 0;
	cin >> flag;
	SeqListDelete(&ps, flag);
	SeqListPrint(&ps);
	//查找
	int num = 0;
	cout << "输入查找的值：";
	cin >> num;
	cout << "下标为：" << SeqListFind(&ps, num) << endl;
	
}