#include <stdio.h>

void swap(int **p1, int **p2) {
    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int a = 10, b = 20;
    int *p1 = &a, *p2 = &b;

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&p1, &p2);
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}