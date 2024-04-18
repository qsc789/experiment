#pragma once
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
using namespace std;
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
	int level;
	int flag;
}BTNode;
typedef char QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QueueNode;
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;

}Queue;

BTNode* buildTree(string preorder,int level);
void QueueInit(Queue* pq);
void QueuePush(Queue* pq, QDataType temp);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
bool QueueEmpty(Queue* pq);
void PrintTree(BTNode* root,int num);
int maxDepth(BTNode* root);