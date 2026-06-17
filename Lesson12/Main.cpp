#include "Tree.h"
#include "SearchTree.h"
#include "Contact.h"

int main()
{
	SearchTree<int> t1;

	t1.add(10);
	t1.add(4);
	t1.add(7);
	//...

	t1.preOrder();
	t1.inOrder();

	bool b = t1.search(8);

	t1.clear();

	SearchTree<Contact> t2;

	Contact c1("efrat", "3562985");
	Contact c2("david", "554645");

	t2.add(c1);
	t2.add(c2);
	//...

	bool b1 = t2.search(c1);

	bool b3 = t2.isHeap();

 }
 
