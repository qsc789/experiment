#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int SLDataType;

typedef struct seqlist
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListCheckCapacity(SL* ps);
void SeqListInsert(SL* ps,int pos, SLDataType x);
void SeqListDelete(SL* ps, int pos);
int SeqListFind(SL* ps, SLDataType x);
void SeqListPrint(SL* ps);