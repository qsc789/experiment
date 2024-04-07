#include"test.h"
int main()
{
	SL ps;
	//头结点
	SeqListInit(&ps);

	//尾插构建单链表
	SeqListPushBack(&ps, "Beijing", 1, 1);
	SeqListPushBack(&ps, "Nanjing", 2, 3);
	SeqListPushBack(&ps, "Tianjin", 2, 4);
	SeqListPushBack(&ps, "Changsha", 6, 8);
	SeqListPushBack(&ps, "Zhengzhou", 9, 6);
	SeqListPushBack(&ps, "Changchun", 4, 3);
	SeqListPushBack(&ps, "Shanghai", 5, 1);
	SeqListPrint(&ps);
	//插入
	int pos = 0, x = 0, y = 0;
	string str;
	cout << "输入插入值的下标：";
	cin >> pos;
	cout << "输入城市名：";
	cin >> str;
	cout << "输入横坐标：";
	cin >> x;
	cout << "输入纵坐标：";
	cin >> y;
	SeqListInsert(&ps, pos, str, x, y);
	SeqListPrint(&ps);
	//删除
	cout << "输入删除值的下标：";
	int flag = 0;
	cin >> flag;
	SeqListDelete(&ps, flag);
	SeqListPrint(&ps);
	//查找
	string s;
	cout << "输入查找的城市名：";
	cin >> s;
	SeqListFindByName(&ps, s);

	int num1, num2;
	cout << "输入查找的横坐标：";
	cin >> num1;
	cout << "输入查找的纵坐标：";
	cin >> num2;
	SeqListFindByPlace(&ps, num1, num2);

	//查找与给定坐标距离<=D的城市
	int tx, ty, D;
	cout << "输入给定横坐标：";
	cin >> tx;
	cout << "输入给定纵坐标：";
	cin >> ty;
	cout << "输入距离：";
	cin >> D;
	
	FindCity(&ps, tx, ty, D);


}