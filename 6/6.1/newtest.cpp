#include"test.h"

//void QueueInit(Queue* pq)
//{
//    assert(pq);
//    pq->head = NULL;
//    pq->tail = NULL;
//}
//void QueuePush(Queue* pq, QDataType x)
//{
//    assert(pq);
//    //assert(!QueueEmpty(pq));
//    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//    newnode->data = x;
//    newnode->next = NULL;
//    if (pq->head == NULL)
//    {
//        pq->head = pq->tail = newnode;
//    }
//    else
//    {
//        pq->tail->next = newnode;
//        pq->tail = newnode;
//    }
//
//
//}
//void QueuePop(Queue* pq)
//{
//    assert(pq);
//    assert(!QueueEmpty(pq));
//    QueueNode* cur = pq->head->next;
//    free(pq->head);
//    pq->head = cur;
//    if (pq->head == NULL)
//    {
//        pq->tail = NULL;
//    }
//
//}
//bool QueueEmpty(Queue* pq)
//{
//    assert(pq);
//    return pq->head == NULL;
//}
//int QueueFront(Queue* pq)
//{
//    assert(pq);
//    assert(!QueueEmpty(pq));
//    return pq->head->data;
//}
//void CreateGraph(Graph* G, int num)
//{
//	G->numVertices = num;
//    for (int i = 0; i < num; i++)
//    {
//        G->adjList[i] = NULL;
//    }
//}
//void addEdge(Graph* G,int head,int tail)
//{
//	Node* newNode1 = (Node*)malloc(sizeof(Node));
//    newNode1->vertex = tail;
//    newNode1->next = G->adjList[head];
//    G->adjList[head] = newNode1;
//
//    Node* newNode2 = (Node*)malloc(sizeof(Node));
//    newNode2->vertex = head;
//    newNode2->next = G->adjList[tail];
//    G->adjList[tail] = newNode2;
//}
//void dfs(Graph* G,int start,bool visited[])
//{
//    visited[start] = true;
//    cout << start << endl;
//
//    Node* temp = G->adjList[start];
//    while (temp != NULL)
//    {
//        int num = temp->vertex;
//        if (visited[num]!=true)
//        {
//            dfs(G, num, visited);
//         }
//        temp = temp->next;
//    }
//}
//void bfs(Graph* G,int start)
//{
//    bool visited[MAX_VERTICES] = { false };
//    Queue q;
//    QueueInit(&q);
//    QueuePush(&q, start);
//    visited[start] = true;
//    cout << start << endl;
//    while (!QueueEmpty(&q))
//    {
//        int num = QueueFront(&q);
//        QueuePop(&q);
//        Node* temp = G->adjList[num];
//        while (temp != NULL)
//        {
//            if (!visited[temp->vertex])
//            {
//                visited[temp->vertex] = true;
//                cout << temp->vertex << endl;
//
//                QueuePush(&q,temp->vertex);
//            }
//            temp = temp->next;
//        }
//    }
//}
//void printGraph(Graph* graph) {
//    for (int i = 0; i < graph->numVertices; i++) {
//        Node* temp = graph->adjList[i];
//        printf("Adjacency list of vertex %d\n", i);
//
//        while (temp != NULL) {
//            printf("%d -> ", temp->vertex);
//            temp = temp->next;
//        }
//        printf("NULL\n");
//    }
//}
//
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