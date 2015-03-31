#ifndef FOTUS_GRAPHICS
#define FOTUS_GRAPHICS

#include <SDL2/SDL.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;

typedef struct {
    SDL_Window *win;
    SDL_Renderer *renderer;
    Color background;
} Graphics;

typedef struct {
    int start;
    int lastTick;
    int frames;
    int fps;
    int tpf;
} Framerate;

Graphics init(int x, int y, int width, int height, Color c);

void obliterate(Graphics g);

void drawRect(Graphics g, Color c, int x, int y, int width, int height); 

void clear(Graphics g);

Color color(int r, int g, int b);

int getKeyB();
int getKey();

Framerate initFramerate(int fps);
Framerate capFrame(Framerate f);
float avgFPS(Framerate f);

#endif
