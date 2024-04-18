#include"test.h"
//int index = 0;
int main()
{
	
	Queue q;
	QueueInit(&q);
	string tree;
	cout << "前序输入树：";
	cin >> tree;
	
	
	BTNode* root=buildTree(tree,0);
	PrintTree(root,maxDepth(root));


	
	return 0;
}