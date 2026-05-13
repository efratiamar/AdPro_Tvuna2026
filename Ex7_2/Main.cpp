#include <iostream>
using namespace std;

#include "List.h"

int main()
{
	try
	{
		List ls1;

		ls1.add(7);

		for (int i = 1; i < 5; i++)
		{
			ls1.add(i);
		}
		cout << ls1; // 4 3 2 1 7

		cout << ls1.firstElement() << endl;
		ls1.removeFirst();
		cout << ls1;
		cout << ls1.search(8) << endl;
		
		ls1.clear();

		for (int i = 1; i < 3; i++)
		{
			ls1.add(i);
		}

		List ls2(ls1);
		cout << ls2;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	catch(...)
	{
		cout << "Unknown error!" << endl;
	}


}