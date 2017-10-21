/*
 * DJTrafficLightManager.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: dakota
 */

 #include "../../inc/DJConstants.h"
 #include "../../inc/JPConstants.h"

DJTrafficLightManager::DJTrafficLightManager()
{
    // include way to get total number of lights, rate of time,
    // state and manage/update from there. May use 2D array for light sorting?
}

void DJTrafficLightManager::initAllLights(int direction, int lane)
{
    // take total number of lines and find a way to 
    // map them on a per-lane/direction basis, along with
    // initializing them with proper values. (might add some to constants?)
}
void DJTrafficLightManager::getSingleLight(int direction, int lane, double time)
{
    // get the specific light located at the position
    // given by both direction and lane
    // return light;
    // TODO: change from void function to different type w/lights(int per light?)
}

int DJTrafficLightManager::getState(int singleLight, double time, double timeRate)
{
    // takes the given light and finds its state given the
    // time and timeRate, using a calculation
    // return state
}

double DJTrafficLightManager::getCycleTime(double time, double timeRate)
{
    // take constant cycle time and multiply it (tentatively)
    // by timeRate
    // return cycleTime
    // for simple test/proof of concept
}

void DJTrafficLightManager::manageState(int singleLight, double time, double timeRate)
{
    // keeps track of and updates each light
    // does not return anything, but is vital to
    // manage the states and ensure no lights have
    // incorrect states.
}

DJTrafficLightManager::~DJTrafficLightManager()
{
    // handle destructor
}