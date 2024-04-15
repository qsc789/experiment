#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int LTDataType;
//int temp = 0;
//int front = 0;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;

}LTNode;

LTNode* ListInit();
//void ListPrint(LTNode* phead);
LTNode* BuyListNode(LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void add(LTNode* num1, LTNode* num2, int n);
void subtract(LTNode* num1, LTNode* num2);
void printres();
//LTNode* res = ListInit();