#include "bullet.h"


bullet::bullet()
	{
   r = 0;
   col = 0;
	dir = 1;
   on = 0;
   }

//******************************************************************************

bullet::bullet(const int &newrow, const int &newcol, const int &newdir, const int &newon)
	{
   r = newrow;
   col = newcol;
	dir = newdir;
   on = newon;
   }

//******************************************************************************

bullet::bullet(const bullet &b)
	{
   r = b.row();
   col = b.column();
   dir = b.direction();
   on = b.on_off();
   }

//******************************************************************************

int bullet::row() const
	{
   return r;
   }

//******************************************************************************

int bullet::column() const
	{
   return col;
   }

//******************************************************************************

int bullet::direction() const
	{
   return dir;
   }

//******************************************************************************

int bullet::on_off() const
	{
   return on;
   }

//******************************************************************************

void bullet::change_row(int new_row)
	{
   r = new_row;
   }

//******************************************************************************

void bullet::change_col(int new_col)
	{
   col = new_col;
   }

//******************************************************************************

void bullet::change_dir(int new_dir)
	{
   dir = new_dir;
   }

//******************************************************************************

void bullet::change_on(int new_on)
  	{
   on = new_on;
   }

//******************************************************************************

void bullet::update()
	{
   switch(dir)
     	{
      case 1:  ++col;
        			break;
      case 2:  --r;
       			break;
      case 3:  --col;
       			break;
      case 4:  ++r;
      }
   }
