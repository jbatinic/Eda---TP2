/*
Robot 
 - Coords (x,y)
 - Dirección

 Baldosa

 - estado (limpio/sucio)

 Piso

 - Baldosa *p
 
 Simulación

 - Robot * robs
 - Baldosa * piso
 - tiempo
 - Height
 - Width
 */

#include "simEngine.h"
#include "allegroEngine.h"
#include <stdlib.h>
#include <cmath>

//Piso:

#define SUCIO false
#define LIMPIO true

// typedef bool baldosa;

extern int my_floor[5][5];


baldosa* createFloor(unsigned int height, unsigned int width) {
    baldosa* ret = NULL;
    int i;
    ret = (baldosa*) malloc(height * width * sizeof(baldosa));
    if (ret != NULL) {
        for (i = 0; i < height * width; i++) {
            ret[i] = SUCIO;
        }
    }
    return ret;
}

void freeFloor(baldosa* p) {
    free(p);
}

bool isFloorClean(baldosa* my_floor, unsigned int height, unsigned int width) {
    int i;
    for (i = 0; i < height * width; i++) {
        if (my_floor[i] = SUCIO) {
            return false;
        }
    }
    return true;
}

//Baldosa:

//baldosa* getBaldosa(baldosa* my_floor, unsigned int fil_baldosa, unsigned int col_baldosa) {
//    return (my_floor[fil_baldosa][col_baldosa]);
//}

//Robot:

robot* createRobots(unsigned int count, unsigned int height, unsigned int width) {
    int i;
    robot* my_robots = (robot*) malloc(count * sizeof(robot));
    if (my_robots != NULL) {
        for (i = 0; i < count; i++) {
            //Asigno dirección y coordenadas random ()
        }
    }

    return my_robots;
}

void freeRobots(robot* my_robots) {
    free(my_robots);
}

void moveRobot(robot* robot, baldosa* piso, unsigned int width, unsigned int height) {

    float new_y = robot->y + sin(robot->angle);
    float new_x = robot->x + cos(robot->angle);
    if (new_x < width && new_x >= 0 && new_y < height && new_y >= 0) {
        robot->x = new_x;
        robot->y = new_y;
    }
    else {
        //rebote()
    }
}

//Simulation:

simulation * createSim(unsigned int count, unsigned int height, unsigned int width) {
    simulation* my_sim = (simulation*)malloc(sizeof(simulation));
    my_sim->robot_count = count;
    my_sim->height = height;
    my_sim->width = width;
    my_sim->my_robots = createRobots(count, height, width);
    my_sim->floor = createFloor(height, width);
    my_sim->time = 0;
    return 0;
}

void freeSim(simulation* my_sim) {
    freeRobots(my_sim->my_robots);
    freeFloor(my_sim->floor);
    free(my_sim);
}

unsigned int simulate(simulation * my_sim) {
    my_sim->time = 0;
    unsigned int i;
    while (!isFloorClean(my_sim->floor, my_sim->height,my_sim->width)) {
        for (i = 0; i < my_sim->robot_count; i++) {       
            moveRobot((my_sim->my_robots)+i, my_sim->floor, my_sim->width, my_sim->height);
        }
        my_sim->time++;
    }
    return 0;
}