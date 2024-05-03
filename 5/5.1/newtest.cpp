#include"test.h"
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    //assert(!QueueEmpty(pq));
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }


}
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    QueueNode* cur = pq->head->next;
    free(pq->head);
    pq->head = cur;
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
int QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}
void CreateGraph(Graph* G, int num)
{
	G->numVertices = num;
    for (int i = 0; i < num; i++)
    {
        G->adjList[i] = NULL;
    }
}
void addEdge(Graph* G,int head,int tail)
{
	Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->vertex = tail;
    newNode1->next = G->adjList[head];
    G->adjList[head] = newNode1;

    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->vertex = head;
    newNode2->next = G->adjList[tail];
    G->adjList[tail] = newNode2;
}
void dfs(Graph* G,int start,bool visited[])
{
    visited[start] = true;
    cout << start << endl;

    Node* temp = G->adjList[start];
    while (temp != NULL)
    {
        int num = temp->vertex;
        if (visited[num]!=true)
        {
            dfs(G, num, visited);
         }
        temp = temp->next;
    }
}
void bfs(Graph* G,int start)
{
    bool visited[MAX_VERTICES] = { false };
    Queue q;
    QueueInit(&q);
    QueuePush(&q, start);
    visited[start] = true;
    cout << start << endl;
    while (!QueueEmpty(&q))
    {
        int num = QueueFront(&q);
        QueuePop(&q);
        Node* temp = G->adjList[num];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = true;
                cout << temp->vertex << endl;

                QueuePush(&q,temp->vertex);
            }
            temp = temp->next;
        }
    }
}
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        printf("Adjacency list of vertex %d\n", i);

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

