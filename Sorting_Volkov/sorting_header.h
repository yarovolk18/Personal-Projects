#ifndef SORTING_H // include guard
#define SORTING_H
#include <iostream>
#include <allegro5/allegro.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// COLOURS
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

// SCREEN SIZES
const int SCREEN_W = 960;   // screen width
const int SCREEN_H = 600;  // screen height
using namespace std;

// STACK PARAMETERS
struct Stack
{
    unsigned capacity;
    int *array;

};

// GENERATING ARRAY
void number_assign(struct Stack* a, int n);

// INTERFACE
void interface(struct Stack* a, int n);

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity);

// swap
void swap(int *a,int *b);
// QUICKSORT CODE START

//Splitting
int partition (struct Stack* a, int p, int r, int &moves, int &comparisons, ALLEGRO_DISPLAY* display);
// Quicksort
void quickSort(struct Stack* a, int p, int r, int &moves, int &comparisons, ALLEGRO_DISPLAY* display);
// QUICKSORT CODE END

// BUBBLE SORT CODE START
void bubbleSort(struct Stack* a, int n, int &moves, int &comparisons, ALLEGRO_DISPLAY* display);
// BUBBLE SORT CODE END

// SELECTION SORT START
void selectionSort(struct Stack* a, int n, int &moves, int &comparisons, ALLEGRO_DISPLAY* display);
// SELECTION SORT END

// BINARY SORT CODE START
void binarySort(struct Stack* a, int n, int &left, int &right, ALLEGRO_DISPLAY* display, ALLEGRO_FONT * fontL);
// BINARY SORT CODE END

// ALLEGRO CODE START
void draw_interface(ALLEGRO_FONT* font,  ALLEGRO_FONT* fontL);

// CHECKING WHICH ALGORITHM IS SELECTED
void click_check(int mx, int my, ALLEGRO_DISPLAY* display, struct Stack* a, int n, int moves, int comparisons);

// DRAWING SORT
void draw_sort(ALLEGRO_DISPLAY* display, struct Stack* a, int n);

// DRAWING QUICK SORT
void draw_quick(ALLEGRO_DISPLAY* display, struct Stack* a, int n, int r);

// DRAWING BINARY SORT
void draw_binary(ALLEGRO_DISPLAY* display, struct Stack* a, int n, int r);

// ALLEGRO CODE END

#endif
