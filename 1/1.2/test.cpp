#include"test.h"
int main()
{
	SL ps;
	//ͷ���
	SeqListInit(&ps);

	//β�幹��������
	SeqListPushBack(&ps, "Beijing", 1, 1);
	SeqListPushBack(&ps, "Nanjing", 2, 3);
	SeqListPushBack(&ps, "Tianjin", 2, 4);
	SeqListPushBack(&ps, "Changsha", 6, 8);
	SeqListPushBack(&ps, "Zhengzhou", 9, 6);
	SeqListPushBack(&ps, "Changchun", 4, 3);
	SeqListPushBack(&ps, "Shanghai", 5, 1);
	SeqListPrint(&ps);
	//����
	int pos = 0, x = 0, y = 0;
	string str;
	cout << "�������ֵ���±꣺";
	cin >> pos;
	cout << "�����������";
	cin >> str;
	cout << "��������꣺";
	cin >> x;
	cout << "���������꣺";
	cin >> y;
	SeqListInsert(&ps, pos, str, x, y);
	SeqListPrint(&ps);
	//ɾ��
	cout << "����ɾ��ֵ���±꣺";
	int flag = 0;
	cin >> flag;
	SeqListDelete(&ps, flag);
	SeqListPrint(&ps);
	//����
	string s;
	cout << "������ҵĳ�������";
	cin >> s;
	SeqListFindByName(&ps, s);

	int num1, num2;
	cout << "������ҵĺ����꣺";
	cin >> num1;
	cout << "������ҵ������꣺";
	cin >> num2;
	SeqListFindByPlace(&ps, num1, num2);

	//����������������<=D�ĳ���
	int tx, ty, D;
	cout << "������������꣺";
	cin >> tx;
	cout << "������������꣺";
	cin >> ty;
	cout << "������룺";
	cin >> D;
	
	FindCity(&ps, tx, ty, D);


}