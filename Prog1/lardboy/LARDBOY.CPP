//****************************************
//***Project Codename: Shrapnel***********
//****************************************
//****************************************
//***Actual Application Name: Lard Boy****
//****************************************
//******************************************************************************
//*************************Main Program Source Code*****************************
//******************************************************************************

//!!!!!Important!!!!!
//For the game to work properly, all of the files that came with the project must
//be in the same directory.  In addition, the path to the game must exist on a
//drive, such as the hard drive, that can be written to freely.  Storing the files
//on a floppy disk or CD will slow the game and disrupt saving routines.

//Company: Wonder Workers, Inc.
//Programmer/Engineer: Ryan Lloyd
//Date Started: 3-31-01
//Date of Completion: 6-4-01

//Check out Wonder Workers' Programming Webpage at:
//							  http://www.geocities.com/wonworkers/main.html

//Feel free to e-mail Wonder Workers at:
//							  wonderworkers@excite.com


//****************************Global Includes******************************************
#include <conio.h>
#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <process.h>
#include <alloc.h>
#include <dos.h>
#include <mem.h>
#include <math.h>
#include <stdlib.h>
#include "apstring.h"
#include <graphics.h>
#include <time.h>
#include <iomanip.h>
#include "bullet.h"
#include "tile.h"
#include "enemy.h"
#include "map.h"
#include "lardfcpg.h"

//****************************Global Constants**********************************
const int cbulletdelay = 40;
const int ebulletdelay = 70;
const int enemydelay = 650;


//**************************************************************************
//*******************Main Driver Begins Below*******************************
//**************************************************************************

void main()
  	{
   int shootdelay = 2000; 		//Holds the number of revolutions that a dummy "for" loop will cycle through each time that the character shoots to allow Lard Boy's gun to be seen.
   int index;        //"index" is used in a later "for" loop to jump from slot-to-slot in a single-dimensional (i.e., "offenfire") to locate an open cell for depositing a new bullet. 
   int subpath;      //After the user pauses the program, his/her choice is returned to "subpath" to determine whether or not the game must end.
   int keycode;		//"keycode" stores the ASCII value of all keys that are pressed during gameplay.
   int newpath;      //The integer variable of "newpath" sets the course of the program after the user exits the main menu.
   int speed;			//Stores the user's computer speed (in MHz).
   speed = find_speed();        //Retrieves the gamer's computer speed (in MHz) and store the result in "speed."
   shootdelay = (7.692308 * speed) + 846.5;		//The vital delay between the character firing his gun and Lard Boy placing his gun back in his pocket is determined with this linear equation.
  	init_mode13h();   //Initializes the screen to Wonder Workers' version of mode 13h.
   load_files();     //The game's title page is shown with a star field, and all of the application's tiles are loaded.
   while(inapp == 1)
   	{
		//The main engine for the program will run as long as the global variable of
      //"inapp" remains at 1.  A value of 1 means that the user desires to be in the application.
      ingame = 1;		//This global variable starts off at 1, signifying that the gamer wishes to play Lard Boy.
      if(inapp == 1)  		//If the gamer still wants to play the application, then
      	{                 //the main menu is accessed and gameplay might continue.
   		newpath = title_screen();
         if(newpath == 0)
         	{
				//If the user selected choice #1 on the menu--to start a new game, then the
            //player is given a new set of 4 lives, a score of 0 points, and the ability
            //to start at level #1.
	         lives = 4;
   	      score = 0;
      	   level = 1;
            }
         while((level <= 5) && (inapp == 1) && (ingame == 1))
         	{
            //The section of the program that calls up new levels and controls the actual
            //gameplay will repeat as long as Lard Boy's current level is less than 6
            //and the player desires to be in both the game and the overall application.
	         subpath = 0;
            display_template();     	//Variables that are present in each stage are given
            									//their initial values, the proper map loads in, and
                                       //the frames and statistics that are present during
                                       //gameplay are brought onto the screen.
            while((ingame == 1) && (finishlevel == 0) && (subpath != 1))
            	{
               //Lard Boy, his enemies, the map, and other actions within the game are
               //refreshed in this "while" loop as long as the user has not chosen to
               //terminate gameplay, Lard Boy has not finished the level, and the result
               //of a pause session does not involve exiting the game.

               //refreshing...

//***************************Keyboard Controls**********************************
					if(kbhit())
               	{
                  keycode = getch();      	//"keycode" receives the ASCII code value of the key that was pressed first.
//***************************UP or '8'******************************************
						if(keycode == 56)
                  	{
                     take_photo(map1, photo);   	//A snapshot of the tiles that are currently on the screen is taken.
         	         if(chardir != 2)
            	        	{
                        //If the player is not facing up when the upwards key is struck,
                        //then the map cell that the player is standing on turns to "202,"
                        //the new version of the main map is shown, and Lard Boy's direction
                        //turns upwards with a value of 2.
               	      map1.change_cell(char_row, char_col, 202);
                        display_map(map1.row_start(), map1.col_start(), 1);
                    	   chardir = 2;
                        }
                     else if((map1.cell((char_row-1), char_col) / 100) == 9)
                        //If the player strikes an enemy or deadly obstacle, then the player must face a punishment.
                        hit_enemy();
	                  else if(((map1.cell((char_row - 1), char_col) / 100) != 1) || (map1.cell((char_row - 1), char_col) == 100))
   	                 	{
                        //If the future cell for the character in the map is equal to any other tile
                        //except for an unmovable obstacle, such as a crate, then...
	   	               map1.change_cell(char_row, char_col, 100);   //The character's old slot turns into flooring.
   	   	            --char_row;                                  //Lard Boy moves up by one unit.
                        move_success();     //The player successfully moved in the map, forcing the program to check if the character lies on an item or exit.
                        map1.change_cell(char_row, char_col, 202);      //Player's new cell in the map turns into Lard Boy looking upwards.
                        map1.ch_row_start(map1.row_start() - 1);        //The row at which the map begins printing sinks by 1 unit.
                        display_map(map1.row_start(), map1.col_start(), 1);     //The current map is displayed with the camera on.
                        }
                     --energy;              //Energy falls by one point and...
                     energy_bars();         //the player's new energy status is shown.
	                  }
//***************************DOWN or '2'****************************************
						else if(keycode == 50)
      	           	{
                     take_photo(map1, photo);		//A snapshot of the tiles that are currently on the screen is taken.
                     if(chardir != 4)
                      	{
                        //If the character is not facing downwards when the "down" key
                        //was pressed, then Lard Boy's present cell in the map becomes
                        //"203," the new form of the map is printed out, and the player's
                        //direction turns downwards with a value of 4.
              	         map1.change_cell(char_row, char_col, 203);
                 	      display_map(map1.row_start(), map1.col_start(), 1);
                    	   chardir = 4;
                        }
							else if((map1.cell((char_row+1), char_col) / 100) == 9)
                        //If the player strikes an enemy or deadly obstacle, then the player must face a punishment.
                        hit_enemy();
	                  else if(((map1.cell((char_row + 1), char_col) / 100) != 1) || (map1.cell((char_row + 1), char_col) == 100))
   	                	{
                        //If the future cell for the character in the map is equal to any tile
                        //except for an unmovable obstacle, such as a crate, then...
	   	               map1.change_cell(char_row, char_col, 100);		//The character's old slot turns into flooring.
   	   	          	++char_row;                                     //The player's position in the array-type map increases in its row-value by one unit (i.e., the character moves downwards in the map).
                        move_success();     //The player successfully moved in the map, forcing the program to check if the character lies on an item or exit.
                        map1.change_cell(char_row, char_col, 203);		//The character takes a stance at his lower position that looks downwards.
                     	map1.ch_row_start(map1.row_start() + 1);        //The map will now be displayed starting at a row-value that is one unit larger then the previous shot of the map.
                        display_map(map1.row_start(), map1.col_start(), 1);		//The current map is displayed with the camera on.
                        }
                     --energy;              //Energy falls by one point and...
                     energy_bars();         //the player's new energy status is shown.
   	               }
//***************************RIGHT or '6'***************************************
						else if(keycode == 54)
   	              	{
                     take_photo(map1, photo); 		//A snapshot of the tiles that are currently on the screen is taken.
      	            if(chardir != 1)
         	           	{
                        //If the character is not looking to the right when the "right"
                        //key is pressed, then the player's original cell in the map
                        //becomes "200" (which means that Lard Boy faces right), the new map
                        //is shown with the efficient camera on, and his direction turns to the right.
            	         map1.change_cell(char_row, char_col, 200);
               	      display_map(map1.row_start(), map1.col_start(), 1);
                        chardir = 1;
                        }
                     else if((map1.cell(char_row, (char_col+1)) / 100) == 9)
                        //If the player strikes an enemy or deadly obstacle, then the player must face a punishment.
                        hit_enemy();
	                  else if(((map1.cell(char_row, (char_col + 1)) / 100) != 1) || (map1.cell(char_row, (char_col + 1)) == 100))
   	                 	{
                        //If the future cell for the character in the map is equal to any other tile
                        //except for an unmovable obstacle, such as a crate, then...
	   	               map1.change_cell(char_row, char_col, 100);		//The character's old slot turns into flooring.
   	   	            ++char_col;                                     //The player's column in the array-type world shifts one unit to the right, elevating by a positive factor of 1. 
                        move_success();     //The player successfully moved in the map, forcing the program to check if the character lies on an item or exit.
                        map1.change_cell(char_row, char_col, 200);		//Lard Boy's new slot in the map transforms into value #200, meaning that the character will face to the right.
                        map1.ch_col_start(map1.col_start() + 1);        //The column at which the map begins to print in the "display_map" function shifts rightward (i.e., the column-value steps up by 1 unit).
                        display_map(map1.row_start(), map1.col_start(), 1);		//The current map is displayed with the camera on.
                   	   }
                     --energy;              //Energy falls by one point and...
                     energy_bars();         //the player's new energy status is shown.
   	               }
//***************************LEFT or '4'****************************************
						else if(keycode == 52)
         	       	{
                     take_photo(map1, photo);		//A snapshot of the tiles that are currently on the screen is taken.
                   	if(chardir != 3)
         	           	{
                        //If the key to move leftward is struck, and Lard Boy is not currently
                        //facing to the left, then the player's cell in the map transforms
                        //into value #201 (Lard Boy now looks leftward), the new version of
                        //the main map is shown, and his direction becomes 3, meaning that
                        //Lard Boy is glancing to the left and is now ready to move further
                        //in that direction.
                        map1.change_cell(char_row, char_col, 201);
             	         display_map(map1.row_start(), map1.col_start(), 1);
                 	      chardir = 3;
                        }
                     else if((map1.cell(char_row, (char_col-1)) / 100) == 9)
                        //If the player strikes an enemy or deadly obstacle, then the player must face a punishment.
                        hit_enemy();
	                  else if(((map1.cell(char_row, (char_col - 1)) / 100) != 1) || (map1.cell(char_row, (char_col - 1)) == 100))
   	                 	{
                        //If the future cell for the character in the map is equal to any other tile
                        //except for an unmovable obstacle, such as a crate, then...                        
	   	               map1.change_cell(char_row, char_col, 100);		//The character's old slot turns into flooring.
   	   	            --char_col;                                     //Lard Boy's column-value shrinks by 1 unit (his column-position in the map falls to the left).
                        move_success();     //The player successfully moved in the map, forcing the program to check if the character lies on an item or exit.
                        map1.change_cell(char_row, char_col, 201);		//The player's new cell in the main map turns into Lard Boy facing to the left.
                        map1.ch_col_start(map1.col_start() - 1);      	//The column-value at which the map starts to be outputted moves to the left by one column.
                        display_map(map1.row_start(), map1.col_start(), 1);		//The current map is displayed with the camera on.
                   	   }
                     --energy;              //Energy falls by one point and...
                     energy_bars();         //the player's new energy status is shown.
   	               }
//***************************SHOOT or SPACEBAR**********************************
						else if((keycode == 32) && (ammo > 0))
                    	{
                     int shootcount; 		//The dummy counter that plays a part in slowing down the computer to allow Lard Boy's fired gun to be shown is declared.
                     for(index=0; offenfire[index].on_off() == 1; ++index);
                     	//The above "for" loop finds an index in the "offenfire" 1-D array
                        //that is empty and can store the new bullet.
                     ++bullets_in_air; 	//The number of character bullets in the air rises by 1 round.
                     --ammo;          		//The player's ammo remaining falls by 1 bullet.
                     display_ammo();      //Lard Boy's new level of ammo is shown.
                     switch(chardir)
                     	{
                        case 1:  //If the character is looking to the right, then...
                        			shootr.display_stamp(110, 70);  	//The stamp of Lard Boy shooting rightward is pasted on the monitor.
                                 for(shootcount=0; (shootcount < shootdelay); ++shootcount)
                                    //This simple "for" loop executes as long as "shootcount"
                                    //is less than the constant of "shootdelay" and the user
                                    //has not pressed a key.
                                 	if(kbhit())
                                 		shootcount = shootdelay;
			                        cright.display_stamp(110, 70);     //The original state of Lard Boy looking right is displayed.
         			               offenfire[index].change_dir(1);    //The direction of the speeding bullet takes a value of 1, meaning that it is moving right.
                  			      break;
                        case 2:	//If the player is glancing to the screen's top, then...
                        			shootu.display_stamp(110, 70);	//The tile featuring Lard Boy shooting his gun upwards is briefly shown.
                                 for(shootcount=0; (shootcount < shootdelay); ++shootcount)
                                    //This simple "for" loop executes as long as "shootcount"
                                    //is less than the constant of "shootdelay" and the user
                                    //has not pressed a key.
                                 	if(kbhit())
                                 		shootcount = shootdelay;
         			               cup.display_stamp(110, 70);		//The initial form of the character glancing to the north is displayed on his current position.
	                  		      offenfire[index].change_dir(2);		//The direction of the speeding bullet takes a value of 2, meaning that it is moving up.
                        			break;
                        case 3:	//If Lard Boy is looking leftward, then...
                        			shootl.display_stamp(110, 70);			//The picture of the player shooting leftward is outputted to the monitor.
                                 for(shootcount=0; (shootcount < shootdelay); ++shootcount)
                                    //This simple "for" loop executes as long as "shootcount"
                                    //is less than the constant of "shootdelay" and the user
                                    //has not pressed a key.
                                 	if(kbhit())
                                 		shootcount = shootdelay;
            			            cleft.display_stamp(110, 70);       //The normal appearance of Lard Boy looking to the left is shown.
                     			   offenfire[index].change_dir(3);		//The direction of the speeding bullet takes a value of 3, meaning that it is moving left.
			                        break;
                        case 4:	//If the character is pointing downwards, then...
                        			shootd.display_stamp(110, 70);      //Lard Boy is displayed shooting his handgun southward.
                                 for(shootcount=0; (shootcount < shootdelay); ++shootcount)
                                    //This simple "for" loop executes as long as "shootcount"
                                    //is less than the constant of "shootdelay" and the user
                                    //has not pressed a key.
                                 	if(kbhit())
                                 		shootcount = shootdelay;                                    
         			               cdown.display_stamp(110, 70);       //The original stamp of the player glancing down is outputted over Lard Boy's shooting stance.
			                        offenfire[index].change_dir(4);		//The direction of the speeding bullet takes a value of 4, meaning that it is moving down.
                        }
                     offenfire[index].change_row(char_row); 	//The row of the new bullet becomes the character's row.
                     offenfire[index].change_col(char_col);    //The bullet's column is given the value of the character's column.
                     offenfire[index].change_on(1);            //The bullet is turned on.
                     update_char_bullets();              //All of the character's bullets are updated.
                     }
//***************************ESCAPE OR 'P' OR 'p'*******************************
                  if((keycode == 27) || (keycode == 80) || (keycode == 112))     //Pause OR Main Menu
                     //The future course for the gameplay is determined after the call to the
                     //function that pauses the application and waits for the user to either
                     //save the game, quit to the main menu, or return to the action.
                     subpath = pause();
                  }
					if(subpath != 1)
                 	{
                  //If the user is still in gameplay and has not chosen to quit the game, then...
                  delay(1);
                  ++eupdate;		//The counter variable that determines when the enemies can be updated is incremented by one.
                  if(eupdate > enemydelay)
                  	{
                     //When "eupdate" exceeds "enemydelay," the positions of the enemies
                     //are updated and the counter is set back to zero.
                     update_enemies();
	                 	eupdate = 0;
                     }
                  if(ebullets_in_air > 0)
      	           	{
                     //When there is at least one enemy bullet floating in the air, then...
         	         delay(1);
            	      ++ebupdate;   //This counter variable is stepped up by 1.
               	   if(ebupdate > ebulletdelay)
                  	  	{
                        //When "ebupdate" is greater than "ebulletdelay," the enemies are
                        //updated and the counter variable is reset to zero.
	                  	update_ebullets();
   	                  ebupdate = 0;
                        }
                     }
                  if(bullets_in_air > 0)
                  	{
                     //If one of Lard Boy's bullets exists on the map, then...
            	      delay(1);
               	   ++bupdate;		//The counter variable than can lead to a refreshing of the character's barrage of bullets is increased by 1.
                  	if(bupdate > cbulletdelay)
                     	{
                        //The player's bullets are updated and the counter is set to zero
                        //once "bupdate" grows larger than the constant integer variable
                        //of "cbulletdelay."
		                	update_char_bullets();
   		               bupdate = 0;
      	               }
                     }
                  }
            	}
            if(finishlevel == 1)
            	{
               //When the character hits the exit symbol, the function that summarizes
               //the completed level is called and the player advances to the next level.
               level_done();
					++level;
               }
            }
			if(level == 6)
         	//The action-filled ending to the game is shown to the user when the player
            //is out of the main engine for the game and he/she has reached the sixth
            //level (or the sixth floor to the barn's basement).
				finish_game();
         }
     	}
   //The final credits and copyright statement is displayed.
	initgraph(&graphdriver, &graphmode, path.c_str());
	cleardevice();
   setcolor(11);
	settextstyle(3,0,4);
	outtextxy(50, 90, "A Wonder Workers, Inc. Production");
   setcolor(2);
	settextstyle(10,0,6);
	outtextxy(0, 300, "Copyright 2001");   
  	getch();
   closegraph();                 //The BGI graphics library is shut down.
  	Video_Mode(TEXT_MODE);      	//Monitor mode returns to the simple DOS text-based version.
	}
