/*
 * JPIntersection.h
 *
 *  Created on: Oct 21, 2017
 *      Author: james
 */

#ifndef SRC_JAMES_JPINTERSECTION_H_
#define SRC_JAMES_JPINTERSECTION_H_
#include "JPLane.h"
/**
 * \brief A class that serves as a container and validator for an intersection.
 *
 * Usage: Setup
 * \code{cpp}
 * Intersection *intersection;
 * intersection = new Intersection();
 *
 *
 * //this aligns the intersection so that the NORTH/SOUTH lanes are offset by two
 * //lane widths and EAST/WEST lanes are offset by 2 lane widths.
 * //i.e. the the northwest corner is 2.5 lane widths
 * //to the left of the center and 2 lane widths, above the center.
 * intersection->setLaneOffsets(2.5,2.5,2,2);
 * \endcode
 *
 * Usage: Accessing lanes.
 *\code{cpp}
 * Intersection *intersection;
 * //initialize or acquire intersection object...
 * int direction, laneNum;
 * int laneCounts[4];
 * Lane *lane;
 *
 * intersection->getLaneCounts(laneCounts);
 * for(direction = 0; direction < 4; direction++)
 * {
 * 	for(laneNum = 0; laneNum < laneCounts[direction]; laneNum++)
 * 	{
 * 		lane = intersection->getLane(direction, laneNum);
 * 		//use lane
 * 	}
 * }
 * \endcode
 */
class JPIntersection {
public:
	//CONSTANT MEMBERS FOR INTERCLASS COMMUNICATION
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
	static const int MAX_LANES = MAX_LANES_MACRO;

	/**
	 * \brief The width of the lane in feet (10).
	 */
	static const int LANE_WIDTH = 10;

	/*
	 *  \brief The maximum tracked length of
	 */
	static const int MAX_LANE_LENG = 2 * 5280;
	/**
		 * \brief Designates  a lane that permits going straight.
		 *
		 * Lane turn directions can be added Initializing a lane with (JPIntersection::STRAIGHT + JPIntersection::RIGHT)
		 * will allow cars in that lane to go either straight or right.
		 */
	static const int STRAIGHT = 1;

		/**
		 * \brief Designates a lane that permits left turns.
		 *
		 * Lane turn directions can be added Initializing a lane with (JPIntersection::STRAIGHT + JPIntersection::RIGHT)
		 * will allow cars in that lane to go either straight or right.
		 */
	static const int RIGHT = 2;

		/**
		 * \brief Designates a lane that permits left turns without a left turn signal.
		 *
		 * Left turns have two distinct situations. The first is a left turn lane without an
		 * explicit left turn signal. Here when the light is green, the driver waits for a break in
		 * oncoming traffic before turning. The second situation is where the lane has an explicit
		 * left turn signal either a three lamp with left arrows or a 5 lamp. This constant describes
		 * first situation. It is mutually exclusive with JPIntersection::LEFT_ON_SIGNAL_ONLY.
		 *
		 * Lane turn directions can be added Initializing a lane with (JPIntersection::STRAIGHT + JPIntersection::RIGHT)
		 * will allow cars in that lane to go either straight or right.
		 */
	static const int LEFT_NO_SIGNAL = 4;

		/**
		 * \brief Left for lanes which may only turn left on a left arrow.
		 *
		 * Left turns have two distinct situations. The first is a left turn lane without an
		 * explicit left turn signal. Here when the light is green, the driver waits for a break in
		 * oncoming traffic before turning. The second situation is where the lane has an explicit
		 * left turn signal either a three lamp with left arrows or a 5 lamp. This constant describes
		 * second situation. It is mutually exclusive with JPIntersection::LEFT_NO_SIGNAL.
		 *
		 * Lane turn directions can be added Initializing a lane with (JPIntersection::STRAIGHT + JPIntersection::RIGHT)
		 * will allow cars in that lane to go either straight or right.
		 */
	static const int LEFT_ON_SIGNAL_ONLY = 8;

		/**
		 * \brief The north position.
		 *
		 * This identifier is used to designate lanes that begin in the
		 * physically north position of the intersection. Synonymous with
		 * SOUTHBOUND.
		 */
	static const int NORTH = 0;

		/**
		 * \brief The east position.
		 *
		 * This identifier is used to designate lanes that begin in the
		 * physically north position of the intersection. Synonymous with
		 * WESTBOUND.
		 */
	static const int EAST = 1;

		/**
		 * \brief The south position.
		 *
		 * This identifier is used to designate lanes that begin in the
		 * physically north position of the intersection. Synonymous with
		 * NORTHBOUND.
		 */
	static const int SOUTH = 2;

		/**
		 * \brief The west position.
		 *
		 * This identifier is used to designate lanes that begin in the
		 * physically north position of the intersection. Synonymous with
		 * EASTBOUND.
		 */
	static const int WEST = 3;

		/**
		 * \brief Designates a lane where traffic travels in the south direction.
		 *
		 * Synonymous with NORTH.
		 */
	static const int SOUTHBOUND = NORTH;

		/**
		 * \brief Designates a lane where traffic travels in the west direction.
		 *
		 * Synonymous with JPIntersection::EAST.
		 */
	static const int WESTBOUND = EAST;


		/**
		 * \brief Designates a lane where traffic travels in the north direction.
		 *
		 * Synonymous with JPIntersection::SOUTH.
		 */
	static const int NORTHBOUND = SOUTH;

		/**
		 * \brief Designates a lane where traffic travels in the east direction.
		 *
		 * Synonymous with JPIntersection::WEST.
		 */
	static const int EASTBOUND = WEST;

	JPIntersection();

	/**
	 * \brief set the offset (in lanes) of the rightmost lane.
	 *
	 * This function is used to set
	 */
	void setLaneOffsets(double north, double south, double east, double west);
	double getLaneOffsets(double &offsets);
	double getLaneOffsetsInFeet(int &offsets);
	void getLaneCounts(int &counts);
	void addLane(int direction, int position, int turnOptions);
	JPLane *getLane(int direction, int position);
	virtual ~JPIntersection();

private:
	JPLane *_lanes[4][6];
	int _laneCounts[4];
	double _laneOffsets[4];
	double _laneLengths[4];

};

#endif /* SRC_JAMES_JPINTERSECTION_H_ */
