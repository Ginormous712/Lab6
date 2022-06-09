#pragma once
#include <string>
#include <iostream>
#include <random>
using namespace std;
struct _23Tree {
    int size;      
    string key [3];
    _23Tree* first;   // *first <= key[0];
    _23Tree* second;  // key[0] <= *second < key[1];
    _23Tree* third;   // key[1] <= *third < key[2];
    _23Tree* fourth;  
    _23Tree* pRoot;
    _23Tree* parent; 
    static bool ifb(string data1, string data2)
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
    static bool ifm_(string data1, string data2)
    {
        if (data1 == data2) return true;
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
    static bool ifb_(string data1, string data2)
    {
        if (data1 == data2) return true;
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
    static bool ifm(string data1, string data2)
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
    bool find(string k) {
        for (int i = 0; i < size; ++i)
            if (key[i] == k) return true;
        return false;
    }

    void swap(string& x, string& y) {
        string r = x;
        x = y;
        y = r;
    }

    void sort2(string& x, string& y) {
        if (ifb(x,y)) swap(x, y);
    }

    void sort3(string& x, string& y, string& z) {
        if (ifb(x, y)) swap(x, y);
        if (ifb(x, z)) swap(x, z);
        if (ifb(y, z)) swap(y, z);
    }

    void sort() { 
        if (size == 1) return;
        if (size == 2) sort2(key[0], key[1]);
        if (size == 3) sort3(key[0], key[1], key[2]);
    }

    void insert_to_node(string k) {  
        key[size] = k;
        size++;
        sort();
    }

    void remove_from_node(string k) { 
        if (size >= 1 && key[0] == k) {
            key[0] = key[1];
            key[1] = key[2];
            size--;
        }
        else if (size == 2 && key[1] == k) {
            key[1] = key[2];
            size--;
        }
    }

    void become_node2(string k, _23Tree* first_, _23Tree* second_) {  
        key[0] = k;
        key[1] = "0";
        key[2] = "0";
        first = first_;
        second = second_;
        third = nullptr;
        fourth = nullptr;
        parent = nullptr;
        size = 1;
    }

    bool is_leaf() { 
        return (first == nullptr) && (second == nullptr) && (third == nullptr);
    }
    void _print(_23Tree* p)
    {
        if (p)
        {
            if (p->first != nullptr) _print(p->first);
            if (p->key[0] != "0")cout << p->key[0] << " ";
            if (p->second != nullptr) _print(p->second);
            if (p->key[1] != "0")cout << p->key[1] << " ";
            if (p->third != nullptr) _print(p->third);
            if (p->key[2] != "0")cout << p->key[2] << " ";
            if (p->fourth != nullptr) _print(p->fourth);
        }
    }
    static string add(string val)
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

    bool bs(string one, string two)
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
    _23Tree* merge(_23Tree* leaf); 
    _23Tree* search_min(_23Tree* p); 
    _23Tree* redistribute(_23Tree* leaf); 
    _23Tree* split(_23Tree* item); 
    
    _23Tree* insert(_23Tree* p, string k); 
    _23Tree* search(_23Tree* p, string k); 
    _23Tree* remove(_23Tree* p, string k); 
    _23Tree* fix(_23Tree* leaf); 
public:
   
    _23Tree(string k) : size(1), first(nullptr), second(nullptr),
        third(nullptr), fourth(nullptr), parent(nullptr) {
        key[0] = k;
        key[1] = "0";
        key[2] = "0";
        pRoot = nullptr;
    }

    _23Tree(string k, _23Tree* first_, _23Tree* second_, _23Tree* third_, _23Tree* fourth_, _23Tree* parent_) :
        size(1), first(first_), second(second_),
        third(third_), fourth(fourth_), parent(parent_) {
        key[0] = k;
        key[1] = "0";
        key[2] = "0";
        pRoot = nullptr;
    }
    void cr(string data)
    {
        pRoot = new _23Tree(data);
        size = 1;
    }
    void Insert(string data)
    {
        pRoot->insert(pRoot, data);
        size++;
    }
    void print()
    {
        _print(pRoot);
    }
    void Remove(string value)
    {
        pRoot = remove(pRoot, value);
    }
    void Search(string value)
    {
        _23Tree* s = search(pRoot,value);
        if (s)
        {
            for (int i = 0; i < s->size; i++)
                if (s->key[i] == value)
                    cout <<"(" << value << ") ";
        }
        
    }
    void Search1(string value1, string value2)
    {
        string value3 = value1;
        
        while (bs(value3, value2))
        {
            this->Search(value3);
            value3 = add(value3);
           
        }
    }
    void rb(int ii)
    {

        random_device random_device;
        mt19937 generator(random_device());
        uniform_int_distribution<> distribution(65, 90);
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
            this->Insert(rw);
            rw.resize(0);
        }

        ///
    }
};

