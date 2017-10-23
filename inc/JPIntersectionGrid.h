/*
 * JPIntersectionGrid.h
 *
 *  Created on: Oct 22, 2017
 *      Author: james
 */

#ifndef SRC_JAMES_JPINTERSECTIONGRID_H_
#define SRC_JAMES_JPINTERSECTIONGRID_H_
#include "SFCar.h"

class JPIntersectionGrid {
public:
	JPIntersectionGrid();
	virtual ~JPIntersectionGrid();

	/**
	 * \brief check the intersection and return required (de/ac)celeration
	 *
	 * \return 0 if the intersection is clear
	 * 	a positive value of required deceleration if the car must slow down
	 * 	a negative value of the maximum allowable acceleration if the car can speed up but the lane is not entirely clear
	 */
	double checkPath(int direction, int lane, SFCar)
};

#endif /* SRC_JAMES_JPINTERSECTIONGRID_H_ */
