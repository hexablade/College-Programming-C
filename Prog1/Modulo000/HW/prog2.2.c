#include <stdio.h>
#define PI 3.14159265

int  main(){
    int v,r; 
     float pi;
   pi = PI;
   

   
   printf("Radius of the sphere: ");
   scanf("%d", &r);
   v = 4.0f / 3.0f * pi * r * r * r; 
  printf("Volume in cubic meters is: %d\n", v);
   
   return 0;


} 
