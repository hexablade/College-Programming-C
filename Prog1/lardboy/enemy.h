// Class declaration file: enemy.h

#ifndef ENEMY_H

class enemy
	{
	public:
   	//Constructors
      enemy();
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions:	The enemy begins at row #0 and at column #0 in the map.  The
      //						fiend is heading towards the right, and it is initialized to
      //						be a zombie-like Lard Boy of type #1.  The enemy is ON.

      enemy(int new_row, int new_col, int new_dir, int new_on, int new_type);
      //preconditions:	The state of the new object that is being created is in an
      //						unpredictable form.
      //postconditions:	The enemy is born at row #new_row and at column #new_col within the
      //						map.  The fiend's direction equals "new_dir," and the value for
      //						"new_on" determines whether or not the enemy is alive.  The
      //						object's type is set to "new_type."


   	//Copy constructor
		enemy(const enemy &e);
      //preconditions:	The state of the current object that is being created is in an
      //						unpredictable form.  The enemy object of "e" has been appropriately
      //						declared and initialized.
      //postconditions:	All of the attributes belonging to object "e" are copied over to
      //						the corresponding attributes of the current object.  The row of this
      //						enemy equals e's row, the current fiend's column is set to e's
      //						column, and the direction of the newly created object is
      //						equivalent to e's direction.  In addition, the "on"-state of
      //						the new fiend equals the similar condition for "e."  This enemy's
      //						type matches e's type.


		//Accessors
		int row() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The enemy's row-value is returned to the caller.

		int col() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The current fiend's column-value is sent back to the caller.

      int dir() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The enemy's direction, which traditionally spans from 1 to 4,
      //						inclusively, is returned to the caller.

      int on() const;
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The state of the enemy being ON ("myon" = 1) or OFF ("myon" = 0)
      //						is returned.

      int type() const;
   	//preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The type of the fiend, which stretches from 1 to 4, inclusively,
      //						in Lard Boy, is returned to the caller.


   	//Modifiers
   	void change_row(int new_row);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The fiend's row-value is now equal to "new_row."

   	void change_col(int new_col);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions: The enemy's column-value now equals "new_col."

   	void change_dir(int new_dir);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The object's direction equals "new_dir."

   	void change_on(int new_on);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The enemy's state of being ON or OFF is changed in accordance
      //						with the value of "new_on."

      void change_type(int new_type);
      //preconditions:	The current object has been appropriately declared and
      //						constructed.
      //postconditions:	The fiend's type equals "new_type."

   private:
		//Data members
	   int myrow;
   	int mycol;
	   int mydir;
   	int myon;
      int mytype;
	};

#define ENEMY_H
#endif