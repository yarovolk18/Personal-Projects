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

// Base Functions
void read_in(apmatrix<int> &v1_f, int col_f, int row_f);
void algorithm(apmatrix<int> &v1_f, int col_f, int row_f);

//Algorithms
void base_algo(apmatrix<int> v1_f, apmatrix<int> &base_moves, int *base_elev, int col_f, int row_f);
void down_algo(apmatrix<int> v1_f, apmatrix<int> &base_moves, int *base_elev, int col_f, int row_f);
void arbi_algo(apmatrix<int> v1_f, apmatrix<int> &arbi_moves, int *arbi_elev, int col_f, int row_f);

//Max, Min
int find_max(apmatrix<int> v1_f);
int find_min(apmatrix<int> v1_f);
void create_squares(apmatrix<int> &v1_f, int col_f, int row_f);

// Main + Actual Algorithm
int main(int argc, char *argv[]){



    int col = 844;
    int row = 480;
    apmatrix<int> v1(1, 1, 0);
    v1.resize(row, col);

    read_in(v1, col, row);
    algorithm(v1, col, row);


return 0;

}
void algorithm(apmatrix<int> &v1_f, int col_f, int row_f){
     // Base Program
    apmatrix<int> base_moves(480, 844, 0);
    int base_elev[480];
    // Always Down
    apmatrix<int> down_moves(480, 844);
    int down_elev[480];
    // Arbitrary Location Extension
    apmatrix<int> arbi_moves(480, 844);
    int arbi_elev[480];

    int prefer = 0;
    int rand_col_arr[844];
    cout << "Please Select The Preffered Algorithm: " << endl;
    cout << "1 : Base Algorithm" << "\n" << "2 : Always Down Algorithm" << "\n" << "3 : Arbitrary Point Algorithm" << endl;
    cin >> prefer;

    int mini = find_min(v1_f);
    int maxi = find_max(v1_f);
    int low_pos = 0;
    int keep = true;
    while(keep){
    if(prefer == 1){
        //Runs base algorithm
        base_algo(v1_f, base_moves, base_elev, col_f, row_f);
        int lowest_path = most_effective(base_elev, row_f , low_pos);
        cout << "Lowest Path Index : " << low_pos << endl;
        cout << "Lowest Path Total Elevation : " << base_elev[low_pos] << endl;
        draw_map(base_moves, mini, maxi, v1_f, low_pos, base_elev, rand_col_arr);
        keep = false;
    }else if(prefer == 2){
        //Runs down algorithm
        down_algo(v1_f, down_moves, down_elev, col_f, row_f);
        int lowest_path = most_effective(down_elev, row_f , low_pos);
        cout << "Lowest Path Index : " << low_pos << endl;
        cout << "Lowest Path Total Elevation : " << down_elev[low_pos] << endl;
        draw_map(down_moves, mini, maxi, v1_f, low_pos, down_elev, rand_col_arr);
        keep = false;
    }else if(prefer == 3){
        // Arbitrary Location
        arbi_algo(v1_f, arbi_moves, arbi_elev, col_f, row_f, rand_col_arr);
        int lowest_path = most_effective(arbi_elev, row_f , low_pos);
        cout << "Lowest Path Index : " << low_pos << endl;
        cout << "Lowest Path Total Elevation : " << arbi_elev[low_pos] << endl;
        draw_map(arbi_moves, mini, maxi, v1_f, low_pos, arbi_elev, rand_col_arr);
        keep = false;
    }else{
        cout << "Please Select A Valid Option." << endl;
        cin >> prefer;
    }

    }
}
