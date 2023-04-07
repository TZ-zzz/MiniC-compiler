int loop(){
    int i, j, k;
    bool a, b,c ,d;
    i = 0;
    j = 0;
    c = true;
    d = false;
    while (i < 40000000) {
        k = j + i;
        j = i * 1;
        j = i / 1;
        j = i * 0;
        if (i < 100000){
            b = true;
        }
        else {
            b = false;
        }
        a = b || c;
        a = b && true;
        a = b || false;
        i = i + 1;
    }
    return i;
}

int main(){
    int i;
    i = loop();
    return i;
}