#include <cstdlib>
#include <iostream>
#include <cctype>
#include "sequence.h"

using namespace mySeq;

void printMenu ();
char getUserOption();
void showSequence(sequence toShow);
double getValue();
size_t getIndex();

int main()
{
	sequence numbers;
	char choice;
	size_t index;
	do
	{
		printMenu();
		choice = std::toupper(getUserOption());
		switch(choice)
		{
			case '<':
				numbers.start();
				break;
			case '-':
				numbers.advance();
				break;
			case '>':
				numbers.end();
				break;
			case 'V':
				index = getIndex();
				std::cout << "Item number " << index << " is " << numbers[index] << "." << std::endl;
				break;
			case '?':
				if(numbers.is_item())
				{
					std::cout << "There is a current item." << std::endl;
				}
				else
				{
					std::cout << "There is no current item." << std::endl;
				}
				break;
			case 'C':
				if(numbers.is_item())
				{
					std::cout << "The current item is " << numbers.current() << "." << std::endl;
				}
				else
				{
					std::cout << "There is no current item." << std::endl;
				}
				break;
			case 'P':
				showSequence(numbers);
				break;
			case 'S':
				std::cout << "The size of the sequence is " << numbers.size() << "." << std::endl;
				break;
			case 'I':
				numbers.insert(getValue());
				break;
			case 'F':
				numbers.insert_front(getValue());
				break;
			case 'A':
				numbers.attach(getValue());
				break;
			case 'B':
				numbers.attach_back(getValue());
				break;
			case 'R':
				numbers.remove_current();
				std::cout << "The current item has been removed." << std::endl;
				break;
			case '/':
				numbers.remove_front();
				break;
			case 'Q':
				std::cout << "Thank you for using this program." << std::endl;
				break;
			default:
				std::cout << "Please enter a valid command." << std::endl;
		}
	} while(choice != 'Q');
	return EXIT_SUCCESS;
}

void printMenu () 
{
	std::cout << std::endl;
	std::cout << "The following choices are available: " << std::endl;
    std::cout << " <   Activate the start( ) function" << std::endl;
    std::cout << " -   Activate the advance( ) function" << std::endl;
    std::cout << " >   Activate the end( ) function" << std::endl;
    std::cout << " V   Print a value with an inputted index" << std::endl;
    std::cout << " ?   Print the result from the is_item( ) function" << std::endl;
    std::cout << " C   Print the result from the current( ) function" << std::endl;
    std::cout << " P   Print a copy of the entire sequence" << std::endl;
    std::cout << " S   Print the result from the size( ) function" << std::endl;
    std::cout << " I   Insert a new number with the insert(...) function" << std::endl;
    std::cout << " F   Insert a new number with the insert_front() function" << std::endl;
    std::cout << " A   Attach a new number with the attach(...) function" << std::endl;
    std::cout << " B   Attach a new number with the attach_back(...) function" << std::endl;
    std::cout << " R   Activate the remove_current( ) function" << std::endl;
    std::cout << " /   Activate the remove_front( ) function" << std::endl;
    std::cout << " Q   Quit this test program" << std::endl;
}

char getUserOption() 
{
	char command;
	std::cout << "Enter choice: ";
	std::cin >> command;
	return command;
}

void showSequence(sequence toShow)
{
	toShow.start();
	while(toShow.is_item())
	{
		std::cout << toShow.current() << std::endl;
		toShow.advance();
	}
}

double getValue()
{
	double newValue;
	std::cout << "Enter a number to a number for the suequence." << std::endl;
	std::cin >> newValue;
	std::cout << newValue << " is your value." << std::endl;
	return newValue;
}

size_t getIndex()
{
	size_t index;
	std::cout << "Enter the index of the sequence: " << std::endl;
	std::cin >> index;
	return index;
}
