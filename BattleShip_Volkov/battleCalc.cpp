#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Battle.h"

int calc(int counter1[], int &gameWin){
    ALLEGRO_FONT *font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 36, 0);
    char printString[200]="";
    int shi = 1100;
    int shi2=100;
    int batX=100;
    int batY=50;
    if(counter1[1] == 1){
        sprintf(printString,"Patrol Boat Sunk!");
        al_draw_text(font, RED, shi, shi2, ALLEGRO_ALIGN_RIGHT, printString);
        ALLEGRO_BITMAP *PATROL = nullptr;
        PATROL = al_load_bitmap("ZPAT.bmp");
        al_draw_bitmap(PATROL,shi,shi2+batY,0);
        gameWin++;
        counter1[1]=0;
    }
    if(counter1[2] == 2){
        sprintf(printString,"Destroyer Sunk!");
        al_draw_text(font, RED, shi, shi2+100, ALLEGRO_ALIGN_RIGHT, printString);
        ALLEGRO_BITMAP *DEST = nullptr;
        DEST = al_load_bitmap("ZDES.bmp");
        al_draw_bitmap(DEST,shi,shi2+batY+batX*1,0);
        gameWin++;
        counter1[2]=0;
    }
    if(counter1[3] == 3){
        sprintf(printString,"Submarine Sunk!");
        al_draw_text(font, RED, shi, shi2+200, ALLEGRO_ALIGN_RIGHT, printString);
        ALLEGRO_BITMAP *SUB = nullptr;
        SUB = al_load_bitmap("ZSUB.bmp");
        al_draw_bitmap(SUB,shi,shi2+batY+batX*2,0);
        gameWin++;
        counter1[3]=0;
    }
    if(counter1[4] == 4){
        sprintf(printString,"Battleship Sunk!");
        al_draw_text(font, RED, shi, shi2+300, ALLEGRO_ALIGN_RIGHT, printString);
        ALLEGRO_BITMAP *BATL = nullptr;
        BATL = al_load_bitmap("ZBAT.bmp");
        al_draw_bitmap(BATL,shi,shi2+batY+batX*3,0);
        gameWin++;
        counter1[4]=0;
    }
    if(counter1[5] == 5){
        sprintf(printString,"Carrier Sunk!");
        al_draw_text(font, RED, shi, shi2+400, ALLEGRO_ALIGN_RIGHT, printString);
        ALLEGRO_BITMAP *CARR = nullptr;
        CARR = al_load_bitmap("ZCAR.bmp");
        al_draw_bitmap(CARR,shi,shi2+batY+batX*4,0);
        gameWin++;
        counter1[5]=0;
    }
    if(gameWin > 4){
            al_clear_to_color(BLACK);
            ALLEGRO_BITMAP *WON = nullptr;
            WON = al_load_bitmap("WON.bmp");
            al_rest(5);
            al_draw_bitmap(WON,250,200,0);
            al_flip_display();

            // Free up memory taken by display.
            //al_destroy_display(display);
    }
    al_flip_display();
    //////////////////////////////////


}
void calc2(int counter2[], int &gameWin2){
    ALLEGRO_FONT *font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 36, 0);
    char printString[200] = "";
    int shi = 1100;
    int shi2 = 550;
    if(counter2[1] == 1){
        sprintf(printString,"Your Patrol Boat Sunk!");
        al_draw_text(font, CYAN, shi, shi2+50, ALLEGRO_ALIGN_CENTER, printString);
        gameWin2 ++;
        counter2[1]=0;
    }
    if(counter2[2] == 2){
        sprintf(printString,"Your Destroyer Sunk!");
        al_draw_text(font, CYAN, shi, shi2+100, ALLEGRO_ALIGN_CENTER, printString);
        gameWin2++;
        counter2[2]=0;
    }
    if(counter2[3] == 3){
        sprintf(printString,"Your Submarine Sunk!");
        al_draw_text(font, CYAN, shi, shi2+150, ALLEGRO_ALIGN_CENTER, printString);
        gameWin2++;
        counter2[3]=0;
    }
    if(counter2[4] == 4){
        sprintf(printString,"Your Battleship Sunk!");
        al_draw_text(font, CYAN, shi, shi2+200, ALLEGRO_ALIGN_CENTER, printString);
        gameWin2++;
        counter2[4]=0;
    }
    if(counter2[5] == 5){
        sprintf(printString,"Your Carrier Sunk!\n");
        al_draw_text(font, CYAN, shi, shi2+250, ALLEGRO_ALIGN_CENTER, printString);
        gameWin2++;
        counter2[5]=0;
    }
    if(gameWin2 > 4){
       al_clear_to_color(BLACK);
            ALLEGRO_BITMAP *LOST = nullptr;
            LOST = al_load_bitmap("LOST.bmp");
            al_rest(5);
            al_draw_bitmap(LOST,250,200,0);
            al_flip_display();
            // Free up memory taken by display.
            //al_destroy_display(display);
    }
}
void computerShot(int grid2[10][10],ship s[],int &victory2,int counter2[]){
    srand(time(0));
    int hitNum = 0;
    int choice = rand() % 4 + 1;
    int nextShotX;
    int nextShotY;
    int shotX = rand() % 10 + 1;
    int shotY = rand() % 10 + 1;
    bool keepItGoing = false;
    int endMe = 0;
    int COOL = 0;

    while(!keepItGoing){
        if (grid2[shotX][shotY]==7){
            shotX = rand() % 10 + 1;
            shotY = rand() % 10 + 1;
        }else{
            keepItGoing = true;
        }
    COOL = grid2[shotX][shotY];
    }

    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(grid2[shotX][shotY]==7){
                endMe++;
            }
        }
    }
         switch (COOL) {

        case 2: counter2[1]++;
            printf("Patrol Boat(A.I.):%d\n",counter2[1]);
            break;
        case 3: counter2[2]++;
            printf("Destroyer(A.I.): %d\n",counter2[2]);
            break;
        case 4: counter2[3]++;
            printf("Submarine(A.I.): %d\n",counter2[3]);
            break;
        case 5: counter2[4]++;
            printf("Battleship(A.I.): %d\n",counter2[4]);
            break;
        case 6: counter2[5]++;
            printf("Carrier(A.I.): %d\n",counter2[5]);
            break;
        // case 7: printf("You've already hit this!\n");
        //    break;
        default: printf("MISS\n");

        }
        grid2[shotX][shotY] = 7;

    }
