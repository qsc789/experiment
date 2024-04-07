#pragma once
#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int SLTDataType;
typedef struct SListNode
{
	int num;
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuyListNode(int num,SLTDataType data);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, int num, SLTDataType data);
//void SListPushFront(SLTNode** pphead, SLTDataType x);
//void SListPopBack(SLTNode** pphead);
//void SListPopFront(SLTNode** pphead);
//SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//void SListInsertAfter(SLTNode* pos, SLTDataType x);

//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//void SListEraseAfter(SLTNode* pos);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListDestroy(SLTNode** pphead);