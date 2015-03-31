#include <stdio.h>
#include <time.h>
#include <stdlib.h> //this is where rand lives

int main(int argc, char *args[]){

    srand (time(NULL));

    int elms[10];
    int length = sizeof(elms) / sizeof(elms[0]);
    int i,j,tmp;

    
    for(i = 0; i<length; i++){
        elms[i] = rand() % 20;
    }

    for(i=0; i<length; i++){
        printf("%i ", elms[i]);

    }
    printf("\n");
    
/*    for(i = 0; i < length; i++){
        for( j = 0; j < length; j++){
            if(elms[i] < elms[j]){
                tmp = elms[i];
                elms[i] = elms[j];
                elms[j] = tmp;
            }
        }
    }
    for ( i = 0; i < length; i++){
        printf("%i ", elms[i]);
    }
  */ 

    int swapped = 1;

    while(swapped == 1){
        swapped = 0;
        for(i = 0; i < length - 1; i++){
            if(elms[i] > elms[i+1]){
                tmp = elms[i];
                elms[i]=elms[i+1];
                elms[i+1] = tmp;
                swapped =1;
            }
        }
       
    }

    for( i=0; i<length; i++){
        printf("%i ", elms[i]);
    }

    printf("\n");{
    }
}
