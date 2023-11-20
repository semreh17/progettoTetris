
#include "classe_tetramino.h"
#include "classe_griglia.h"
#include <cstdlib>
#include <ctime>

using namespace std;



int main(void){

    srand(time(0));

    initscr();

    cbreak();
    curs_set(0);
    keypad(stdscr, true);

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    griglia campo = griglia(24, 24, 0, 60);
    campo.disegna_griglia();

    bool loop = true;
    int tick = 0;
    int input;
    int pos_x;
    int pos_y;


    int num_sprint = 10;
    int temp_caduta = 125;
    int rand_int;


    while(loop){

        rand_int = rand()%7 + 1;

        tetramino player = choose_tetramino(rand_int);

        attron(COLOR_PAIR(rand_int));
        player.move(0,65);
        attroff(COLOR_PAIR(rand_int));


        while(!player.is_caduto()){

            pos_x = player.get_x();
            pos_y = player.get_y();

            timeout(temp_caduta);
            input = getch();

            player.cancella();

            if(input == -1){tick = num_sprint;}
            else{napms( ((2 * temp_caduta)/num_sprint) ); tick += 1;}

            if(input == KEY_RIGHT){pos_x += 1;}
            if(input == KEY_LEFT){pos_x -= 1;}

            if(input == KEY_UP){player.ruota_90_dx();}
            if(input == KEY_DOWN){player.ruota_90_sx();}

            if(input == KEY_F(1)){loop = false; player.set_caduto(true);}

            if( !player.can_print(pos_y, pos_x) ){

                if(input == KEY_RIGHT){pos_x -= 1;}
                if(input == KEY_LEFT){pos_x += 1;}

                if(input == KEY_UP){player.ruota_90_sx();}
                if(input == KEY_DOWN){player.ruota_90_dx();}

            }


            if( (tick >= num_sprint) && ( !player.is_caduto()) ){

                pos_y += 1;
                tick = 0;

                if( !player.can_print(pos_y, pos_x) ){
                    pos_y -= 1;
                    player.set_caduto(true);
                }
            }


            attron(COLOR_PAIR(rand_int));
            player.move(pos_y, pos_x);
            attroff(COLOR_PAIR(rand_int));

            }

    }

    endwin();

}



