#include"test.h"
//计算机目录树，也称为文件系统树，是计算机文件系统中的一个重要概念。
// 它是一种树状的数据结构，用于组织和管理计算机中的文件和目录。在目录树中，每个节点代表一个文件或目录，节点之间通过父子关系建立连接，形成树形结构。
//在典型的计算机文件系统中，根目录是位于顶层的根节点，所有其他文件和目录都是从根目录开始向下组织的。
// 用户可以在目录树中创建、删除、移动和复制文件和目录，以便更好地组织和管理计算机中的数据。
//目录树提供了一种类似于现实世界中文件柜、文件夹和文件的组织方式，使用户可以轻松地找到并访问他们所需的文件和目录。
// 通过不同的路径，用户可以有效地导航和浏览目录树，找到所需的文件或目录。
//目录树在计算机系统中起着非常重要的作用，是文件系统的基础。常见的文件系统如FAT、NTFS、EXT等，都是通过目录树这种数据结构来组织和管理文件数据的。
//通过理解和使用目录树，用户可以更好地管理自己的文件和数据，并有效地进行文件操作和数据查找。
int main()
{
	BTNode* node1 = CreateDirectory((char*)"level--1");
	BTNode* node2 = CreateDirectory((char*)"level--2");
	BTNode* node3 = CreateDirectory((char*)"level--3");

	insertDirectory(node1, node2);
	insertDirectory(node1, node3);

	char str[15];
	cout << "输入查询的目录：";
	cin >> str;
	BTNode* find = searchDirectory(node1, str);
	if (find)
	{
		cout << "found dicectory:" << find->data << endl;
	}
	else
	{
		cout << "not found";
	}

	cout << "Directory tree:"<<endl;
	traverseDirectory(node1);
	cout << endl;

	deleteDirectory(node1);
	node1 = NULL;

	return 0;
}