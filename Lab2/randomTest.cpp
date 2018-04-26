#include "random.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
	const int size = 769;
	myNum::RandGen r1;
	int a[size];
	int i;
	for(i=0;i<size;i++)
	{
		a[i] = r1.next();
		std::cout << std::setw(6) << ' ' << a[i] << ' ' << std::endl;
	}
	return EXIT_SUCCESS;
}