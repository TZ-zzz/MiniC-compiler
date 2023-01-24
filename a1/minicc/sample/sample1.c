#include <stdbool.h>
#include "minicio.h"


int max(int * n_list){
    int m = n_list[0];
    for (int i = 0; i < 10; i = i + 1){
        if (n_list[i] > m){
            m = n_list[i];
        }   
    }
    return m;
}

int main(){
    int n_list[10] = {-2, 3, 1, 7, 0, 5, 4, 8, 12, -4};
    int m = max(n_list);
    putint(m);
    putnewline();
    return 0;
}