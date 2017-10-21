#ifndef TRAFFIC_CONSTANTS_HEADER
#define TRAFFIC_CONSTANTS_HEADER
#include <stdio.h>

/**
 *  \brief A group of constants used throughout the program.
 *
 *  This namespace includes constants that are used throughout the
 *  project for communication between classes. It includes positions
 *  (NORTH, EAST, SOUTH, WEST) which are synonymous with travel directions
 *  (SOUTHBOUND, WESTBOUND, NORTHBOUND, EASTBOUND).
 *
 *  The positions and directions are GUARANTEED to be the consecutive
 *  numbers between 0 and 3 in a circular direction. It follows that all lanes can be iterated over
 *  using a numeric loop. For example to use the first lane of every direction:
 *  \code{cpp}
 *  int i;
 *  Lane lane;
 *  for (i = 0; i < 4; i++)
 *  {
 *  	lane = myIntersection.getLane(i, 0);
 *  	//do stuff with lane...
 *  }
 *  \endcode
 *
 *  It also follows that the opposite direction is always computable
 *  by adding two and computing the modulus.
 *  For example: SOUTHBOUND := (NORTHBOUND + 2) % 4.
 */
namespace consts
{
	//used as a define so it can be hard coded into array sizes
	/**
	 * \brief The maximum number of lanes supported. Presently 6.
	 *
	 * This is used in addition to the const value for instances where it is necessary to hard code the value such as
	 * statically defined allocated arrays.
	 */
	#define MAX_LANES_MACRO 6

	/**
	 * \brief The maximum number of lanes supported. Presently 6.
	 *
	 * This is synonymous with the value in MAX_LANES_MACRO.
	 */
	const int MAX_LANES = MAX_LANES_MACRO;

	/**
	 * \brief The width of the lane in feet (10).
	 */
	const int LANE_WIDTH = 10;

	/*
	 *  \brief The maximum tracked length of
	 */
	const int MAX_LANE_LENG = 2 * 5280;

	const int DESIRE_STRAIGHT = 1;
	const int DESIRE_RIGHT = 2;
	const int DESIRE_LEFT = 4;

	/**
	 * \brief Designates  a lane that permits going straight.
	 *
	 * Lane turn directions can be added Initializing a lane with (consts::STRAIGHT + consts::RIGHT)
	 * will allow cars in that lane to go either straight or right.
	 */
	const int STRAIGHT = 1;

	/**
	 * \brief Designates a lane that permits left turns.
	 *
	 * Lane turn directions can be added Initializing a lane with (consts::STRAIGHT + consts::RIGHT)
	 * will allow cars in that lane to go either straight or right.
	 */
	const int RIGHT = 2;

	/**
	 * \brief Designates a lane that permits left turns without a left turn signal.
	 *
	 * Left turns have two distinct situations. The first is a left turn lane without an
	 * explicit left turn signal. Here when the light is green, the driver waits for a break in
	 * oncoming traffic before turning. The second situation is where the lane has an explicit
	 * left turn signal either a three lamp with left arrows or a 5 lamp. This constant describes
	 * first situation. It is mutually exclusive with consts::LEFT_ON_SIGNAL_ONLY.
	 *
	 * Lane turn directions can be added Initializing a lane with (consts::STRAIGHT + consts::RIGHT)
	 * will allow cars in that lane to go either straight or right.
	 */
	const int LEFT_NO_SIGNAL = 4;

	/**
	 * \brief Left for lanes which may only turn left on a left arrow.
	 *
	 * Left turns have two distinct situations. The first is a left turn lane without an
	 * explicit left turn signal. Here when the light is green, the driver waits for a break in
	 * oncoming traffic before turning. The second situation is where the lane has an explicit
	 * left turn signal either a three lamp with left arrows or a 5 lamp. This constant describes
	 * second situation. It is mutually exclusive with consts::LEFT_NO_SIGNAL.
	 *
	 * Lane turn directions can be added Initializing a lane with (consts::STRAIGHT + consts::RIGHT)
	 * will allow cars in that lane to go either straight or right.
	 */
	const int LEFT_ON_SIGNAL_ONLY = 8;

	/**
	 * \brief The north position.
	 *
	 * This identifier is used to designate lanes that begin in the
	 * physically north position of the intersection. Synonymous with
	 * SOUTHBOUND.
	 */
	const int NORTH = 0;

	/**
	 * \brief The east position.
	 *
	 * This identifier is used to designate lanes that begin in the
	 * physically north position of the intersection. Synonymous with
	 * WESTBOUND.
	 */
	const int EAST = 1;

	/**
	 * \brief The south position.
	 *
	 * This identifier is used to designate lanes that begin in the
	 * physically north position of the intersection. Synonymous with
	 * NORTHBOUND.
	 */
	const int SOUTH = 2;

	/**
	 * \brief The west position.
	 *
	 * This identifier is used to designate lanes that begin in the
	 * physically north position of the intersection. Synonymous with
	 * EASTBOUND.
	 */
	const int WEST = 3;

	/**
	 * \brief Designates a lane where traffic travels in the south direction.
	 *
	 * Synonymous with NORTH.
	 */
	const int SOUTHBOUND = NORTH;

	/**
	 * \brief Designates a lane where traffic travels in the west direction.
	 *
	 * Synonymous with consts::EAST.
	 */
	const int WESTBOUND = EAST;


	/**
	 * \brief Designates a lane where traffic travels in the north direction.
	 *
	 * Synonymous with consts::SOUTH.
	 */
	const int NORTHBOUND = SOUTH;

	/**
	 * \brief Designates a lane where traffic travels in the east direction.
	 *
	 * Synonymous with consts::WEST.
	 */
	const int EASTBOUND = WEST;

	//Traffic light colors
	const int RED = 1; /** The light is red */
	const int YELLOW = 2; /** The light is yellow */
	const int GREEN = 4; /** The light is green */
	const int LEFT_GREEN = 8; /** The left arrow is green */
	const int LEFT_BLINK_YELLOW = 16; /** The left arrow is flashing yellow */
	const int LEFT_SOLID_YELLOW = 32; /** The left arrow is solid yellow */

	/**
	 * \Brief a simple portable test report function.
	 *
	 * \param name The name or description of the test.
	 * \param testPassed Zero for pass non zero for failure
	 * \return Returns the value of testPassed for easy use inline.
	 */
	inline int testOuptut(const char *name, const int testFailed)
	{
		if(0 == testFailed)
			printf("    %-65s[Passed]\n", name);
		else
			printf("    %-65s[Failed]\n", name);
		return testFailed;
	}
}
#endif
