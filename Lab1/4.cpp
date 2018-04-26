/*
	Made by Lyman Shen. 9/25/17
	Fixes original program so second line prints "Hello World"
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	struct object {
		string*s;
	};
	object A, B;
	A.s = new string;
	B.s = new string;	  //Added; declares a string for B
	*A.s = "Hello World"; // A has "Hello World"
	*B.s = *A.s;		  // B has "Hello World"
					      /* changed so A's string is copied to B's string instead of
						     B being set to memory of A */
	*A.s = "Goodbye";	  // A has "Goodbye"
	cout << *A.s << endl;
	cout << *B.s << endl;
	return EXIT_SUCCESS;
}