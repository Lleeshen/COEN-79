#include "lunarLander.h"
#include <iostream>
#include <cstdlib>

int main()
{
	myLander::lunarLander l1 (1,4,19900,150,600,5,100);
	double totalTime = 0;
	const double timeSeg = 0.5;
	std::cout << "Initial condition: FlowRate, Velocity, Altitude, Fuel, Mass, Max Fuel rate, Max thrust" << std::endl;
	std::cout << l1.getFlowRate() << " " << l1.getVelocity() << " " << l1.getAltitude()  << " " << l1.getFuel() << " " << l1.getMass() << " " << l1.getMaxFuelRate() << " " << l1.getMaxThrust() << std::endl;
	std::cout << "Every time 0.5s pass, conditions: Time, FlowRate, Velocity, Altitude, Fuel" << std::endl;
	while(l1.getAltitude() != 0)
	{
		l1.timePassage(timeSeg);
		totalTime += timeSeg;
		std::cout << "Time " << totalTime <<  ", Velocity " << l1.getVelocity() << ", Altitude " << l1.getAltitude() << ", Fuel " << l1.getFuel() << std::endl;
	}
	std::cout << "Total time taken is " << totalTime << std::endl;
	return EXIT_SUCCESS;
}

