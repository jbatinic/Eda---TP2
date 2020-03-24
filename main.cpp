#include "allegroEngine.h"
#include "simEngine.h"
#include <windows.h>

int main(int argc, char** argv) {

	inicializacion(6,7);
	create_tablero(6,7);
	print_robot(2.0, 2.0);
	Sleep(5000);
    
	update_board(6,7,);

	close();
	return 0;
}