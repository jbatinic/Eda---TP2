#include <iostream>
#include "simEngine.h"
#include "allegroEngine.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_color.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

extern int my_floor[5][5];
extern robot robots[10];


#define FPS    60.0
#define HEIGHT 500
#define WIDTH  500
#define CUADRADITO_SIZE 20
#define MOVE_RATE  4.0



ALLEGRO_DISPLAY* display;  //punteros que apuntan a un estructuras de allegro, se los apuntan a NULL para controlar errores
ALLEGRO_BITMAP* imagen;
ALLEGRO_EVENT_QUEUE* event_queue;

ALLEGRO_EVENT ev;

ALLEGRO_BITMAP* robotjpg = NULL;

int close_display = 0;

int inicializacion(void) {



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


    display = al_create_display(WIDTH, HEIGHT);

    //se crea el display

    al_register_event_source(event_queue, al_get_display_event_source(display)); //se registra la fuente de los eventos de cierre de display

    if (!display) {//creo display
        al_shutdown_primitives_addon();      //se destruye la imagen porque ocupa espacio en heap y el programa fallo por otro motivo
        fprintf(stderr, "failed to create display");

        return -1;
    }

    robotjpg = al_load_bitmap("robotjpg.bmp");

    if (!robotjpg) {
        fprintf(stderr, "failed to load image robotjpg !\n");
        return 0;
    }

    al_clear_to_color(al_color_name("white"));          //se pinta las dos caras del display con blanco
    al_flip_display();
    al_clear_to_color(al_color_name("white"));

}

void erase_events(void) {
    al_flush_event_queue(event_queue);
}


void create_pantalla(void) {           //se crea el grafico 
    int i, j;

    for (i = 0;i < 5;i++)
        for (j = 0;j < 5;j++) {

            al_draw_filled_rectangle(WIDTH * j / 5, HEIGHT * i / 5, WIDTH * (j + 1) / 5, HEIGHT * (i + 1 ) / 5, al_map_rgb(220, 220, 220));
            al_draw_rectangle(WIDTH * j / 5, HEIGHT * i / 5, WIDTH * (j + 1) / 5, HEIGHT * (i + 1) / 5, al_map_rgb(0, 0, 0), 0);



        }
    al_draw_rectangle(0,0, WIDTH, HEIGHT, al_map_rgb(70, 70, 70), 3);
    al_flip_display();


}



void close(void) { // funcion que desinstala los plugins de alegro



    al_destroy_bitmap(imagen);       //se libera la memoria dinamica , destruyendo los elemntos usados
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_shutdown_primitives_addon();
    printf("bye\n");


}

void update_board(int cant_robots) { // funcion principal en el juego
                                     // esta funcion actualiza el floor y lo imprime en pantalla
    int i, j,xp,yp;

    for (i = 0;i < 5;i++) {


        for (j = 0;j < 5;j++) {


            if (my_floor[i][j]) {


                    al_draw_filled_rectangle(WIDTH * j / 25, HEIGHT * i / 19, WIDTH * (j+ 1) / 25, HEIGHT * (i + 1) / 19, al_color_name("white"));
                    al_draw_rectangle(WIDTH * j / 25, HEIGHT * i / 19, WIDTH * (j + 1) / 25, HEIGHT * (i + 1) / 19, al_map_rgb(70, 70, 70), 0);


            }

            for (i = 0;i < cant_robots;i++) {

                xp = ((int)robots[i].x) * 100;
                yp = ((int)robots[i].y) * 100;
                al_draw_bitmap(robotjpg, xp, yp, 0);

            }
        }

    }
    al_draw_rectangle(0,0, WIDTH, HEIGHT , al_map_rgb(70, 70, 70), 3);
    al_flip_display();

}


void init_robots(int cant_robots) { // funcion que imprime los robots en la pos inicial 
                         
    int i, xp, yp;
    al_set_target_backbuffer(display);

    for (i = 0;i < cant_robots;i++) {

        xp= ((int) robots[i].x)*100;
        yp = ((int) robots[i].y)*100;
        al_draw_bitmap(robotjpg, xp, yp, 0);

    }

    al_flip_display();

}