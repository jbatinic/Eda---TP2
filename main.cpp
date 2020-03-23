#include "Header.h"
#include "simulation.h"


int main(int arc, char** argv) {
	srand(time(NULL));

	uint width = atoi(argv[1]);
	uint length = atoi(argv[2]);
	uint robotNumber = atoi(argv[3]);
	int mode = atoi(argv[4]);
	bool valid_input =  width>0 && width <= 70 &&
						length>0 && length <= 100 &&
						robotNumber>0 && 
						mode>0 && mode < 3;
	if (valid_input) {
		sim_t* simPtr = createSim(width, length, robotNumber);
		int res = startSim(simPtr, mode);
		if (res == ERROR) {
			cout << "error" << endl;
		}
		else {
			cout << res << endl;
		}
		return 0;
	}
	else {
		cout << "Invalid parameters." << endl;
		return ERROR;
	}

}