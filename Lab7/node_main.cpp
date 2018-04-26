#include <iostream>
#include <cstdlib>
#include "node.h"

using namespace coen79_lab7;

//tT is test list tail, tH is test list Head, tC is test list cursors, nH is new list head, nT is new list tail, nC is new list cursors

int main()
{
	node *tT;
	node *tC;
	node *tH;
	node *nH;
	node *nC;
	node *nT;
	tH = new node(1, NULL);
	tC= tH;
	while(tC != NULL)
	{
		std::cout << "Item in list ";
		std::cout << tC->data() << std::endl;
		tC = tC -> link();
	}
	list_insert_at(tH, 1, 2);
	tT = tH -> link();
	tC= tH;
	while(tC != NULL)
	{
		std::cout << "Item in list ";
		std::cout << tC->data() << std::endl;
		tC = tC -> link();
	}
	list_insert_at(tH, 2, 1);
	tC= tH;
	while(tC != NULL)
	{
		std::cout << "Item in list ";
		std::cout << tC->data() << std::endl;
		tC = tC -> link();
	}
	list_insert_at(tH, 2, 3);
	tT = tT -> link();
	tC= tH;
	while(tC != NULL)
	{
		std::cout << "Item in list ";
		std::cout << tC->data() << std::endl;
		tC = tC -> link();
	}
	std::cout << list_occurrences(tH,6) << std::endl;
	list_piece(tH, tT, nH, nT);
	std::cout << list_occurrences(nH,1) << std::endl;
	list_remove_at(nH, 2);
	std::cout << list_occurrences(nH,1) << std::endl;
	list_clear(nH);
	nH = list_copy_segment(tH, 1,3);
	nC= nH;
	while(nC != NULL)
	{
		std::cout << "Item in list ";
		std::cout << nC->data() << std::endl;
		nC = nC -> link();
	}
	return 0;
}
