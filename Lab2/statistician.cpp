/*
 * Lyman Shen, 10/7/17
 *
 * class implemented: statistician (see statistician.h for documentation)
 * INVARIANT for statistician class
 *	1. The number of numbers added is in member variable length
 *	2. The last number added is in member variable Last
 *	3. The sum of every number added is in member variable Sum
 *	4. The smallest number added is in member variable Smallest
 *	5. The largest number addded is in member variable Largeest
 */

#include "statistician.h"

namespace myStats
{

	statistician::statistician()
	{
		Length = 0;
		Sum = 0.0;
	}

	void statistician::next_number(double newStat)
	{
		if(Length == 0)
		{
			Smallest = newStat;
			Largest = newStat;
		}
		else
		{
			if(newStat < Smallest)
			{
				Smallest = newStat;
			}
			else if(newStat > Largest)
			{
				Largest = newStat;
			}
		}
		Last = newStat;
		Sum += newStat;
		Length++;
	}

	double statistician::mean()
	{
		return Sum/((double) Length);
	}
	void statistician::erase()
	{
		Length = 0;
		Sum = 0.0;
	}

	statistician operator + (const statistician& s1, const statistician& s2)
	{
		statistician s3;
		s3.Sum = s1.Sum + s2.Sum;
		s3.Last = s2.Last;
		s3.Length = s1.Length + s2.Length;
		if(s1.Smallest < s2.Smallest)
		{
			s3.Smallest = s1.Smallest;
		}
		else
		{
			s3.Smallest = s2.Smallest;
		}
		if (s1.Largest > s2.Largest)
		{
			s3.Largest = s1.Largest;
		}
		else
		{
			s3.Largest = s2.Largest;
		}
		return s3;
	}

	void statistician::operator = (const statistician& s1)
	{
		if(this == &s1)
			return;
		Length = s1.Length;
		Sum = s1.Sum;
		Last = s1.Last;
		Smallest = s1.Smallest;
		Largest = s1.Largest;
		return;
	}

}