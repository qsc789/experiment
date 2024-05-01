#include"test.h"
BTNode* CreateDirectory(char name[])
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	strncpy_s(newnode->data, name, sizeof(newnode->data));
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void insertDirectory(BTNode* parent, BTNode* child)
{
	//放双亲节点左边
	if (parent->left == NULL)
	{
		parent->left = child;
	}
	else//左边不为空放最右边
	{
		BTNode* cur = parent->left;
		while (cur->right != NULL)
		{
			cur = cur->right;
		}
		cur->right = child;
	}
}
void deleteDirectory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	deleteDirectory(root->left);
	deleteDirectory(root->right);
	free(root);

}
void traverseDirectory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	traverseDirectory(root->left);	
	cout << root->data << endl;
	traverseDirectory(root->right);

}
BTNode* searchDirectory(BTNode* root, char name[])
{
	if (root == NULL)
	{
		return NULL;
	}
	if (strcmp(root->data,name)==0)
	{
		return root;
	}
	BTNode* find = searchDirectory(root->left,name);
	if (find == NULL)
	{
		find = searchDirectory(root->right, name);
	}
	return find;

}
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->head = NULL;
//}
//void QueueDestrory(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	newnode->data = x;
//	newnode->next = NULL;
//	if (pq->head == NULL)
//	{
//		pq->head = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	if (pq->head == NULL)
//	{
//		pq->tail = NULL;
//	}
//	
//}
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//
//}
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	int n = 0;
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		n++;
//		cur = cur->next;
//	}
//	return n;
//}
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head;
//}
//BTNode* BuildTree(string str,int* index)
//{
//
//	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
//	if ((*index) <str.size())
//	{
//		if (str[*index] == ' ')
//		{
//			(*index)++;
//			tmp = NULL;
//			return tmp;
//		}
//		else
//		{
//			tmp->data = str[(*index)];
//			(*index)++;
//			tmp->left = BuildTree(str, index);
//			tmp->right = BuildTree(str, index);
//
//			return tmp;
//		}
//	}
//	return tmp;
//}
//void PrevOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	cout<<root->data;
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//}
//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		
//		return;
//	}
//
//	InOrder(root->left);
//	cout << root->data;
//	InOrder(root->right);
//}
//void PostOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		
//		return;
//	}
//
//	PostOrder(root->left);
//	PostOrder(root->right);
//	cout << root->data;
//}
