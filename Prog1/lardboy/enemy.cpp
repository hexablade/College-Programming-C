#include "enemy.h"

enemy::enemy()
	{
   myrow = 0;
   mycol = 0;
   mydir = 1;
   myon = 1;
   mytype = 1;
   }

//******************************************************************************

enemy::enemy(int new_row, int new_col, int new_dir, int new_on, int new_type)
	{
   myrow = new_row;
   mycol = new_col;
   mydir = new_dir;
   myon = new_on;
   mytype = new_type;
   }

//******************************************************************************

enemy::enemy(const enemy &e)
	{
   myrow = e.myrow;
   mycol = e.mycol;
   mydir = e.mydir;
   myon = e.myon;
   mytype = e.mytype;
   }

//******************************************************************************

int enemy::row() const
	{
   return myrow;
   }

//******************************************************************************

int enemy::col() const
	{
   return mycol;
   }

//******************************************************************************

int enemy::dir() const
	{
   return mydir;
   }

//******************************************************************************

int enemy::on() const
	{
   return myon;
   }

//******************************************************************************

int enemy::type() const
	{
   return mytype;
   }

//******************************************************************************

void enemy::change_row(int new_row)
	{
   myrow = new_row;
   }

//******************************************************************************

void enemy::change_col(int new_col)
	{
   mycol = new_col;
   }

//******************************************************************************

void enemy::change_dir(int new_dir)
	{
   mydir = new_dir;
   }

//******************************************************************************

void enemy::change_on(int new_on)
	{
   myon = new_on;
   }

//******************************************************************************

void enemy::change_type(int new_type)
	{
   mytype = new_type;
   }
