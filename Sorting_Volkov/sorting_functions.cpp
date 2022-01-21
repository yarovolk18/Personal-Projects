#include "sorting_header.h"

// GENERAL CODE START
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

// RANDOM NUMBERS
void number_assign(struct Stack* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        a->array[i] = rand()%400+1;
    }
}

// USER INTERFACE
void interface(struct Stack* a, int n)
{
    // Allegro Initialize
    al_init();

    // Initialize display
    ALLEGRO_DISPLAY *display = nullptr;
    display = al_create_display(SCREEN_W, SCREEN_H);
    al_set_window_title(display, "Sorting");

    // Event Queue
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    event_queue = al_create_event_queue();

    // Font & Shapes
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 50, 0);
    ALLEGRO_FONT *fontL = al_load_ttf_font("comic.ttf", 30, 0);

    if (!al_init_primitives_addon())
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        //return -1;
    }

    draw_interface(font, fontL);
    al_flip_display();

    // MOUSE + KEYBOARD
    al_install_mouse();
    al_install_keyboard();
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    ////

    bool gameOver = false;
    int mX = 0;
    int mY = 0;
    int moves = 0;
    int comparisons = 0;
    int L = 0;
    int R = 199;
    int numChoice = 0;
    // MAIN GAME LOOP
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
            case ALLEGRO_KEY_ESCAPE:
                gameOver = true;
                break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            mX = ev.mouse.x;
            mY = ev.mouse.y;

            click_check(mX, mY, display, a, n, moves, comparisons);
            gameOver = true;
        }
    }
    for(int i = 0; i < 200; i++)
    {
        cout << a-> array[i] << endl;
    }
    al_draw_text(fontL, BLUE, 10, 10, ALLEGRO_ALIGN_LEFT, "Input the number you wish to find into exe window");
    al_flip_display();
    // Number that needs to be found within the list
    cout << "Array Listed above for testing purposes/knowledge of present and absent elements" << endl;
    cout << "Enter a Number between 1 & 400 that you wish to find: " ;
    cin >> numChoice;

    al_flip_display();
    binarySort(a, numChoice, L, R, display, fontL);
    al_rest(5);

    // Destroy Display
    al_destroy_display(display);
}
// GENERAL CODE END

