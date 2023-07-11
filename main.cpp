#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"HugeReal.h"
void load_all_integers(int size, HugeReal* his, ifstream& rdr)
{
	for (int i = 0; i < size; i++)
	{
		while (rdr.peek() == '\n' || rdr.peek() == ' ')
			rdr.ignore();
		his[i].load_integer(rdr);
	}
}
void load_all_integers_2(int size, HugeReal** his, ifstream& rdr)
{
	for (int i = 0; i < size; i++)
	{
		while (rdr.peek() == '\n' || rdr.peek() == ' ')
			rdr.ignore();
		his[i] = new HugeReal(rdr);
	}
}
void print_all_integes(int size, HugeReal* his)
{
	for (int i = 0; i < size; i++)
	{
		cout << his[i] << endl;
	}
}
void print_all_integes_2(int size, HugeReal** his)
{
	for (int i = 0; i < size; i++)
	{
		cout << *his[i] << endl;
	}
}
int main()
{
	ifstream rdr("Source.txt");
	int Isize;
	HugeReal* his;
	HugeReal** his_2;
	rdr >> Isize;
	his_2 = new HugeReal * [Isize];
	his = new HugeReal[Isize];
	//load_all_integers(Isize, his, rdr);
	load_all_integers_2(Isize, his_2, rdr);
	//print_all_integes(Isize, his);
	print_all_integes_2(Isize, his_2);
	int choice = 0;
	cout << "\nEnter choice: ";
	cin >> choice;
	if (choice == 1)
	{
		int a = 0, b = 0;
		cout << "\nEnter integer_1: ";
		cin >> a;
		cout << "\nEnter integer_2: ";
		cin >> b;
		HugeReal A = *(his_2[a]);
		HugeReal B = (*his_2[b]);
		HugeReal answer = A + B;
	}
	else if (choice == 2)
	{
		int a = 0, b = 0;
		cout << "\nEnter integer_1: ";
		cin >> a;
		cout << "\nEnter integer_2: ";
		cin >> b;
		cout << "\n Notice that the difference will be as 1-2\n";
		HugeReal A = *(his_2[a]);
		HugeReal B = (*his_2[b]);
		HugeReal answer = A - B;
	}
	//kkjk
	else if (choice == 3)
	{
		int a = 0, b = 0;
		cout << "\nEnter integer_1: ";
		cin >> a;
		cout << "\nEnter integer_2: ";
		cin >> b;
		cout << "\n Notice that the difference will be as 1-2\n";
		HugeReal A = *(his_2[a]);
		HugeReal B = (*his_2[b]);
		HugeReal answer = A * B;
		cout <<endl<< answer;
	}
	else if (choice == 4)
	{
		int a = 0, b = 0;
		cout << "\nEnter integer_1: ";
		cin >> a;
		cout << "\nEnter integer_2: ";
		cin >> b;
		cout << "\n Notice that the difference will be as 1/2\n";
		HugeReal A = *(his_2[a]);
		HugeReal B = (*his_2[b]);
		HugeReal answer = A / B;
	}
	else if (choice == 5)
	{
		int a = 0, b = 0;
		cout << "\nEnter integer_1: ";
		cin >> a;
		cout << "\nEnter integer_2: ";
		cin >> b;
		cout << "\n Notice that the difference will be as 1>2\n";
		HugeReal A = *(his_2[a]);
		HugeReal B = (*his_2[b]);
		if (A < B)
			cout << "\nA is greater than B\n";
		else
			cout << "\nB is greater than A\n";
	}
	else if (choice == 6)
	{
		int a = 0, b = 0;
		cout << "\nEnter integer_1: ";
		cin >> a;
		cout << "\nEnter integer_2: ";
		cin >> b;
		cout << "\n Notice that the Comparison will be as 1<2\n";
		HugeReal A = *(his_2[a]);
		HugeReal B = (*his_2[b]);
		if (A > B)
			cout << "\nA is less than B\n";
		else
			cout << "\nB is less than A\n";
	}
}