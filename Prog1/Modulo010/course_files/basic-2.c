#include <stdio.h>
#include "graphics.h"
#define PIECEA color(0,99,158)
#define PIECEB color(99,158,0)
#define PIECEC color(0,255,0)
#define PIECED color(110,120,50)
#define BORDER color(255,255,255)
#define W 50
#define H 50
#define MAXW 40
#define MAXH 40
#define BSIZE 50 
#define YSQUARE 10
#define XSQUARE 10
#define WINH (XSQUARE*H+(2*BSIZE))
#define WINW (YSQUARE*W+(2*BSIZE))
#define ENDX 50*XSQUARE
#define ENDY 50*YSQUARE
#define STARTX 55
#define STARTY 55
#define CLOSEX STARTX-W + W*XSQUARE
#define CLOSEY STARTY-H + H*YSQUARE


int main(int argc, char *argv[]) {
    printf("Start test...\n");

    //make the grid large enough for our board plus a boarder
    Graphics g = init(0, 0, WINW, WINH, BORDER);

    int x = BSIZE + ((W-MAXW)/2);
    int y = BSIZE + ((H-MAXH)/2);
    int key; 
    Color sc;

    int quit = 0;
    while (!quit) {
        clear(g);

       for (int i=1; i <= XSQUARE; i++){
       for (int j=1; j <= YSQUARE; j++){
            if((i+j)%2==1)
                sc = PIECEA;
      else
            sc = PIECEB;

        drawRect(g,sc, i*50, j*50,W, H);
            }
            }   
        drawRect(g, PIECEC, ENDX, ENDY, W, H);
        drawRect(g, PIECED, x, y, MAXW, MAXH);
        
            
        
        
        
        
        
        

        key = getKeyB();


        if(key==-1) {
            quit = 1;
        }

        if(key == 79 && x < 150) {
            x+=50;
        }
        if(key == 80 && x > 55) {
            x-=50;
        }
        if(key == 81 && y < 150) {
            y+=50;
        }
        if(key == 82 && y > 55) {
            y-=50;
        }

        if(x == 155 && y == 155) {
            quit = 1;
        }

}    
    printf("Closing program...\n");
    obliterate(g);

    return 0;
}
