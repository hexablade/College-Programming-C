#include <stdio.h>
#include <stdlib.h>


int main (int argc, char*args[]){

    int i;
    int j;
    int a[10] = {1, 1};
    int fib_numbers;

    printf("%i %i ", a[0], a[1]);
    
    for(i = 2; i < 10; i++){
        a[i] = a[i-1] + a[i - 2];
        printf("%i ", a[i]);
    }    
    printf(" \n");
}

