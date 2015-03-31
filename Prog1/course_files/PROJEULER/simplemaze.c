/************************* very simple maze game.
*  *
*   * Author: Zach Tomaszewski
*    */

#include <stdio.h>
#include <ctype.h>
#include "graphics.h"

//size of room
#define WIDTH 8
#define HEIGHT 8

//chars used when printing the room
#define FLOOR '.'
#define PLAYER '@'
#define EXIT '#'

//game controls (set to lowercase values only)
#define UP 'n'
#define DOWN 's'
#define LEFT 'w'
#define RIGHT 'e'

void printRoom(int playerX, int playerY, int exitX, int exitY);
char getUserMove(void);


/*
* Repeatedly prints a room map showing the player's current location
* and an exit.  Each turn, asks the user to move.  When the player
* reaches the exit, the game ends.
*/
int main() {

//player starts in center of room.
//(x increases left-to-right; y increases top-to-bottom)
int playerX = WIDTH / 2;
int playerY = HEIGHT / 2;

//exit is in lower right corner
int exitX = WIDTH - 1;
int exitY = HEIGHT - 1;

//Explain game to user
printf("Try to escape the maze!  Move yourself (%c) to the exit (%c).\n", 
PLAYER, EXIT);

//play the game
while (!(playerX == exitX && playerY == exitY)) {
int move;

//show room and get user's move
printRoom(playerX, playerY, exitX, exitY);
move = getUserMove();

//update player position based on move choice
switch (move) {
case UP:    playerY--; break;
case DOWN:  playerY++; break; 
case LEFT:  playerX--; break;
case RIGHT: playerX++; break;
}

//if now outside of maze, roll back move and report error
if (playerX < 0 || playerY < 0 || playerX >= WIDTH || playerY >= HEIGHT) {      
puts("Invalid move: You can only leave the room through the exit.");
switch (move) {
case UP:    playerY++; break;
case DOWN:  playerY--; break; 
case LEFT:  playerX++; break;
case RIGHT: playerX--; break;
}      
}
}

//loop only exits when player makes it to exit, so: congrats
printf("\nCongratulations!  You made it out alive.\n");

return 0;
}


/*
* Gets a valid move from the user.
* 
* Prompts the user to enter one of the valid move constant values: 
* UP, DOWN, LEFT, RIGHT.  Will continue to ask until the user
* enters a valid move.  Accepts either upper or lowercase versions.
* 
* Returns the move the user entered.
*/
char getUserMove() {
char move = '\0';
for (;;) { 
//ask user until they get it right
printf("Enter a move (%c/%c/%c/%c): ", UP, DOWN, LEFT, RIGHT);
move = getchar();
while (getchar() != '\n');  //clear remaining input from stream
move = tolower(move);
if (move == UP || move == DOWN || move == LEFT || move == RIGHT) {
return move;
}else { 
puts("Sorry, that is not a valid move option. Please try again.");
}
}
}

/*
* Prints the room containing a player and an exit at the given locations.
* 
* The characters used to print the room are set by the PLAYER, FLOOR, and
* EXIT constants.
*
* playerX and exitX must be >= 0 and < WIDTH.  playerY and exitY must be
* >= 0 and < HEIGHT.  If any of these coordinates place the player or
* exit outside of the room, that character (player or exit) will not be
* printed.  If the player and exit are at the same location, it will 
* be printed as a player character.
*/

void printRoom(int playerX, int playerY, int exitX, int exitY) {
int row, col;
for (row = 0; row < HEIGHT; row++) {
for (col = 0; col < WIDTH; col++) {
if (row == playerY && col == playerX) {
printf ("%c", PLAYER);
}else if (row == exitY && col == exitX) {
printf ("%c", EXIT);
}else {
printf("%c", FLOOR);
}
}
printf("\n");  //end row
}
}
/*
 //Crystopher Echavarria *
*************************


#include <stdio.h>
#include <stdlib.h>


#define P
#define W
#define F

int main(int argc, char *args[]){

int i;
int j;
int m[8][8] ={0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1,
0,1,0,1,0,1,0,1};
i = m[7][7];
printf("%i \n", i);

}
*/

