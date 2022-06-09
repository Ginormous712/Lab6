#ifndef LISTIMPL_H
#define LISTIMPL_H
#include <string>
#include <iostream>
#include <stack>
#include <random>
using namespace std;
class ListImpl
{
	class Node
	{
	public:
		string data;
		Node* pNext;
		Node(string data, Node* pNext = 0)
		{
			this->data= data;
			this->pNext = pNext;
		}
	};
	Node* pRoot;
	int Size; 

	bool ifb(string data1, string data2);
	string add(string val);
	
	bool bs(string one, string two);
	
public:
	ListImpl()
	{
		pRoot = 0;
		Size = 0;
	}
	ListImpl(string data)
	{
		pRoot = new Node(data);
		Size = 0;
	}
	void insertData(string data);
	

	void Print();
	
	void Remove(string value);
	
	void search(string value);
	
	void search(string value1, string value2);
	
	void rf(int ii);
	
};

#endif // !LISTIMPL_H


