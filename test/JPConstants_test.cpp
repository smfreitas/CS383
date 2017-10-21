
#include "../inc/JPConstants.h"

#include <stdio.h>

int directionIterationCheck();
int directionOppositeCheck();
int laneDirectionBitFieldCheck();
int directionAndBoundOppositeCheck();
int lightColorsBitFieldCheck();

//int testReportOuptut(char *name, int testStatus);
/**
 * \brief Main function to test assertions of the constants file.
 *
 * The constants file makes several guarantees that must be upheld for the program to work properly.
 * The following assertions are tested.
*/

int main()
{
	int ret = 0;
	ret = consts::testOuptut(
			"jponstants: Direction Iteration Check",
			directionIterationCheck());

	ret = consts::testOuptut(
			"jponstants: Direction Opposite Check",
			directionOppositeCheck());

	ret = consts::testOuptut(
			"jponstants: Lane Direction Bit Field Check",
			laneDirectionBitFieldCheck());

	ret = consts::testOuptut(
			"jponstants: Direction And Bound Opposite Check",
			directionAndBoundOppositeCheck());

	ret = consts::testOuptut(
			"jponstants: Light Colors Bit Field Check",
			lightColorsBitFieldCheck());

	if( 100 == ret ) { printf("This is just here to suppress non-use warnings"); }
}

/**
 * Verify that all directions can be iterated over.
 */
int directionIterationCheck()
{
	//flags that make sure each one was hit
	bool northMet = 0;
	bool southMet = 0;
	bool eastMet = 0;
	bool westMet = 0;

	int i;
	int previous = -5;
	//iterate over over the directions
	for(i =0; i < 4; i++)
	{
		//ensure each directions previous is correct
		//and flag that each direction is met
		if(consts::NORTH == i)
		{
			northMet = 1;
			if( previous != -5 && previous != consts::WEST)
				return 1;
			previous = i;
		}
		else if(consts::EAST == i)
		{
			eastMet = 1;
			if( previous != -5 && previous != consts::NORTH)
				return 1;
			previous = i;
		}
		else if(consts::SOUTH == i)
		{
			southMet = 1;
			if( previous != -5 && previous != consts::EAST)
				return 1;
			previous = i;
		}
		else if(consts::WEST == i)
		{
			westMet = 1;
			if( previous != -5 && previous != consts::SOUTH)
				return 1;
			previous = i;
		}
	}

	if(! (northMet && southMet && eastMet && westMet) )
		return 1;

	return 0;
}

/**
 * \brief Verify that (direction + 2) % 4 yields the opposite direction.
 */
int directionOppositeCheck()
{
	//printf("EASTBOUND : %d\n",consts::EASTBOUND );
	//printf("EASTBOUND : %d\n", (consts::EASTBOUND + 2)%4);
	//printf("WESTBOUND : %d\n",consts::WESTBOUND);
	if( (consts::SOUTHBOUND + 2)% 4 != consts::NORTHBOUND)
		return 1;
	if( (consts::NORTHBOUND + 2)% 4 != consts::SOUTHBOUND)
		return 2;
	if( (consts::EASTBOUND + 2)% 4 != consts::WESTBOUND)
		return 3;
	if( (consts::WESTBOUND + 2)% 4 != consts::EASTBOUND)
		return 4;
	return 0;
}

/**
 * \brief Verify that SOUTHBOUND and NORTH etc are synonyms
 */
int directionAndBoundOppositeCheck()
{
	if(consts::SOUTHBOUND != consts::NORTH)
		return 1;
	if(consts::NORTHBOUND != consts::SOUTH)
		return 1;
	if(consts::EASTBOUND != consts::WEST)
		return 1;
	if(consts::WESTBOUND != consts::EAST)
		return 1;
	return 0;
}

/**
 * \brief Verify a separate bit is used for each lane direction.
 *
 * Lanes can permit multiple directions. Using a bit field to specify
 * directions requires that each constant occupy a separate bit.
 * To verify this, a cumulative field is used. It is initialized to
 * one of the constants. A bit is new if and only if or-ing it with
 * the field is different. This check is performed for each successive
 * constant in the set, then that constant is added to the field.
 */
int laneDirectionBitFieldCheck()
{
	int sumField = consts::STRAIGHT;

	//check against right
	if( (sumField | consts::RIGHT) == sumField)
		return 1;
	sumField += consts::RIGHT;

	//check against LOSO
	if( (sumField | consts::LEFT_ON_SIGNAL_ONLY) == sumField)
		return 1;
	sumField += consts::LEFT_ON_SIGNAL_ONLY;

	//check against LNS
	if( (sumField | consts::LEFT_NO_SIGNAL) == sumField)
		return 1;

	return 0;
}

/**
 * \brief Verify a separate bit is used for each light color.
 *
 * Because of 5 lamp lights, the traffic light permits multiple
 * simultaneous outputs.
 *  Using a bit field to specify
 * directions requires that each constant occupy a separate bit.
 * To verify this, a cumulative field is used. It is initialized to
 * one of the constants. A bit is new if and only if or-ing it with
 * the field is different. This check is performed for each successive
 * constant in the set, then that constant is added to the field.
 */
int lightColorsBitFieldCheck()
{
	int sumField = consts::RED;

	//check against Green
	if( (sumField | consts::GREEN) == sumField)
		return 1;
	sumField += consts::GREEN;

	//check against YELLOW
	if( (sumField | consts::YELLOW) == sumField)
		return 1;
	sumField += consts::YELLOW;

	//check against LEFT_GREEN
	if( (sumField | consts::LEFT_GREEN) == sumField)
		return 1;
	sumField += consts::LEFT_GREEN;

	//check against LEFT_BLINK_YELLOW
	if( (sumField | consts::LEFT_BLINK_YELLOW) == sumField)
		return 1;

	return 0;
}
