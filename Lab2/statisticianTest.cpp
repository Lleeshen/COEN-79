#include "statistician.h"
#include <iostream>
#include <cstdlib>

int main()
{
	myStats::statistician s1;
	s1.next_number(3.5);
	s1.next_number(-6.5);
	s1.next_number(0);
	std::cout << "Test length, sum, mean, smallest, largest" << std::endl;
	std::cout << s1.length() << std::endl;
	std::cout << s1.sum() << std::endl;
	std::cout << s1.mean() << std::endl;
	std::cout << s1.smallest() << std::endl;
	std::cout << s1.largest() << std::endl;
	std::cout << "Test assignment" << std::endl;
	myStats::statistician s2;
	s2 = s1;
	s2.next_number(7);
	std::cout << "Copy" << std::endl;
	std::cout << s2.length() << std::endl;
	std::cout << s2.sum() << std::endl;
	std::cout << s2.mean() << std::endl;
	std::cout << s2.smallest() << std::endl;
	std::cout << s2.largest() << std::endl;
	std::cout << "Original" << std::endl;
	std::cout << s1.length() << std::endl;
	std::cout << s1.sum() << std::endl;
	std::cout << s1.mean() << std::endl;
	std::cout << s1.smallest() << std::endl;
	std::cout << s1.largest() << std::endl;
	myStats::statistician s3;
	s3 = s1+s2;
	s3.next_number(-9);
	s3.next_number(9);
	std::cout << "New: add copy to original" << std::endl;
	std::cout << s3.length() << std::endl;
	std::cout << s3.sum() << std::endl;
	std::cout << s3.mean() << std::endl;
	std::cout << s3.smallest() << std::endl;
	std::cout << s3.largest() << std::endl;
	return EXIT_SUCCESS;
}