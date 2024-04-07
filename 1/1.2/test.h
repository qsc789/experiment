#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int SLDataType;
typedef struct city
{
	string CityName;
	int x;
	int y;
}city;
typedef struct seqlist
{
	vector<city> a;

}SL;

void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, string name, int x, int y);
void SeqListInsert(SL* ps, int pos, string str, int x, int y);
void SeqListDelete(SL* ps, int pos);
void SeqListFindByName(SL* ps, string str);
void SeqListFindByPlace(SL* ps, int x, int y);
void SeqListPrint(SL* ps);
void FindCity(SL* ps, int tx, int ty, int D);