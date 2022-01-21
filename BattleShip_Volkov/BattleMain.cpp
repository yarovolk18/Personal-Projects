#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdlib.h>
#include "Battle.h"

int main(int argc, char *argv[]) {

    //initialize Allegro
    initializeAllegro();

    //declare and initialize display and font, and check they have been setup properly
    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);
    ALLEGRO_FONT *font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 36, 0);
    checkSetup(display, font);

    //set window title
	al_set_window_title(display,"BattleShips");
    // Initialize primative add on
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

    ALLEGRO_EVENT_QUEUE *event_queue;
	//*********************PRINTS OUTPUT TO SCREEN*******************
	//Builds screen by printing to the buffer

	al_clear_to_color(BACKGROUND);
    bool conti = false;
    char printString[200]="";
    grid battleTime[20];
    ship battleShip[20];
    int grid1[10][10];
    int grid2[10][10];
    makeShips(grid2,battleShip);
	al_flip_display();
	start(display,event_queue,font,conti);
	if(conti==true){

        playerShips(grid1,battleShip);
        gameStart(display,event_queue,font,grid1,grid2,battleShip);
	}else{
    al_clear_to_color(BACKGROUND);
    sprintf(printString, "RULES:");
    al_draw_text(font, RED, COL_2, 300, ALLEGRO_ALIGN_LEFT, printString);
    sprintf(printString, "PRESS ENTER TO SHOOT");
    al_draw_text(font, RED, COL_2, 400, ALLEGRO_ALIGN_LEFT, printString);
    sprintf(printString, "USE THE AROW KEYS TO MOVE AND LOOK IN THE TOP RIGHT CORNER TO SEE WHERE YOU ARE.");
    al_draw_text(font, RED, COL_1, 500, ALLEGRO_ALIGN_LEFT, printString);
    sprintf(printString, "PLEASE WAIT 5 SECONDS");
    al_draw_text(font, RED, COL_2, 600, ALLEGRO_ALIGN_LEFT, printString);
    al_flip_display();
    al_rest(5);

    playerShips(grid1,battleShip);
    gameStart(display,event_queue,font,grid1,grid2,battleShip);
	}
    //drawMap();
    //flips the buffer to the screen
    al_flip_display();

    //wait for 5 seconds.
    al_rest(5);

    // Free up memory taken by display.
    al_destroy_display(display);

    // Exit with no errors
	return 0;
}
