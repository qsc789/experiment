#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
using namespace std;

#define MAX_VERTICES 100
//邻接矩阵
//typedef struct graph
//{
//	int vertices[MAX_VERTICES][MAX_VERTICES];
//	int numVertices;
//}Graph;
//邻接链表
//typedef struct Node
//{
//	int vertex;
//	struct Node* next;
//}Node;
//typedef struct graph
//{
//	Node* adjList[MAX_VERTICES];
//	int numVertices;
//}Graph;
//typedef int QDataType;
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;
//	QueueNode* tail;
//
//}Queue;
//void QueueInit(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//bool QueueEmpty(Queue* pq);
//QDataType QueueFront(Queue* pq);
//void CreateGraph(Graph* G,int num);
//void addEdge(Graph* G,int head,int tail);
//void dfs(Graph* G, int start, bool visited[]);
//void bfs(Graph* G,int start);
//void printGraph(Graph* graph);
//
typedef int TDataType;
typedef struct TreeNode {
	TDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
	int level;
}TreeNode;

TreeNode* CreateTree(int x,TreeNode* root);//用插入来构建树
bool search(int flag,TreeNode* root,int num);
void deleteNode(TreeNode* root, int flag);
void prevOrder(TreeNode* root);
void InOrder(TreeNode* root);
void BackOrder(TreeNode* root);
int maxDepth(TreeNode* root);
void setLevel(TreeNode* root, int level);
void PrintTree(TreeNode* root, int num);


