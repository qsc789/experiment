#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
using namespace std;
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;
typedef string BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	char data[15];

}BTNode;
BTNode* CreateDirectory(char name[]);
void insertDirectory(BTNode* parent, BTNode* child);
void deleteDirectory(BTNode* root);
void traverseDirectory(BTNode* root);
BTNode* searchDirectory(BTNode* root, char name[]);
//void QueueInit(Queue* pq);
//void QueueDestrory(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//QDataType QueueFront(Queue* pq);
//QDataType QueueBack(Queue* pq);
//int QueueSize(Queue* pq);
//bool QueueEmpty(Queue* pq);
//BTNode* BuildTree(string str,int* index);
//void PrevOrder(BTNode* root);
//void InOrder(BTNode* root);
//void PostOrder(BTNode* root);
