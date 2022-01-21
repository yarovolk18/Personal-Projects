#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>                     // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include <stdlib.h>
#include "Battle.h"

void start(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_FONT *font,bool &cont1){

    // Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
   	}

    event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
	}
	// Initialize primative add on
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);

	}
	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);

	}
	ALLEGRO_BITMAP *image = nullptr;
	image = al_load_bitmap("Bullet.bmp");
        if (!image) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
            al_destroy_display(display);

        }
    char printString[200] = "";
    char title[200] = "BATTLE SHIP";




    al_register_event_source(event_queue, al_get_keyboard_event_source());
	bool doexit = false;

	int dy=350;
    int dx=350;
	int y2=400;
	int x2=400;
    bool startPlease = false;
    int moveCount= 0;

    ALLEGRO_BITMAP *frontA = nullptr;
    frontA = al_load_bitmap("Home page2.bmp");
    al_draw_bitmap(frontA,0,0,0);
    al_draw_bitmap(image,dx,dy,0);
    al_draw_text(font, FOREGROUND, COL_1, 5, ALLEGRO_ALIGN_LEFT, title);
    sprintf(printString, "Start Game");
    al_draw_text(font, FOREGROUND, COL_3, 350, ALLEGRO_ALIGN_LEFT, printString);
    sprintf(printString, "How To Play");
    al_draw_text(font, FOREGROUND, COL_3, 400, ALLEGRO_ALIGN_LEFT, printString);

    al_flip_display();
	while (!doexit) {

    	ALLEGRO_EVENT ev;

      	al_wait_for_event(event_queue, &ev);
      	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        	doexit = true;
      	}
      	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         	switch(ev.keyboard.keycode) {
            	case ALLEGRO_KEY_UP:
            	    if(moveCount == 0){
                        //does literally nothing
            	    }else{
                        dy-=50;
                        y2-=50;
                        moveCount=0;
                    }
               		break;
                case ALLEGRO_KEY_DOWN:
                     if(moveCount == 1){
                        //does literally nothing
            	    }else{
               		dy+=50;
               		y2+=50;
               		moveCount=1;
            	    }
               		break;
                case ALLEGRO_KEY_ENTER:
                    if(moveCount == 0){
                        cont1 = true;
                        al_clear_to_color(BACKGROUND);
            	    }else{
            	    cont1 = false;
            	    }
            	    doexit = true;
                    break;
                case ALLEGRO_KEY_ESCAPE:
               		doexit = true;
               		break;
         	}

            al_clear_to_color(BACKGROUND);
            al_draw_bitmap(frontA,0,0,0);
            al_draw_bitmap(image,dx,dy,0);
            al_draw_text(font, FOREGROUND, COL_1, 5, ALLEGRO_ALIGN_LEFT, title);
            sprintf(printString, "Start Game");
            al_draw_text(font, FOREGROUND, COL_3, 350, ALLEGRO_ALIGN_LEFT, printString);
            sprintf(printString, "How To Play");
            al_draw_text(font, FOREGROUND, COL_3, 400, ALLEGRO_ALIGN_LEFT, printString);
		 	al_flip_display();


		}

	}



}
