
#include "funz_array.h"
using namespace std;


void scambia(int& x, int& y){

    int temp;

    temp = x;
    x = y;
    y = temp;
}


void inverti(int a[], const int length){

    for (int i = 0; i < length/2; i++){
        scambia(a[i], a[length - 1 - i]);
    }

}
