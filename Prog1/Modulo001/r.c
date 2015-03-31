#include <stdio.h>

#define M 10
int main(void){

    int n, p = 0;

    
        printf("Enter a digit of any: ");
        scanf("%d", &n);
    do{
     p *= 10;
     p = p + n%10;
     n = n/10;   
    }
    while( n != 0 );
    printf("The reverse is: %d\n", p); 

}
