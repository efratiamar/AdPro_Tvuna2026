//#include "GList.h"
//int main()
//{
//	GList<int> list1;
//	list1.IsEmpty();
//
//}

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;


int main()
{
	vector<int> v1;
	cout << v1.size(); //0

	vector<int> v2(4); //0 0 0 0
	cout << v2.size(); //4

	vector<char> v3(3); //'0' '0' '0' 
	cout << v3.size(); //3

	vector<char> v4(5, 'x'); //'x' 'x' 'x' 'x' 'x'
	cout << v4.size(); //5

	v1.push_back(4); //4
	v1.push_back(3); //4 3
	v1.push_back(2); //4 3 2
	v1.push_back(1); //4 3 2 1

	v1.pop_back(); // 4 3 2

	cout << v1.capacity(); // ???

	cout << v1.front(); //4

	cout << v1.back(); //2

	cout << v1.at(1); //3
	
	v1.at(1) = 6; //4 6 2
	v1[1] = 7; //4 7 2

	for (int i; i < v1.size(); i++)
		cout << v1[i] << " ";

	int* vec = new int[9];

	int* p;
	p = vec + 3;
	p++;
	cout << *p;

	vector<int>::iterator it1;

	it1 = v1.begin();
	it1++;

	cout << *it1; //7

	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1 + 2 << " "; //6 9 4

	}


	for (it1 = v2.begin(); it1 != v2.end(); it1++)
	{
		cout << *it1 + 2 << " "; //6 9 4

	}

	for (vector<char>::iterator itC = v3.begin(); itC != v3.end(); itC++)
		cout << *itC << " ";

	////v1.erase(it1)


	list<string> ls1;
	ls1.push_back("AA"); //AA
	ls1.push_back("BB"); //AA BB
	ls1.push_front("CC"); //CC AA BB

	cout<< ls1.size(); //3

	cout << ls1.back(); //BB
	cout << ls1.front(); //CC

	list<string>::iterator itL;

	for (itL = ls1.begin(); itL != ls1.end(); itL++)
	{
		cout << *itL << " ";
	}


	stack<char> s1;
	s1.push('A');
	s1.push('B');

	//stack<char>::iterator itS; //cannot!!


}