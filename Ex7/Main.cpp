#include <iostream>
using namespace std;

#include "List.h"

int main()
{
	try
	{
		List ls1;

		ls1.add(1);

		for (int i = 0; i < 5; i++)
		{
			ls1.add(i);
		}
		cout << ls1; //4 3 2 1 0 1

		cout << ls1.search(5); //false 0

		ls1.clear();
		cout << ls1;

		if (!ls1.isEmpty())
			cout << ls1.firstElement();

		ls1.add(6);
		ls1.add(2);
		ls1.add(1);
		cout << ls1; //1 2 6
		ls1.removeFirst();
		cout << ls1; //2 6


		List ls2(ls1);

		cout << ls2; //2 6

	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}


}
