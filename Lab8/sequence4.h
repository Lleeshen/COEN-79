// Lyman Shen, 11/18/17
// FILE: sequence.h
// CLASS PROVIDED: sequence (part of the namespace main_savitch_5)
// This is the header file for the project described in Section 5.4
// of "Data Structures and Other Objects Using C++"
// This is called "sequence3" because some students already implemented
// sequence1 (with a fixed array) and sequence2 (with a dynamic array).
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef Item value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor. This
//      data type is used as a template, so sequences storing different data types
//      can use the same class. This typedef only provides a convenient alias for
//      the data type stored in this sequence.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The precursor and cursor are adjusted such that the first
//     item in the sequence becomes the current item (but if the sequence is
//     empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   const_iterator begin( ) const
//   iterator end( )
//   const iterator end( ) const
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#ifndef COEN_70_SEQUENCE_H
#define COEN_70_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include "node2.h"  // Provides node class

namespace scu_coen79_8B
{
    template <class Item>
    class sequence
    {
        public:
            // TYPEDEFS and MEMBER CONSTANTS
            typedef Item value_type;
            typedef std::size_t size_type;
            typedef node_iterator<Item> iterator;
            typedef const_node_iterator<Item> const_iterator;
            // CONSTRUCTORS and DESTRUCTOR
            sequence( );
            sequence(const sequence& source);
            ~sequence( );
            // MODIFICATION MEMBER FUNCTIONS
            void start( );
            void advance( );
            void insert(const Item& entry);
            void attach(const Item& entry);
            void operator =(const sequence& source);
    	    void remove_current( );
            // CONSTANT MEMBER FUNCTIONS
            size_type size( ) const;
            bool is_item( ) const;
            Item current( ) const;
            // FUNCTIONS TO PROVIDE ITERATORS
            iterator begin( ) { return iterator(head_ptr); }
            const_iterator begin( ) const { return const_iterator(head_ptr); }
            iterator end( ) { return iterator(); }
            const_iterator end( ) const {return const_iterator(); }
        private:
        	coen79_lab8::node<Item>* head_ptr;
        	coen79_lab8::node<Item>* tail_ptr;
        	coen79_lab8::node<Item>* cursor;
        	coen79_lab8::node<Item>* precursor;
        	size_type many_nodes;

            void init();
        };
}

#include "sequence4.cxx"
#endif
