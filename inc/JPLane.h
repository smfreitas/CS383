/*
 * JPLane.h
 *
 *  Created on: Oct 20, 2017
 *      Author: james
 */

//change this when I have a real class to work with
#include "../src/james/SFCar.h"


#ifndef SRC_JAMES_JPLANE_H_
#define SRC_JAMES_JPLANE_H_

/**
 * A lane is a linked list of cars that may be iterated over for computation or rendering.
 * The list is primarily operated as a queue with a few special functions for early
 * removal and addition. Throughout this documentation, the beginning of the lane
 * refers the first i.e. forward most car. So when iterating over the lane a given
 * car will be moved before the car that is physically behind it.
 *
 * This class is NOT THREAD SAFE. Due to the use of the iterator, only one thread
 * should access an instance of this class at a given time.
 */
class JPLane
{
public:
	JPLane();

	/**
	 * \brief resets the iterator back to the first car.
	 *
	 * This will cause the getNextCar() method to restart at the beginning of the
	 * lane. The next call to getNextCar() will return the first car.
	 */
	void resetToFirstCar();

	/**
	 * \brief Returns the next car in the lane.
	 *
	 * If this is the first call since resetToFirstCar the first car will be returned.
	 * \return Zero if there are no more cars in the lane, otherwise the next.
	 */
	SFCar *getNextCar();

	/**
	 * \brief Return the first car that might be renderable.
	 *
	 * This function returns the car marked by the flagCarAsFirstRendered() method
	 * and sets the iterator to the next car following it.
	 * It's aim is to prevent unnecsary iteration by skipping the cars in the
	 * beginning region of the lane that is out of view of the visualization.
	 *
	 * The fact that the car is actually in a renderable region should not be
	 * trusted and should be checked because:
	 * -# The engine may flag early for example due to mismatched dimensions (i.e) 800x600
	 * -# The engine may not flag at all in which case it will fall back to returning the first car in the lane.
	 *
	 * \return the first car that can be rendered or one shortly before the renderable region
	 */
	SFCar *getFirstRenderedCar();

	/**
	 * \brief Remove the last car to be returned from the lane.
	 *
	 * This is used for early removal of cars that change lanes.
	 */
	void removeCurrentCar();

	/**
	 * \brief Remove the first car in the lane.
	 *
	 * This is when the first car has reached the tracked boundary and we no longer
	 * care about it.
	 */
	void removeFirstCar();

	/**
	 * \brief Add a car at specific physical position within the lane.
	 *
	 * This is used to move a car into its new lane when turning.
	 * \param car the car to be added.
	 * \param position the position in feet
	 */
	void addCarAtPos(SFCar *car, double position);

	/**
	 * \brief Add a car at the end of the lane.
	 *
	 * \param car the car to be added.
	 */
	void addCarAtEnd(SFCar *car);

	/**
	 * \brief Flag the current car in the iteration as the first rendered.
	 *
	 * This is used while the simulation engine is iterating over the lane and
	 * processing it. When the engine reaches the first car that is within the
	 * visualization's field of view, it flags that car with this method.
	 */
	void flagCarAsFirstRendered();

	virtual ~JPLane();

private:
	//_iterator
	bool _renderFlagged;
};

#endif /* SRC_JAMES_JPLANE_H_ */
