
#include "classe_matrice.h"


class tetramino{

protected:

    int pos_x;
    int pos_y;
    bool caduto;
    matrice mat;

public:

    tetramino(int x = 0, int y = 0, bool cad = false ,matrice matr = matrice()){
        pos_x = x;
        pos_y = y;
        caduto = cad;
        mat = matr;};

    bool is_caduto(){return caduto;}
    int get_x(){return pos_x;};
    int get_y(){return pos_y;};
    matrice get_mat(){return mat;};

    void set_caduto(bool cad){caduto = cad;}
    void set_pos(int y, int x){pos_x = x; pos_y = y;}
    void set_mat(matrice matr){mat = matr;}

    void cancella(){

        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                if(mat.get(k,j) != 0){mvprintw(pos_y + k, pos_x + j, " ");}
            }
        }


    };

    bool can_print(int y, int x){

        bool printable = true;

        int col = 0;
        int rig = 0;

        while((printable) && (rig < n)){

            col = 0;

            while((printable) && (col < n)){

                if( (mat.get(rig, col) != 0) && (mvinch(y + rig, x + col) != 32) ){printable = false;}
                else{col += 1;}
            }

            rig += 1;
        }

        return printable;

    };

    void move(int y, int x){

        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){

                if(mat.get(k, j) != 0){

                    attron(COLOR_RED);
                    mvaddch(y + k, x + j, 'X');
                    attroff(COLOR_RED);

                }

            }
        }

        pos_y = y;
        pos_x = x;

        refresh();
    };

    void ruota_90_dx(){
        mat.ruota_90_dx_ancorato();
    };

    void ruota_90_sx(){
        mat.ruota_90_sx_ancorato();
    };


};



tetramino quadrato();
tetramino rettangolo();
tetramino T_shape();
tetramino Z_shape();
tetramino S_shape();
tetramino J_shape();
tetramino L_shape();
tetramino choose_tetramino(int temp);
