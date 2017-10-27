/*
 * JPIntersection.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: james
 */

#include "../../inc/JPIntersection.h"
#include "../../inc/JPIntersectionExceptions.h"

static int count = 0; //enforce only 1 intersection

JPIntersection::JPIntersection()
{
	if(1 == count)
		throw JPMultipleIntersectionsException();
	else
		count = 1;

	_laneExit[0] = 600.0;
	_laneExit[1] = 600.0;
}

void JPIntersection::setLaneOffset(int direction, double offset) {
}

void JPIntersection::setTrackedLaneLength(int direction, double distance) {
}

void JPIntersection::setSpeedLimits(double northSouth, double eastWest) {
}

double JPIntersection::getTrackedLaneLength(int direction)
{
	return 0.0;
}

JPIntersection::~JPIntersection()
{
	count = 0;
}

void JPIntersection::finalize() {
}

void JPIntersection::setLaneOffsets(double north, double south, double east,
		double west) {
}

void JPIntersection::setTrackedLaneLengths(double north, double south,
		double east, double west) {
}

void JPIntersection::setTrackedExitLength(double northSouth,
		double eastWest) {
}

void JPIntersection::addLane(int direction, int position, int turnOptions,
		int leftTarget, int rightTarget) {
}

double JPIntersection::getLaneOffset(int direction)
{
	return _laneOffsets[direction];
}

double JPIntersection::getLaneOffsetInFeet(int direction)
{
	return 10.0 * _laneOffsets[direction];
}

void JPIntersection::getLaneCounts(int& counts) {
}

int JPIntersection::getLaneCount(int direction)
{
	return 0;
}

double JPIntersection::getLaneExitLength(int direction)
{
	return 0;
}

JPLane* JPIntersection::getLane(int direction, int position)
{
	//validate position and direction
	return _lanes[direction][position];
}
