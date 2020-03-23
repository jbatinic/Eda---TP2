

typedef bool baldosa;

typedef struct {
	float x;
	float y;
	float angle; // [angle] = radians!!
} robot;
typedef struct {
	baldosa* floor;
	robot* my_robots;
	unsigned int robot_count;
	unsigned int height;
	unsigned int width;
	unsigned long time;
} simulation;

baldosa* createFloor(unsigned int height, unsigned int width);
