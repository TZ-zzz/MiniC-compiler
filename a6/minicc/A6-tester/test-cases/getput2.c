#include "minicio.h"
int input1;
bool compare(int i, int t);
bool compare(int x, int y){
    if(x < y){
        return true;
    }else{
        return false;
    }
    return true;
}
int main(){
    int input2;
    bool result;
    input1 = getint();
    input2 = getint();
    result = compare(input1,input2);
    if(result){
        putint(input1);
    }else{
        putint(input2);
    }
    return 0;
}