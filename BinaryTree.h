#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <array>
#include <string>
#include <stack>
#include <random>
using namespace std;
class BinaryTree
{
	struct Node
	{
		string data;
		Node* left;
		Node* right;
		Node(string d) { data = d; left = right = 0; }
		Node(string d, Node* left, Node* right) { data = d; this->left = left; this->right = right; }

	};
	void _print(Node* p)
	{
		if (p->left != 0)
			_print(p->left);
		cout << "(" << p->data << ")";
		if (p->right != 0)
			_print(p->right);
		return;
	}
	void search(Node* p, string data)
	{
		if (!p) return;
		if (ifm(data, p->data))
			search(p->left, data);
		else if (ifb(data, p->data))
			search(p->right, data);
		else 
		{
			cout << p->data << endl;
		}
	}
	Node* pRoot;
	string add(string val);
	bool bs(string one, string two);
	bool ifb(string data1, string data2);
	bool ifm(string data1, string data2);
	void insert(Node* p, string data);
	Node* _remove(Node* p, string data);
	Node* removemin(Node* p);
	Node* findmin(Node* p);
public:
	BinaryTree()
	{
		pRoot = nullptr;
	}
	void insertData(string data)
	{
		if (!pRoot)
			pRoot = new Node(data);
		else 
			insert(pRoot, data);
	}
	void Print();
	void Remove(string value);
	void search(string value);
	void search(string value1, string value2);
	void rf(int ii);
};
#endif // !BINARYTREE_H


