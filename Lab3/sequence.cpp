#include "sequence.h"
#include <cassert>
#include <cstdlib>
#include <algorithm>

namespace mySeq {

	sequence::sequence() 
	{
		used = 0;
		current_index = 0;
	}

	sequence::sequence(const sequence& s1)
	{
		std::copy(s1.data,((s1.data)+(s1.used)),this->data);
		used = s1.used;
		current_index = s1.current_index;
	}

	void sequence::start( )
	{
		if(used)
		{
			current_index = 0;
		}	
	}

	void sequence::advance( )
	{
		assert(is_item());
		current_index++;
	}

	void sequence::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);
		size_type i;
		if(!is_item())
		{
			current_index = 0;
		}
		for(i = used; i > current_index ; i--)
		{
			data[i] = data[i-1];
		}
		data[i] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
		assert(size() < CAPACITY);
		size_type i;
		if(!is_item())
		{	
			current_index = used;
		}
		else
		{
			current_index ++;
		}
		for(i = used; i > current_index ; i--)
		{
			data[i] = data[i-1];
		}
		data[i] = entry;
		used++;
	}

	void sequence::remove_current( )
	{
		assert(is_item());
		size_type i;
		used--;
		for(i = current_index; i < used; i++)
		{
			data[i] = data[i+1];
		}
	}

	void sequence::insert_front(const value_type& entry)
	{
		current_index = 0;
		insert(entry);
	}

	void sequence::remove_front()
	{
		current_index = 0;
		remove_current();
	}

	void sequence::attach_back(const value_type& entry)
	{
		current_index = used;
		attach(entry);	
	}

	void sequence::end()
	{
		current_index = used - 1;
	}

	sequence& sequence::operator = (const sequence& s1)
	{
		if(this != &s1)
		{
			std::copy(s1.data,((s1.data)+(s1.used)),this->data);
			used = s1.used;
			current_index = s1.current_index;
		}
		return *this;
	}

	sequence& sequence::operator += (const sequence& s1)
	{
		assert((this->size() + s1.size()) < CAPACITY);
		std::copy(s1.data,((s1.data)+(s1.used)),((this->data)+(this->used))); 
		used += s1.used;
		return *this;
	}

	sequence::value_type sequence::operator [] (size_type index) const
	{
		assert(index > 0 && index < used);
		return data[index];
	}

	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item( ) const
	{
		return (current_index < used);
	}

	sequence::value_type sequence::current( ) const
	{
		assert(is_item());
		return data[current_index];
	}

	sequence operator + (const sequence& s1, const sequence& s2)
	{
		assert((s1.used + s2.used) < sequence::CAPACITY);
		sequence s3;
		std::copy(s1.data,((s1.data)+(s1.used)),(s3.data)); 
		std::copy(s2.data,((s2.data)+(s2.used)),((s3.data)+(s3.used))); 
		s3.used = s1.used + s2.used;
		return s3;
	}
}