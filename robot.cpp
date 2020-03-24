#include "robot.h"

robot_t *createRobot(int width, int height, int robotNum) {
	int i;
	robot_t *robotPtr = (robot_t *)malloc(robotNum * sizeof(robot_t));		//se utiliza malloc para asignar memoria
	if (robotPtr == NULL) {
		free(robotPtr);
		return NULL;
	}
	else {
		for (i = 0; i<robotNum; i++) {										//si pudo hacerse la asignación, se procede a generar posiciones aleatorias para cada robot
			robotPtr[i].x = rand() % ((width)*1000);
			robotPtr[i].x /= 1000;
			robotPtr[i].y = rand() % ((height)*1000);
			robotPtr[i].y /= 1000;
			robotPtr[i].dir = (rand() % 360)*PI / 180;
			//robotPtr[i].coord.x = (double) rand() / (RAND_MAX/width); 
			//robotPtr[i].coord.y = (double)rand() / (RAND_MAX /height);

		}
		return robotPtr;
	}
}

void moveRobot(robot_t *robotPtr, int robotNum, int width, int height) {		//se mueve a cada robot a su nueva posición (esto incluye cambiar su dirección si choca contra una pared)
	int i;
	for (i = 0; i<robotNum; i++) {
		double nx = robotPtr[i].x + cos(robotPtr[i].dir);
		double ny = robotPtr[i].y + sin(robotPtr[i].dir);
		cout << "width: " << width << " height: " << height << endl;
		if ((0 < nx && nx < width) && (0 < ny && ny < height))
		{
			robotPtr[i].x = nx;
			robotPtr[i].y = ny;
		}
		else {
			robotPtr[i].dir = (rand() % 360)*PI / 180;
		}
	}
}

void shutdown(robot_t *robotPtr) {		//se libera el espacio dado por malloc
	free(robotPtr);
}