#include <stdio.h>
#include "graphics.h"

int main(int argc, char *argv[]){
    printf("Start test...\n");
   
    int key;
    Graphics g = init(150, 150, 300, 300, color(255,255,255));

    int quit = 0;
    while (!quit) {
        clear(g);

        drawRect(g, color(255, 0, 255), 50, 50, 200, 200);
                            
        key = getKeyB();
        printf("Key Pressed: %i\n", key);

        if(key == -1 ){
            quit = 1;
        }

    }

    printf("Closing program...\n");
    obliterate(g);

    return 0;
}
