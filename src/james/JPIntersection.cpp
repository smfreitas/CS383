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

JPIntersection::~JPIntersection()
{
	count = 0;
}

