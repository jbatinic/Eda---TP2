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
		bool clean = false;
		while (!clean) {
			for (i = 0; i < (simPtr->rNum); i++) {
				cleanTile(simPtr->floorPtr, simPtr->robotPtr[i].x, simPtr->robotPtr[i].y);
			}
			if (!(clean = (checkFloor(simPtr->floorPtr, simPtr->w, simPtr->h)))) {
				moveRobot(simPtr->robotPtr, simPtr->rNum, simPtr->w, simPtr->h);
				simPtr->tick++;
			}
			update_board(simPtr->h, simPtr->w, simPtr->floorPtr->tile);
			for (i = 0; i < (simPtr->rNum); i++) {
				print_robot((simPtr->robotPtr[i].y), simPtr->robotPtr[i].x);
			}
			Sleep(100);
		}
		cleanFloor(simPtr->floorPtr);
		shutdown(simPtr->robotPtr);
		close_window();
		return simPtr->tick;
	}
	else if (mode == 2) {
		int simulationsDone;
		float totalTicks;
		float promedio;
		simPtr->rNum = 0;
		float* tiemposMedios = (float*) malloc(simPtr->w * simPtr->h * sizeof(float) * 3); // 
		if (tiemposMedios != NULL)
			do {
				totalTicks = 0;
				simPtr->rNum++;
				for (simulationsDone = 0; simulationsDone < 1000; simulationsDone++) {
					simPtr->robotPtr = createRobot(simPtr->w, simPtr->h, simPtr->rNum);
					if ((simPtr->robotPtr) == NULL)
						return ERROR;
					simPtr->floorPtr = createFloor(simPtr->w, simPtr->h);
					if ((simPtr->floorPtr) == NULL)
						return ERROR;
					bool clean = false;
					while (!clean) {
						for (i = 0; i < (simPtr->rNum); i++) {
							cleanTile(simPtr->floorPtr, simPtr->robotPtr[i].x, simPtr->robotPtr[i].y);
						}
						if (!(clean = (checkFloor(simPtr->floorPtr, simPtr->w, simPtr->h)))) {
							moveRobot(simPtr->robotPtr, simPtr->rNum, simPtr->w, simPtr->h);
							simPtr->tick++;
						}
					}
					totalTicks += simPtr->tick;
					cleanFloor(simPtr->floorPtr);
					shutdown(simPtr->robotPtr);
					simPtr->tick = 0;
				}

				promedio = totalTicks / 1000;
			} while (promedio > 0.5);
		else
		//LLAMAR A FUNCIÓN QUE GRAFIQUE (toma como parametros tiemposMedios y rNum grafico -- > Tiempo(rNum-1)
		free(tiemposMedios);
		return simPtr->rNum;
	}
	else return ERROR;
}

