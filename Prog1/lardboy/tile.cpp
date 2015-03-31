#include <fstream.h>
#include "apstring.h"
#include "tile.h"

unsigned char far *video_buf = (char far *)0xA0000000L;

tile::tile()
	{
   int r, c;
   for(r=0; r<20; ++r)
   	for(c=0; c<20; ++c)
      	mytile[r][c] = 0;
   }

//******************************************************************************

tile::tile(const tile &t)
	{
   int r, c;
   for(r=0; r<20; ++r)
   	for(c=0; c<20; ++c)
      	mytile[r][c] = t.mytile[r][c];   
   }

//******************************************************************************

void tile::load_stamp(apstring filename)
	{
   int current_char;
   int row=0, col=0;
   ifstream infile;
   infile.open(filename.c_str());
   if(infile.fail())
   	{
      black_scr();
      gotoxy(1,1);
      cout<<"Error: File Not Found\n\n\nFilename: "<<filename<<"\n\n\n\n\nTerminate Program Immediately";
      for(int r=0; r < 20; ++r)
      	for(int c=0; c < 20; ++c)
         	mytile[r][c] = 0;
      getch();
      }
   else
   	{
   	infile>>current_char;
   	while((! infile.eof()) && (current_char != 1000))
   		{
	      if((current_char >= 0) && (current_char < 256))
   	      {
      	   mytile[row][col] = current_char;
         	++col;
	         }
   	   else if(current_char == 999)
      		{
         	++row;
	         col = 0;
   	      }
      	infile>>current_char;
	      }
   	infile.close();
	   }
   }

//******************************************************************************

void tile::display_stamp(int topx, int topy)
	{
   int row, column;
   for(row=0; row < 20; ++row)
   	for(column=0; column < 20; ++column)
      	Plot_Pix((column + topx), (row + topy), mytile[row][column]);
   }

//******************************************************************************

void Plot_Pix(int x, int y, unsigned char color)
	{
  	video_buf[((y<<8) + (y<<6)) + x] = color;
	}

//******************************************************************************************

void box_fill(int x1, int y1, int x2, int y2, int color)
	{
   if(y1 < y2)
	   for(int i = x1; i < x2; ++i)
   		for(int j = y1; j < y2; ++j)
      		Plot_Pix(i, j, color);
   else
		for(int i = x1; i < x2; ++i)
   		for(int j = y2; j < y1; ++j)
      		Plot_Pix(i, j, color);
   }

//******************************************************************************************

void black_scr()
	{
   box_fill(0,0,320,200,0);
   }
