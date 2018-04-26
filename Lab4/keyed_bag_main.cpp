#include <cstdlib>
#include <iostream>
#include "keyed_bag.h"

using namespace coen79_lab4;

int main()
{
	std::size_t countV;
	keyed_bag kb[3];
	std::cout << kb[0].size() << std::endl;
	kb[0].insert(2,"Rat");
	kb[0].insert(4,"Pig");
	std::cout << kb[0].size() << std::endl;
	if(!kb[0].has_key("Owl"))
	{
		std::cout << "There is no value associated with Owl." << std::endl;
	}
	if(kb[0].has_key("Pig"))
	{
		std::cout << "The value associated with Pig is " << kb[0].get("Pig") << std::endl;
	}
	kb[1] = kb[0];
	kb[0].erase();
	if(kb[1].has_key("Rat"))
	{
		std::cout << "The value associated with Rat is " << kb[1].get("Rat") << std::endl;
	}
	std::cout << kb[0].size() << " " << kb[1].size() << std::endl;
	kb[1].insert(4, "Cat");
	countV = kb[1].count(4);
	std::cout << "There are " << countV << " values of 4." << std::endl;
	kb[1].insert(6, "Dog");
	if(kb[1].has_key("Cat"))
	{
		kb[1].erase("Cat");
		std::cout << "There is no longer a value associated with Cat." << std::endl;
	}
	kb[2].insert(3,"Rat");
	kb[2].insert(5, "Bat");
	kb[0].insert(7, "Bee");
	if(kb[1].hasDuplicateKey(kb[2]))
	{
		std::cout << "There are same keys in those bags." << std::endl;
	}
	if(!(kb[1].hasDuplicateKey(kb[0])))
	{
		std::cout << "There are not same keys in those bags." << std::endl;
	}
	kb[2].erase("Rat");
	kb[2].insert(6,"Cow");
	kb[0] = kb[1] + kb[2];
	std::cout << kb[1].size() << " " << kb[2].size() << " " << kb[0].size() << std::endl;;
	return EXIT_SUCCESS;
}