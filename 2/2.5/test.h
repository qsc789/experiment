#pragma once
#include<iostream>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
using namespace std;
#define money 10;

typedef struct point
{
	char now;
	int num;
	int time;
	int trueTime;
}point;
typedef point STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps, int n);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
bool StackEmpty(ST* ps);
void StackPrint(ST ps);
bool StackFull(ST* ps);
//ѭ������

typedef point QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType temp;
}QueueNode;
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;

}Queue;
void QueueInit(Queue* pq);
void QueuePush(Queue* pq, QDataType temp);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue pq);