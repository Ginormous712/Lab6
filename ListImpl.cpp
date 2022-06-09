#include "ListImpl.h"


#include <string>
#include <iostream>
#include <random>
using namespace std;
bool ListImpl::ifb(string data1, string data2)
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

string ListImpl::add(string val)
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

bool ListImpl::bs(string one, string two)
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

void ListImpl::insertData(string data)
{
	if (!pRoot)
	{
		pRoot = new Node(data);
		Size++;
		return;
	}
	Node* current(pRoot), * preCur(pRoot);
	if (ifb(data, current->data))
	{
		while (current->pNext != 0)
		{
			if (ifb(data, current->pNext->data))
			{
				current = current->pNext;
			}
			else
			{
				current->pNext = new Node(data, current->pNext);
				Size++;
				return;
			}
		}
		current->pNext = new Node(data);
		Size++;
		return;
	}
	else
	{
		pRoot = new Node(data, current);
		Size++;

	}

}

void ListImpl::Print()
{

	for (Node* curr = pRoot; curr != 0; curr = (curr->pNext != 0) ? (curr->pNext) : 0)
	{
		cout << curr->data << " ";
	}
	cout << endl;
}

void ListImpl::Remove(string value)
{
	if (pRoot == 0) return;
	Node* current = pRoot;
	if (current->data == value)
	{
		if (pRoot->pNext != 0)
			pRoot = pRoot->pNext;
		else
			pRoot = 0;
		Size--;
		delete current;
		return;
	}
	while (current->pNext != 0)
	{
		if (current->pNext->data == value)
		{
			if (current->pNext != 0)
			{
				current->pNext = current->pNext->pNext;
				Size--;
				return;
			}
			else
			{
				current->pNext = 0;
				Size--;
				return;
			}

		}
		current = current->pNext;
	}
}

void ListImpl::search(string value)
{
	if (pRoot == 0) return;
	Node* current = pRoot;
	if (current->data == value)
	{
		cout << current->data << endl;
	}
	while (current->pNext != 0)
	{
		if (current->pNext->data == value)
		{
			cout << current->pNext->data << endl;
		}
		current = current->pNext;
	}
}
void ListImpl::search(string value1, string value2)
{
	if (pRoot == 0) return;
	string value = value1;
	while (bs(value, value2))
	{
		search(value);
		value = add(value);
	}
}

void ListImpl::rf(int ii)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(65, 90);
	int n = distribution(generator);
	Size += ii;
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
