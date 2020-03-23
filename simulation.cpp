#include "simulation.h"
#include "allegroEngine.h"
#include "windows.h"

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
		inicializacion(simPtr->w, simPtr->h);
		simPtr->robotPtr = createRobot(simPtr->w, simPtr->h, simPtr->rNum);
		if ((simPtr->robotPtr) == NULL)
			return ERROR;
		simPtr->floorPtr = createFloor(simPtr->w, simPtr->h);
		if ((simPtr->floorPtr) == NULL)
			return ERROR;
		while (!(checkFloor(simPtr->floorPtr,simPtr->w,simPtr->h))) {					
			for (i = 0; i < (simPtr->rNum); i++) {
				moveRobot(simPtr->robotPtr, simPtr->rNum,simPtr->w,simPtr->h);
				cleanTile(simPtr->floorPtr, simPtr->robotPtr[i].x, simPtr->robotPtr[i].y);
			}
			
			
			update_board(simPtr->h, simPtr->w, simPtr->floorPtr->tile);
			for (i = 0; i < (simPtr->rNum); i++) {
				print_robot(simPtr->robotPtr[i].y, simPtr->robotPtr[i].x);
			}
			Sleep(350);
			simPtr->tick++;
		}
		close_window();
		return simPtr->tick;
	}
	else if (mode == 2) {
		int totalSims = 1000;
	}
	else return ERROR;
}

