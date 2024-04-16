#pragma once
#include<iostream>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
using namespace std;
//ջ
typedef struct point
{
	char now;
	int num;
	int time;
}point;
typedef point STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
void StackPrint(ST ps);

q);