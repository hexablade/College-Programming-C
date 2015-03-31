#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#define MW 30
#define MH 30
#define W 50
#define H 50
#define PW 10
#define PH 10
#define MOVING_SQUAREX 10
#define MOVING_SQUAREY 10
#define SQUARESIZEX 50 
#define SQUARESIZEY 50
#define ROW 9
#define COL 9
#define PORTALC color(0,0,0)
#define BRDRC color(255,255,255)
#define PIECEB color(0,0,0)
#define PIECEE color(100,100,100)
#define PIECEC color(250,250,0)
#define PIECEF color(0,0,255)
#define PIECEP color(0,255,255)
#define PIECEM color(255,0,0)
#define MPC color(255,0,0)
#define ENDF color(0,0,0)
#define B 0
#define S 1
#define _ 2
#define P 3
#define E 4
#define I 5
#define F 6
#define J 7
#define L 8

int main(int argc, char *argv[]){
    printf("Start test...\n");
   
    int key;
    Color sc;
   init_graphics(150, 150, 450, 450, BRDRC);


    int maze[ROW][COL] = { {B, B, B, B, B, B, B, B, B},
                           {B, S, B, _, P, J, B, L, B},
                           {B, P, B, P, B, B, _, P, B},
                           {B, _, B, _, B, _, P, _, B},
                           {B, P, B, P, B, P, B, P, B},
                           {B, _, B, _, P, _, B, _, B},
                           {B, P, B, P, B, P, B, P, B},
                           {B, _, P, _, P, B, B, E, B},
                           {B, B, B, B, B, B, B, F, B}};
    int px = 1;
    int py = 1;
    int count = 0;

    int quit = 0;
    while(!quit) {
    clear_graphics();
    
    int y;
    int x;
    
        
            for(y=0; y < COL; y++){
            for(x=0; x < ROW; x++){
                if(maze[y][x]== _){
                    sc = PIECEE;
                    drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
                }
                if(maze[y][x]== S){
                        sc = PIECEC;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
                }
                if(maze[y][x]== E){
                        sc = PIECEM;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
                }
                if(maze[y][x]== B){
                        sc = PIECEB;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
                }
                if(maze[y][x]==P){
                        sc = PIECEP;
                drawRect(sc, x*SQUARESIZEX + PW , y*SQUARESIZEY + PH, MW, MH);
                }
                if(maze[y][x]== F){
                        sc = ENDF;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
                if(maze[y][x]== J && maze[y][x]== L){
                        sc = PORTALC;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
                }
            }    
        }    
        

        render_graphics();
        
        key = getKeyB();
        
        if(key == -1 ){
            quit = 1;
        }
        if(key == 44){
             quit = 1;
             }
        
        if(key== 79 && maze[py][px+1] != B){   
              px += 1;
              if(maze[py][px]== P){
                count += 1;
              }
            if(maze[py+1][px] == F||maze[py][px+1] == F || maze[py-1][px] == F || maze[py][px-1] == F){
                quit = 1;
            }

              maze[py][px] = S;
              maze[py][px-1] = _;
           }
        
        
       if(key==80 &&  maze[py][px-1]!= B){
           px -= 1;        
              if(maze[py][px]== P){
                count += 1;
              }
           if(maze[py+1][px] == F||maze[py][px+1] == F || maze[py-1][px] == F || maze[py][px-1] == F){
               quit = 1;
           }

           maze[py][px] = S;     
           maze[py][px+1] = _;   
           }
       
       
       if(key==81 && maze[py+1][px] != B){
           py += 1;
              if(maze[py][px]== P){
                count += 1;
              }
           if(maze[py+1][px] == F||maze[py][px+1] == F || maze[py-1][px] == F || maze[py][px-1] == F){
               quit = 1;
           }

           maze[py][px] = S;
           maze[py-1][px] = _;
           }
        

       if(key==82 && maze[py-1][px] != B ){
           py -= 1;
              if(maze[py][px]== P){
                count += 1;
              }
           if(maze[py+1][px] == F||maze[py][px+1] == F || maze[py-1][px] == F || maze[py][px-1] == F){
               quit = 1;
           }

           maze[py][px] = S;
           maze[py+1][px] = _;
           }
        }
  
    if(maze[py+1][px] == F||maze[py][px+1] == F || maze[py-1][px] == F || maze[py][px-1] == F){
        quit = 1;
    }
    
    
    
    printf("Closing program...\n");
    obliterate_graphics();
    printf("Pellets eaten: %i\n", count); 
    return 0;
        
    
}
