
#include <ncurses.h>
#include <iostream>
#include "funz_array.h"

using namespace std;


const int n = 4;

struct vett_riga {int colonna[n];};

class matrice {

protected:

    vett_riga riga[n];

    int find_most_down(){

        int index = 0;
        bool found_non_zero = false;
        int col = 0;
        int rig = n - 1;

        while((!found_non_zero) && (rig >= 0)){

            col = 0;
            found_non_zero = false;

            while( (!found_non_zero) && (col < n) ){

                if(riga[rig].colonna[col] != 0){

                    found_non_zero = true;
                    index = rig;
                }
                else{col += 1;}
            }

            rig -= 1;
        }

        return index;

    };

    int find_most_left(){

        int index = 0;
        bool found_non_zero = false;
        int col = 0;
        int rig = 0;

        while((!found_non_zero) && (col < n)){

            rig = 0;
            found_non_zero = false;

            while( (!found_non_zero) && (rig < n) ){

                if(riga[rig].colonna[col] != 0){

                    found_non_zero = true;
                    index = col;
                }
                else{rig += 1;}
            }

            col += 1;
        }

        return index;

    };

    int find_most_up(){

        int index = 0;
        bool found_non_zero = false;
        int col = 0;
        int rig = 0;

        while((!found_non_zero) && (rig < n)){

            col = 0;
            found_non_zero = false;

            while( (!found_non_zero) && (col < n) ){

                if(riga[rig].colonna[col] != 0){

                    found_non_zero = true;
                    index = rig;
                }
                else{col += 1;}
            }

            rig += 1;
        }

        return index;

    };

    int find_most_right(){

        int index = 0;
        bool found_non_zero = false;
        int col = n - 1;
        int rig = 0;

        while((!found_non_zero) && (col >= 0)){

            rig = 0;
            found_non_zero = false;

            while( (!found_non_zero) && (rig < n) ){

                if(riga[rig].colonna[col] != 0){

                    found_non_zero = true;
                    index = col;
                }
                else{rig += 1;}
            }

            col -= 1;
        }

        return index;
    };

    void ruota_90_dx_libero() {

        trasponi();
        simm_vertical_flip();

    };

    void ruota_90_sx_libero() {

        ruota_90_dx_libero();
        ruota_90_dx_libero();
        ruota_90_dx_libero();

    };

public:

    matrice() {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                riga[k].colonna[j] = 0;
            }
        }
    };

    void set(int k, int j, int x) { riga[k].colonna[j] = x; }

    void set_mat(matrice mat_input){

        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){

                riga[k].colonna[j] = mat_input.get(k,j);

            }
        }

    }

    int get(int k, int j){return riga[k].colonna[j];}

    void simm_vertical_flip() {

        for (int k = 0; k < n; k++) {
            inverti(riga[k].colonna, n);
        }
    };

    void stampa_matrice() {

        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                cout << riga[k].colonna[j] << " ";
            }
            cout << endl;
        }

        cout << endl;

    };

    void trasponi() {

        for (int k = 0; k < n; k++) {
            for (int j = k + 1; j < n; j++) {

                int temp = riga[k].colonna[j];

                riga[k].colonna[j] = riga[j].colonna[k];
                riga[j].colonna[k] = temp;
            }
        }
    };

    void ancora_up_sx(){

        int most_left = find_most_left();
        int most_up = find_most_up();

        for (int k = most_up; k < n; k++){

            for(int j = most_left; j < n; j++){

                scambia(riga[k].colonna[j], riga[k - most_up].colonna[j - most_left]);

            }

        }

    };

    void ruota_90_dx_ancorato(){

        ruota_90_dx_libero();
        ancora_up_sx();

    };

    void ruota_90_sx_ancorato(){

        ruota_90_sx_libero();
        ancora_up_sx();
    };

};


matrice mat_quadrato();
matrice mat_rettangolo();
matrice mat_S_shape();
matrice mat_Z_shape();
matrice mat_T_shape();
matrice mat_L_shape();
matrice mat_J_shape();