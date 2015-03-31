#include <stdio.h>

int main(void){

    int a = 3;
    int b = 5;
    int r[100];
    int i;
    int c;
    int j;

    for( i = 1; i < 100; i++){
        for( j = 1; j < 100; j++){
            if( r[i]/3 % 1 && r[j]/5 % 1){
           c = r[i] + r[j];  
             }
        }
    }
    printf("Sum is: %i \n", c);
}    

