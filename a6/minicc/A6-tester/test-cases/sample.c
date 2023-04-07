#include "minicio.h"
int loop2(){
    int a, b, i, c;
    a = 1;
    b = 2;
    c = 0;
    for (i = 0; i < 200000000; i = i + 1) {
        c = a + b;
        c = a - b;
        c = a * b;
        c = a / b;
    }
    return c;
}

int main(){
    int a, b, c;
    c = loop2();
    putint(c);
    return c;
}
