#include "TailList.h"
int main()
{
	TailList tl1;
	tl1.addFirst(5);

	tl1.addLast(6);
	for (int i = 5; i > 0; i--)
	{
		tl1.addFirst(i);
	}
	tl1.addLast(7);

	cout << tl1;

}