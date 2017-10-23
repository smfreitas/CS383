/*
 * SimulationEngine_test.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: james
 */

#include "../inc/JPSimulationEngine.h"

int straightGreenTest();
int rightTurnRedTest();
int leftTurnGreenTest();
int leftTurnBlinkYellowTest();
int matchPaceTest();
int redLightStopTest();

int main()
{
	int ret;
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			rightTurnRedTest() );
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			rightTurnRedTest() );
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			leftTurnGreenTest() );
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			leftTurnBlinkYellowTest() );
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			matchPaceTest() );
	ret = consts::testOuptut(
			"JPSimulationEngine: ",
			redLightStopTest() );

	if(ret == 100 ) printf("Stop warning me I know I don't use ret");
	return 0;
}

inline int straightGreenTest() { return 1;
}

inline int rightTurnRedTest() {return 1;
}

inline int leftTurnGreenTest() {return 1;
}

inline int leftTurnBlinkYellowTest() {return 1;
}

inline int matchPaceTest() {return 1;
}

inline int redLightStopTest() {return 1;
}
