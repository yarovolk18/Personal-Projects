// VOLKOV, YAROSLAV // ICS4U // TOWERS OF HANOI // 02/10/2020
#include "towers_header.h"

// DRAWING THE TOWERS
int allegro_draw(ALLEGRO_DISPLAY *display, int num_of_disks, struct Stack *src,
                 struct Stack *aux, struct Stack *dest, int &moves, ALLEGRO_FONT* font, int optMoves, int &i)
{
    // Shapes and Stuff
    al_clear_to_color(BLACK);
    // WIN CONDITION
    if(dest -> top == num_of_disks-1)
    {
        al_draw_filled_circle(315, 300, 30, RED);
        al_draw_filled_circle(645, 300, 30, RED);
        al_draw_text(font, PURPLE, 480, 100, ALLEGRO_ALIGN_CENTER, "GREAT SOLVE!");
    }
    // PRESS ENTER
    al_draw_text(font, MAGENTA, 10, 46, ALLEGRO_ALIGN_LEFT, "PRESS ENTER TO SOLVE");
    // NUMBER OF MOVES
    al_draw_textf(font, CORAL, 10, 10, ALLEGRO_ALIGN_LEFT, "%d", moves);
    // OPTIMAL MOVES
    al_draw_textf(font, CORAL, 960, 10, ALLEGRO_ALIGN_RIGHT, "OPTIMAL MOVES : %d", optMoves);
    // PIN DRAWING
    for(i = 0; i < 3; i++)
    {
        al_draw_filled_rectangle(0 + (300 + 30)*i, 510,
                                 0 + (i+1)*300 +30*i, 510 + 50, PURPLE);
        al_draw_filled_rectangle(140 + (20 + 310)*i, 510,
                                 140 + (i+1)*20 + 310*i, 510 - 300, PURPLE);
        al_draw_rectangle(0 + (300 + 30)*i, 510,
                                 0 + (i+1)*300 + 30*i, 510 + 50, CORAL, 5);
        al_draw_rectangle(140 + (20 + 310)*i, 510,
                                 140 + (i+1)*20 + 310*i, 510 - 300, CORAL, 5);
    }
    // DRAWING SOURCE PIN
    for(i = 0; i < src -> top + 1; i++)
    {
        al_draw_filled_rectangle(150 + 10*(src->array[i]), 510 - 20 - 20*i,
                                 150 - 10*(src->array[i]), 510 - 20*i, ORANGE);

        al_draw_rectangle(150 + 10*(src->array[i]), 510 - 20 - 20*i,
                          150 - 10*(src->array[i]), 510 - 20*i, LAVENDER, 3);
    }
    // DRAWING AUXILLARY PIN
    for(i = 0; i < aux -> top + 1; i++)
    {
        al_draw_filled_rectangle(480 + 10*(aux->array[i]), 510 - 20 - 20*i,
                                 480 - 10*(aux->array[i]), 510 - 20*i, ORANGE);

        al_draw_rectangle(480 + 10*(aux->array[i]), 510 - 20 - 20*i,
                          480 - 10*(aux->array[i]), 510 - 20*i, LAVENDER, 3);
    }
    // DRAWING DESTINATION PIN
    for(i = 0; i < dest -> top + 1; i++)
    {
        al_draw_filled_rectangle(810 + 10*(dest->array[i]), 510 - 20 - 20*i,
                                 810 - 10*(dest->array[i]), 510 - 20*i, ORANGE);

        al_draw_rectangle(810 + 10*(dest->array[i]), 510 - 20 - 20*i,
                          810 - 10*(dest->array[i]), 510 - 20*i, LAVENDER, 3);

    }
    i = 0;
    al_flip_display();
    return 0;
}
//PLAYABLE FUNCTION
int allegro_play(ALLEGRO_DISPLAY * display, int &num_of_disks, struct Stack *src,
                 struct Stack *aux, struct Stack *dest, int &moves, int &i)
{
    // add event queue object
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    event_queue = al_create_event_queue();

    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 36, 0);
    ALLEGRO_FONT *fontL = al_load_ttf_font("comic.ttf", 20, 0);

    if (!al_init_primitives_addon())
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_install_mouse();
    al_install_keyboard();
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //INSTRUCTION
    int space = 40;
    int x_cor = 480;
    for(int i = 10; i >= 1; i--)
    {
        al_clear_to_color(CORAL);
        al_draw_text(fontL, PURPLE, x_cor, 0*space, ALLEGRO_ALIGN_CENTER, "RULES");
        al_draw_text(fontL, PURPLE, x_cor, 1*space, ALLEGRO_ALIGN_CENTER, "PRESS ENTER TO SOLVE");
        al_draw_text(fontL, PURPLE, x_cor, 2*space, ALLEGRO_ALIGN_CENTER, "USE THE UP/DOWN KEYS TO ALTER THE NUMBER OF DISKS");
        al_draw_text(fontL, PURPLE, x_cor, 3*space, ALLEGRO_ALIGN_CENTER, "STEP 1: CLICK THE TOWER FROM WHICH YOU WISH TO A DISK");
        al_draw_text(fontL, PURPLE, x_cor, 4*space, ALLEGRO_ALIGN_CENTER, "STEP 2: CLICK THE TOWER ON WHICH YOU WISH TO PLACE SET DISK");
        al_draw_text(fontL, PURPLE, x_cor, 5*space, ALLEGRO_ALIGN_CENTER, "STEP 3: CONTINUE UNTIL ALL DISKS ARE ON THE RIGHTMOST TOWER");
        al_draw_text(fontL, PURPLE, x_cor, 6*space, ALLEGRO_ALIGN_CENTER, "STARTING IN:");
        al_draw_textf(fontL, PURPLE, x_cor+ 150, 6*space, ALLEGRO_ALIGN_CENTER, "%d", i);
        al_flip_display();
        al_rest(1);
    }
    //al_clear_to_color(BLACK);
    bool gameOver = false;
    int mX = 0;
    int mY = 0;
    int mX2;
    int mY2;
    int optMoves = pow(2, num_of_disks) - 1;
    while(!gameOver)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            gameOver = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ENTER:
                moves = 0;
                empty_it(src);
                empty_it(aux);
                empty_it(dest);
                for (int i = num_of_disks; i >= 1; i--)
                {
                    push(src, i);
                }
                allegro_draw(display, num_of_disks, src, aux, dest, moves, font, optMoves, i);
                moveTower(num_of_disks, 'A', 'C', 'B', src, aux, dest, display, num_of_disks, moves, font, optMoves, i);
                //TESTING
                //gameOver = true;
                break;
            // INCREASE DISKS
            case ALLEGRO_KEY_UP:
                moves = 0;
                if(num_of_disks < 13)
                {
                    num_of_disks++;
                    empty_it(src);
                    empty_it(aux);
                    empty_it(dest);
                    for (int i = num_of_disks; i >= 1; i--)
                    {
                        push(src, i);
                    }
                }
                optMoves = pow(2, num_of_disks) - 1;
                break;
            // DECREASE DISKS
            case ALLEGRO_KEY_DOWN:
                moves = 0;
                if(num_of_disks > 2)
                {
                    num_of_disks--;
                    empty_it(src);
                    empty_it(aux);
                    empty_it(dest);
                    for (int i = num_of_disks; i >= 1; i--)
                    {
                        push(src, i);
                    }
                }
                optMoves = pow(2, num_of_disks) - 1;
                break;
            case ALLEGRO_KEY_ESCAPE:
                gameOver = true;
                break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(mX == 0 && mY == 0)
            {
                mX = ev.mouse.x;
                mY = ev.mouse.y;
                //TESTING
                //cout << "X: " << mX << endl;
                //cout << "Y: " << mY << endl;
            }
            else
            {
                mX2 = ev.mouse.x;
                mY2 = ev.mouse.y;
                moves ++;
                //TESTING
                //cout << "X2: " << mX2 << endl;
                //cout << "Y2: " << mY2 << endl;
                click_check(mX, mY, mX2, mY2, src, aux, dest, num_of_disks);
                mX = 0;
                mY = 0;
            }
            // TESTING
            /*if(dest -> top == (num_of_disks - 1))
            {
                gameOver = true;
            }*/
        }
        allegro_draw(display, num_of_disks, src, aux, dest, moves, font, optMoves, i);
    }
    return 0;
};

