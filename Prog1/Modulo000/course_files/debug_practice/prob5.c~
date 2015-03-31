// Crystopher Ecahvarria
// Module 000 exercise 1 
// Broker.c remake 


#include <stdio.h>

int main(void){
   float comission, value, share, rcomission, price;

   printf("Enter number of shares: ");
   scanf("%f", &share);
   printf("Enter price of shares: ");
   scanf("%f", &price);


   value = share*price; 

   if(value < 2500.00f){
      rcomission = 33.00f + .03f * value;
       comission = 30.00f + .017f * value;
   }
   if(value < 6250.00f){
       comission = 56.00f + .0066f * value;
    rcomission = 33.00f + .03f * value;
   }
   if(value < 20000.00f){
        rcomission = 33.00f + .03f * value;
       comission = 76.00f + .0034f * value;
   }
   if(value < 50000.00f){
        rcomission = 33.00f + .03f * value;
       comission = 100.00f + .00022f * value;
   }
   if(value < 500000.00f){
       comission = 155.00f + .0011f * value;
    rcomission = 33.00f + .03f * value;
   }
   else{
       rcomission = 33.00f + .02 * value;   
       comission = 255.00f + .0009f * value;
   }
   if (comission < 39.00f){
       comission = 39.00f;
   }

   printf("Rival's Comission: $%.2f\n", rcomission);
   printf("Comission: $%.2f\n", comission);
   return 0;
}
              
