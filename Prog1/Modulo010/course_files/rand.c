#include <stdio.h>
#include <time.h>
#include <stdlib.h> //this is where rand lives

int main(int argc, char *args[]){

    srand (time(NULL));

    int elms[10];
    int length = sizeof(elms) / sizeof(elms[0]);
    int i,j,temp;

    
    for(i = 0; i<length; i++){
        elms[i] = rand() % 20;
    }

    for(i=0; i<length; i++){
        printf("%i ", elms[i]);

    }
    printf("\n");
}
     for( i = 0; i < length - 1, i++){
     for( j = i; j < length, j++)
         if(elms[i]<elms[j];
    while j > 0 and A[j-1] > x
            A[j] = A[j-1]
             j = j - 1
              A[j] = x 
}
