#ifndef TRAFFIC_CONSTANTS_HEADER
	#define TRAFFIC_CONSTANTS_HEADER
	#define MAX_LANES = 6;
	#define LANE_WIDTH = 10;

	//turn directions and lane allowance specs
	#define STRAIGHT = 1;
	#define RIGHT = 2;
	#define LEFT = 4;
	//mutually exclusive with LEFT, only used for lane specs
	#define LEFT_ON_SIGNAL_ONLY = 8; 

	#define NORTH = 0;
	#define EAST = 1;
	#define SOUTH = 2;
	#define WEST = 4;

	#define SOUTHBOUND = 0;
	#define WESTBOUND = 1;
	#define NORTHBOUND = 2;
	#define EASTBOUND = 4;

	//Traffic light colors
	#define RED = 1;
	#define YELLOW = 2;
	#define GREEN = 4;
	#define LEFT_GREEN = 8;
	#define LEFT_BLINK_YELLOW = 16;
#endif
