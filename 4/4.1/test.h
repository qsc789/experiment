#pragma once
#include<iostream>
#include<string>
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

BTNode* buildTree(string preorder);
void QueueInit(Queue* pq);

void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void BackOrder(BTNode* root);