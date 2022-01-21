#include "rpn_header.h"

void allegro_draw(ALLEGRO_DISPLAY * display, string &input)
{

    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            al_draw_rectangle(0+i*50, 0+j*70, 100+i*50, 100+j*70, RED, 3);
        }
    }
    al_flip_display();

}
