/*
 * Lyman Shen, 10/7/17
 *
 * FILE: statistician.h
 * Class provided: statistician (a class that take statistics from user enter numbers)
 *
 * CONSTRUCTOR for statistician class
 * 	statistician()
 *		Postcondition: A statistician with no values added is initialized.
 *					As such, its length will be 0, the sum is 0, and the 
 *					Smallest and Largest will be initialized after the first number is added.
 * MODIFICATION MEMBER FUNCTIONS for statistician class
 * 	void next_number (double newStat)
 *		Postcondition: The newStat is added to the class. If the length of the instance is 0,
 *					The newStat is initailized the the class' smallest and biggest value. Otherwise,
 *					the smallest and biggest values are updated if newStat is one of those. No 
 *					matter what the length is, the last value is set to the newStat and the sum
 *					increases by newStat.
 *	void erase();
 *		Postcondition: the length is set to 0 and the sum is set to 0
 * 
 * CONSTANT MEMBER FUNCTIONS for statistician clss
 *	double mean()
 *		Postcondition: The arithmetic mean is returned as double, using the formula the total sum
 *					divide the total number of numbers
 *
 *	double last()
 *		Postcondition: return the last number added
 *
 *	double sum()
 *		Postcondition: return the sum of every number added
 *
 *	double smallest()
 *		Postcondition: return the smallest number added
 *
 *	double largest()
 *		Postcondition: return the largest number added
 *
 * NONMEMBER FUNCTIONS for statistician class
 *	statistician operator + (const statistician& s1, const statistician& s2)
 *		Postcondition: return the class that would be obtained by adding every value in s1,
 *					then every value in s2, both in order
 *
 * VALUE SEMANTICS
 *	Assignment operator and copy constructor can be used with statistician class.
 */

#ifndef STATISTICIAN_H
#define STATISTICIAN_H

namespace myStats
{

	class statistician
	{
		public:
			statistician();
			void next_number(double newStat);
			double mean();
			void erase();
			int length() const { return Length; }
			double last() const { return Last; }
			double sum() const { return Sum; }
			double smallest() const { return Smallest; }
			double largest() const { return Largest; }
			void operator = (const statistician& s1);
			//Friend function
			friend statistician operator + (const statistician& s1, const statistician& s2);

		private:
			int Length;
			double Last;
			double Sum;
			double Smallest;
			double Largest;					
	};
	
}

#endif