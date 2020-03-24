#include "floor.h"

floor_t* createFloor(int width, int height) {		//crea el arreglo de estructuras tiles (i.e. el piso) con un malloc
	int i;
	floor_t *floor = (floor_t *)malloc(sizeof(floor_t));
	if (floor == NULL) {
		free(floor);
		return NULL;
	}
	else {
		floor->w = width;
		floor->h = height;
		floor->tile = (bool*) malloc (width*height*sizeof(bool));
			for (i = 0; i < (width*height); i++) {
				floor->tile[i] = false;
		}
			return floor;
	}
}

void cleanTile(floor_t *floor, double x, double y) {		//limpia la baldosa indicada
	floor->tile[(floor->w) * ((int)y) + ((int)x)] = true;
	
}

bool checkFloor(floor_t* floor, int width, int height) {						//devuelve cero si hay alguna baldosa sucia, y 1 si todas están limpias
	bool res = true;
	int i;
	for (i=0;i<width*height;i++) {
		if (floor->tile[i] == false)
			return false;
	}
	return res;
}

void cleanFloor(floor_t *floor) {					//libera el espacio dado por malloc
	free(floor);
}
