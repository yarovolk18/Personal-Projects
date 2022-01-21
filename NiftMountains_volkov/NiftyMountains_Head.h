#ifndef NIFTYMOUNTAINS_HEAD_H_INCLUDED
#define NIFTYMOUNTAINS_HEAD_H_INCLUDED
#include "apmatrix.h"
#include "apvector.h"

#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

const int SCREEN_W = 844;       // screen width
const int SCREEN_H = 510;       // screen height

#define RED	al_map_rgb(230, 25, 75)
#define GREY al_map_rgb(128, 128, 128)

void read_in(apmatrix<int> &v1_f, int col_f, int row_f);

void algorithm(apmatrix<int> &v1_f, int col_f, int row_f);

void base_algo(apmatrix<int> v1_f, apmatrix<int> &base_moves, int *base_elev, int col_f, int row_f);

void down_algo(apmatrix<int> v1_f, apmatrix<int> &base_moves, int *base_elev, int col_f, int row_f);

void arbi_algo(apmatrix<int> v1_f, apmatrix<int> &arbi_moves, int *arbi_elev, int col_f, int row_f, int *rand_col_arr);

int draw_map(apmatrix<int> base_moves, int mini_f, int maxi_f, apmatrix<int> &v1_f, int low_pos,int *base_elev, int *rand_col_arr);

void draw_path(int summ_f, int i_f);

void create_squares(apmatrix<int> &v1_f, int col_f, int row_f);

int find_max(apmatrix<int> v1_f);

int find_min(apmatrix<int> v1_f);

int most_effective(int *total_elevation, int row_f, int &low_pos);

#endif
