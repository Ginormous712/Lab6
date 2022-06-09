#ifndef LISTMASS_H

#define LISTMASS_H
#include <iostream>
#include <array>
#include <string>
#include <stack>
#include <random>
using namespace std;
class ListMass
{	
	const int MaxSize = 1000;
	array<string,1000> mass{};
	int Size;
	string add(string val);
	bool bs(string one, string two);
	static bool compare(string data1, string data2)
	{
		if (data1[0] == 0 || data2[0] == 0) return false;
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
				return false;
			else if ((int)data1[i] < (int)data2[i])
				return true;
		}
		return false;
	}
public:
	ListMass(string data)
	{
		this->mass[0] = data;
		Size = 1;
	}
	ListMass()
	{
		Size = 0;
	}
	void insertData(string data);
	void Print();
	void Remove(string value);
	void search(string value);
	void search(string value1, string value2);
	void rf(int ii);
};

#endif // !LISTMASS_H


