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
#include "JPIntersectionGrid.h"
#include "JPTrafficModel.h"
#include "JPUpdatableInterface.h"
#include "../src/james/SFCar.h"

class JPSimulationEngine {
public:
	JPSimulationEngine();
	virtual ~JPSimulationEngine();

	//control
	void start();
	void pause();
	void step();
	void step(double sec); /** \brief Advance the simulation by sec seconds */
	void end(); /** \brief Terminate the simulation allow for report generation */

	//configuration
	void setVisualization(JPUpdatableInterface *interface);
	void setTrafficModel(JPTrafficModel *model);
	void setIntersection(JPIntersection *intersection);
	//void setTrafficLight(DJTrafficLightManager *light);
	void setInitTime(double secs); /** \brief Set how long the initialization phase runs */

	//double* getThroughput(int direction, int &laneCount);
	//getWhateverElseWeTracked()

private:
	//Base configuration
	int _laneCounts[4];
	double _duration;  //not used at present
	double _initTime;  //default 5 minutes
	double _timeScale; //default 1.0 = realtime
	double _stepTime; //seconds default 0.1

	//Internal Constants
	const double turnSpeed = 20 * 5280/3600; //20 mph
	const double acceleration = 5.0 * 5280/3600; //ft/s^2 from 5 mph/s
	//const double reactionTime= 0.25; //probably not used

	//internal simulation objects
	JPUpdatableInterface *_graphic;
	JPIntersection *_intersection;
	JPIntersectionGrid *_iGrid;
	JPTrafficModel *_trafficModel;
	//DJTrafficLightManager *_light

	//Running Variables
	double _time;
	bool _paused;
	//long _throughput[4][MAX_LANES_MACRO];
	double _nextCreationTime[4];
	double _yellowTime[4];

	//Internal Methods
	void run();
	double intersectionDeceleration(double pos, double speed, double pcPos, double pcSpeed, SFCar *car);
	//previous car's speed/pos
	//double carDeceleration(SFCar &car, double prevSpeed, double prevPos);

	//returns position
	//double translatePosition(int direction, int lnNum,
	void processLane(JPLane *lane);
	void addCars(int direction, JPLane lane, double timeStep);

};

#endif /* JPSIMULATIONENGINE_H_ */
