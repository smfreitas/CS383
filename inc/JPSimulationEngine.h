/*
 * JPSimulationEngine.h
 *
 *  Created on: Sep 27, 2017
 *      Author: james
 */

#ifndef JPSIMULATIONENGINE_H_
#define JPSIMULATIONENGINE_H_
#include "JPConstants.h"
#include "JPLane.h"
#include "JPIntersection.h"
#include "../src/james/SFCar.h"

class JPSimulationEngine {
public:
	JPSimulationEngine();
	virtual ~JPSimulationEngine();
	void start();
	void pause();
	void step();
	void step(double sec);

	//double* getThroughput(int direction, int &laneCount);
	//getWhateverElseWeTracked()

private:
	//Base configuration
	//Lane lanes[4][6];
	int _laneCounts[4];
	double _duration;
	double _initTime;
	double _timeScale;
	//TrafficLight light;

	//Internal Constants
	const double turnSpeed = 20;
	//const double straightSpeed = 20;
	const double reactionTime= 0.25;

	//Running Variables
	double _time;
	bool _paused;
	//long _throughput[4][MAX_LANES_MACRO];
	double _nextCreationTime[4];

	//Internal Methods
	void run();
	double intersectionDeceleration(double pos, double speed, double pcPos, double pcSpeed, SFCar *car);
	//double carDeceleration();
	void processLane(JPLane *lane);

	//void chooseLane(Car car, int direction,Lane lanes[][])

};

#endif /* JPSIMULATIONENGINE_H_ */
