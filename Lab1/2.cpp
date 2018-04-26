 /*
	Made by Lyman Shen. 9/25/17
	Take a line as input and tells the user
	how many alphanumeric and non-alphanumeric characters there are
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main ()
{
	//Create a string to use as input
	string inputStr;
	int i;
	/* Use variables length, alphaNum, nAlphanum, spaces
	   for the length of string, # of alphanumeric characters,
	   # of non-alphanumeric characters, and number of spaces respectively */
	int length, alphaNum, nAlphaNum, spaces = 0;
	//Take line as input and get its length
	getline(cin, inputStr);
	length = inputStr.length();
	//Loop through string to get number of alphanumeric characters and spaces
	for(i=0; i < length; i++)
	{
		if (isalnum(inputStr[i]))
		{
			alphaNum++;
		} else if (inputStr[i] == ' ')
		{
			spaces++;
		}
	}
	/*# of non-alphanumeric characters is total number of characters
	  less the alphanumeric characters and spaces */
	nAlphaNum = length - alphaNum - spaces;
	//Print word and information about alphanumeric and non-alpha numeric characters
	cout << "\"" << inputStr << "\" has " << alphaNum 
		 << " alphanumeric characters and "
		 << nAlphaNum << " non-alphanumberic charcters" << endl;
	return EXIT_SUCCESS;
}