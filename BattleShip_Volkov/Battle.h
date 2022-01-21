#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
const int SCREEN_W = 1300;       // screen width
const int SCREEN_H = 990;       // screen height
const int COL_1 = 40;    //tabs for chart layout
const int COL_2 = 180;
const int COL_3 = 400;
const int COL_4 = 650;
const int COL_5 = 890;
//#define BACKGROUND al_map_rgb(0x09, 0x31, 0x45)
#define BACKGROUND al_map_rgb(0xff, 0xff, 0xff)
#define FOREGROUND al_map_rgb(0x3C, 0x64, 0x78)


// lots of colours to choose from
#define RED		 al_map_rgb(230, 25, 75)
#define GREEN	 al_map_rgb(60, 180, 75)
#define YELLOW	 al_map_rgb(255, 225, 25)
#define BLUE	 al_map_rgb(0, 130, 200)
#define ORANGE   al_map_rgb(245, 130, 48)
#define PURPLE	 al_map_rgb(145, 30, 180)
#define CYAN	 al_map_rgb(70, 240, 240)
#define MAGENTA	 al_map_rgb(240, 50, 230)
#define LIME	 al_map_rgb(210, 245, 60)
#define PINK	 al_map_rgb(250, 190, 190)
#define TEAL	 al_map_rgb(0, 128, 128)
#define LAVENDER al_map_rgb(230, 190, 255)
#define BROWN	 al_map_rgb(170, 110, 40)
#define BEIGE	 al_map_rgb(255, 250, 200)
#define MAROON	 al_map_rgb(128, 0, 0)
#define MINT	 al_map_rgb(170, 255, 195)
#define OLIVE	 al_map_rgb(128, 128, 0)
#define CORAL	 al_map_rgb(255, 215, 180)
#define NAVY	 al_map_rgb(0, 0, 128)
#define GREY	 al_map_rgb(128, 128, 128)
#define WHITE	 al_map_rgb(255, 255, 255)
#define BLACK	 al_map_rgb(0, 0, 0)

struct ship {
    int locationX[5];//Toset up location for the ship
    int locationY[5];
};

void initializeAllegro();
int checkSetup(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void drawMap();
void gameStart(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_FONT *font, int grid1[10][10],int grid2[10][10],ship s[]);
int calc(int counter1[],int &gameWin);
void start(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_FONT *font,bool &cont1);
void makeShips(int grid1[10][10],ship s[]);
void playerShips(int grid2[10][10],ship s[]);
void computerShot(int grid2[10][10],ship s[],int &victory2,int counter2[]);
void calc2(int counter2[], int &gameWin2);
