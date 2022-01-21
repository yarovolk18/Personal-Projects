// VOLKOV, YAROSLAV // ICS4U // TOWERS OF HANOI // 02/10/2020
#ifndef TOWER_H // include guard
#define TOWER_H
#include<iostream>
#include "towers_header.h"
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

const int SCREEN_W = 960;   // screen width
const int SCREEN_H = 600;  // screen height
using namespace std;

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
using namespace std;
// A structure to represent a stack
struct Stack
{
    unsigned capacity;
    int top;
    int *array;

};
// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity);

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack);

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack);

// Function to add an item to stack. It increases
// top by 1
void push(struct Stack *stack, int item);

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack);

//Function to implement TOH puzzle
void moveTower(int height, char fromPole, char toPole, char withPole, struct Stack *src, struct Stack *aux,
               struct Stack *dest, ALLEGRO_DISPLAY *display, int disks, int &moves, ALLEGRO_FONT* font, int optMoves, int &i);
// Function to implement legal movement between
// two poles
void moveDisk(char fp, char tp, struct Stack *src,
              struct Stack *aux, struct Stack *dest, int disks,
              ALLEGRO_DISPLAY *display, int &moves, ALLEGRO_FONT* font, int optMoves, int &i);

//Drawing the Disks
int allegro_draw(ALLEGRO_DISPLAY *display, int num_of_disks, struct Stack *src,
                 struct Stack *aux, struct Stack *dest, int &moves, ALLEGRO_FONT* font, int optMoves, int &i);

// Playable
int allegro_play(ALLEGRO_DISPLAY * display, int &num_of_disks, struct Stack *src,
                 struct Stack *aux, struct Stack *dest, int &moves, int &i);

// Boundaries
void click_check(int mx, int my, int mx2, int my2, struct Stack *src, struct Stack *aux, struct Stack *dest, int num_of_disks);

// EMTPY LISTS
void empty_it(struct Stack *temp);
#endif

