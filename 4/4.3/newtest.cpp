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
BTNode* buildTree(string preorder, int level)
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (index < preorder.size())
	{
		if (preorder[index] == '#')
		{
			index++;
			tmp = NULL;
			return tmp;
		}
		else
		{
			tmp->data = preorder[index];
			tmp->level = level;
			index++;
			tmp->left = buildTree(preorder, level + 1);
			tmp->right = buildTree(preorder, level + 1);
			
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
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq -> tail->temp;
//}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
QDataType QueueFront(Queue* pq)
{
	return (pq->head)->val;
}
void PrintTree(BTNode* root,int num)
{
	if (root == NULL)
	{
		//cout << endl;
		return;
	}
	
	PrintTree(root->right,num);
	
	for (int i = root->level; i >= 1; i--)
	{
		cout << ' ';
	}
	cout << root->data << endl;
	if (root->level < num-1)
	{
		cout << endl;
	}
	PrintTree(root->left,num);
}