#include"test.h"

int main()
{
	int n = 0;
	cout << "输入数据个数：";
	cin >> n;
	cout << "依次输入数据：";
	TreeNode* root = NULL;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		root=CreateTree(num, root);
	}
	cout << "前序：";
	prevOrder(root);
	cout << endl;
	cout << "中序：";
	InOrder(root);
	cout << endl;
	cout << "后序：";
	BackOrder(root);
	cout << endl;

	cout << "输入删除的节点：";
	int x;
	cin >> x;
	deleteNode(root, x);
	setLevel(root, 1);
	cout << "前序：";
	prevOrder(root);
	cout << endl;
	cout << "中序：";
	InOrder(root);
	cout << endl;
	cout << "后序：";
	BackOrder(root);
	cout << endl;
	PrintTree(root,maxDepth(root));

	return 0;
}
