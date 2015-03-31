// Class declaration file: tile.h

#include "apstring.h"

#ifndef TILE_H

class tile
	{
	public:
		//Constructors
		tile();
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions:	Every element of the "mytile" primary attribute is set to 0.


   	//Copy constructor
		tile(const tile &t);
      //preconditions:	The state of the current object that is being created is in an
      //						unpredictable form.  The tile object of "t" has been appropriately
      //						declared and initialized.  The new object and "t" have the same
      //						number of rows and the identical amount of columns.
      //postconditions:	Every element in every row and column of "t" is copied into its
      //						proper place in the current tile-based object.  For instance, if
      //						the value of 200 exists at row 5, column 8 of "t," then 200 shall
      //						be placed into the slot that has a row-value of 5 and a column-
      //						value of 8 in the current tile.


      //Utilities
      void load_stamp(apstring filename);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.  The computer can pull information from a file that
      //						exists on the user's machine via an input file stream.  The tile
      //						that the program is attempting to load may or may not lie in the
      //						specified path and may or may not be corrupted.  The monitor and
      //						video card are prepped for screen mode 13h.
      //postconditions:	An input file stream is possibly connected to the file that the
      //						user/programmer is trying to load.  If the file fails to be loaded,
      //						then an error message is displayed to the gamer, along with the
      //						path and name of the file that is corrupted or missing.  In
      //						addition, when a tile fails to load, every element in the "mytile"
      //						class attribute is set to 0.  Otherwise, if the computer can find
      //						and successfully load the tile, then the elements which exist in
      //						in the file in an array-type setup are deposited into "mytile" in
      //						their corresponding order.

		void display_stamp(int topx, int topy);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.  The monitor and video card are prepped to receive
      //						graphics in mode 13h.
      //postconditions:	The tile is printed out on the monitor, beginning at its
      //						upper-left corner with the coordinates of (topx, topy).

	private:
		//Data members
		int mytile[20][20];
	};

//FREE FUNCTIONS
	void Plot_Pix(int x, int y, unsigned char color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x" should be between 0 and 319, inclusively, while "y" must be between
   //						0 and 199, inclusively.  The program will not halt and errors will not
   //						arise if the pixel's coordinates are not within their specifications.
   //postconditions:	The pixel of color "color" from the 256 various shades of the mode 13h
   //						graphics library is planted in video memory at row "y" and column "x"
   //						within the screen.

	void box_fill(int x1, int y1, int x2, int y2, int color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x1" and "x2" should be between 0 and 319, inclusively, while "y1"
   //						and "y2" must be between 0 and 199, inclusively.  The program will
   //						not halt and errors will not arise if the pixels' coordinates are
   //						not within their specifications.
   //postconditions:	A rectangle with an upper-left corner of (x1, y1) and a lower-right
   //						corner of (x2, y2) is displayed on the monitor in color "color" and
   //						then filled in with the color of "color."

	void black_scr();
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.
   //postconditions:	The monitor is instantly erased with a sheet of black pixels.


#define TILE_H
#endif