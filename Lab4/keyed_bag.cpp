 /* 
	Lyman Shen, October 21 2017
	FILE: keyed_bag.cpp
	CLASS implemented: keyed_bag (see keyed_bag.h for documentation)
	INVARIANT for the sequence class:
		1. The number of items in the keyed_bag is in the member variable used;
		2. For an empty keyed bag, we do not care what is stored in any of data; for a non-empty keyed bag,
		   the items in the keyed bag are stored in data[0] through data[used-1], and we don't care
		   what's in the rest of the data
		2. For an empty keyed bag, we do not care what is stored in any of keys; for a non-empty keyed bag,
		   the keys in the keyed bag are stored in keys[0] through keys[used-1], and we don't care
		   what's in the rest of the data
 */

#include <algorithm>
#include <cassert>
#include "keyed_bag.h"

namespace coen79_lab4
{

	bool keyed_bag::erase(const key_type& key)
	{
		bool erased = false;
		size_type i = 0;
		while(i < used)
		{
			if (keys[i] == key)
			{
				used--;
				keys[i] = keys[used];
				data[i] = data[used];
				erased = true;
			}
			else
			{
				i++;
			}
		}
		return erased;
	}

	void keyed_bag::insert(const value_type& entry, const key_type& key)
	{
		assert((size() < CAPACITY) && (!has_key(key)));
		keys[used] = key;
		data[used] = entry;
		used++; 
	}

	void keyed_bag::operator +=(const keyed_bag& addend)
	{
		assert((size() + addend.size() < CAPACITY) && (!hasDuplicateKey(addend)));
		std::copy(addend.data, addend.data + used, data);
		std::copy(addend.keys, addend.keys + used, keys);
		used += addend.used;
	}

	bool keyed_bag::has_key(const key_type& key) const
	{
		size_type i = 0;
		while(i < used)
		{
			if(keys[i] == key)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	
	keyed_bag::value_type keyed_bag::get(const key_type& key) const
	{
		size_type i = 0;
		value_type value;
		assert(has_key(key));
		while(i < used)
		{
			if(keys[i] == key)
			{
				value = data[i];
				break;
			}
			i++;
		}
		return value;
	}

	bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const
	{
		key_type orig;
		size_type i;
		for(i = 0; i < used; i++)
		{
			orig = keys[i];
			if(otherBag.has_key(orig))
			{
				return true;
			}
		}
		return false;	
	}

	keyed_bag::size_type keyed_bag::count(const value_type& target) const {
		size_type i, count;
		count = 0;
		i = 0;
		while(i < used)
		{
			if(data[i] == target)
			{
				count++;
			}
			i++;
		}
		return count;
	}

	keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
	{
		keyed_bag b3(b1);
		b3 += b2;
		return b3;
	}
}