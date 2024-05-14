#include"test.h"


TreeNode* CreateTree(int x, TreeNode* root)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->level = 1;
	
	if (root == NULL)
	{
		root = newNode;
		
	}
	else
	{
		int flag;
		TreeNode* cur = root;
		TreeNode* prev = root;
		while (cur != NULL)
		{
			prev = cur;
			if (newNode->data > cur->data)
			{
				cur = cur->right;
				flag = 1;
			}
			else if (newNode->data < cur->data)
			{
				cur = cur->left;
				flag = 0;
			}
			newNode->level++;
		}
		if (flag == 1)
		{
			prev->right = newNode;
		}
		else
		{
			prev->left = newNode;
		}
	}
	return root;
}
bool search(int flag, TreeNode* root, int num)
{
	TreeNode* cur = root;
	if (cur->data > flag)
	{
		if (cur->right == NULL)
		{
			return false;
		}
		else
		{
			search(flag, cur->right, num + 1);
		}
	}
	else if (cur->data < flag)
	{
		if (cur->left == NULL)
		{
			return false;
		}
		else
		{
			search(flag, cur->left, num + 1);
		}
	}
	else if (cur->data == flag)
	{
		cout << num << endl;
		return true;
	}
}

void deleteNode(TreeNode* root, int flag)
{
	TreeNode* cur = root;
	TreeNode* prev1 = root;

	while (cur->data != flag)
	{
		prev1 = cur;
		if (cur->data < flag)
		{
			cur = cur->right;

		}
		else if (cur->data > flag)
		{
			cur = cur->left;

		}
	}
	if (cur->left == NULL && cur->right == NULL)
	{
		if (prev1->left == cur)
		{
			prev1->left = NULL;
		}
		else if (prev1->right == cur)
		{
			prev1->right = NULL;
		}
	}
	else if (cur->left == NULL)
	{
		if (prev1->left == cur)
		{
			prev1->left =cur->right;
		}
		else if (prev1->right == cur)
		{
			prev1->right = cur->right;
		}
	}
	else if (cur->right == NULL)
	{
		if (prev1->left == cur)
		{
			prev1->left = cur->left;
		}
		else if (prev1->right == cur)
		{
			prev1->right = cur->left;
		}
	}
	else
	{
		TreeNode* temp = cur->left;
		TreeNode* prev2 = cur->left;
		while (temp->right != NULL)
		{
			prev2 = temp;
			temp = temp->right;
		}
		cur->data = temp->data;
		prev2->right = temp->left;
		free(temp);
	}
	
}
void prevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << ' ';
	prevOrder(root->left);
	prevOrder(root->right);
}
void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left);
	cout << root->data << ' ';
	InOrder(root->right);
}
void BackOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BackOrder(root->left);
	BackOrder(root->right);
	cout << root->data << ' ';
}
int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
void setLevel(TreeNode* root,int level)
{
	if (root == NULL)
	{
		return;
	}
	root->level = level;
	setLevel(root->left, level + 1);
	setLevel(root->right, level + 1);
}
void PrintTree(TreeNode* root, int num)
{
	if (root == NULL)
	{
		return;
	}

	PrintTree(root->right, num);

	for (int i = root->level; i >= 1; i--)
	{
		cout << ' ';
	}
	cout << root->data << endl;
	if (root->level < num - 1)
	{
		cout << endl;
	}
	PrintTree(root->left, num);
}