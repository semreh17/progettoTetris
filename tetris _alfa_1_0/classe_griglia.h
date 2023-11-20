
#include <ncurses.h>

class griglia{

protected:

    int larg;
    int alt;
    int pos_x;
    int pos_y;

public:

    griglia(int L, int A, int y, int x){larg = L; alt = A; pos_x = x; pos_y = y;};

    void disegna_griglia(){

        for(int k = 0; k < alt; k++){
            for(int j = 0; j < larg; j++){

                if((j == 0) || (j == larg - 1) || (k == alt - 1)){

                    mvaddch(pos_y + k, pos_x + j, '#');

                }

            }


        }

        refresh();

    };



};
