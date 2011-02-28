#include <iostream>
#include "dict.cpp"

int
main(void)
{
	Dict alist("new-data.txt");
	alist.print(5);
	return 0;
}
