/*
 * IntersectionExceptions.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: james
 */

#include "../../inc/JPIntersectionExceptions.h"

JPMalformedIntersectionException::JPMalformedIntersectionException()
{
	_direction = -1;
	_lane = -1;
}
JPMalformedIntersectionException::JPMalformedIntersectionException(int direction)
{
	_direction = direction;
	_lane = -1;
}
JPMalformedIntersectionException::JPMalformedIntersectionException(int direction, int lane)
{
	_direction = direction;
	_lane = lane;
}

JPMalformedIntersectionException::~JPMalformedIntersectionException() throw()
{
	// TODO Auto-generated destructor stub
}

int JPMalformedIntersectionException::getOriginationLane()
{
	return _lane;
}

int JPMalformedIntersectionException::getDirection()
{
	return _direction;
}

const char* JPMalformedIntersectionException::what() const throw ()
{
	return "The intersection is not build correctly!";
}
//collide colliding
JPTwoLanesToOneException::JPTwoLanesToOneException(int direction, int thisLane, int targetLane, int collidingLane ):
		JPMalformedIntersectionException(direction, thisLane)
{
	_targetLane = targetLane;
	_collidingLane = collidingLane;
}

const char* JPTwoLanesToOneException::what() const throw ()
{
	return "";
}

int JPTwoLanesToOneException::getTargetLane()
{
	return _targetLane;
}

int JPTwoLanesToOneException::getCollidingLane()
{
	return _collidingLane;
}

JPMultipleIntersectionsException::JPMultipleIntersectionsException(){}

const char* JPMultipleIntersectionsException::what() const throw ()
{
	return "You can only instantiate one instance of JPIntersection";
}
