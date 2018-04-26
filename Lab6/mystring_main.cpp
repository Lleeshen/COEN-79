#include <cstdlib>
#include <iostream>
#include "mystring.h"

using namespace coen79_lab6;

int main ()
{
	size_t i;
	char cLit1 = ' ';
	char sLit1[10] = "Hello";
	char sLit2[10] = "World";
	string s1; //Check default constructor
	string s2("s"); //Check construtor with c-style string parameter
	string s3("c");
	string s4;
	s1 += sLit1; //Check + and += operators (+= implemented as +) with c-style string addend, reserve will be called
	s1 += cLit1; //Check + and += operators (+= implemented as +) with char addend
	s1 += sLit2;
	std::cout << s1 << std::endl; //Check << operator
	std::cout << s2 << std::endl;
	s4 = s3 + s2; //Check + and += operators (+= implemented as +) with string object addend
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	s4 = s1; //Check = operator
	std::cout << s4 << std::endl;
	std::cin >> s3; //Check >> operator
	std::cout << s3 << std::endl;
	string s5(s1); //Check copy constructor
	std::cout << s5 << std::endl;
	for(i = 0; i < s1.length() ; i++)
	{
		std::cout << s1[i]; //Check [] operator
	}
	std::cout << std::endl;

	//Test the 6 comparison operators in different cases
	string testC = "b1";
	const string empty = "";
	string test[9];
	test[0] = "a";
	test[1] = "b";
	test[2] = "b0";
	test[3] = "b0g";
	test[4] = "b1";
	test[5] = "b1g";
	test[6] = "b2";
	test[7] = "c";

	char ctest[7];

	for(i = 0; i < 8; i++) 
	{
		ctest[0] = (test[i] < testC) ? 'T' : 'F';
		ctest[1] = (test[i] <= testC) ? 'T' : 'F';
		ctest[2] = (test[i] == testC) ? 'T' : 'F';
		ctest[3] = (test[i] != testC) ? 'T' : 'F';
		ctest[4] = (test[i] >= testC) ? 'T' : 'F';
		ctest[5] = (test[i] > testC) ? 'T' : 'F';
		ctest[6] = '\0';
		test[8] = empty;
		test[8] += ctest;
		std::cout << test[8] << std::endl;
	}

	return EXIT_SUCCESS;
}