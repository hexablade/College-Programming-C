// created by Crystopher Echavarria
// Info 230 in Goshen College
// Chavi productions 

#include <stdio.h>
#include "graphics.h"

#define W 50 // width
#define H 50 // Height
#define CenterColor color(43,0,178) 
#define MidPieceColor color(229,2,155)
#define CornerPieceColor color(225,23,34)
#define MovingPieceColor color(68,126,197)
 

int main(){
    printf("Start test...\n");
   
    int key;
    Graphics g = init(150, 150, 250, 250, color(255,255,255));

    int quit = 0;
    int x,y,x1,y1,x2,y2;

    x = 50; y = 50; x1 = 100; y1 = 100; x2 = 150; y2 = 150; 
    while (!quit) {
        clear(g);

         drawRect(g,CenterColor, 100, 100, W, H); // The x and y coordinates for the center are obtained is half the squares side.//
         drawRect(g,MidPieceColor, 150, 100, W, H);
         drawRect(g,MidPieceColor, 50, 100, W, H);
         drawRect(g,MidPieceColor, 100, 150, W,H);
         drawRect(g,MidPieceColor, 100, 50, W, H);
         drawRect(g,CornerPieceColor, 150, 150, W, H);
         drawRect(g,CornerPieceColor, 50, 50, W, H);
         drawRect(g,CornerPieceColor, 150, 50, W, H);
         drawRect(g,CornerPieceColor, 50, 150, W, H);

         drawRect(g,(MovingPieceColor), x, y, W, H); 
         {
         clear(g);
         }   
         key = getKeyB();{
        printf("Key Pressed: %i\n", key);    
        }

        if(key == 44 ){
            quit = 1;
        }
        {
        clear(g);
        } 
        if(key == -1 ){
            quit = 1;
        }
        
        if(key == 79 ){ // right arrow key
           if(x < 150){
            x = x+50;
           }
        } 
      
        if(key == 80 ){ // left arrow key
           if(x > 50){
               x = x-50; 
         }
        } 
        if(key == 81 ){ // down arrow key
           if(y < 150){
            y = y+50;
        }
        }
        if(key == 82 ){ // up arrow key
        if( y > 50){    
        y = y - 50;
        }
        }
        if(x == 150 && y == 150){
                    quit = 1;
                    }
        {    
        clear(g);
        }
    }

    printf("Closing program...\n");
    obliterate(g);

    return 0;
}
