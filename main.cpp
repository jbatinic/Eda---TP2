#include "Header.h"
#include "simulation.h"

int main(void) {
	srand(time(NULL));
	sim_t *simPtr = createSim(20, 20, 99);
	int res=startSim(simPtr, 1);
	if (res == ERROR) {
		cout << "error" << endl;
	}
	else {
		cout << res << endl;
		cin.get();
	}
	return 0;
}