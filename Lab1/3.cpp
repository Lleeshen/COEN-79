/*
	Made by Lyman Shen. 9/25/17
	Takes a file as input and outputs the words
	that are 10 or more characters long, after
	removing punctuation and converting the word
	to all upper case
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

int main (int argv, char *argc[])
{
	//Use word to later input word by word
	string word;
	//Auxillary variables to help erase punctuation later
	int i,count, len;
	//Make sure a text file possibly exists as an argument
	assert(argv == 2);
	assert(argc[1] != "");
	//Open the text file
	ifstream myReadFile;
	myReadFile.open(argc[1]);
	//Read the file
	while(myReadFile.peek() != EOF)
	{
		//Read the file word-by-word
		while(myReadFile >> word)
		{
			//Get length of word, and do things with it if length more than 10
			len = word.length();
			if(len >= 10)
			{
				//Loop through characters of the word
				for(i = 0; i < len; i++)
				{
					/*If there is punctuation, remove punctuation and fix rest of string
					   Otherwise change the character to its uppercase*/
					if(ispunct(word[i]))
					{
						word.erase(i,1);
						i--;
						len = word.length();
					}
					else
					{
						word[i] = toupper(word[i]);
					}
				}
				//Print the word after punctuation is removed and word is in all-upper case
				cout << word << endl;
			}
		}
	}
	//Close file
	myReadFile.close();
	return EXIT_SUCCESS;
}