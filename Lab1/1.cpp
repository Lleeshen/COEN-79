/*
	Made by Lyman Shen. 9/25/17
	Alternately print "01234567890"
	and "9876543210", with 1 more
	space before the string on each
	line for 10 lines, using a loop
	and the setw() function.

	Expected output is
	0123456789
	 9876543210
	  0123456789
	   9876543210
	    0123456789
		 9876543210
	      0123456789
		   9876543210
	        0123456789
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	// Declare variables
	int i;
	bool even;
	//Use string constants
	string str1 = "0123456789";
	string str2 = "9876543210";
	for(i=0; i < 10; i++)
	{
		//Set width of what is printed
		cout << setw(i + 10);
		//Check if i is even
		even = (i % 2 == 0) ? true : false;
		//Print str1 if i is even, str2 if not
		if(even)
		{
			cout << str1 << endl;
		} else
		{
			cout << str2 << endl;
		}
	}
	return EXIT_SUCCESS;
}
