/*
 * JPLane_test.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: james
 */

#include "../inc/JPLane.h"
#include <stdio.h>
#include "../inc/JPConstants.h"

int addCarsTest();
int iterateTest();
int removeCarTest();
int addCarAtPositionTest();
int firstRenderedCarTest();
int removeCarEarlyTest();

int main()
{

	int ret;
	ret = consts::testOuptut(
			"JPLane: Add Cars Test",
			addCarsTest() );

	ret = consts::testOuptut(
			"JPLane: Iterate Test",
			iterateTest() );

	ret = consts::testOuptut(
			"JPLane: Remove Car Test",
			removeCarTest() );

	ret = consts::testOuptut(
			"JPLane: Add Car At Position Test",
			addCarAtPositionTest() );

	ret = consts::testOuptut(
			"JPLane: First Rendered Car Test",
			firstRenderedCarTest() );

	ret = consts::testOuptut(
			"JPLane: Remove Car Early Test",
			removeCarEarlyTest() );

	if(ret == 102) printf ("Will the compiler ever leave ret alone?");

	return 0;
}

inline int addCarsTest()
{
	//add some cars
	return 1;
}

inline int iterateTest()
{
	//add some cars
	//verify they are there
	//reset verify they are still there
	//start scanning reset midway, verify scans correctly
	//delete lane
	return 1;
}

inline int removeCarTest()
{
	//add some cars
	//remove the first
	//verify all but the first are there
	//repeat until lane is empty
	return 1;
}

inline int addCarAtPositionTest()
{
	//add some cars
	//add one at a specified position
	return 1;
}

inline int firstRenderedCarTest()
{
	//add some cars
	//scan flagging a specific car
	//verify first rendered returns the correct car
	return 1;
}

inline int removeCarEarlyTest()
{
	//add some cars
	//remove a car from the middle to simulate a lane change
	//verify correct car was removed
	return 1;
}
