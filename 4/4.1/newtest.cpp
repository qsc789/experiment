#include"test.h"
int index = 0;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
int maxDepth(BTNode* root) {
	if (root == NULL)
		return 0;
	int leftDepth = maxDepth(root->left);//��¼һ�£���ֹʱ�䳬��
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//ȡ�ϴ��һ��
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
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->val = x;
	newnode->val = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
		newnode->next = pq->head;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
		//pq->tail->next = pq->head;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
QDataType QueueFront(Queue* pq)
{
	return (pq->head)->val;
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