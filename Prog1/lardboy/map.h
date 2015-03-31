// Class declaration file: map.h


#include <time.h>
#include <fstream.h>
#include "tile.h"
#include "apstring.h"
#include "apmatrix.cpp"

#ifndef MAP_H

class map
	{
	public:
		//Constructors
      map();
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions:	The map has 0 rows ("rows"=0), 0 columns ("cols"=0), 0
      //						rows visible on the screen ("r_onscreen" = 0), and 0 columns
      //						that are shown on the monitor ("c_onscreen" = 0).  In addition,
      //						the map will start being displayed at row #0 ("start_maprows"=
      //						0) and at column #0 ("start_mapcols"=0).

		map(const int &numrows, const int &numcols, const int &rows_ons, const int &cols_ons, const int &start_mapr, const int &start_mapc);
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions:	The map has "rows_ons" rows that are visible on the screen at
      //						any given time, and "cols_ons" columns of tiles will always
      //						appear on the monitor.  The map shall begin to be displayed
      //						at row #start_mapr and at column #start_mapc.  The "mymap" attribute,
      //						which stores the actual elements of each world, is resized with
      //						"numrows" rows and "numcols" columns.


   	//Copy constructor
		map(const map &m);
      //preconditions:	The state of the current object that is being created is in an
      //						unpredictable form.  The map object of "m" has been appropriately
      //						declared and initialized.
      //postconditions:	All of the attributes belonging to object "m" are copied over to
      //						the corresponding attributes of the current object.  The current
      //						object has the same number of rows as "m," the identical amount
      //						of columns as "m," and contains every element in its "mymap"
      //						primary attribute that is present in m's "mymap" array.
      //						The object's number of rows and columns that will appear on
      //                the screen match the number of rows and columns that object m
      //						can show on the monitor.  Additionally, the row-value and column-
      //						value that the map will initially begin to print at is the same
      //						at the starting row and column of object "m."


		//Accessors
		int numrows() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The total number of rows that exist in the map-type object
      //						is returned to the caller.

		int numcols() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The total number of columns that lie within the current object
      //						is sent back to the caller.

      int numrows_os() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The amount of rows in the map that appear on the monitor
      //						at any given time is sent to the caller.

      int numcols_os() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The quantity of columns within the map that are shown on
      //						the screen at any moment is returned to the caller.

      int row_start() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The row number in the map at which a section of the map
      //						will begin to be displayed is returned to the caller.

      int col_start() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The column address within the map at which the map begins
      //						to be printed out is sent back to the caller.

      int cell(int rws, int cls);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The element within the "mymap" attribute of the current object
      //						that has a row-value of "rws" and a column-value of "cls"
      //						is returned to the caller as an integer.


   	//Modifiers
   	void change_rows(int new_rows);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The number of rows that exist in the map is now changed
      //						to "new_rows" rows, and the "mymap" attribute is resized
      //						to have "new_rows" rows and an unaltered quantity of columns.

   	void change_cols(int new_cols);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The amount of columns that lie in the map is changed to
      //						"new_cols" columns, and the "mymap" attribute is adjusted
      //						to contain "new_cols" columns and an unchanged number of rows.

   	void change_rows_os(int new_rows_os);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The number of rows that may appear on the monitor is changed
      //						to "new_rows_os" rows.

   	void change_cols_os(int new_cols_os);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The amount of columns that will be shown on the screen is
      //						altered to "new_cols_os" columns.

      void ch_row_start(int new_rs);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The map now starts to be displayed at row #new_rs.

      void ch_col_start(int new_cs);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The map is now outputted beginning at column #new_cs.

      void change_cell(int rws, int cls, int new_value);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions: The cell in the object's "mymap" attribute that is located
      //						at row #rws and at column #cls now equals "new_value."


      //Utilities
	   void load_map(apstring filename, int &foodleft, int &origfood);
      //preconditions:	The current map-type object has been appropriately declared and
      //						constructed.  The "apstring" class is fully operational, and the
      //						computer can read from a map file that is located on the user's
      //						machine with the aid of input file streams.  The video card
      //						and monitor are prepped for mode 13h graphics.
      //postconditions:	The file in which the map is located in array-form is successfully
      //						or unsuccessfully opened.  If the map failed to load, the user
      //						is given an error message about the missing or corrupted file,
      //						along with the name of the file that cannot be loaded.  When
      //						a map file cannot fill in the elements within the "mymap"
      //						attribute, all of the map's elements are given values of 0.
      //						Otherwise, if the file is found in stable condition, then
      //						the data in the file are directly transferred to the slots in
      //						"mymap."  For example, if the fifth row and third column of the
      //						map within the file has an element of 100, then the fifth row and
      //                third column of "mymap" will also contain 100.  About 1/14 of the
      //						floor elements of value #100 have been given food items at random
      //						for the character to pick up.  The total amount of food in the
      //						given map is calculated and stored to "origfood" and "foodleft."

	private:
		//Data members
	   int rows;
   	int cols;
      apmatrix<int> mymap;
      int r_onscreen;
      int c_onscreen;
      int start_maprows;
      int start_mapcols;
	};

//FREE FUNCTIONS
	void take_photo(map &scene, int photo[7][11]);
   //preconditions:	The map-type object of "scene" has been appropriately declared and
   //						constructed.  The 2-D integer of "photo" can contain the current elements
   //						that appear on the screen.
   //postconditions:	"photo" holds all of the elements that are shown on the monitor in
   //						their proper order.


#define MAP_H
#endif