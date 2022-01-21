#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Battle.h"

void gameStart(v, ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_FONT *font, int grid1[10][10],int grid2[10][10], ship s[]){
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
	ALLEGRO_BITMAP *shot = nullptr;
	ALLEGRO_BITMAP *cancel = nullptr;
	ALLEGRO_BITMAP *white = nullptr;
	image = al_load_bitmap("Bullet.bmp");
	shot = al_load_bitmap("FIRE.bmp");
	cancel = al_load_bitmap("MISS.bmp");
	white = al_load_bitmap("white.bmp");

        if (!image) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
            al_destroy_display(display);

        }
    al_clear_to_color(BACKGROUND);
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    grid battleTime[20];
    ship battleShip[20];

    for(int k = 1; k <11;k++){
        for(int j = 1; j<11;j++){
            printf("%d  ",grid1[k][j]);
        }
            printf("\n");
    }
    printf("\n");
    for(int k = 1; k <11;k++){
        for(int j = 1; j<11;j++){
            printf("%d  ",grid2[k][j]);
        }
    printf("\n");
    }

    char printString[200] = "";
    int dy=790;
    int dx=173;
    int moveIt=73;
    bool boi = false;
    bool hitCheck = false;
    //bool startPlease = false;
    int moveX = 1;
    int moveY = 1;
    bool exitThis = false;
    int kool = 10;
    int counter1[6];
    for(int i = 0;i<=5;i++){
        counter1[i]=0;
    }
    int victory = 0;
    int counter2[6];
    for(int i = 0;i<=5;i++){
        counter2[i]=0;
    }
    int victory2 = 0;

    drawMap();

    int turn = 0;
    al_flip_display();
    while(!exitThis){
        ALLEGRO_EVENT ev;
        al_draw_bitmap(white, 890, 0, 0);
        sprintf(printString, "X:%d,Y:%d",moveX,moveY);
        al_draw_text(font, RED, COL_5, 5, ALLEGRO_ALIGN_LEFT, printString);
        //printf("x:%d,y:%d\n",moveX,moveY);
        al_flip_display();

            al_wait_for_event(event_queue, &ev);
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                exitThis = true;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                        if(moveY == 10){
                        }else{
                        dy-=moveIt;
                        moveY++;
                        }
                        break;
                    case ALLEGRO_KEY_DOWN:
                        if(moveY==1){

                        }else{
                        dy+=moveIt;
                        moveY--;
                        }
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        if(moveX==10){
                        }else{
                        dx+=moveIt;
                        moveX++;
                        }
                        break;
                    case ALLEGRO_KEY_LEFT:
                        if(moveX==1){
                        }else{
                        dx-=moveIt;
                        moveX--;
                        }
                        break;
                    case ALLEGRO_KEY_ENTER:
                       // printf("PLACED");
                        hitCheck = true;
                        boi = true;
                        break;
                    case ALLEGRO_KEY_ESCAPE:
                        exitThis = true;
                        break;
                }
            if(boi){
                if(grid1[moveX][moveY] > 1){
                    //Don't do anything
                    }else{
                al_draw_bitmap(cancel,dx,dy,0);
                    }
            //printf("Miss\n");
            }
            if(hitCheck){
                    if(grid1[moveX][moveY]!=7){
                        computerShot(grid2,battleShip,victory2,counter2);
                        al_draw_bitmap(white,COL_2,850,0);
                        al_draw_bitmap(white,COL_2+100,850,0);
                        al_draw_bitmap(white,COL_2+190,850,0);
                        al_draw_bitmap(white,COL_2+280,850,0);
                    }else{
                    sprintf(printString,"You've Already Hit this! Try Again.");
                    al_draw_text(font, RED, COL_2, 850, ALLEGRO_ALIGN_LEFT, printString);
                    }

                    if(grid1[moveX][moveY] > 0 &&grid1[moveX][moveY]<7){

                        turn++;
                        printf("HIT\n");
                        al_draw_bitmap(shot,dx,dy,0);

                        int COOL = grid1[moveX][moveY];

                        switch (COOL) {

                        case 2: counter1[1]++;
                                printf("Patrol Boat:%d\n",counter1[1]);
                                break;
                        case 3: counter1[2]++;
                                printf("Destroyer: %d\n",counter1[2]);
                                break;
                        case 4: counter1[3]++;
                                printf("Submarine: %d\n",counter1[3]);
                                break;
                        case 5: counter1[4]++;
                                printf("Battleship: %d\n",counter1[4]);
                                break;
                        case 6: counter1[5]++;
                                printf("Carrier: %d\n",counter1[5]);
                                break;
                       // case 7: printf("You've already hit this!\n");
                              //  break;
                       default: printf("MISS\n");

                        }
                        grid1[moveX][moveY] = 7;
                        //Drawing the grid
                        //printf("\n");
                        printf("PLAYER GRID\n");
                        for(int k = 1; k <11;k++){
                            for(int j = 1; j<11;j++){
                                printf("%d  ",grid2[k][j]);
                            }
                        printf("\n");
                        }
                        printf("\n");
                        printf("A.I. GRID\n");
                        for(int k = 1; k <11;k++){
                            for(int j = 1; j<11;j++){
                                printf("%d  ",grid1[k][j]);
                                }
                                printf("\n");
                                }

                    }else if(grid1[moveX][moveY]==7){
                        printf("You've already hit this!");
                        }
                        calc(counter1,victory);
                        calc2(counter2,victory2);
                        printf("%d",turn);
            }


       // printf("\n");
            hitCheck = false;
            boi = false;
            al_flip_display();
    }

}
//printf("IT WORKS");
}

void drawMap(){

    al_clear_to_color(BACKGROUND);
     	ALLEGRO_BITMAP *grid = nullptr;
     	grid = al_load_bitmap("graph almost done2.bmp");
        ALLEGRO_BITMAP *backA = nullptr;
        backA = al_load_bitmap("backA.bmp");
     	al_draw_bitmap(backA,0,0,0);
     	al_draw_bitmap(grid,50,50,1);
}

void makeShips(int grid1[10][10],ship s[]){
    srand(time(0));

    //keeping track of placement
    for(int i = 1; i <11;i++){
        for(int j = 1; j<11;j++){
            grid1[i][j] = 0;
        }
    }
    bool overLap = false;
    //Creating the 5 unit ship
    int counterXX = 6;

    while(counterXX>1){

    int randNum = rand() % 10 + 1 ;
    int choice = rand() % 2 + 1 ;

    if(choice == 1){
        for(int i = 1; i <counterXX;i++){
        //For horizontal ships
            if(randNum <= counterXX-1){
                s[1].locationX[i] = i+randNum;
                s[1].locationY[i] = randNum;
            }else{
                s[1].locationX[i] = randNum-i;
                s[1].locationY[i] = randNum;
            }
            if(grid1[s[1].locationX[i]][s[1].locationY[i]]>1){
                overLap = true;
            }
            grid1[s[1].locationX[i]][s[1].locationY[i]] = counterXX;
            }
    }else{

        for(int i = 1; i <counterXX;i++){
            if(randNum <= counterXX-1){
                s[1].locationX[i] = randNum;
                s[1].locationY[i] = randNum+i;
            }else{
                s[1].locationX[i] = randNum;
                s[1].locationY[i] = randNum-i;
            }
            if(grid1[s[1].locationX[i]][s[1].locationY[i]]>1){
                overLap = true;
            }
            grid1[s[1].locationX[i]][s[1].locationY[i]] = counterXX;


        }

        }
        counterXX--;

        if(overLap){
            for(int i = 1; i <11;i++){
                for(int j = 1; j<11;j++){
                    grid1[i][j] = 0;
                }
            }
            counterXX=6;
        }
        overLap = false;
    }





}

void playerShips(int grid2[10][10], ship s[]){
    srand(time(0));

    //keeping track of placement
    for(int i = 1; i <11;i++){
        for(int j = 1; j<11;j++){
            grid2[i][j] = 0;
        }
    }
    bool overLap = false;
    //Creating the 5 unit ship
    int counterXX = 6;

    while(counterXX>1){

    int randNum1 = rand() % 10 + 1 ;
    int choice1 = rand() % 2 + 1 ;

    if(choice1 == 1){
        for(int i = 1; i <counterXX;i++){
        //For horizontal ships
            if(randNum1 <= counterXX-1){
                s[1].locationX[i] = i+randNum1;
                s[1].locationY[i] = randNum1;
            }else{
                s[1].locationX[i] = randNum1-i;
                s[1].locationY[i] = randNum1;
            }
            if(grid2[s[1].locationX[i]][s[1].locationY[i]]>1){
                overLap = true;
            }
            grid2[s[1].locationX[i]][s[1].locationY[i]] = counterXX;
            }
    }else{

        for(int i = 1; i <counterXX;i++){
            if(randNum1 <= counterXX-1){
                s[1].locationX[i] = randNum1;
                s[1].locationY[i] = randNum1+i;
            }else{
                s[1].locationX[i] = randNum1;
                s[1].locationY[i] = randNum1-i;
            }
            if(grid2[s[1].locationX[i]][s[1].locationY[i]]>1){
                overLap = true;
            }
            grid2[s[1].locationX[i]][s[1].locationY[i]] = counterXX;


        }

        }
        counterXX--;

        if(overLap){
            for(int i = 1; i <11;i++){
                for(int j = 1; j<11;j++){
                    grid2[i][j] = 0;
                }
            }
            counterXX=6;
        }
        overLap = false;
    }

}
