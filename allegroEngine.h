
#ifndef ALE_ENGINE
#define ALE_ENGINE

int inicializacion(int width, int height);
void erase_events(void);
void create_tablero(int width, int height);
void close_window(void);
void update_board(int board_height, int board_width, bool* my_floor);
void print_robot(double x, double y);

#endif // ALE_ENGINE