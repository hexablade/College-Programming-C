#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "graphics.h"
#define IMAGE_WIDTH 100
#define IMAGE_HEIGHT 100


Color pixels[IMAGE_HEIGHT][IMAGE_WIDTH];

typedef struct Rect {
        int width;
            int height;
                int x;
                    int y;
} Rect;

//Interaction




//Math
//Distance, area

//int distance(int x1, int y1, int x2, int y2){
  
  //}

  bool insideRect(Rect r, int x, int y){
      return ( x>r.x && y>r.y && x<r.x+r.width && y<r.y+r.height );
      }


      //Drawing helpers
      //Lines, rectangles, ovals, triangles
      //gradients?

      void drawLine(Color c, int x1, int y1, int x2, int y2){
          float x=x1;
              float y=y1;

              }


              int main(int argc, char *args[]){
                 init_graphics(150,150,500,500,color(50,50,50));

                    drawPx(color(255, 0, 0), 50, 50);
                       render_graphics();
                          getKeyB();
                             obliterate_graphics();
                             }



