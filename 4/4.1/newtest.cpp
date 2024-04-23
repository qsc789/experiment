#include"test.h"
int index = 0;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

BTNode* buildTree(string preorder)
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (index < preorder.size())
	{
		if (preorder[index] == ' ')
		{
			index++;
			tmp = NULL;
			return tmp;
		}
		else
		{
			tmp->data = preorder[index];
			index++;
			tmp->left = buildTree(preorder);
			tmp->right = buildTree(preorder);
			return tmp;
		}
	}
	return tmp;


}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data;
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	InOrder(root->left);
	cout << root->data;
	InOrder(root->right);
}

void BackOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	BackOrder(root->left);
	BackOrder(root->right);
	cout << root->data;
}