#include "minicio.h"

int num_neg(int n, int * c){
    int count = 0;
    for (int i = 0; i < n; i = i + 1){
        if (c[i] < 0){
            count = count + 1;
        }
    }
    return count;
}

int main(){
    int n = 10;
    int c[10] = {-2, 3, -1, -7, 0, -5, 4, -8, -10, -99};
    int count = num_neg(n, c);
    putint(count);
    putnewline();
    return 0;
}