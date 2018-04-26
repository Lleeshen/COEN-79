/*
 * Lyman Shen, 10/7/17
 *
 * FILE: lunarLander.h
 * class implemented: lunarLander (see lunarLander.h for documentation)
 */

#include "lunarLander.h"

namespace myLander
{
	lunarLander::lunarLander(double initFlowRate, double initVelocity, double initAltitude, 
		double initFuel, double initMass, double initMaxFuelRate, double initMaxThrust)
	{
		flowRate = initFlowRate;
		velocity = initVelocity;
		altitude = initAltitude;
		fuel  = initFuel;
		mass = initMass;
		maxFuelRate = initMaxFuelRate;
		maxThrust = initMaxThrust;
	}

	void lunarLander::setFlowRate(double newFlowRate)
	{
		flowRate = newFlowRate;
	}

	void lunarLander::timePassage(double t)
	{
		double vChange = (((flowRate * maxThrust) / (mass + fuel)) - 1.62) * t;
		double aChange = velocity * t;
		double flChange = -flowRate * maxFuelRate * t;
		flowRate = (flowRate != 0 && fuel <= 0) ? 0 : flowRate;
		velocity += vChange;
		altitude += aChange;
		fuel += flChange;
		if(altitude < 0)
		{
			altitude = 0;
			velocity = 0;
		}
		if (fuel < 0)
		{
			fuel = 0;
		}
	}
}