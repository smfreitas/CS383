/*
 * JPIntersection_test.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: james
 */
#include "../inc/JPIntersectionExceptions.h"
#include "../inc/JPIntersection.h"
#include "../inc/JPConstants.h"

#define JPEXCEPTION_REPLACE_ME JPMalformedIntersectionException

//checks of constants
int directionIterationCheck();
int directionOppositeCheck();
int laneDirectionBitFieldCheck();
int directionAndBoundOppositeCheck();

//error checks
int addingAfterFinalizedCheck();
int multipleIntersectionCheck();
int laneCollidesWithOncomingLaneCheck();
int twoLanesTurningToOneCheck();
int laneOffsetMismatchCheck();
int turningLaneCrossingStraightLaneCheck();
int laneNumberOutOfBoundsCheck();
int directionOutOfBoundsCheck();
int addingAfterFinalized();


//functionality
int addLanesCheck();

int main()
{
	int ret = 0;

	//the following functions verify the constants are setup correctly
	ret = consts::testOuptut(
			"JPIntersection: constants: Direction Iteration Check",
			directionIterationCheck());

	ret = consts::testOuptut(
			"JPIntersection: constants: Direction Opposite Check",
			directionOppositeCheck());

	ret = consts::testOuptut(
			"JPIntersection: constants: Lane Direction Bit Field Check",
			laneDirectionBitFieldCheck());

	ret = consts::testOuptut(
			"JPIntersection: constants: Direction And Bound Opposite Check",
			directionAndBoundOppositeCheck());

	//the following functions test to make sure exceptions are thrown when they shoudl be
	ret = consts::testOuptut(
			"JPIntersection: Lane Collides With Oncoming Lane Error",
			laneCollidesWithOncomingLaneCheck() );

	ret = consts::testOuptut(
			"JPIntersection: Two Lanes Turning to One Error",
			twoLanesTurningToOneCheck() );

	ret = consts::testOuptut(
				"JPIntersection: Lane Offset Mismatch Error",
				laneOffsetMismatchCheck() );

	ret = consts::testOuptut(
				"JPIntersection: Turning Lane Crossing Straight Lane Error",
				turningLaneCrossingStraightLaneCheck() );

	ret = consts::testOuptut(
				"JPIntersection: Lane Number Out of Bounds Error",
				laneNumberOutOfBoundsCheck() );

	ret = consts::testOuptut(
				"JPIntersection: Lane Direction Out of Bounds Error",
				directionOutOfBoundsCheck() );

	ret = consts::testOuptut(
				"JPIntersection: Missing Lanes Error",
				multipleIntersectionCheck() );

	ret = consts::testOuptut(
				"JPIntersection: Adding After Finalized Error",
				addingAfterFinalizedCheck() );

	//this method verifies that lanes are correctly added and retrieved
	ret = consts::testOuptut(
				"JPIntersection: Adding Lanes Test",
				addLanesCheck() );

	/*blank
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			);
*/

	if( 100 == ret ) { printf("This is just here to suppress non-use warnings"); }
	return 0;
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
		if(JPIntersection::NORTH == i)
		{
			northMet = 1;
			if( previous != -5 && previous != JPIntersection::WEST)
				return 1;
			previous = i;
		}
		else if(JPIntersection::EAST == i)
		{
			eastMet = 1;
			if( previous != -5 && previous != JPIntersection::NORTH)
				return 1;
			previous = i;
		}
		else if(JPIntersection::SOUTH == i)
		{
			southMet = 1;
			if( previous != -5 && previous != JPIntersection::EAST)
				return 1;
			previous = i;
		}
		else if(JPIntersection::WEST == i)
		{
			westMet = 1;
			if( previous != -5 && previous != JPIntersection::SOUTH)
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
	//printf("EASTBOUND : %d\n",JPIntersection::EASTBOUND );
	//printf("EASTBOUND : %d\n", (JPIntersection::EASTBOUND + 2)%4);
	//printf("WESTBOUND : %d\n",JPIntersection::WESTBOUND);
	if( (JPIntersection::SOUTHBOUND + 2)% 4 != JPIntersection::NORTHBOUND)
		return 1;
	if( (JPIntersection::NORTHBOUND + 2)% 4 != JPIntersection::SOUTHBOUND)
		return 2;
	if( (JPIntersection::EASTBOUND + 2)% 4 != JPIntersection::WESTBOUND)
		return 3;
	if( (JPIntersection::WESTBOUND + 2)% 4 != JPIntersection::EASTBOUND)
		return 4;
	return 0;
}

/**
 * \brief Verify that SOUTHBOUND and NORTH etc are synonyms
 */
int directionAndBoundOppositeCheck()
{
	if(JPIntersection::SOUTHBOUND != JPIntersection::NORTH)
		return 1;
	if(JPIntersection::NORTHBOUND != JPIntersection::SOUTH)
		return 1;
	if(JPIntersection::EASTBOUND != JPIntersection::WEST)
		return 1;
	if(JPIntersection::WESTBOUND != JPIntersection::EAST)
		return 1;
	return 0;
}

/**
 * \brief Verify a separate bit is used for each lane direction.
 *
 * Lanes can permit multiple directions. Using a bit field to specify
 * directions requires that each constant occupy a separate bit.
 * To verify this, a cumulative field is used. It is initialized to
 * one of the constants. A new bit is set if and only if or-ing it with
 * the field is different. This does not ensure that only a new bit was set.
 * To achieve this it is and-ed with the sumfileld, and the result is verfied to be zero.
 * This check is performed for each successive
 * constant in the set, then that constant is added to the field.
 */
int laneDirectionBitFieldCheck()
{
	int sumField = JPIntersection::STRAIGHT;

	//check against right
	if( ((sumField | JPIntersection::RIGHT) == sumField)&&
			((sumField & JPIntersection::RIGHT) == 0))
		return 1;
	sumField += JPIntersection::RIGHT;


	//check against left
	if( ((sumField | JPIntersection::LEFT) == sumField) &&
			((sumField & JPIntersection::LEFT) == 0))
		return 1;
/*
	//check against LOSO
	if( ((sumField | JPIntersection::LEFT_ON_SIGNAL_ONLY) == sumField) &&
			((sumField & JPIntersection::LEFT_ON_SIGNAL_ONLY) == 0))
		return 1;
	sumField += JPIntersection::LEFT_ON_SIGNAL_ONLY;

	//check against LNS
	if( ((sumField | JPIntersection::LEFT_NO_SIGNAL) == sumField) &&
			((sumField & JPIntersection::LEFT_NO_SIGNAL) == 0))
		return 1;
*/
	return 0;
}

inline int addingAfterFinalizedCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}
}

inline int multipleIntersectionCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}

}

inline int laneCollidesWithOncomingLaneCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}

}

inline int twoLanesTurningToOneCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}
}

inline int laneOffsetMismatchCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}

}

inline int turningLaneCrossingStraightLaneCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}

}

inline int laneNumberOutOfBoundsCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}
}

inline int directionOutOfBoundsCheck()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}
}

inline int addingAfterFinalized()
{
	try
	{
		//bad news if you made it here
		return 1;
	}
	catch(JPEXCEPTION_REPLACE_ME & e)
	{
		//some checks on output
		return 0;
	}
}

inline int addLanesCheck()
{
	return 1;
}
