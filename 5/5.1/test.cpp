#include"test.h"
//输入
// 6 
// 5
//0 1
//0 2
//1 3
//1 4
//2 5

int main()
{
	int num,num1;
	cout << "输入节点个数：";
	cin >> num;
	Graph G;
	CreateGraph(&G,num);
	cout << "输入边的个数：";
	cin >> num1;
	cout << "依次输入边的头和尾：" << endl;
	for (int i = 1; i <= num1; i++)
	{
		int head, tail;
		cin >> head >> tail;
		addEdge(&G, head, tail);

	}
	printGraph(&G);
	bool visited[MAX_VERTICES] = { false };
	cout << "dfs:" << endl;
	dfs(&G, 0, visited);
	cout << "bfs:" << endl;
	bfs(&G, 0);

}
