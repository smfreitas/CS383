#ifndef TRAFFIC_CONSTANTS_HEADER
#define TRAFFIC_CONSTANTS_HEADER
#include <stdio.h>
#include <cmath>

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
	//NORTH(BOUND), SOUTH(BOUND), etc have been moved to class JPIntersection

	//These could be taken over by Samantha or I could retain them as members of
	//the SimEngine Class. Their actual values don't matter as long as they are unique.
	//However they may be useful for animating blinkers or something.
	const int DESIRE_STRAIGHT = 1;
	const int DESIRE_RIGHT = 2;
	const int DESIRE_LEFT = 4;

	//Traffic light colors have been taken over by Dakota

	/**
	 * \brief a simple portable test report function.
	 *
	 * \param name The name or description of the test.
	 * \param testFailed Zero for pass non zero for failure
	 * \return Returns the value of testPassed for easy use inline.
	 */
	inline int testOuptut(const char *name, const int testFailed)
	{
		// "\033[32mtext[\033[0m" change 32 to 31 for red. Not working on MSYS
		if(-1 == testFailed)
			printf("    %-65s[xFail ]\n", name);
		else if(0 == testFailed)
			printf("    %-65s[Passed]\n", name);
		else
			printf("    %-65s[Failed]\n", name);
		return testFailed;
	}

	/**
	 * \brief compare near equality for doubles
	 */
	inline bool deq(double d1, double d2)
	{
		double avg = (d1+d2)/2;
		double dif = std::abs(d1-d2);
		if( dif/avg < 0.00001)
			return true;
		else
			return false;
	}
}
#endif
