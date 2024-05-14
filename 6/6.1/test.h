#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
using namespace std;


typedef int TDataType;
typedef struct TreeNode {
	TDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
	int level;
}TreeNode;

TreeNode* CreateTree(int x,TreeNode* root);//�ò�����������
bool search(int flag,TreeNode* root,int num);
void deleteNode(TreeNode* root, int flag);
void prevOrder(TreeNode* root);
void InOrder(TreeNode* root);
void BackOrder(TreeNode* root);
int maxDepth(TreeNode* root);
void setLevel(TreeNode* root, int level);
void PrintTree(TreeNode* root, int num);


