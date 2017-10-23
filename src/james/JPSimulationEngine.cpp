/*
 * SimulationEngine.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: james
 */

#include "../../inc/JPSimulationEngine.h"

JPSimulationEngine::JPSimulationEngine()
{
	// TODO Auto-generated constructor stub
	_duration = 0.0;
	_initTime = 300.0;
	_timeScale = 1.0;
	_time = 0.0;
	_paused = 1;

	int i;
	for(i = 0; i<4;  i++)
		_laneCounts[i] = 0;
}

JPSimulationEngine::~JPSimulationEngine()
{
	// TODO Auto-generated destructor stub
}

void JPSimulationEngine::start()
{

}

void JPSimulationEngine::pause()
{
}

void JPSimulationEngine::step()
{
}

void JPSimulationEngine::step(double sec)
{
}

/*
double* JPSimulationEngine::getThroughput(int direction, int &laneCount)
{
	double *throughput;
	throughput = new double[consts::MAX_LANES];
	return throughput;
}
*/
void JPSimulationEngine::run()
{

}

double JPSimulationEngine::intersectionDeceleration(double pos, double speed,
		double pcPos, double pcSpeed, SFCar* car)
{
	return 0.0;
}

void JPSimulationEngine::processLane(JPLane* lane)
{
}
