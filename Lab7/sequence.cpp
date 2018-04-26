/*
 *	Lyman Shen, Nov 10, 2017
 *	FILE: sequence.cpp
 *	CLASS implemented: sequence (see sequence.h for documentation)
 *	INVARIANT for the sequence class:
 *		1. The number of items in the sequence in member variable many_nodes.
 *		2. The first item of the sequence is pointed to by the data of member variable head_ptr
 *		3. The last item of the sequence is pointed to by the data of member variable tail_ptr
 *		4. The current item of the sequence is pointed to the data of member variable cursor if it is valid
 *		5. The item before the current item is pointed to the data of member variable precursor if cursor is valid
 *				If cursor is the first item of the sequence, precursor is NULL.
 */

#include "sequence.h"
#include <cassert>

namespace coen79_lab7
{
	sequence::sequence() 
	{
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0;
	}

	sequence::sequence(const sequence& source) 
	{
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		node *sourceCursor = source.head_ptr;
		node *currentCursor = head_ptr;
		if(source.cursor == NULL)
		{
			precursor = NULL;
			cursor = NULL;
		}
		else if(sourceCursor == source.cursor)
		{
			precursor = NULL;
			cursor = head_ptr;
		}
		else 
		{
			while(sourceCursor != source.precursor)
			{
				sourceCursor = sourceCursor -> link();
				currentCursor = currentCursor -> link();
			}
			precursor = currentCursor;
			cursor = precursor -> link();
		}
	}

	sequence::~sequence()
	{
		list_clear(head_ptr);
	}

	void sequence::start()
	{
		cursor = head_ptr;
		precursor = NULL;
	}

	void sequence::end()
	{
		cursor = tail_ptr;
		precursor = list_locate(head_ptr, many_nodes - 1);
	}

	void sequence::advance()
	{
		assert(is_item() == true);
		precursor = cursor;
		cursor = cursor -> link();
	}

	void sequence::insert(const value_type& entry)
	{
		if(is_item())
		{
			if(precursor == NULL)
			{
				list_head_insert(head_ptr,entry);
				precursor = NULL;
				cursor = head_ptr;
			}
			else
			{
				list_insert(precursor, entry);
				cursor = precursor -> link();
			}
		}
		else
		{
			list_head_insert(head_ptr,entry);
			precursor = NULL;
			cursor = head_ptr;
			if(many_nodes == 0)
			{
				tail_ptr = head_ptr;
			}
		}
		++many_nodes;
	}

	void sequence::attach(const value_type& entry)
	{
		if(is_item())
		{
			list_insert(cursor, entry);
			precursor = cursor;
			cursor = cursor -> link();
			if(tail_ptr -> link() != NULL)
			{
				tail_ptr = tail_ptr -> link();
			}
		}
		else if (many_nodes == 0)
		{
			list_head_insert(head_ptr,entry);
			precursor = NULL;
			cursor = head_ptr;
			tail_ptr = head_ptr;
		}
		else
		{
			list_insert(tail_ptr , entry);
			precursor = tail_ptr;
			cursor = precursor -> link();
			tail_ptr = tail_ptr -> link();
		}
		++many_nodes;
	}

	void sequence::operator =(const sequence& source)
	{
		if(this == &source)
		{
			return;
		}
		list_clear(head_ptr);
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		node *sourceCursor = source.head_ptr;
		node *currentCursor = head_ptr;
		if(source.cursor == NULL)
		{
			precursor = NULL;
			cursor = NULL;
		}
		else if(sourceCursor == source.cursor)
		{
			precursor = NULL;
			cursor = head_ptr;
		}
		else 
		{
			while(sourceCursor != source.precursor)
			{
				sourceCursor = sourceCursor -> link();
				currentCursor = currentCursor -> link();
			}
			precursor = currentCursor;
			cursor = precursor -> link();
		}
	}

	void sequence::remove_current( )
	{
		assert(is_item() == true);
		if(precursor == NULL)
		{
			list_head_remove(head_ptr);
			cursor = cursor -> link();
		}
		else
		{
			list_remove(precursor);
			cursor = precursor -> link();
		}
		--many_nodes;
	}

	sequence::size_type sequence::size( ) const
	{
		return many_nodes;
	}

	bool sequence::is_item( ) const
	{
		return (cursor != NULL);
	}

	sequence::value_type sequence::current( ) const
	{
		assert(is_item() == true);
		return cursor -> data();
	}
}