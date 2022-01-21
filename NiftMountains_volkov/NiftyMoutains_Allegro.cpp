#include "NiftyMountains_Head.h"
// Here is your first line. You must include the allegro header file or else nothing will work!
#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

// lots of colours to choose from
#define MAROON	 al_map_rgb(128, 0, 0)
#define GREEN    al_map_rgb(0, 255, 10)
#define GREY	 al_map_rgb(128, 128, 128)
#define WHITE	 al_map_rgb(255, 255, 255)
#define BLUE     al_map_rgb(0, 0, 255)
#define YELLOW   al_map_rgb(255, 255, 0)
#define PURPLE   al_map_rgb(255, 0,255)
#define BLACK	 al_map_rgb(0, 0, 0)

using namespace std;
// Drawing the selected algorithm
int draw_map(apmatrix<int> base_moves, int mini_f, int maxi_f, apmatrix<int> &v1_f, int low_pos, int *base_elev, int *rand_col_arr) {
	ALLEGRO_DISPLAY *display = nullptr;

	// Initialize Allegro
	al_init();

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
    al_set_window_title(display, "Nifty Mountains Map");

	// Initialize primative add on
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	int c = 0;
	int diff = maxi_f - mini_f;
	ALLEGRO_COLOR colour = al_map_rgb(c, c, c);
	int sizeC = 1;

    // Drawing the Mountain Range
        for(int i = 0; i < 480; i++){
            for(int j = 0; j < 844; j++){
                c = 255 - (v1_f[i][j]/(diff/255));
                colour = al_map_rgb(c, c, c);
                al_draw_pixel(j, i, colour);
            }
        }
    // Drawing all the paths of the selected algorithms
        for(int i = 0; i < 480; i++){
            for(int j = 0; j < 844; j++){
                al_draw_pixel(j, base_moves[i][j], MAROON);
            }
        }
    // Drawing the best path of the selected algorithm
         for(int i = 0; i < 480; i++){
            for(int j = 0; j < 844; j++){
                // Best Path
                if(i == low_pos){
                    al_draw_pixel(j, base_moves[i][j], GREEN);
                }
                // Highest Altitude
                if(v1_f[i][j] == maxi_f){
                    al_draw_circle(j, i, 4, BLUE, 4);
                }
                // Lowest Altitudes
                if(v1_f[i][j] == mini_f){
                    al_draw_circle(j, i, 4, YELLOW, 4);
                }
            }
        }
    // Font Addon
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon

    // load the specific font you want
    ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 20, 0);
    int first_line = 480;
    int addon = 150;
    // Drawing the Text to Explain Paths
    al_draw_text(font, RED, 0, first_line, ALLEGRO_ALIGN_LEFT, "All Paths");
    al_draw_text(font, GREEN, 0 + addon - 50, first_line, ALLEGRO_ALIGN_LEFT, "Best Path");
    al_draw_text(font, BLUE, 0 + (addon*2) - 80, first_line, ALLEGRO_ALIGN_LEFT, "Highest Point");
    al_draw_text(font, YELLOW, 0 + (addon*3) - 50, first_line, ALLEGRO_ALIGN_LEFT, "Lowest Point");


    // Drawing
  	al_flip_display();

  	// Wait for a 5 seconds before destroy the dispaly and exit the program.
	al_rest(10);
	al_destroy_display(display);
	return 0;
}


