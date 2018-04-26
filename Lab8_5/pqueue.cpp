/*
 *	Lyman Shen, 11/18/17
 *	FILE: pqueue.cxx
 *	CLASS IMPLEMENTED: pqueue (see pqueue.h for documentation)
 *	Invariant for pqueue class:
 *		1. The number of items in the sequence is stored in the member variable "many_nodes" 
 *		2. For an empty priority queue, we do not care what is stored in any of data and head_ptr
 *        point to NULL; for a non-empty sequence, the items stored in the priority queue can be
 *		  accessed using head_ptr and we don't care what is stored in the rest of the data.
 *		3. The priority queue is sorted so the item with the most priority to remove is at the head_ptr;
 *			When items of different priority are in the queue, the item with more priority is earlier in the list;
 *			and when items of same priority are in the queue, the item inserted first is earlier in the list.
 */

#include <cassert>
#include <iostream>
#include "pqueue.h"

namespace coen79_lab8_5
{
	PriorityQueue::PriorityQueue()
	{
		many_nodes = 0;
		head_ptr = NULL;
	}

	PriorityQueue::PriorityQueue(const PriorityQueue& source)
	{
		node* s_cursor;
		node* nodes;
		node* cursor;
		head_ptr = NULL;
		s_cursor = source.head_ptr;
		if(s_cursor != NULL)
		{
			head_ptr = new node(source.head_ptr->data(), source.head_ptr->priority(), NULL);
			cursor = head_ptr;
			s_cursor = s_cursor -> link();
			while(s_cursor != NULL)
			{
				nodes = new node(s_cursor->data(), s_cursor->priority(), NULL);
				cursor -> set_link(nodes);
				cursor = nodes;
				s_cursor = s_cursor -> link();
			}
		}
		many_nodes = source.many_nodes;
	}

	PriorityQueue::~PriorityQueue()
	{
		node *toRemove;
		while(head_ptr != NULL)
		{
			toRemove = head_ptr;
			head_ptr = head_ptr -> link();
			delete toRemove;
		}
	}

	void PriorityQueue::insert(const Item& entry, unsigned int priority)
	{
		
		node *cursor = head_ptr;
		node *newNode = new node(entry, priority, NULL);
		node *pcursor = NULL;
		if(head_ptr == NULL)
		{
			head_ptr = newNode;
		}
		else
		{
			while(cursor != NULL && cursor->priority() >= priority)
			{
				pcursor = cursor;
				cursor = cursor -> link();
			}
			if(pcursor == NULL)
			{
				newNode -> set_link(head_ptr);
				head_ptr = newNode;
			}
			else
			{
				pcursor -> set_link(newNode);
				newNode -> set_link(cursor);
			}
		}
		++many_nodes;
	}

	PriorityQueue::Item PriorityQueue::get_front( )
	{
		assert(size() != 0);
		Item removedData;
		node *toRemove = head_ptr;
		head_ptr = head_ptr -> link();
		removedData = toRemove -> data();
		delete toRemove;
		--many_nodes;
		return removedData;
	}

	size_t PriorityQueue::size( ) const
	{
		return many_nodes;
	}

	bool PriorityQueue::is_empty( ) const
	{
		return (many_nodes == 0) ? true : false;
	}

	void PriorityQueue::operator = (const PriorityQueue& source)
	{
		node *s_cursor;
		node *n_nodes;
		node *n_cursor;
		if(this == &source)
		{
			return;
		}
		while(!is_empty())
		{
			n_cursor = head_ptr;
			head_ptr = head_ptr -> link();
			delete n_cursor;
			--many_nodes;
		}
		s_cursor = source.head_ptr;
		if(s_cursor == NULL)
		{
			head_ptr = NULL;
			many_nodes = 0;
		}
		else
		{
			head_ptr = new node(s_cursor -> data(), s_cursor -> priority(), NULL);
			n_cursor = head_ptr;
			s_cursor = s_cursor -> link();
			while(s_cursor != NULL)
			{
				n_nodes = new node(s_cursor -> data(), s_cursor -> priority(), NULL);
				n_cursor -> set_link(n_nodes);
				n_cursor = n_nodes; 
				s_cursor = s_cursor -> link();
			}
			many_nodes = source.many_nodes;
		}

	}
}