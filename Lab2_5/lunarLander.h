/*
 * Lyman Shen, 10/7/17
 *
 * FILE: lunarLander.h
 * Class provided: lunarLander (to simulate a ship landing on the moon)
 *
 * CONSTRUCTOR for lunarLander class
 *	lunarLander(double initFlowRate = 0.0, double initVelocity = 0.0, double initAltitude = 1000.0, double initFuel = 1700.0, double initMass = 900.0, double initMaxFuelRate = 10, double initMaxThrust = 5000);
 *		Postcondition: set initial conditionns with parameters, otherwise use default initail conditions.
 *
 * MODIFICATION MEMBER FUNCTIONS
 *	void setFlowRate(double newFlowRate)
 *		Precondition: newFlowRate is between 0 and 1
 *		Postcondition: newFlowRate is set as the flow rate, as ratio between current flow rate and max flow rate
 *
 *	void timePassage(double t);
 *		Precondition: t is positive
 *		Postcondition: The conditions for flowRate, velocity, altitude, and fuel are changed in accordance to physics formulas.
 *
 * CONSTANT MEMBER FUNCTIONS
 *	double getFlowRate()
 *		Postcondition: return the flow rate as ratio between cureent flow rate and max flow rate	
 *
 *	double getVelocity()
 *		Postcondition: return the current velocity of the moon lander
 *
 *	double getFuel()
 *		Postcondition: return mass of fuel left
 *
 *	douvle getMass()
 *		Postcondition: return mass moon lander without fuel
 *
 *	double getMaxFuelRate()
 *		Postcondition: return the maximum fuel rate
 *
 *	double getMaxThrust()
 *		Postcondition: return the maximum thrust
 */

#ifndef LUNAR_LANDER_H
#define LUNAR_LANDER_H

namespace myLander
{
	class lunarLander {
		public:
			lunarLander(double initFlowRate = 0.0, double initVelocity = 0.0, 
				double initAltitude = 1000.0, double initFuel = 1700.0, 
				double initMass = 900.0, double initMaxFuelRate = 10, double initMaxThrust = 5000);
			void setFlowRate(double newFlowRate);
			void timePassage(double t);
			double getFlowRate() { return flowRate; }
			double getVelocity() { return velocity; }
			double getAltitude() { return altitude; }
			double getFuel() { return fuel; }
			double getMass() { return mass; }
			double getMaxFuelRate() { return maxFuelRate; }
			double getMaxThrust() { return maxThrust; }
		private:
			double flowRate;
			double velocity;
			double altitude;
			double fuel;
			double mass;
			double maxFuelRate;
			double maxThrust;
	};
}

#endif