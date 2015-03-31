#include <stdio.h>

int main(void){

int m;
int n;
int GCD;

    printf("Insert two numbers: ");
    scanf("%d%d", &m, &n);
 
    while ( n != 0) {
      GCD = m % n;
      m = n;
      n = GCD;

    }
    printf("Greatest common divisor: %d\n", m);
}
