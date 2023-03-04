// Semantic fail 5

int i;
int a[10];
bool x[10];
bool j;

void dummy(int j) {
    return;
}

void main() {

    x[0] = true;
    for (i = 1; i < 10; i = i + 1) {
        x[i] = x[0];
    }

    i = 1;
    while (i) {
        i = i + 1;
    }


    dumy();
    

    dummy(j);

    return;
}

void main() {
    0;
}