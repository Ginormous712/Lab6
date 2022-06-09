#include "AVLTree.h"

unsigned char AVLTree::height(node* p)
{
	return p ? p->height : 0;
}

int AVLTree::bfactor(node* p)
{
	return height(p->right) - height(p->left);
}



AVLTree::node* AVLTree::rotateright(node* p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

void AVLTree::fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;

}

AVLTree::node* AVLTree::rotateleft(node* q)
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

AVLTree::node* AVLTree::balance(node* p)
{
	fixheight(p);

	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

AVLTree::node* AVLTree::insert(node* p, string data)
{
	if (!p) return new node(data);
	if (sizeData(data, p->data))
		p->left = insert(p->left, data);
	else
		p->right = insert(p->right, data);
	return balance(p);
}

bool AVLTree::sizeData(string data1, string data2)
{
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


AVLTree::node* AVLTree::removemin(node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

AVLTree::node* AVLTree::remove(node* p, string data)
{
	if (!p) return 0;
	if (ifm(data, p->data))
		p->left = remove(p->left, data);
	else if (ifb(data, p->data))
		p->right = remove(p->right, data);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

AVLTree::node* AVLTree::findmin(node* p)
{
	return p->left ? findmin(p->left) : p;
}

void AVLTree::_print(node* p)
{
	if (p->left != 0)
		_print(p->left);
	cout << "(" << p->data << ")";
	if (p->right != 0)
		_print(p->right);
	return;
}

string AVLTree::add(string val)
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

bool AVLTree::ifb(string data1, string data2)
{
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
}

bool AVLTree::ifm(string data1, string data2)
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

bool AVLTree::bs(string one, string two)
{
	int sum1(0), sum2(0);
	for (int i = 0; i < one.size(); i++)
		sum1 += one[i];
	for (int i = 0; i < two.size(); i++)
		sum2 += two[i];
	if (sum1 < sum2)return true;
	return false;
}

void AVLTree::rd(int ii)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(65, 90);
	string rw;
	int len;
	size = ii;
	for (int i = 0; i < ii; i++)
	{
		len = 1 + rand() % 3;
		for (int j = 0; j < len; j++)
		{
			int n = distribution(generator);
			rw.push_back(n);

		}
		pRoot = this->insert(pRoot, rw);
		rw.resize(0);
	}
}