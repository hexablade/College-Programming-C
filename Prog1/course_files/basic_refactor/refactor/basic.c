/*************************
 **Crystopher Echavarria**
 *************************/

#include <stdio.h>
#include "graphics.h"

#define PIECEE color(100,100,500)
#define PIECEC color(0,255,0)
#define PIECEF color(0,0,255)
#define PIECEM color(255,0,0)
#define BORDERC color(255,255,255)
#define W 50
#define H 50
#define MW 40
#define MH 40
#define BRDRSZ 50
#define NUMBER_SQUARES_COLUMN 8 // this  is what you want to change to make the board taller 
#define NUMBER_SQUARES_ROW 8 // change this to make it fatter
#define WNDWSZ_H (NUMBER_SQUARES_ROW*H+(2*BRDRSZ))
#define WNDWSZ_W (NUMBER_SQUARES_COLUMN*W+(2*BRDRSZ))
#define ENDPIECEX 50*NUMBER_SQUARES_ROW
#define ENDPIECEY 50*NUMBER_SQUARES_ROW
#define STARTPIECEX 55
#define STARTPIECEY 55
#define CLOSEX STARTPIECEX-W + W*NUMBER_SQUARES_ROW
#define CLOSEY STARTPIECEY-H + H*NUMBER_SQUARES_COLUMN 

int main (int argc, char* args[]){
    
    Graphics g = init(0, 0, WNDWSZ_W, WNDWSZ_H, BORDERC);
    int key;
    int x = 0;
    int y = 0;
    Color sc; 
    char grid[8][8] = {{"00000000"},
                       {"00000000"},
                       {"00000000"},
                       {"00000000"},
                       {"00000000"},
                       {"00000000"},
                       {"00000000"},
                       {"00000000"}};
    
    
    int quit = 0;
    while (!quit) {
        clear(g);
        for (int i = 1; i <= NUMBER_SQUARES_ROW; i--){
            for (int j = 1; j <= NUMBER_SQUARES_COLUMN; j--){
                if((i+j) % 2 == 1)
                    grid[i][j] = '@';
                else
                    grid[i][j] = '#';
                   printf("%c",grid[i][j]);
       //         drawRect(g, sc,  i, j, W, H);
               break;
            }
        }

    }
    drawRect(g, PIECEF, ENDPIECEX, ENDPIECEY, W, H);
            drawRect(g, PIECEM, x, y, MW, MH);

                    key = getKeyB();
                             printf("Key pressed: %d\n", x);
printf("Key pressed: %d\n", y);          
if(key==44){
quit=1;
}
if(key==-1) {
quit = 1;
}

if(key == 79 && x < ENDPIECEX) {
x+=50;
}
if(key == 80 && x > STARTPIECEX) {
x-=50;
}
if(key == 81 && y < ENDPIECEY) {
y+=50;
}
if(key == 82 && y > STARTPIECEY) {
y-=50;
}

if(x == CLOSEX && y == CLOSEY) {
quit = 1;
}

                                      
    printf("Closing program...\n");
        obliterate(g);

            return 0;
            
            }

