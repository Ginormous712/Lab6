#ifndef  AVLTREE_H
#define AVLTREE_H
#include <string>
#include <iostream>
#include <stack>

#include <random>
using namespace std;
class AVLTree
{
	struct node 
	{
		string data;
		unsigned char height;
		node* left;
		node* right;
		node(string d) { data = d; left = right = 0; height = 1; }
	};
	unsigned char height(node* p);
	int bfactor(node* p);
	void fixheight(node* p);
	node* rotateright(node* p); 
	node* rotateleft(node* q); 
	node* balance(node* p); 
	node* insert(node* p, string data); 
	bool sizeData(string data1, string data2);
	node* removemin(node* p); 
	node* remove(node* p, string data); 
	node* findmin(node* p);
	void search(node* p, string data)
	{
		if (!p) return;
		if (sizeData(data, p->data))
			search(p->left, data);
		else if (!sizeData(data, p->data) && data != p->data)
			search(p->right, data);
		else //  k == p->key 
		{
			cout << p->data << endl;
		}
	}
	node* pRoot;
	int size;
	void _print(node* p);

	string add(string val);
	
	bool ifb(string data1, string data2);

	bool ifm(string data1, string data2);
	bool bs(string one, string two);
	
public:
	AVLTree(string data)
	{
		pRoot = new node(data);
		size = 1;
	}
	AVLTree()
	{
		pRoot = nullptr;
		size = 0;
	}
	void insertData(string data)
	{
		pRoot = insert(pRoot,data);
		size++;
	}

	void Print()
	{
		_print(pRoot);
	}
	void Remove(string value)
	{
		pRoot = remove(pRoot, value);
	}
	void search(string value)
	{
		search(pRoot,value);
	}
	void search(string value1, string value2)
	{
		string value = value1;
		while (bs(value, value2))
		{
			search(pRoot, value);
			value = add(value);
		}
		
	}
	void rd(int ii);
	
};
#endif // ! AVLTREE_H


