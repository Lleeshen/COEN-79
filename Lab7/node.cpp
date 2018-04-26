// Lyman Shen, Nov 11, 2017
// FILE: node.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>

using namespace std;

namespace coen79_lab7
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;
    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr)
    {
        std::cout << "Test list_piece start" << std::endl;
        head_ptr = NULL;
        tail_ptr = NULL;
        node* cursor = start_ptr;


        // Handle the case of the empty list.
        if (start_ptr == NULL || start_ptr == end_ptr)
        {
            return;
        }
        while (start_ptr != NULL)
        {
            cursor = cursor -> link();
            if(cursor == end_ptr)
            {
                break;
            }
        }
        assert(cursor == end_ptr); //Check condition for start_ptr and end_ptr on same list
        cursor = start_ptr;
        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr, start_ptr->data( ));
        tail_ptr = head_ptr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        start_ptr = start_ptr->link( );
        while (start_ptr != NULL && start_ptr != end_ptr)
        {
            list_insert(tail_ptr, start_ptr->data( ));
            tail_ptr = tail_ptr->link( );
            start_ptr = start_ptr->link( );
        }
        std::cout << "Test list_piece end" << std::endl;

    }

    size_t list_occurrences(node* head_ptr, const node::value_type& target)
    {
        std::cout << "Test list_occurrences" << std::endl;
        size_t count = 0;
        //No need to check precondition because function will return 0 occurences for target if head_ptr is NULL
        while(head_ptr != NULL)
        {
            head_ptr = list_search(head_ptr, target);
            if(head_ptr != NULL)
            {
                count++;
                head_ptr = head_ptr -> link();
            }
        }
        std::cout << "Test list_occurrences end" << std::endl;
        return count;
    }

    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position)
    {
        std::cout << "Test list_insert_at start" << std::endl;
        assert(head_ptr != NULL && position > 0 && position <= (list_length(head_ptr) + 1));
        node* cursor = head_ptr;
        if(position == 1)
        {
            list_head_insert(head_ptr, entry);
        }
        else
        {
            cursor = list_locate(head_ptr, position - 1);
            list_insert(cursor, entry);
        }
        std::cout << "Test list_insert_at end" << std::endl;
    }

    node::value_type list_remove_at(node*& head_ptr, size_t position)
    {
        std::cout << "Test list_remove_at start" << std::endl;
        assert(head_ptr!= NULL && position > 0 && position <= list_length(head_ptr));
        node::value_type removed;
        node* precursor = NULL;
        node* cursor = head_ptr;
        if(position == 1)
        {
            head_ptr = head_ptr->link();
        }
        else
        {
            while(position != 1)
            {
                precursor = cursor;
                cursor = cursor -> link();
                --position;
            }
            precursor -> set_link(cursor -> link());
        }
        removed = cursor -> data();
        delete cursor;
        std::cout << "Test list_remove_at end" << std::endl;
        return removed;
    }

    node* list_copy_segment(node* head_ptr, size_t start, size_t finish)
    {
        std::cout << "Test list_copy_segment start" << std::endl;
        assert(head_ptr != NULL && 1 <= start && start <= finish && finish <= list_length(head_ptr));
        node *newHead;
        node *hcursor = head_ptr;
        node *nHpCursor = NULL;
        node *nHcursor = head_ptr;

        while(start != 1)
        {
            hcursor = hcursor -> link();
            --start;
            --finish;
        }
        newHead = new node;
        newHead -> set_data(hcursor->data());
        newHead -> set_link(NULL);
        nHpCursor = newHead;
        --finish;
        while(finish != 0)
        {
            hcursor = hcursor -> link();
            nHcursor = new node;
            nHcursor -> set_data(hcursor->data());
            nHpCursor -> set_link(nHcursor);
            nHpCursor = nHcursor;
            --finish;
        }
        std::cout << "Test list_copy_segment end" << std::endl;
        return newHead;
    }
}
