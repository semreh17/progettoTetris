

#include "classe_matrice.h"


matrice mat_quadrato(){

    matrice temp = matrice();

    temp.set(0,0,1);
    temp.set(0,1,1);
    temp.set(1,0,1);
    temp.set(1,1,1);

    return temp;
}

matrice mat_rettangolo(){

    matrice temp = matrice();

    temp.set(0,0,1);
    temp.set(0,1,1);
    temp.set(0,2,1);
    temp.set(0,3,1);

    return temp;
}

matrice mat_S_shape(){

    matrice temp = matrice();

    temp.set(0,1,1);
    temp.set(0,2,1);
    temp.set(1,0,1);
    temp.set(1,1,1);

    return temp;
}

matrice mat_Z_shape(){

    matrice temp = matrice();

    temp.set(0,0,1);
    temp.set(0,1,1);
    temp.set(1,1,1);
    temp.set(1,2,1);

    return temp;
}

matrice mat_T_shape(){

    matrice temp = matrice();

    temp.set(0,0,1);
    temp.set(0,1,1);
    temp.set(0,2,1);
    temp.set(1,1,1);

    return temp;
}

matrice mat_L_shape(){

    matrice temp = matrice();

    temp.set(0,0,1);
    temp.set(0,1,1);
    temp.set(0,2,1);
    temp.set(1,0,1);

    return temp;
}

matrice mat_J_shape(){

    matrice temp = matrice();

    temp.set(0,0,1);
    temp.set(1,0,1);
    temp.set(1,1,1);
    temp.set(1,2,1);

    return temp;
}