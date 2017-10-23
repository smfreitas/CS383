/*
 * JPIntersectionExceptions.h
 *
 *  Created on: Oct 22, 2017
 *      Author: james
 */
#include <exception>

#ifndef SRC_JAMES_MALFORMEDINTERSECTIONEXCEPTION_H_
#define SRC_JAMES_MALFORMEDINTERSECTIONEXCEPTION_H_


class JPMalformedIntersectionException: public std::exception
{
public:
	JPMalformedIntersectionException();
	JPMalformedIntersectionException(int direction);
	JPMalformedIntersectionException(int direction, int lane);
	virtual ~JPMalformedIntersectionException() throw();
	int getOriginationLane();
	int getDirection();
	virtual const char* what() const throw();

private:
	int _lane;
	int _direction;
};

/**
 * \brief User has tried to create more than one intersection
 */
class JPMultipleIntersectionsException: public std::exception
{
public:
	JPMultipleIntersectionsException();
	virtual const char* what() const throw();
};

/**
 * \brief Two turn lanes are trying to turn into the same lane.
 */
class JPTwoLanesToOneException: public JPMalformedIntersectionException
{
public:
	JPTwoLanesToOneException(int direction, int thisLane, int targetLane, int collidingLane );
	virtual const char* what() const throw();

	/**
	 * \brief Returns the lane that both lanes in the current direction are trying to turn into.
	 */
	int getTargetLane();

	/**
	 * \brief Returns the other lane from the same directions that this lane is trying to turn into.
	 */
	int getCollidingLane();

private:
	int _targetLane;
	int _collidingLane;
};

#endif /* SRC_JAMES_MALFORMEDINTERSECTIONEXCEPTION_H_ */
