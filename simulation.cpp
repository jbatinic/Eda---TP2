#include "simulation.h"

sim_t *createSim(int width, int height, int robotNum) {
	sim_t *simPtr = (sim_t *)malloc(sizeof(sim_t));
	if (simPtr == NULL) {
		free(simPtr);
		return NULL;
	}
	else {
		simPtr->w = width;
		simPtr->h = height;
		simPtr->rNum = robotNum;
		simPtr->tick = 0;
		return simPtr;
	}
}

void destroySim (sim_t *simPtr) {
	free(simPtr);
}

int startSim(sim_t* simPtr, int mode) {
	int i;
	if (mode==1) {
		simPtr->robotPtr = createRobot(simPtr->w, simPtr->h, simPtr->rNum);
		if ((simPtr->robotPtr) == NULL)
			return ERROR;
		simPtr->floorPtr = createFloor(simPtr->w, simPtr->h);
		if ((simPtr->floorPtr) == NULL)
			return ERROR;
		while (!(checkFloor(simPtr->floorPtr,simPtr->w,simPtr->h))) {		//acá se queda en un loop infinito
			for (i = 0; i < (simPtr->rNum); i++) {
				cleanTile(simPtr->floorPtr, simPtr->robotPtr[i].x, simPtr->robotPtr[i].y);
				moveRobot(simPtr->robotPtr, simPtr->rNum,simPtr->w,simPtr->h);
			}
			simPtr->tick++;
		}
		return simPtr->tick;
	}
	else return ERROR;
}

