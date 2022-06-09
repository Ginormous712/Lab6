#include "BinaryTree.h"
#include <iostream>
#include <array>
#include <string>
#include <stack>
#include <random>
using namespace std;
string BinaryTree::add(string val)
{
	int loc;
	for (int i = val.size() - 1; i >= 0; i--)
	{
		loc = val[i];
		loc++;
		if (loc == 91)
		{
			loc = 97;
			val[i] = loc;
			return val;
		}

		if ((loc < 65 || loc > 90) && (loc < 97 || loc > 122))
		{
			loc = 65;
			val[i] = loc;
			continue;
		}

		val[i] = loc;
		return val;
	}
	val.insert(val.begin(), 'A');
	return val;
}

bool BinaryTree::bs(string one, string two)
{
	if (one.size() < two.size())
		return true;
	for (int i = 0; i < one.size(); i++)
	{
		if (one[i] < two[i]) return true;
		if (one[i] > two[i]) return false;
	}
	return false;
}

bool BinaryTree::ifb(string data1, string data2)
{
	if (data1 == data2) return false;
	if (data1.size() < data2.size())
	{
		int size = data1.size();
		data1.resize(data2.size());
		for (int i = size; i < data2.size(); i++)
			data1[i] = '0';
	}
	else if (data1.size() > data2.size())
	{
		int size = data2.size();
		data2.resize(data1.size());
		for (int i = size; i < data1.size(); i++)
			data2[i] = '0';
	}

	for (int i = 0; i < data2.size(); i++)
	{
		if ((int)data1[i] > (int)data2[i])
			return true;
		else if ((int)data1[i] < (int)data2[i])
			return false;
	}


	return false;
}

bool BinaryTree::ifm(string data1, string data2)
{
	if (data1 == data2) return false;
	if (data1.size() < data2.size())
	{
		int size = data1.size();
		data1.resize(data2.size());
		for (int i = size; i < data2.size(); i++)
			data1[i] = '0';
	}
	else if (data1.size() > data2.size())
	{
		int size = data2.size();
		data2.resize(data1.size());
		for (int i = size; i < data1.size(); i++)
			data2[i] = '0';
	}

	for (int i = 0; i < data2.size(); i++)
	{
		if ((int)data1[i] < (int)data2[i])
			return true;
		else if ((int)data1[i] > (int)data2[i])
			return false;
	}


	return false;
}

void BinaryTree::insert(Node*p,string data)
{

	if (ifm(data, p->data))
	{
		if (!p->left)
			p->left = new Node(data);
		else
			insert(p->left, data);
	}

	else
	{
		if(!p->right)
			p->right = new Node(data);
		else
			insert(p->right, data);

	}
}

BinaryTree::Node* BinaryTree::_remove(Node* p, string data)
{
	
	if (!p) return 0;
	if (ifm(data, p->data))
		p->left = _remove(p->left, data);
	else if (ifb(data, p->data))
		p->right = _remove(p->right, data);
	else 
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r) return q;
		Node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return new Node(min->data, min->left, min->right);
	}
	return new Node(p->data, p->left, p->right);
}

BinaryTree::Node* BinaryTree::removemin(Node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return p;
}

BinaryTree::Node* BinaryTree::findmin(Node* p)
{
	return p->left ? findmin(p->left) : p;
}

void BinaryTree::Print()
{
	if(pRoot)
		_print(pRoot);
}

void BinaryTree::Remove(string value)
{
	if (pRoot)
	{
		_remove(pRoot, value);

	}
}

void BinaryTree::search(string value)
{
	search(pRoot, value);
}

void BinaryTree::search(string value1, string value2)
{
	string value = value1;
	while (bs(value, value2))
	{
		search(pRoot, value);
		value = add(value);
	}
}

void BinaryTree::rf(int ii)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(65, 90);
	int n = distribution(generator);

	string rw;
	int len;
	for (int i = 0; i < ii; i++)
	{
		len = 1 + rand() % 3;
		for (int j = 0; j < len; j++)
		{

			int n = distribution(generator);
			rw.push_back(n);

		}
		this->insertData(rw);
		rw.resize(0);
	}
}
