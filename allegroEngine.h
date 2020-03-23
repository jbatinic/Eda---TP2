




#ifndef ALE_ENGINE
#define ALE_ENGINE

int inicializacion(void);
void erase_events(void);
void create_pantalla(void);
void close(void);
void update_board(int cant_robots);
void init_board(void);
void init_robots(int cant_robots);

#endif // ALE_ENGINE