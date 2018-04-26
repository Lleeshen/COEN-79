/*
 * Lyman Shen, 10/7/17
 *
 * class implemented: RandGen (see random.h for documentation)
 */

#include "random.h"

namespace myNum {
	RandGen::RandGen(int initSeed, int initMultiplier, int initIncrement, int initModulus)
	{
		seed = initSeed;
		multiplier = initMultiplier;
		increment = initIncrement;
		modulus = initModulus;	
	}

	int RandGen::next()
	{
		int newNum;
		newNum = (multiplier * seed + increment) % modulus;
		setSeed(newNum);
		return newNum;
	}

	void RandGen::setSeed(int newSeed)
	{
		seed = newSeed;
		return;
	}
}