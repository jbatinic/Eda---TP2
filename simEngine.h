

typedef bool baldosa;

typedef struct {
	float x;
	float y;
	float angle; // [angle] = radians!!
} robot;

robot robots[10];

typedef struct {
	baldosa* floor;
	robot* my_robots;
	unsigned int robot_count;
	unsigned int height;
	unsigned int width;
	unsigned long time;
} simulation;

int my_floor[5][5];

baldosa* createFloor(unsigned int height, unsigned int width);
