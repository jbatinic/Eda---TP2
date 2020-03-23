#ifndef _ROBOT_H
#define _ROBOT_H
/**********************************
INCLUDE
**********************************/
#include "header.h"

/**********************************
DEFINE
**********************************/

/**********************************
TYPEDEF
**********************************/

typedef struct {
	double x;
	double y;
	double dir;
} robot_t;

/*******************************
FUNCTION PROTOTYPE
*******************************/
robot_t * createRobot(int width, int height, int robotNum);  //inicializa el arreglo de robots
void moveRobot(robot_t* robotPtr, int robotNum, int width, int height);		//asigna una nueva posición a cada robot
void shutdown(robot_t* robotPtr);		//libera el espacio de memoria asignado a robots


#endif
