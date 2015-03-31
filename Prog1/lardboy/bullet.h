// Class declaration file: bullet.h

#ifndef BULLET_H

class bullet
	{
	public:
		//Constructors
      bullet();
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions:	The initial row and column of the bullet are both initialized to 0.
      //						The direction of the bullet is 1, meaning that the projectile is
      //						traveling to the right.  The bullet is turned off.

		bullet(const int &newrow, const int &newcol, const int &newdir, const int &newon);
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions: The starting column of the bullet is "newcol," while the beginning
      //						row for the bullet is set to "newrow."  "newdir" specifies the
      //						projectile's dirction.  If "newon" is equal to 1, then the bullet
      //						is on.  On the other hand, the bullet is turned off if "newon" is 0.


   	//Copy constructor
		bullet(const bullet &b);
      //preconditions:	The state of the current object that is being created is in an
      //						unpredictable form.  The bullet object of "b" has been appropriately
      //						declared and initialized.
      //postconditions:	The row of the current bullet equals the row-value of "b," and
      //						the new bullet has a column-value equivalent to b's column.
      //						In addition, the object gains b's direction and b's state of
      //						being ON or OFF.


		//Accessors
		int row() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions: The row number that the bullet owns within the map is
      //						returned to the caller.

		int column() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions: The current bullet's column-value is sent back to the calling body.

      int direction() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The direction that the bullet is moving in, which can range from
      //						1 to 4, is received by the caller.
      //						Direction Guide:
      //								1 = right
      //								2 = up
      //								3 = left
      //								4 = down

      int on_off() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions: The value of the "on" attribute for the object is returned
      //						to the caller.


   	//Modifiers
   	void change_row(int new_row);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The row that the bullet is situated in changes to "new_row."

   	void change_col(int new_col);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The bullet's column-value is altered to equal "new_col."

   	void change_dir(int new_dir);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The projectile's direction is set to "new_dir."

   	void change_on(int new_on);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The bullet's state of being ON is switched to "new_on."
      //						(The projectile is ON when "on" = 1, and the object is OFF
      //						whenever "on" = 0.)


      //Utilities
      void update();
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The position of the bullet has been updated.  Bullets with a
      //						direction of 1 move an extra slot to the right, projectiles that
      //						have directions of 2 move upwards by 1 row, and those that have
      //						a direction of 3 shift an additional column in the map to the
      //						left.  On the other hand, bullets with direction-values of 4
      //						will move downwards by one row. 

	private:
		//Data members
	   int r;
   	int col;
	   int dir;
   	int on;
	};

#define BULLET_H
#endif