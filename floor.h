#ifndef FLOOR_H_
#define FLOOR_H_
/**********************************
INCLUDE
**********************************/
#include "header.h"

/**********************************
DEFINE
**********************************/
#define CLEAN 1
#define DIRTY 0

/**********************************
TYPEDEF
**********************************/
typedef struct {
	bool *tile;
	int w;
	int h;
} floor_t;

/*******************************
FUNCTION PROTOTYPES
*******************************/
floor_t *createFloor(int width, int height);				//crea floor utilizando malloc
void cleanFloor(floor_t *floor);												//libera el espacio asginado por malloc
bool checkFloor(floor_t *floor, int width, int height);												//revisa que todas las baldosas estén limpias
void cleanTile(floor_t *floor, double fila, double columna);		//limpia una baldosa específica

#endif