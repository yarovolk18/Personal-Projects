#include <iostream>
#include <vector>
#include <fstream>
#include<cstdlib>
#include "apmatrix.h"
#include "apvector.h"
#include "NiftyMountains_Head.h"
#include <allegro5/allegro.h>                       // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h>
using namespace std;

//The most effective Path for each Algorithm
int most_effective(int *total_elevation_f, int row_f, int &low_pos){
    int low_elev = total_elevation_f[0];

    for(int i = 1; i < row_f; i++){
        if(total_elevation_f[i] < low_elev){
            low_elev = total_elevation_f[i];
            low_pos = i;

        }
    }
    return low_elev;
}
//Min, Max
int find_max(apmatrix<int> v1_f){

int maxi = 0;

for(int i = 0; i < 480; i++){
    for(int j = 0; j<844; j++){
        if(v1_f[i][j] > maxi){
            maxi = v1_f[i][j];
        }
    }
}
return maxi;
}
int find_min(apmatrix<int> v1_f){

int mini = v1_f[0][0];

for(int i = 0; i < 480; i++){
    for(int j = 0; j<844; j++){
        if(v1_f[i][j] < mini){
            mini = v1_f[i][j];
        }
    }
}

return mini;
}
//General
void create_squares(apmatrix<int> &v1_f, int col_f, int row_f){
    int new_num = 0;
    for(int i = 0; i < row_f; i++){
        for(int j = 0; j < col_f; j++){
            new_num = rand()% 1000 + 4500;
            v1_f[i][j] = new_num;
        }
    }
}
void read_in(apmatrix<int> &v1_f, int col_f, int row_f){
//Reading in the file
    ifstream MyFile("Colorado.dat");
    int i = 0;
    int j = 0;

    for(i = 0; i < row_f; i++){
        for(j = 0; j < col_f; j++){
            MyFile >> v1_f[i][j];
        }
    }
    MyFile.close();
}
//Algorithms
void base_algo(apmatrix<int> v1_f, apmatrix<int> &base_moves, int *base_elev, int col_f, int row_f){
    // Variables
    int direc = rand() % 2;
    int min_e = v1_f[0][0];
    int min_en = min_e;
    int curr_r = 0;
    int curr_re = curr_r;
    int vary[3] = {-1, 0, 1};
    int elev = 0;
    int summ = 0;

    for(int i = 0; i < row_f; i++){
        base_elev[i] = 0;
    }

// Pathfinding Algorithm
    for(int k = 0; k < row_f; k++){
        elev = 0;
        min_en = v1_f[k][0];
        base_moves[k][0] = k;
        curr_re = k;
        for(int i = 1; i < col_f; i++){
            elev = 10000;
            min_e = min_en;
            curr_r = curr_re;
            for(int j = 0; j <= 2; j++){
                if(curr_r + vary[j] >=0 && curr_r + vary[j] <=row_f-1){
                    if(abs(min_e - v1_f[(curr_r + vary[j])][i]) < elev){
                        min_en = v1_f[(curr_r + vary[j])][i];
                        elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                        curr_re = curr_r + vary[j];
                        summ = curr_r + vary[j];
                        base_moves[k][i] = summ;
// If the elevation is the same, choose one randomly
                    }else if(abs(min_e - v1_f[(curr_r + vary[j])][i]) == elev){
                        direc = rand() % 2;
                        if (direc == 1){
                            curr_re = curr_r + vary[j];
                            elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                            summ = curr_r + vary[j];
                            base_moves[k][i] = summ;
                        }else{
                            summ = curr_re;
                            base_moves[k][i] = summ;
                        }
                    }

                }
            }
// Elevation tracking
            base_elev[k]+=elev;
        }
    }
}
void down_algo(apmatrix<int> v1_f, apmatrix<int> &down_moves, int *down_elev, int col_f, int row_f){
// Variables
    int direc = rand() % 2;
    int min_e = v1_f[0][0];
    int min_en = min_e;
    int curr_r = 0;
    int curr_re = curr_r;
    int vary[3] = {-1, 0, 1};
    int elev = 0;
    int summ = 0;
    int down_change = -10000;
// Making elevation = 0 initially
    for(int i = 0; i < row_f; i++){
        down_elev[i] = 0;
    }
// Algorithm
    for(int k = 0; k < row_f; k++){
        elev = 0;
        min_en = v1_f[k][0];
        down_moves[k][0] = k;
        curr_re = k;
        for(int i = 1; i < col_f; i++){
            elev = 10000;
            min_e = min_en;
            curr_r = curr_re;
// In case that there is no negative elevation
            for(int j = 0; j <= 2; j++){
                if(curr_r + vary[j] >=0 && curr_r + vary[j] <=row_f-1){
                    if(abs(min_e - v1_f[(curr_r + vary[j])][i]) < elev){
                        min_en = v1_f[(curr_r + vary[j])][i];
                        elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                        curr_re = curr_r + vary[j];
                        summ = curr_r + vary[j];
                        down_moves[k][i] = summ;
// If two elevations are the same, chooses one randomly
                    }else if(abs(min_e - v1_f[(curr_r + vary[j])][i]) == elev){
                        direc = rand() % 2;
                        if (direc == 1){
                            curr_re = curr_r + vary[j];
                            elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                            summ = curr_r + vary[j];
                            down_moves[k][i] = summ;
                        }else{
                            summ = curr_re;
                            down_moves[k][i] = summ;
                        }
                    }
                }
            }
            // Checking for negative elevation (going down rather than up)
                for(int j = 0; j <= 2; j++){
                    if(curr_r + vary[j] >=0 && curr_r + vary[j] <=row_f-1){
                    if(min_e - v1_f[(curr_r + vary[j])][i] < 0 && min_e - v1_f[(curr_r + vary[j])][i] > down_change){
                        min_en = v1_f[(curr_r + vary[j])][i];
                        elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                        curr_re = curr_r + vary[j];
                        summ = curr_r + vary[j];
                        down_moves[k][i] = summ;
                        down_change = min_e - v1_f[(curr_r + vary[j])][i];
                }
            }
        }
// Keeping track of elevation
            down_elev[k]+=elev;
        }
    }


}
void arbi_algo(apmatrix<int> v1_f, apmatrix<int> &arbi_moves, int *arbi_elev, int col_f, int row_f, int *rand_col_arr){

    int rand_col = 0;
    int direc = rand() % 2;
    int min_e = v1_f[0][0];
    int min_en = min_e;
    int curr_r = 0;
    int curr_re = curr_r;
    int vary[3] = {-1, 0, 1};
    int elev = 0;
    int summ = 0;

    for(int i = 0; i < row_f; i++){
        arbi_elev[i] = 0;
    }

    for(int k = 0; k < row_f; k++){
        rand_col = rand() % 843+1;
        rand_col_arr[k] = rand_col;
        elev = 0;
        min_en = v1_f[k][rand_col];
        curr_re = k;
// For values between random column and 843
        for(int i = rand_col + 1; i < col_f; i++){
            elev = 10000;
            min_e = min_en;
            curr_r = curr_re;
            for(int j = 0; j <= 2; j++){
                if(curr_r + vary[j] >=0 && curr_r + vary[j] <=row_f-1){
                    if(abs(min_e - v1_f[(curr_r + vary[j])][i]) < elev){
                        min_en = v1_f[(curr_r + vary[j])][i];
                        elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                        curr_re = curr_r + vary[j];
                        summ = curr_r + vary[j];
                        arbi_moves[k][i] = summ;
                    }else if(abs(min_e - v1_f[(curr_r + vary[j])][i]) == elev){
                        direc = rand() % 2;
                        if (direc == 1){
                            curr_re = curr_r + vary[j];
                            elev = abs(min_e - v1_f[(curr_r + vary[j])][i]);
                            summ = curr_r + vary[j];
                            arbi_moves[k][i] = summ;
                        }else{
                            summ = curr_re;
                            arbi_moves[k][i] = summ;
                        }
                    }
                }
            }
            arbi_elev[k]+=elev;
        }
// For values from 0 to random
        curr_re = k;
        for(int m = rand_col; m >= 0; m--){
            elev = 10000;
            min_e = min_en;
            curr_r = curr_re;
            for(int j = 0; j <= 2; j++){
                if(curr_r + vary[j] >=0 && curr_r + vary[j] <=row_f-1){
                    if(abs(min_e - v1_f[(curr_r + vary[j])][m]) < elev){
                        min_en = v1_f[(curr_r + vary[j])][m];
                        elev = abs(min_e - v1_f[(curr_r + vary[j])][m]);
                        curr_re = curr_r + vary[j];
                        summ = curr_r + vary[j];
                        arbi_moves[k][m] = summ;
                    }else if(abs(min_e - v1_f[(curr_r + vary[j])][m]) == elev){
                        direc = rand() % 2;
                        if (direc == 1){
                            curr_re = curr_r + vary[j];
                            elev = abs(min_e - v1_f[(curr_r + vary[j])][m]);
                            summ = curr_r + vary[j];
                            arbi_moves[k][m] = summ;
                        }else{
                            summ = curr_re;
                            arbi_moves[k][m] = summ;
                        }
                    }
                }
            }
// Keeping Track of the elevation
            arbi_elev[k]+=elev;
        }

    }

}

