#include <iostream>
#include <array>
#include <vector>
#include <ctime>
#include "AVLTree.h"
#include "BinaryTree.h"
#include "ListImpl.h"
#include "ListMass.h"
#include "_23Tree.h"
#include <conio.h>
#include <Windows.h>
using namespace std;
void test1();
void test2();
void test3();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int r = 0;
	while (1)
	{
		std::cout << "������ ������:\n";
		std::cout << "1.	������������� ��������� �����\n";
		std::cout << "2.	��������������� �����\n";
		std::cout << "3.	��������\n";
		std::cout << "4.	����� �� ���������\n";
		r = _getch() - 48;
		if (r == 1)
		{
			test1();

		}
		else if (r == 2)
		{
			test2();
		}
		else if (r == 3)
		{
			test3();
		}
		else if (r == 4)
			break;
	}
}

void test1()
{
	int r = 0;
	while (1)
	{
		std::cout << "\n��������\n\t\t1.	������� ������ \n";
		std::cout << "\t\t2.	������ �� ����� ������ \n";
		std::cout << "\t\t3.	������� ������ ������ \n";
		std::cout << "\t\t4.	���-������ \n";
		std::cout << "\t\t5.	2-3 ������ \n";
		std::cout << "\t\t6.	����� \n";
		r = _getch() - 48;
		
		if (r == 1)
		{
			ListImpl *List = new ListImpl{};
			while (true)
			{
				std::cout << "\n\t\t1.	������ ������� \n";
				std::cout << "\t\t2.	�������� ������� \n";
				std::cout << "\t\t3.	������ �� ��������� \n";
				std::cout << "\t\t4.	������ �� ��������� �������  \n";
				std::cout << "\t\t5.	�������� �������� \n";
				std::cout << "\t\t6.	���� ��������� A < AA < AB < B \n";
				std::cout << "\t\t7.	����� \n";
				r = _getch() - 48;
				if (r == 1)
				{
					while (true)
					{
						std::cout << "\n\t\t�������(��� ������ �� �������) \n";
						string el;
						cin >> el;
						List->insertData(el);
						std::cout << "\n\t\tExit? 1|0\n";
						if (_getch() - 48 == 1) break;

					}
				}
				else if (r == 2)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					List->Remove(el);

				}
				else if (r == 3)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					std::cout <<"������� ��������: ";
					List->search(el);
					std::cout << endl;
				}
				if (r == 4)
				{
					std::cout << "\n\t\t�������";
					string el1,el2;
					cin >> el1;
					std::cout << "\n\t\t����� (�� �������) ";
					cin >> el2;
					std::cout << "������� ��������: ";
					List->search(el1,el2);
					std::cout << endl;

				}
				else if (r == 5)
				{
					std::cout << "\n\t\t�������: ";
					int count;
					cin >> count;
					List->rf(count);
				}
				else if (r == 6)
				{
					List->Print();
					std::cout << endl;
				}
				else if (r == 7)
				{
					break;
				}
				else continue;
			}

		}
		else if (r == 2)
		{
			ListMass* List = new ListMass{};
			while (true)
			{
				std::cout << "\n\t\t1.	������ ������� \n";
				std::cout << "\t\t2.	�������� ������� \n";
				std::cout << "\t\t3.	������ �� ��������� \n";
				std::cout << "\t\t4.	������ �� ��������� �������  \n";
				std::cout << "\t\t5.	�������� �������� \n";
				std::cout << "\t\t6.	���� ��������� A < AA < AB < B \n";
				std::cout << "\t\t7.	����� \n";
				r = _getch() - 48;
				if (r == 1)
				{
					while (true)
					{
						std::cout << "\n\t\t�������(��� ������ �� �������) \n";
						string el;
						cin >> el;
						List->insertData(el);
						std::cout << "\n\t\tExit? 1|0\n";
						if (_getch() - 48 == 1) break;

					}
				}
				else if (r == 2)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					List->Remove(el);

				}
				else if (r == 3)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					std::cout << "������� ��������: ";
					List->search(el);
					std::cout << endl;
				}
				if (r == 4)
				{
					std::cout << "\n\t\t�������";
					string el1, el2;
					cin >> el1;
					std::cout << "\n\t\t����� (�� �������) ";
					cin >> el2;
					std::cout << "������� ��������: ";
					List->search(el1, el2);
					std::cout << endl;

				}
				else if (r == 5)
				{
					std::cout << "\n\t\t�������: ";
					int count;
					cin >> count;
					List->rf(count);
				}
				else if (r == 6)
				{
					List->Print();
					std::cout << endl;
				}
				else if (r == 7)
				{
					break;
				}
				else continue;
			}
		}
		else if (r == 3)
		{
			BinaryTree *List = new BinaryTree{};
			while (true)
			{
				std::cout << "\n\t\t1.	������ ������� \n";
				std::cout << "\t\t2.	�������� ������� \n";
				std::cout << "\t\t3.	������ �� ��������� \n";
				std::cout << "\t\t4.	������ �� ��������� �������  \n";
				std::cout << "\t\t5.	�������� �������� \n";
				std::cout << "\t\t6.	���� ��������� A < AA < AB < B \n";
				std::cout << "\t\t7.	����� \n";
				r = _getch() - 48;
				if (r == 1)
				{
					while (true)
					{
						std::cout << "\n\t\t�������(��� ������ �� �������) \n";
						string el;
						cin >> el;
						List->insertData(el);
						std::cout << "\n\t\tExit? 1|0\n";
						if (_getch() - 48 == 1) break;

					}
				}
				else if (r == 2)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					List->Remove(el);

				}
				else if (r == 3)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					std::cout << "������� ��������: ";
					List->search(el);
					std::cout << endl;
				}
				if (r == 4)
				{
					std::cout << "\n\t\t�������";
					string el1, el2;
					cin >> el1;
					std::cout << "\n\t\t����� (�� �������) ";
					cin >> el2;
					std::cout << "������� ��������: ";
					List->search(el1, el2);
					std::cout << endl;

				}
				else if (r == 5)
				{
					std::cout << "\n\t\t�������: ";
					int count;
					cin >> count;
					List->rf(count);
				}
				else if (r == 6)
				{
					List->Print();
					std::cout << endl;
				}
				else if (r == 7)
				{
					break;
				}
				else continue;
			}
		}
		if (r == 4)
		{
			
			AVLTree *List = new AVLTree{};
			while (true)
			{
				std::cout << "\n\t\t1.	������ ������� \n";
				std::cout << "\t\t2.	�������� ������� \n";
				std::cout << "\t\t3.	������ �� ��������� \n";
				std::cout << "\t\t4.	������ �� ��������� �������  \n";
				std::cout << "\t\t5.	�������� �������� \n";
				std::cout << "\t\t6.	���� ��������� A < AA < AB < B \n";
				std::cout << "\t\t7.	����� \n";
				r = _getch() - 48;
				if (r == 1)
				{
					while (true)
					{
						std::cout << "\n\t\t�������(��� ������ �� �������) \n";
						string el;
						cin >> el;
						List->insertData(el);
						std::cout << "\n\t\tExit? 1|0\n";
						if (_getch() - 48 == 1) break;

					}
				}
				else if (r == 2)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					List->Remove(el);

				}
				else if (r == 3)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					std::cout << "������� ��������: ";
					List->search(el);
					std::cout << endl;
				}
				if (r == 4)
				{
					std::cout << "\n\t\t�������";
					string el1, el2;
					cin >> el1;
					std::cout << "\n\t\t����� (�� �������) ";
					cin >> el2;
					std::cout << "������� ��������: ";
					List->search(el1, el2);
					std::cout << endl;

				}
				else if (r == 5)
				{
					std::cout << "\n\t\t�������: ";
					int count;
					cin >> count;
					List->rd(count);
				}
				else if (r == 6)
				{
					List->Print();
					std::cout << endl;
				}
				else if (r == 7)
				{
					break;
				}
				else continue;
			}
		}
		else if (r == 5)
		{
			_23Tree *List = new _23Tree("A");
			List->cr("0");
			while (true)
			{
				std::cout << "\n\t\t1.	������ ������� \n";
				std::cout << "\t\t2.	�������� ������� \n";
				std::cout << "\t\t3.	������ �� ��������� \n";
				std::cout << "\t\t4.	������ �� ��������� �������  \n";
				std::cout << "\t\t5.	�������� �������� \n";
				std::cout << "\t\t6.	���� ��������� A < AA < AB < B \n";
				std::cout << "\t\t7.	����� \n";
				r = _getch() - 48;
				if (r == 1)
				{
					while (true)
					{
						std::cout << "\n\t\t�������(��� ������ �� �������) \n";
						string el;
						cin >> el;
						List->Insert(el);
						std::cout << "\n\t\tExit? 1|0\n";
						if (_getch() - 48 == 1) break;

					}
				}
				else if (r == 2)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					List->Remove(el);

				}
				else if (r == 3)
				{
					std::cout << "\n\t\t������� \n";
					string el;
					cin >> el;
					std::cout << "������� ��������: ";
					List->Search(el);
					std::cout << endl;
				}
				if (r == 4)
				{
					std::cout << "\n\t\t�������";
					string el1, el2;
					cin >> el1;
					std::cout << "\n\t\t����� (�� �������) ";
					cin >> el2;
					std::cout << "������� ��������: ";
					List->Search1(el1, el2);
					std::cout << endl;

				}
				else if (r == 5)
				{
					std::cout << "\n\t\t�������: ";
					int count;
					cin >> count;
					List->rb(count);
				}
				else if (r == 6)
				{
					List->print();
					std::cout << endl;
				}
				else if (r == 7)
				{
					break;
				}
				else continue;
			}
		}
		else if (r == 6)
		{
			break;
		}
		else
		{
			continue;
		}
	}
}

void test2()
{

	{
		ListImpl* List = new ListImpl{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t�������� ������� AA\n";
		List->Remove("AA");
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";
		List->search("AB");
		std::cout << "\t\t������ �� ��������� �������  A CC\n";
		List->search("A","CC");
		std::cout << "\t\t�������� �������� 20\n";
		List->rf(20);
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t2.	������ �� ����� ������ \n";
	
	{
		ListMass* List = new ListMass{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t�������� ������� AA\n";
		List->Remove("AA");
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";
		List->search("AB");
		std::cout << "\t\t������ �� ��������� �������  A CC\n";
		List->search("A", "CC");
		std::cout << "\t\t�������� �������� 20\n";
		List->rf(20);
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t3.	������� ������ ������ \n";

	{
		BinaryTree* List = new BinaryTree{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t�������� ������� AA\n";
		List->Remove("AA");
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";
		List->search("AB");
		std::cout << "\t\t������ �� ��������� �������  A CC\n";
		List->search("A", "CC");
		std::cout << "\t\t�������� �������� 20\n";
		List->rf(20);
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t4.	���-������ \n";

	{
		AVLTree* List = new AVLTree{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t�������� ������� AA\n";
		List->Remove("AA");
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";
		List->search("AB");
		std::cout << "\t\t������ �� ��������� �������  A CC\n";
		List->search("A", "CC");
		std::cout << "\t\t�������� �������� 20\n";
		List->rd(20);
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t5.	2-3 ������ \n";
	{
		_23Tree* List = new _23Tree("A");
		List->cr("0");
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->Insert("A");
		List->Insert("AA");
		List->Insert("AB");
		List->Insert("B");
		List->Insert("BD");
		List->Insert("D");
		List->Insert("E");
		std::cout << "\t\t���� ���������\n";
		List->print();
		std::cout << endl;
		std::cout << "\t\t�������� ������� AA\n";
		List->Remove("AA");
		std::cout << "\t\t���� ��������� \n";
		List->print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";
		List->Search("AB");
		std::cout << "\t\t������ �� ��������� �������  A CC\n";
		List->Search1("A", "CC");
		std::cout << "\t\t�������� �������� 20\n";
		List->rb(20);
		std::cout << "\t\t���� ��������� \n";
		List->print();
		std::cout << endl;
	}
	
	
}
void test3()
{

	unsigned int start_time, end_time;

	{
		ListImpl* List = new ListImpl{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		start_time = clock();
	
		List->Print();

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t�������� ������� AA\n";
		start_time = clock();
		List->Remove("AA");
		
		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";

		start_time = clock();
		List->search("AB");
		
		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t������ �� ��������� �������  A CC\n";

		start_time = clock();
		List->search("A", "CC");
		
		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t�������� �������� 20\n";
		start_time = clock();
		List->rf(20);
		
		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t2.	������ �� ����� ������ \n";

	{
		ListMass* List = new ListMass{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		start_time = clock();

		List->Print();

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t�������� ������� AA\n";
		start_time = clock();
		List->Remove("AA");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";

		start_time = clock();
		List->search("AB");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t������ �� ��������� �������  A CC\n";

		start_time = clock();
		List->search("A", "CC");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t�������� �������� 20\n";
		start_time = clock();
		List->rf(20);

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t3.	������� ������ ������ \n";

	{
		BinaryTree* List = new BinaryTree{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		start_time = clock();

		List->Print();

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t�������� ������� AA\n";
		start_time = clock();
		List->Remove("AA");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";

		start_time = clock();
		List->search("AB");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t������ �� ��������� �������  A CC\n";

		start_time = clock();
		List->search("A", "CC");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t�������� �������� 20\n";
		start_time = clock();
		List->rf(20);

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t4.	���-������ \n";

	{
		AVLTree* List = new AVLTree{};
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->insertData("A");
		List->insertData("AA");
		List->insertData("AB");
		List->insertData("B");
		List->insertData("BD");
		List->insertData("D");
		List->insertData("E");
		std::cout << "\t\t���� ���������\n";
		start_time = clock();

		List->Print();

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t�������� ������� AA\n";
		start_time = clock();
		List->Remove("AA");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";

		start_time = clock();
		List->search("AB");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t������ �� ��������� �������  A CC\n";

		start_time = clock();
		List->search("A", "CC");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t�������� �������� 20\n";
		start_time = clock();
		List->rd(20);

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t���� ��������� \n";
		List->Print();
		std::cout << endl;
	}
	std::cout << "\t\t5.	2-3 ������ \n";
	{
		_23Tree* List = new _23Tree("A");
		List->cr("0");
		std::cout << "\n\t\t������ ������� A,AA,AB,B,BD,D,E\n";
		List->Insert("A");
		List->Insert("AA");
		List->Insert("AB");
		List->Insert("B");
		List->Insert("BD");
		List->Insert("D");
		List->Insert("E");
		std::cout << "\t\t���� ���������\n";
		start_time = clock();

		List->print();

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t�������� ������� AA\n";
		start_time = clock();
		List->Remove("AA");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;
		std::cout << "\t\t���� ��������� \n";
		List->print();
		std::cout << endl;
		std::cout << "\t\t������ �� ��������� AB\n";

		start_time = clock();
		List->Search("AB");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t������ �� ��������� �������  A CC\n";

		start_time = clock();
		List->Search1("A", "CC");

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t�������� �������� 20\n";
		start_time = clock();
		List->rb(20);

		end_time = clock();
		cout << endl << "��� ������" << end_time - start_time << endl;

		std::cout << "\t\t���� ��������� \n";
		List->print();
		std::cout << endl;
	}
}
