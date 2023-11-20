
#include "classe_tetramino.h"

tetramino quadrato(){tetramino temp = tetramino(0,0, false, mat_quadrato()); return temp;}
tetramino rettangolo(){tetramino temp = tetramino(0,0, false, mat_rettangolo()); return temp;}
tetramino T_shape(){tetramino temp = tetramino(0,0, false, mat_T_shape()); return temp;}
tetramino Z_shape(){tetramino temp = tetramino(0,0, false, mat_S_shape()); return temp;}
tetramino S_shape(){tetramino temp = tetramino(0,0, false, mat_Z_shape()); return temp;}
tetramino J_shape(){tetramino temp = tetramino(0,0, false, mat_J_shape()); return temp;}
tetramino L_shape(){tetramino temp = tetramino(0,0, false, mat_L_shape()); return temp;}

tetramino choose_tetramino(int temp){

    if(temp == 1){return  quadrato();}
    else if(temp == 2){return rettangolo();}
    else if(temp == 3){return T_shape();}
    else if(temp == 4){return Z_shape();}
    else if(temp == 5){return S_shape();}
    else if(temp == 6){return L_shape();}
    else {return J_shape();}

}