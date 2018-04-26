/*
 * Lyman Shen, 10/7/17
 *
 * FILE: random.h
 * class provided RandGen (class that generates psuedo-random numbers)
 *
 * CONSTRUCOTOR for RandGen class
 *	RandGen(int initSeed = 1, int initMultiplier = 37, int initIncrement = 383, int initModulus = 769)
 *		Postcondition: Generator set with seed, multiplier, increment, modulus given;
 *					If they are not given, use default values
 *
 * MODIFICATION MEMBER FUNCTIONS
 *	int nest()
 *		Postcondition: seed is changed and the next number in psuedo-random sequence is returned.
 *
 *	void setSeed(int newSeed)
 *		Postcondition: newSeed is set to the seed of the generator.
 */

#ifndef RANDOM_H
#define RANDOM_H

namespace myNum
{
	class RandGen
	{
		public:
			RandGen(int initSeed = 1, int initMultiplier = 37, int initIncrement = 383, int initModulus = 769);
			int next();
			void setSeed(int newSeed);
		private:
			int seed;
			int multiplier;
			int increment;
			int modulus;
	};
}

#endif