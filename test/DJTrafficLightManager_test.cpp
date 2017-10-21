/*
 * DJTrafficLightManager_test.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: dakota
 */

#include "../inc/DJConstants.h"
#include <stdio.h>

// TODO write tests && include/import ...manager.cpp
int lightPerLaneCheck();
int changeStateSuccessCheck();
int noChangeStateCheck();
int noInvalidStateCheck();
int recoveryFromInvalidStateCheck();
int simTimeSpeedChangeCheck();

int main()
{
    // call each function with an expected pass/fail and check for 
    // expected results
    return 0;
}

/**
 * \brief Verify that each lane has a light for each direction.
 */
int lightPerLaneCheck()
{
    return 0;
}

/**
 * \brief Verify that the proper response is given for a state-change.
 */
int changeStateSuccessCheck()
{
    return 0;
}

/**
 * \brief Verify that the proper response is given for a non-change.
 */
int noChangeStateCheck()
{
    return 0;
}

/**
 * \brief Verify that each light won't conflict with another for each direction.
 */
int noInvalidStateCheck()
{
    return 0;
}

/**
 * \brief Verify that system can recover from an invalid state.
 */
int recoveryFromInvalidStateCheck()
{
    return 0;
}

/**
 * \brief Verify that changing rate of time will correctly change cycle times.
 */
int simTimeSpeedChangeCheck()
{
    return 0;
}