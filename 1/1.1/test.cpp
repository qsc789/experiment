#include"test.h"
int main()
{
	SL ps;
	SeqListInit(&ps);
	//ͷ���
	SeqListPushBack(&ps, 0);
	//β�幹��������
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	SeqListPushBack(&ps, 6);
	SeqListPrint(&ps);
	//����
	int pos = 0, val = 0;
	cout << "�������ֵ���±꣺";
	cin >> pos;
	cout << "����ֵ��";
	cin >> val;
	SeqListInsert(&ps, pos, val);
	SeqListPrint(&ps);
	//ɾ��
	cout << "����ɾ��ֵ���±꣺";
	int flag = 0;
	cin >> flag;
	SeqListDelete(&ps, flag);
	SeqListPrint(&ps);
	//����
	int num = 0;
	cout << "������ҵ�ֵ��";
	cin >> num;
	cout << "�±�Ϊ��" << SeqListFind(&ps, num) << endl;
	
}