#include <stdio.h>
#include "graphics.h"

int main() {
    printf("Start test...\n");

    //make the grid large enough for our board plus a boarder
    Graphics g = init(0, 0, 250, 250, color(255,255,255));

    int x = 55;
    int y = 55;
    int key; 

    int quit = 0;
    while (!quit) {
        clear(g);

        //nested loops for drawing the NxN grid
        drawRect(g, color(0,255,255), 50, 50, 50, 50);
        drawRect(g, color(255,0,255), 100, 50, 50, 50);
        drawRect(g, color(0,255,255), 150, 50, 50, 50);
        drawRect(g, color(255,0,255), 50, 100, 50, 50);
        drawRect(g, color(0,255,255), 100, 100, 50, 50);
        drawRect(g, color(255,0,255), 150, 100, 50, 50);
        drawRect(g, color(0,255,255), 50, 150, 50, 50);
        drawRect(g, color(255,0,255), 100, 150, 50, 50);
        drawRect(g, color(0,0,0), 150, 150, 50, 50);
        drawRect(g, color(255,0,0), x * 50 + 5, y * 50 + 5, 40, 40);

        key = getKeyB();


        if(key==-1) {
            quit = 1;
        }

        if(key == 79 && x < 150) {
            x++;
        }
        if(key == 80 && x > 45) {
            x--;
        }
        if(key == 81 && y < 150) {
            y++;
        }
        if(key == 82 && y > 45) {
            y--;
        }

        if(x == 150 && y == 150) {
            quit = 1;
        }

    }
    printf("Closing program...\n");
    obliterate(g);

    return 0;
}
