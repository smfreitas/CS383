#ifndef TRAFFIC_LIGHT_CONSTANTS_HEADER
#define TRAFFIC_LIGHT_CONSTANTS_HEADER
#include <stdio.h>

/**
 *  \brief A group of constants used throughout the traffic light module.
 *
 *  This namespace includes constants that are used throughout the
 *  traffic light module for a centralized area containing raw numbers assuming no
 *  time change has been made. There are two basic uses these constants have:
 *  ({TYPEOF}_DURATION) which are used to calculate the state in the cycle and
 *  (COLOR/TYPE) indicating the state to either change into or stay at.
 *
 *  Given a lane, time, and direction, the function getState can be called, which
 *  is guarenteed to return one of the constants defined below(integer) IF the fields given
 *  are valid. For example, to get the state of every light in every lane:
 *  \code{cpp}
 *  int i;
 *  Lane lane;
 *  for (i = 0; i < 4; i++)
 *  {
 *  	lane = myIntersection.getLane(i, 0);
 *  	state = getState(time, direction, lane);
 *      // more logic with states on a per-lane basis
 *  }
 *  \endcode
 *
 *  In addition, tests are wrote to ensure a crash won't happen.
 *  For example: if a NORTHBOUND light is green, getState(time, WESTBOUND, lane)
 *  will NEVER return green.
 */
namespace tlightconsts
{
    //used to set a base cycle duration, which can be computed against given a time multiplier
    /**
	 * \brief Gives clean integers for light duration to compute against
	 *
	 * Each duration gives a base time for which the light will stay in its current state. The
     * total state duration adds the standard GREEN/RED/YELLOW durations together. The specialized
     * arrow types can also be totaled to an entire CYCLE_DURATION (when adding in a normal red).
	 */
    const int CYCLE_DURATION = 18;
    
    const int GREEN_DURATION = 8;
    const int YELLOW_DURATION = 2;
    const int RED_DURATION = 8;
    const int GREEN_ARROW_DURATION = 4;
    const int YELLOW_ARROW_DURATION = 6;

    /**
	 * \brief Gives an easy way to keep the current state of light if no change was made.
	 *  
     * After a getState() or manageState() call, the current state will be checked and if 
     * nothing was changed, this will be returned. This ensures there will be no wasted resources
     * on constantly resetting the state to the same thing.
	 */
    const int NO_CHANGE = 0;

}
#endif