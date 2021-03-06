/*
 * JPTrafficModel.h
 *
 *  Created on: Oct 11, 2017
 *      Author: james
 */

#ifndef SRC_JAMES_TRAFFICMODEL_H_
#define SRC_JAMES_TRAFFICMODEL_H_

/**
 * \brief Generates entry timing and direction of new cars.
 *
 * This class is used to determine when new cars are added to the model, and what direction they will go.
 * For each direction the rate in cars per hour is specified as is the probability  for eache direction.
 * The probabilities are relative so they do not need to add up to 100.
 *
 * Usage is as follows:
 * \code{cpp}
 * JPTrafficModel = *model;
 * model = new JPTrafficModel;
 * model->setProbability(Intersection::NORTH, 20, 20, 60);
 * model->setProbability(Intersection::SOUTH, 15, 20, 60);
 * model->setProbability(Intersection::EAST, 20, 15, 60);
 * model->setProbability(Intersection::WEST, 20, 20, 70);
 * \endcode
 */
class JPTrafficModel {
public:
	JPTrafficModel();
	/**
	 * \brief Set the relative probability that a car entering from the given direction
	 * will want to turn right, turn left or go straight
	 *
	 * \param direction The direction the car is going or side of the intersection being entered (e.g. JPIntersection::NORTH or JPIntersection::SOUTH)
	 * \param left The relative probability of a car wanting to turn left
	 * \param right The relative probability of a car wanting to turn right
	 * \param straight The relative probability of a car wanting to go straight
	 *
	 * Because the probabilities are relative, they do not need to add up to 100
	 */
	void setProbability(int direction, double left, double right, double straight);

	/**
	 * \brief Sets the rate that cars will be introduced for the given direction.
	 *
	 * \param direction The direction the car is going or side of the intersection being entered (e.g. JPIntersection::NORTH or JPIntersection::SOUTH)
	 * \param rate The rate at which cars enter in cars per hour.
	 */
	void setTrafficRate(int direction, double rate);

	/**
	 * \brief Returns the time till the next car and sets its turn direction.
	 *
	 * \param direction The direction the car is going or side of the intersection being entered (e.g. JPIntersection::NORTH or JPIntersection::SOUTH)
	 * \param turnDirection A variable for storing the desired turn direction. This value will be set to JPIntersection::RIGHT, JPIntersection::LEFT or JPIntersection::STRAIGHT.
	 * \return the amount of time until the next car enters a lane going the given direction
	 */
	double getNextTiming(int direction, int &turnDirection);
	virtual ~JPTrafficModel();

private:
	double _rate;
	double _turnCDF[3];
};

#endif /* SRC_JAMES_TRAFFICMODEL_H_ */
