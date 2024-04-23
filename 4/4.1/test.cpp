#include"test.h"

int main()
{
	
	Queue q;
	QueueInit(&q);
	string tree;
	cout << "前序输入树：";
	getline(cin, tree);
	
	
	BTNode* root=buildTree(tree);
	cout<<"前序：";
	PrevOrder(root);
	cout << endl;
	cout << "中序：";
	InOrder(root);
	cout << endl;
	cout << "后序：";
	BackOrder(root);
	cout << endl;


	
	return 0;
}