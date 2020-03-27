#include <iostream>
#include "allegroEngine.h"


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_color.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>


#define FPS    60.0

#define CUADRADITO_SIZE 20
#define MOVE_RATE  4.0



ALLEGRO_DISPLAY* display;  //punteros que apuntan a un estructuras de allegro, se los apuntan a NULL para controlar errores
ALLEGRO_BITMAP* imagen;
ALLEGRO_EVENT_QUEUE* event_queue;

ALLEGRO_EVENT ev;

ALLEGRO_BITMAP* robot_img = NULL;

int close_display = 0;

int inicializacion(int width, int height) {



    if (!al_init()) {        //inicializacion general del allegro
        fprintf(stderr, "error al inicializar el allegro\n");
        return -1;
    }


    event_queue = al_create_event_queue();       //se inicializa los eventos

    if (!event_queue) {                         //se controla si fallo la init de los eventos
        fprintf(stderr, "failed to create event_queue!\n");
        return -1;
    }


    if (!al_init_primitives_addon()) {       //se controla si fallo la inicializacion de las primitivas
        fprintf(stderr, "error al inicializar las primitivas\n");
        return -1;
    }

    if (!al_init_image_addon()) { // necesario para manejo de imagenes 
        fprintf(stderr, "failed to initialize image addon !\n");
        return -1;
    }


    display = al_create_display(width*100, height*100);

    //se crea el display

    al_register_event_source(event_queue, al_get_display_event_source(display)); //se registra la fuente de los eventos de cierre de display

    if (!display) {//creo display
        al_shutdown_primitives_addon();      //se destruye la imagen porque ocupa espacio en heap y el programa fallo por otro motivo
        fprintf(stderr, "failed to create display");

        return -1;
    }

    robot_img = al_load_bitmap("robot_img.png");

    if (!robot_img) {
        fprintf(stderr, "failed to load image robot_img !\n");
        return -1;
    }

    al_clear_to_color(al_color_name("white"));          //se pinta las dos caras del display con blanco
    al_flip_display();
    al_clear_to_color(al_color_name("white"));

    return 0;
}

void erase_events(void) {
    al_flush_event_queue(event_queue);
}


void create_tablero(int width, int height) {           //se crea el grafico 
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            al_draw_filled_rectangle(100 * i, 100 * j, 100 * (i + 1), (j + 1) * 100, al_map_rgb(220, 220, 220));
            al_draw_rectangle(100 * i, 100 * j, 100 * (i + 1), (j + 1) * 100, al_map_rgb(0, 0, 0), 0);

        }
    }
    al_draw_rectangle(0,0, height, width, al_map_rgb(70, 70, 70), 3);
    al_flip_display();

}

void create_graph(float* tMedio, int nRobots, int wTiles, int hTiles) {
    
    al_clear_to_color(al_color_name("black"));
    int width = wTiles * 100;
    int height = hTiles * 100;
    al_draw_line(50, 50, 50, height - 50, al_map_rgb_f(1, 1, 1), 4);  //se dibuja el eje y
    al_draw_line(50, height-50, width - 50, height-50, al_map_rgb_f(1, 1, 1), 4);  //se dibuja el eje x

    float ancho = ((width - 100) / (nRobots+0.5)); //se calcula el ancho de cada barra del grafico teniendo en cuenta el ancho del display y un espacio entre cada barra
    float alto = ((height - 100) / (tMedio[0] + 0.5)); //se calcula el espacio entre cada valor del eje y
    
    for (int i = 1; i <= nRobots; i++) {
        
       al_draw_line(50 + ancho * i, height - 52, 50 + ancho * i, (height - 50 ) - (tMedio[i-1] * alto), al_map_rgb_f(1,0,0), ancho/2 );
   
    }


    al_flip_display();
    al_rest(10);
    al_shutdown_primitives_addon();
   
    
    al_destroy_display(display);
    
}



void close_window(void) { // funcion que desinstala los plugins de alegro



    al_destroy_bitmap(imagen);       //se libera la memoria dinamica , destruyendo los elemntos usados
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_shutdown_primitives_addon();
    printf("bye\n");


}

void update_board( int board_height, int board_width, bool*my_floor) { // funcion principal en el juego
                                                                                                         // esta funcion actualiza el floor y lo imprime en pantalla
    int i, j;

    for (i = 0;i < board_height;i++) {

        for (j = 0;j < board_width;j++) {

            if (!my_floor[i*board_width+j]) {

                al_draw_filled_rectangle(100 * j, 100 * i, 100 * (j + 1), (i + 1) * 100, al_map_rgb(84, 39, 22));
                al_draw_rectangle(100 * j, 100 * i, 100 * (j + 1), (i + 1) * 100, al_map_rgb(70, 70, 70), 0);
                
            }
            else {
                al_draw_filled_rectangle(100 * j, 100 * i, 100 * (j + 1), (i + 1) * 100, al_color_name("white"));
                al_draw_rectangle(100 * j, 100 * i, 100 * (j + 1), (i + 1) * 100, al_map_rgb(70, 70, 70), 0);
            }
            

        }

    }
    al_draw_rectangle(0,0, board_width * 100, board_height * 100, al_map_rgb(70, 70, 70), 3);
    al_flip_display();

}

void print_robot (double y, double x){

    int xp = (int) (x * 100);
    int yp = (int) (y * 100);
    al_draw_bitmap(robot_img, xp, yp, 0);
    al_flip_display();
}