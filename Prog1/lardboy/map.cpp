#include <fstream.h>
#include "map.h"

//unsigned char far *video_buf = (char far *)0xA0000000L;

map::map()
	{
   rows = 0;
   cols = 0;
   r_onscreen = 0;
   c_onscreen = 0;
   start_maprows = 0;
   start_mapcols = 0;
   }

//******************************************************************************
map::map(const int &numrows, const int &numcols, const int &rows_ons, const int &cols_ons, const int &start_mapr, const int &start_mapc)
	{
   rows = numrows;
   cols = numcols;
   mymap.resize(numrows, numcols);
   r_onscreen = rows_ons;
   c_onscreen = cols_ons;
   start_maprows = start_mapr;
   start_mapcols = start_mapc;
   }

//******************************************************************************

map::map(const map &m)
	{
   rows = m.numrows();
   cols = m.numcols();
   mymap = m.mymap;
   r_onscreen = m.r_onscreen;
   c_onscreen = m.c_onscreen;
   start_maprows = m.start_maprows;
   start_mapcols = m.start_mapcols;
   }

//******************************************************************************

int map::numrows() const
	{
   return rows;
   }

//******************************************************************************

int map::numcols() const
	{
   return cols;
   }

//******************************************************************************

int map::numrows_os() const
	{
   return r_onscreen;
   }

//******************************************************************************

int map::numcols_os() const
	{
   return c_onscreen;
   }

//******************************************************************************

int map::row_start() const
	{
   return start_maprows;
   }

//******************************************************************************

int map::col_start() const
	{
   return start_mapcols;
   }

//******************************************************************************

int map::cell(int rws, int cls)
	{
   return mymap[rws][cls];
   }

//******************************************************************************

void map::change_rows(int new_rows)
	{
   rows = new_rows;
   mymap.resize(rows, cols);
   }

//******************************************************************************

void map::change_cols(int new_cols)
	{
   cols = new_cols;
   mymap.resize(rows, cols);
   }

//******************************************************************************

void map::change_rows_os(int new_rows_os)
	{
  	r_onscreen = new_rows_os;
   }

//******************************************************************************

void map::change_cols_os(int new_cols_os)
	{
   c_onscreen = new_cols_os;
   }

//******************************************************************************

void map::ch_row_start(int new_rs)
	{
   start_maprows = new_rs;
   }

//******************************************************************************

void map::ch_col_start(int new_cs)
	{
   start_mapcols = new_cs;
   }

//******************************************************************************

void map::change_cell(int rws, int cls, int new_value)
	{
   mymap[rws][cls] = new_value;
   }

//******************************************************************************

void map::load_map(apstring filename, int &foodleft, int &origfood)
	{
   int current_char;
   int row=0, col=0;
   int foodyn, cat;
   foodleft=0;
   ifstream infile;
   infile.open(filename.c_str());
   if(infile.fail())
   	{
      black_scr();
      gotoxy(1,1);
      cout<<"Error: File Not Found\n\n\nFilename: "<<filename<<"\n\n\n\n\n!Terminate Program Immediately!";
      for(int r=0; r < rows; ++r)
      	for(int c=0; c < cols; ++c)
         	mymap[r][c] = 0;
      getch();
      }
   else
   	{
   	infile>>current_char;
   	while(! infile.eof())
   		{
	      if((current_char >= 0) && (current_char < 999))
   	      {
            if(current_char == 100)
            	{
               foodyn = rand() % 14;
               if(foodyn == 0)
               	{
                  ++foodleft;
                  cat = (rand() % 6) + 3;
                  switch (cat)
                  	{
                     case 3:	current_char = (rand() % 7) + 300;
                     			break;
                     case 4:  current_char = (rand() % 6) + 400;
                     			break;
                     case 5:  current_char = (rand() % 6) + 500;
                     			break;
                     case 6:  current_char = (rand() % 4) + 600;
                     			break;
                     case 7:  current_char = (rand() % 6) + 700;
                     			break;
                     case 8:  current_char = (rand() % 4) + 800;
                     }
                  }
               }
      	   mymap[row][col] = current_char;
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
   origfood = foodleft;
   }

//******************************************************************************

void take_photo(map &scene, int photo[7][11])
	{
   int r, c;      	//The integer variables of 'r' and 'c' are used in the "for" loops to cycle through the rows and columns of the current screen, respectively.
   for(r=0; r < scene.numrows_os(); ++r)
   	for(c=0; c < scene.numcols_os(); ++c)
      	photo[r][c] = scene.cell((scene.row_start() + r), (scene.col_start() + c));
   }

