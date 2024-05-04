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
	int flag;
	Graph G;
	cout << "*******************************************" << endl;
	cout << "   输入1----------------------图的建立" << endl;
	cout << "   输入2-----------------深度优先遍历图" << endl;
	cout << "   输入3-----------------广度优先遍历图" << endl;
	cout << "   输入0--------------------------结束" << endl;
	cout << "*******************************************" << endl;
	while (scanf_s("%d", &flag) != EOF)
	{

		if (flag != 0)
		{
			switch (flag)
			{
			case 1:
			{
				int num, num1;
				cout << "输入节点个数：";
				cin >> num;

				CreateGraph(&G, num);
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
			}
			break;
			case 2:
			{
				bool visited[MAX_VERTICES] = { false };
				cout << "dfs:" << endl;
				dfs(&G, 0, visited);
			}
			break;
			case 3:
			{
				cout << "bfs:" << endl;
				bfs(&G, 0);
			}
			break;
			}

		}
		else
		{
			break;
		}

	}
	return 0;
}
