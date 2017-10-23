/*
 * JPTrafficModel.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: james
 */

#include "../../inc/JPTrafficModel.h"
#include "../../inc/JPIntersection.h"

JPTrafficModel::JPTrafficModel()
{
	_rate = 1;
	_turnCDF[0]=0;
	_turnCDF[1]=1;
	_turnCDF[2]=2;
}
void JPTrafficModel::setProbability(int direction, double left, double right, double straight)
{

}
void JPTrafficModel::setTrafficRate(int direction, double rate)
{
	//if(rate <= 0 || rate > 2000)
	if(JPIntersection::NORTH == direction ||
			JPIntersection::SOUTH == direction ||
			JPIntersection::EAST == direction ||
			JPIntersection::WEST == direction)
		_rate = rate;
	//else do error things
}
double JPTrafficModel::getNextTiming(int direction, int &turnDirection)
{
	turnDirection = 1;
	return 0.0;
}
JPTrafficModel::~JPTrafficModel()
{
	// TODO Auto-generated destructor stub
}

