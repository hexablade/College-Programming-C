#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MOVES 4




void generate_random_walk(char walk[][COLS])
{


enum {UP,DOWN, LEFT, RIGHT};
const char available = '.';
int move, letter, row, col;
bool possible[4];

srand(time(NULL));

for (row = 0; row < ROWS; row++) {
for (col = 0; col < COLS; col++)
    walk[row][col] = available;
}

row = col = ROWS / 2;
for (letter = 0; letter < 26; letter++)  {
walk[row][col] = 'A' + letter;


for (move = 0; move < MOVES; move++)
possible[move] = false;

if (row > 0 && walk[row-1][col] == available)
possible[UP] = true;

if (row < ROWS-1 && walk[row+1][col] == available)
possible[DOWN] = true;

if (col > 0 && walk[row][col-1] == available)
possible[LEFT] = true;

if (col < COLS-1 && walk[row][col+1] == available)
possible[RIGHT] = true;

for (move = 0; possible[move] == false && move < MOVES; move++);

if (move == MOVES)
break;

move = -1;
while (move < 0) {
move = rand() % MOVES;
if (possible[move])
break;
move = -1;
}

switch(move) {
case UP:
row--;
break;
case DOWN:
row++;
break;
case LEFT:
col--;
break;
case RIGHT:
col++;
break;
}
}
}


void print_array(char walk[][COLS])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", walk[i][j]);
        }
            printf("\n");
    }
  
}

int main()
{
    char randomwalks[ROWS][COLS];
        
    generate_random_walk(randomwalks);

    print_array(randomwalks);

    return 0;
}


