/*
 *	Lyman Shen, October 28 2017
 *	FILE: mystring.cpp
 *	CLASS implemented: string (see mystring.h for documentation)
 *	INVARIANT for the string class:
 *		1. The number of characters used in the string is stored in the member variable current_length
 *		2. The string is stored as a partially filled array of char characters.
 *				The array of characters is a dynamic array pointed to by the member variable sequence.
 *		3. The characters of the string are stored in the first current_length characters in the array
 *			followed by the terminating null character. We do not care about what is inside the array
 *			past the terminating null character.
 *		4. The size of the array is stored by the member variable allocated.
 */

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "mystring.h"

namespace coen79_lab5
{
	string::string(const char str[ ])
	{
		size_t length = 0;
		length = strlen(str);
		assert(str[length] == '\0'); //Check if str is an ordinary null-terminated string
		sequence = new char[length + 1];
		std::strncpy(sequence, str, length);
		sequence[length] = '\0';
		allocated = length + 1;
		current_length = length;
	}

	string::string(const string& source)
	{
		sequence = new char[source.allocated];
		strncpy(sequence, source.sequence, source.allocated);
		allocated = source.allocated;
		current_length = source.current_length;
	}

	string::~string( )
	{
		delete [] sequence;
	}

	void string::operator +=(const string& addend)
	{
		if(((current_length + addend.current_length + 1) > allocated))
		{
			reserve(current_length + addend.current_length + 1);
		}
		strncat(sequence, addend.sequence, addend.allocated);
		current_length += addend.current_length;
		allocated = current_length + 1;
	}
	

	void string::operator +=(const char addend[ ])
	{
		size_t addLength = 0;
		addLength = strlen(addend);
		assert(addend[addLength] == '\0'); //Check if adddend is an ordinary null-terminated string
		if(current_length + addLength + 1 > allocated)
		{
			reserve(current_length + addLength + 1);
		}
		strncat(sequence, addend, addLength);
		current_length += addLength;
		allocated = current_length + 1;
	}

	void string::operator +=(char addend)
	{
		if(current_length + 2 > allocated)
		{
			reserve(current_length + 2);
		}
		sequence[current_length] = addend;
		current_length++;
		sequence[current_length] = '\0';
		allocated = current_length + 1;
	}

	void string::reserve(size_t n)
	{
		char *largerSequence;
	    if (n == allocated)
	    {
	        return; // The allocated memory is already the right size.
	    }
	    if (n < allocated)
	    {
	        n = allocated; // Can’t allocate less than used.
	    }
	    largerSequence = new char[n];
	    strncpy(largerSequence, sequence, current_length + 1);
	    delete [ ] sequence;
	    sequence = largerSequence;
	    allocated = n;
	}

	string& string::operator =(const string& source)
	{
		char *nSeq;
		if(this == &source)
		{
			return *this;
		}
		if(allocated != source.allocated)
		{
			nSeq = new char[source.allocated];
			delete [] sequence;
			sequence = nSeq;
			allocated = source.allocated;
		}
		strncpy(nSeq, source.sequence, source.current_length);
		current_length = source.current_length;
		nSeq[source.current_length] = '\0';
		return *this;
	}

	char string::operator [](size_t position) const
	{
		assert(position < length());
		return sequence[position];
	}

	std::ostream& operator <<(std::ostream& outs, const string& source)
	{
		outs << source.sequence;
		return outs;
	}

	bool operator ==(const string& s1, const string& s2)
	{
		return(strncmp(s1.sequence, s2.sequence, s1.current_length + 1) == 0);
	}

	bool operator !=(const string& s1, const string& s2)
	{
		return(strncmp(s1.sequence, s2.sequence, s1.current_length + 1) != 0);
	}

	bool operator > (const string& s1, const string& s2)
	{
		return(strncmp(s1.sequence, s2.sequence, s1.current_length + 1) > 0);
	}

	bool operator < (const string& s1, const string& s2)
	{
		return(strncmp(s1.sequence, s2.sequence, s1.current_length + 1) < 0);
	}

	bool operator >= (const string& s1, const string& s2)
	{
		return(strncmp(s1.sequence, s2.sequence, s1.current_length + 1) >= 0);
	}

	bool operator <= (const string& s1, const string& s2)
	{
		return(strncmp(s1.sequence, s2.sequence, s1.current_length + 1) <= 0);
	}

	string operator +(const string& s1, const string& s2)
	{
		string s3 = s1;
		s3 += s2;
		return s3;
	}

    string operator +(const string& s1, const char addend[ ])
    {
    	string s3 = s1;
    	s3 += addend;
    	return s3;
    }
	
    std::istream& operator >> (std::istream& ins, string& target)
    {
    	char toAdd;
    	while(!ins.fail() && isspace(ins.peek()))
    	{
    		ins.ignore();
    	}
    	target = "";
    	while(!ins.fail() && !isspace(ins.peek()))
    	{
    		ins >> toAdd;
    		target += toAdd;
    	}
    	return ins;
    }
    
}