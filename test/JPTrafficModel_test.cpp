/*
 * TrafficModel_test.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: james
 */

#include <stdio.h>
#include "../inc/JPTrafficModel.h"
#include "../inc/JPConstants.h"
#include "../inc/JPIntersection.h"

int directionOutOfBoundsTest();
int rateLessThanZeroTest();
int probabilityLessThanZeroTest();
int distributionTests();
int main()
{

	// "\033[32mtext[\033[0m" change 32 to 31 for red. Not working on MSYS
	consts::testOuptut("JPTrafficModel: Direction Out Of Bounds Test",
			directionOutOfBoundsTest() );
	consts::testOuptut("JPTrafficModel: Rate Less Than Zero Test",
			rateLessThanZeroTest() );
	consts::testOuptut("JPTrafficModel: Probability Less Than Zero Test",
			probabilityLessThanZeroTest() );
	distributionTests();

	return 0;
}

inline int directionOutOfBoundsTest()
{
	//verify that an out of bounds direction causes the correct exception
	return 1;
}

inline int rateLessThanZeroTest()
{
	//verify that a rate of less than 0 causes the correct exception
	return 1;
}

inline int probabilityLessThanZeroTest()
{
	//verify that a probability less than zero causes the correct exception
	return 1;
}

inline int distributionTests()
{
	//same data is used for both tests.

	JPTrafficModel tm;
	tm.setProbability(JPIntersection::NORTH,15,60,25); // -> no more than 10% error in distribution
	tm.setProbability(JPIntersection::SOUTH,10,0,0); // -> Only left turns
	tm.setProbability(JPIntersection::EAST,0,10,0); // -> Only right turns
	tm.setProbability(JPIntersection::WEST,0,0,10); // -> Only straight
	tm.setTrafficRate(JPIntersection::NORTH, 1);
	tm.setTrafficRate(JPIntersection::SOUTH, 10);
	tm.setTrafficRate(JPIntersection::EAST, 100);
	tm.setTrafficRate(JPIntersection::WEST, 1000);

	//20,000 calls getNextTiming()
	//verify distributions.
	consts::testOuptut("JPTrafficModel: Direction Distribution Test", 1);
	consts::testOuptut("JPTrafficModel: Rate Distribution Test", 1);
	return 1;
}
/*
Errors
direction != N/S/E/W
rate <= 0;
probability < 0

Tests
each invalid input
*/
