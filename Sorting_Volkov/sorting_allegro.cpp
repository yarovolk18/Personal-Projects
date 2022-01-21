#include "sorting_header.h"

// DRAWING THE SORTED ARRAY
void draw_sort(ALLEGRO_DISPLAY* display, struct Stack* a, int n)
{
    al_clear_to_color(BLACK);
    for(int i = 0; i < n; i++)
    {
        al_draw_filled_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), GREEN);
        al_draw_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), BLACK, 1);
        al_flip_display();
    }
}

// DRAWING THE QUICK SORT ARRAY (Different functions due to more parameters)
void draw_quick(ALLEGRO_DISPLAY* display, struct Stack* a, int n, int r)
{
    al_clear_to_color(BLACK);
    for(int i = 0; i < n; i++)
    {
        if(a->array[i] == r)
        {
            al_draw_filled_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), RED);
            al_draw_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), BLACK, 1);
        }
        else
        {
            al_draw_filled_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), GREEN);
            al_draw_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), BLACK, 1);
        }
        al_flip_display();
    }
}

// CHECKING WHICH SORT IS SELECTED
void click_check(int mx, int my, ALLEGRO_DISPLAY* display, struct Stack* a, int n, int moves, int comparisons)
{
    if(mx >= 100 && mx <= 860)
    {
        if(my >= 150 && my <= 250)
        {
            quickSort(a,0,n-1, moves, comparisons, display);
            cout << "QUICK COMPARISONS: " << comparisons << endl;
            cout << "QUICK MOVES: " << moves << endl;
        }
        else if(my >= 300 && my <= 400)
        {
            bubbleSort(a, n, moves, comparisons, display);
            cout << "BUBBLE COMPARISONS: " << comparisons << endl;
            cout << "BUBBLE MOVES: " << moves << endl;
        }
        else if(my >= 450 && my <= 550)
        {
            selectionSort(a, n, moves, comparisons, display);
            cout << "SELECTION COMPARISONS: " << comparisons << endl;
            cout << "SELECTION MOVES: " << moves << endl;
        }
    }

}

// INTERFACE FOR SELECTION
void draw_interface(ALLEGRO_FONT* font, ALLEGRO_FONT* fontL)
{
    al_draw_text(font, BLUE, 480, 50, ALLEGRO_ALIGN_CENTER, "SORTING");
    // BUBBLE SORT
    al_draw_filled_rectangle(100, 150, 860, 250, TEAL);
    al_draw_rectangle(100, 150, 860, 250, GREEN, 3);
    al_draw_text(fontL, MINT, 480, 175, ALLEGRO_ALIGN_CENTRE, "QUICK SORT");
    // SELECTION SORT
    al_draw_filled_rectangle(100, 300, 860, 400, TEAL);
    al_draw_rectangle(100, 300, 860, 400, GREEN, 3);
    al_draw_text(fontL, MINT, 480, 325, ALLEGRO_ALIGN_CENTRE, "BUBBLE SORT");
    // QUICK SORT
    al_draw_filled_rectangle(100, 450, 860, 550, TEAL);
    al_draw_rectangle(100, 450, 860, 550, GREEN, 3);
    al_draw_text(fontL, MINT, 480, 475, ALLEGRO_ALIGN_CENTRE, "SELECTION SORT");
}

// Drawing binary (Lack of flip display for output purposes)
void draw_binary(ALLEGRO_DISPLAY* display, struct Stack* a, int n, int r)
{
    for(int i = 0; i < n; i++)
    {
        if(a->array[i] == r)
        {
            al_draw_filled_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), RED);
            al_draw_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), BLACK, 1);
        }
        else
        {
            al_draw_filled_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), GREEN);
            al_draw_rectangle(0+(5*i), 600, 0+(5*(i+1)), 600-(a->array[i]), BLACK, 1);
        }
        al_flip_display();
    }
}
