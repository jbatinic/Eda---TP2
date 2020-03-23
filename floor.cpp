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
	int row = (int)x;
	int column = (int)y;
	int width = floor->w;
	int caso = width*row + column;
	if (floor->tile[caso] == true) {

	}
	else {
		floor->tile[caso] = true;
		//cout << "state of tile" << caso << floor->tile[caso] << endl;
	}
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
