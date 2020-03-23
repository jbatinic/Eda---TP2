#include "Header.h"
#include "simulation.h"


int main(void) {
	srand(time(NULL));
	sim_t *simPtr = createSim(5, 5, 2);
	int res=startSim(simPtr, 1);
	if (res == ERROR) {
		cout << "error" << endl;
	}
	else {
		cout << res << endl;
	}
	return 0;
}