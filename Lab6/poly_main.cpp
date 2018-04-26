#include <cstdlib>
#include <climits>
#include <iostream>
#include "poly.h"

using namespace coen79_lab6;

/*
void printMenu();
int getPolyChoice();
char getOperChoice();
*/

int main()
{
	polynomial p[3];
	p[0].assign_coef(-1,0);
	std::cout << p[0] << std::endl;
	p[0].assign_coef(4,1);
	std::cout << p[0] << std::endl;
	p[0].add_to_coef(-4,2);
	std::cout << p[0] << std::endl;
	p[1] = p[0];
	p[0].clear();
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	p[0] = p[1];
	p[1] = p[0].derivative();
	p[2] = p[0].antiderivative();
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;
	p[2].assign_coef(8,3);
	p[2].assign_coef(6,2);
	p[2].assign_coef(-2,1);
	p[2].assign_coef(3,0);
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;
	p[1] = p[0] + p[2];
	std::cout << p[1] << std::endl;
	p[1] = p[0] - p[2];
	std::cout << p[1] << std::endl;
	p[1] = p[0] * p[2];
	std::cout << p[1] << std::endl;
	std::cout << p[2] << " with x = 2 is " << p[2].eval(2) << std::endl;
	std::cout << "Integral of " << p[2] << " from 1 to 2  is " << p[2].definite_integral(1,2) << std::endl;
	std::cout << "The degree of " << p[2] << " is " << p[2].degree() << std::endl;
	if(p[2].is_zero())
	{
		std::cout << "The function is already zero." << std::endl;
	}
	else
	{
		p[2].clear();
		if(p[2].is_zero())
		{
			std::cout << "The function is now zero." << std::endl;
		}
	}
	std::cout << p[0].next_term(1) << std::endl;
	std::cout << p[0].previous_term(1) << std::endl;

	/*
	int pChoice;
	char oChoice;
	double coef;
	size_t exponent;
	size_t setPoly;
	double lowerL;
	double upperL;
	do
	{
		pChoice = getPolyChoice();
		if(pChoice > -1)
		{
			printMenu();
			oChoice = getOperChoice();
			switch(oChoice)
			{
				case 'P': //Show polynomial
					std::cout << p[pChoice] << std::endl;
					break;
				case 'C': //Change coeficient
					std::cin >> coef;
					std::cin >> exponent;
					p[pChoice].assign_coef(coef, exponent);
					break;
				case 'A': //Add to coeficient
					std::cin >> coef;
					std::cin >> exponent;
					p[pChoice].add_to_coef(coef, exponent);
					break;
				case 'D': //Erase polynomial
					p[pChoice].clear();
				case 'S': //Set to another polynomial
					std::cin >> setPoly;
					p[pChoice] = p[setPoly];
					break;
				case 'V': //Set to own derivative
					p[pChoice] = p[pChoice].derivative();
					break;
				case 'O': //Set to own antiderivative
					p[pChoice] = p[pChoice].antiderivative();
					break;
				case 'E': //Evaluate at number
					std::cin >> lowerL;
					std::cout << p[pChoice].eval(lowerL) << std::endl;
					break;
				case 'I': //Evaluate definite integral
					std::cin >> lowerL;
					std::cin >> upperL;
					std::cout << p[pChoice].definite_integral(lowerL, upperL) << std::endl;
					break;
				case '0': //Check if is 0
					if(p[pChoice].is_zero())
					{
						std::cout << "Is zero" << std::endl;
					}
					else
					{
						std::cout << "Is not zero" << std::endl;
					}
					break;
				case 'L': //Find exponent term smaller
					std::cin >> exponent;
					exponent = p[pChoice].previous_term(exponent);
					if(exponent != UINT_MAX)
					{
						std::cout << "Next smallest non-zero power is " << exponent << std::endl;
					}
					else
					{
						std::cout << "There is no smaller non-zero power." << std::endl;
					}
					break;
				case 'M': //Find exponent term larger
					std::cin >> exponent;
					exponent = p[pChoice].next_term(exponent);
					if(exponent != 0)
					{
						std::cout << "Next larger non-zero power is " << exponent << std::endl;
					}
					else
					{
						std::cout << "There is no larger non-zero power." << std::endl;
					}
					break;
				case '+': //Add another polynomial to current
					std::cin >> setPoly;
					p[pChoice] = p[setPoly];
					break;
				case '-': //Subtract another polynomial from current
					std::cin >> setPoly;
					p[pChoice] = p[pChoice] - p[setPoly];
					break;
				case '*': //Multiply another polynomial to current
					std::cin >> setPoly;
					p[pChoice] = p[pChoice] * p[setPoly];
					break;
				default:
					std::cout << "Please enter a valid command." << std::endl;
			}
		}
		else
		{
			std::cout << "Thank you for using this program." << std::endl;
		}
	} while(pChoice > -1);
	*/
	return EXIT_SUCCESS;
}

/*
void printMenu()
{
	std::cout << "The following operations are availible:" << std::endl;
}
int getPolyChoice() 
{
	int polychoice;
	std::cin >> polychoice;
	if(polychoice < 0)
		return 0;
	if(polychoice > 2)
		return 2;
	return polychoice;
}

char getOperChoice()
{
	char oper;
	std::cin >> oper;
	return toupper(oper);
}
*/