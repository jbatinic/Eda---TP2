#ifndef _SIMULATION_H
#define _SIMULATION_H
/**********************************
INCLUDE
**********************************/
#include "header.h"
#include "robot.h"
#include "floor.h"

/**********************************
DEFINE
**********************************/

/**********************************
TYPEDEF
**********************************/
typedef struct {
	robot_t *robotPtr;		//puntero a la estructura robots, que tiene tres doubles (x,y,dir)
	floor_t *floorPtr;		//puntero a la estructura floor, que tiene dos int (ancho y alto) y un puntero a un arreglo
							//de bools que son las baldosas
	int w;					//ancho
	int h;					//alto
	int tick;				//cuenta el tiempo
	int rNum;				//cantidad de robots
} sim_t;

/*******************************
FUNCTION PROTOTYPES
*******************************/
sim_t *createSim(int width, int height, int robotNum);
void destroySim(sim_t *simPtr);
int startSim(sim_t *simPtr, int mode);




#endif
