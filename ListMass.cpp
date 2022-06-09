#include "ListMass.h"
#include <algorithm>
#include <array>
#include <string>
#include <iostream>
#include <random>
using namespace std;




string ListMass::add(string val)
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

bool ListMass::bs(string one, string two)
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

void ListMass::insertData(string data)
{
	if (!Size)
	{
		mass[0] = data;
		Size++;
		return;
	}
	if (Size + 1 <= MaxSize)
	{
		mass[Size] = data;
		Size++;
		sort(mass.begin(), mass.begin() + Size, compare);
		
	}
	
}

void ListMass::Print()
{
	for (int i = 0; i < Size; i++)
		cout << mass[i] << " ";
	cout << endl;
}

void ListMass::Remove(string value)
{
	for (int i = 0; i < Size; i++)	
		if (mass[i] == value)
		{
			for (int j = i; j < Size-1; j++)
				mass[j] = mass[j + 1];
			Size--;
			return;
		}
}

void ListMass::search(string value)
{
	for(int i = 0; i < Size;i++)
		if (mass[i] == value)
		{
			cout << mass[i] << endl;
			return;
		}
}

void ListMass::search(string value1, string value2)
{
	
	if (!Size) return;
	string value = value1;
	while (bs(value, value2))
	{
		search(value);
		value = add(value);
	}
}

void ListMass::rf(int ii)
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
