//******************************************************************************
//*************Lard Boy's Second Engine--The Game's Main Title Page*************
//******************************************************************************

//********************************Palette Defines for Mode 13h******************
#define MODE13H             0x13
#define TEXT_MODE           0x03
#define PALETTE_MASK        0x3C6
#define PALETTE_REGISTER_RD 0x3C7
#define PALETTE_REGISTER_WR 0x3C8
#define PALETTE_DATA        0x3C9

//Function Declarations

	//Graphics Mode 13H Functions
   void init_mode13h();
   //preconditions:	The screen mode for the program is in an unpredictable state
	// 					and can exist in any resolution that uses any palette of colors,
   //						including mode 13h.
   //postconditions:	The monitor and video memory are adapted to accompany 200 rows of
   //						pixels by 320 columns of pixels by 256 colors.  In other words, the
   //						screen is set to mode 13h.

	void Video_Mode(int vmode);
   //preconditions:	The screen mode for the program is in an unpredictable state
	// 					and can exist in any resolution that uses any palette of colors,
   //						including mode 13h.
   //postconditions: The monitor and video card are adjusted to fit the "vmode" style.
   //						The function usually receives one of the defined slots of memory
   //						that are predefined above, such as "MODE13H" or "TEXT_MODE."

	void Plot_Pixel(int x, int y, unsigned char color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x" should be between 0 and 319, inclusively, while "y" must be between
   //						0 and 199, inclusively.  The program will not halt and errors will not
   //						arise if the pixel's coordinates are not within their specifications.
   //postconditions:	The pixel of color "color" from the 256 various shades of the mode 13h
   //						graphics library is planted in video memory at row "y" and column "x".

	void Set_PalReg(int index, unsigned char red, unsigned char green, unsigned char blue);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  The slot in the video buffer that is represented by
   //						"index" exists and can adopt the new attributes of "red," "green,"
   //						and "blue."
   //postconditions:	The red, green, and blue elements of the pixel with the address of
   //						"index" in the video buffer have been altered with the new attributes
   //						of "red," "green," and "blue," respectively.

	int Get_PalReg(int index, int color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is either 1, 2, or 3, standing for the
   //						red, green, or blue attribute of a pixel's color, respectively.
   //						The slot in the video buffer that is represented by "index" exists.
   //postconditions:	If "color" is 1, then the function returned the red-value of the
   //						pixel that has the address of "index" in video memory.  However, the
   //						green-value of the pixel at "index" is returned when "color" is 2, and
   //						the blue attribute of the pixel is sent back to the caller if "color"
   //						equals 3.

   
   //Basic Functions for the VGA Graphics Library
	void draw_line(int x1, int y1, int x2, int y2, int color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x1" and "x2" should be between 0 and 319, inclusively, while "y1"
   //						and "y2" must be between 0 and 199, inclusively.  The program will
   //						not halt and errors will not arise if the pixels' coordinates are
   //						not within their specifications.
   //postconditions:	A line of color "color" stretches from the coordinate of (x1, y1) to
   //						(x2, y2) in a step-like manner without smooth edges.  The line has a
   //                pixel length of one unit.

	void draw_circle(int x, int y, int r, int color);
   //preconditions:  The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x" should be between 0 and 319, inclusively, while "y"
   //						must be between 0 and 199, inclusively.  "r," which represents the
   //						circle's radius, should be at such a value that any point drawn "r"
   //						pixels away from the shape's center at (x, y) is still in the bounds of
   //						the video mode.  The program will not halt and errors will not arise
   //						if the pixels' coordinates are not within their specifications.
   //postconditions:	A circle with a radius of "r" pixels and center at (x, y) is created
   //						on the monitor in color "color."

	void box_filled(int x1, int y1, int x2, int y2, int color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x1" and "x2" should be between 0 and 319, inclusively, while "y1"
   //						and "y2" must be between 0 and 199, inclusively.  The program will
   //						not halt and errors will not arise if the pixels' coordinates are
   //						not within their specifications.
   //postconditions:	A rectangle with an upper-left corner of (x1, y1) and a lower-right
   //						corner of (x2, y2) is displayed on the monitor in color "color" and
   //						then filled in with the color of "color."

	void box_outlined(int x1, int y1, int x2, int y2, int color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //						"x1" and "x2" should be between 0 and 319, inclusively, while "y1"
   //						and "y2" must be between 0 and 199, inclusively.  The program will
   //						not halt and errors will not arise if the pixels' coordinates are
   //						not within their specifications.
   //postconditions:	An empty, unfilled rectangle is placed on the screen in the shade of
   //						"color."  The coordinate of (x1, y1) represents the shape's upper-
   //						left corner, while (x2, y2) symbolizes the rectangle's lower-right corner.

	void box_in_box(int x1, int y1, int x2, int y2, int startc, int finishc);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "startc" and "finishc" are between 0 and 255,
   //						inclusively.  "x1" and "x2" should be between 0 and 319, inclusively,
   //						while "y1" and "y2" must be between 0 and 199, inclusively.  The
   //						program will not halt and errors will not arise if the pixels'
   //						coordinates are not within their specifications.
   //postconditions:	A cascading series of boxes that grow larger and shoot outwards is
   //						formed on the monitor.  The initial, most-inner rectangle that is not
   //						filled has an upper-left coordinate of (x1, y1) and a lower-right corner
   //						of coordinate (x2, y2).  This starting rectangle is of color "startc,"
   //						and each successive box increments upwards by one color until surpassing
   //						"finishc."  In addition, every bigger box has an upper-left corner which
   //						is one pixel to the left of and one pixel above the upper-left corner of
   //						the previous rectangle.  The lower-right coordinate of a new rectangle
   //						is one pixel below and one pixel to the right of the similar corner
   //						belonging to the previous rectangle. 

	void black_screen();
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.
   //postconditions:	The monitor is instantly erased with a sheet of black pixels.

	void erase_vert(int color);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "color" is between 0 and 255, inclusively.
   //postconditions:	A horizontal line in shade "color" and a second horizontal line of
   //						color "color" began at the bottom and top of the monitor, respectively.
   //						The two lines slowly moved towards the center row of the screen,
   //						completing a solid display of "color" once they meet.

	void fade_to_red(int slowness);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						is in any condition.  "slowness" represents how slow the screen should
   //						fade to red, with a value of 1 being extremely fast and the amount of
   //						100 being quite slow.  The variable should be a positive integer.
   //postconditions:	The entire screen began in its original condition and turned to a solid
   //						sheet of color #4 (dark red) with a quickness corresponding to how
   //						low "slowness" is.  The red attribute of each color is intensified, while
   //						the green and blue elements of every pixel are dropped to 0.  The original
   //						palette of colors is refreshed by re-initializing mode 13h.


   //Star-Field Functions
	void twod_stars(int slowness, int NBR_STARS, int MinX, int MaxX, int MinY, int MaxY);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						in the region where the stars shall fly is solely black.
   //postconditions: The star field consists of "NBR_STARS" that all change their
   //						positions (the objects shoot to the left) whenever the computer
   //						exits a stop in a "delay" statement that lasts "slowness" units
   //						of time.  None of the stars have x-values that exceed MaxX or fall
   //                to the left of MinX, and the stars all contain y-values which
   //						are between MinY and MaxY, inclusively.  The user has struck a
   //						key to cause the action to stop and the program to continue executing.

	void InitStars(int NBR_STARS, int MinX, int MaxX, int MinY, int MaxY);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						in the region where the stars shall fly is preferably black.
   //postconditions:	The "NBR_STARS" slots within the "Stars" structured array have
   //						each been given a new x-value, a new y-value, and a new plane to
   //						travel through.  The new set of stars remain in the field defined by the
   //						"MinX," "MaxX," "MinY," and "MaxY" restrictions.

	void DeleteStars(int NBR_STARS);   //preconditions:	The video mode is set to version 13h, and the display on the screen   //						in the region where the stars fly is either black or filled with stars   //						composed of single pixels.  The "InitStars" function has been previously   //						called to establish the x and y coordinates of the pixels that must   //						be erased.    //postconditions:	The pixel at which every star existed is given the "invisible"   //						color of black.	void MoveStars(int NBR_STARS, int MinX, int MaxX, int MinY, int MaxY);
   //preconditions:	The "InitStars" function has been previously
   //						called to establish the x and y coordinates of the pixels that must   //						be shifted leftward.  Preferably, the "DeleteStars" function has been
   //						recently utilized.
   //postconditions:	All "NBR_STARS" stars within the "Stars" array are shifted vertically
   //						and/or horizontally.  When the global variable of "DirX" is -1, the
   //						stars advance leftward, but the stars move to the right if "DirX" is
   //						1.  In addition, if "DirY" equals positive 1, stars move downwards, and
   //						the stars shift upwards if "DirY" is -1.  However, the horizontal and
   //						vertical effects cannot be combined; either "DirX" or "DirY" must be
   //						set to 0.  The brighter stars that appear to exist in the top
   //						plane move leftward in greater leaps than the dull, gray-colored
   //						celestial bodies that seem to lie in the background.  Stars that
   //						evade the boundaries of the star field are placed back at the
   //					   apparent origin of the landscape with new planes of motion.

	void DrawStars(int NBR_STARS);
   //preconditions:	The video mode is set to version 13h, and the display on the screen
   //						in the region where the stars fly is either black or filled with stars   //						composed of single pixels.  The "Stars" array has been appropriately
   //						initialized, and the "DeleteStars" and "MoveStars" functions were
   //						recently called.
   //postconditions:	All "NBR_STARS" stars have been drawn on the monitor within their proper
   //						boundaries with degrees of light that match their "Plane" fields.  For
   //						example, a star with a "Plane" value of 16 has a white color, while
   //						stars belonging to Plane #4 have dark-gray colors.  

	void WR();

	//Unique Functions to Game
   int find_speed();
   //preconditions:	The monitor is capable of printing out text.
   //postconditions:	The top speed of the user's computer (in MHz.) is pulled from the
   //						keyboard and returned to the caller.

   void hit_enemy();
   //preconditions:	Lard Boy has struck a fiend in the map that can injure or kill the
   //						character.
   //postconditions:	Lard Boy's energy decreases by a particular amount, possibly
   //						killing the fat boy.

   void move_success();
   //preconditions:	The African American male's new location in the large map is free of
   //						enemies and permanent obstructions.
   //postconditions:	The player receives points and/or energy if the
   //						function determines that Lard Boy is stepping on an ammunition crate,
   //						the exit to a level, or a food item.

   void clear_keys();
   //preconditions:	The gamer pressed between zero and several dozen keys while the computer
   //						was executing a different sector of the program.
   //postconditions:	The buffer that holds every key that the user struck is wiped clean.

   void fix_path(apstring &path);
   //preconditions:	The user attempted to provide the path (i.e., the drive and directories)
   //						for a project's various files, and the given path is stored in the valid
   //						apstring object named "path."  "path" may or may not hold the
   //						directory for the files in the format that the computer can understand,
   //						and the path might not even be accessible on the person's computer.
   //postconditions:	Any back slashes, which are represented as '\,' that the user wrongly
   //						included in the path are converted to forward slashes (or '/').  If the
   //						user's path lacks a forward slash charater at its very end, then '/' is
   //						tacked onto the end of the path.

   void prompt_np();
   //preconditions:	The monitor is capable of printing out text in the basic C++ screen mode.
   //						The program is likely at a point where the user must press a key
   //						after he/she reads a segment of text or simply views a picture.
   //postconditions:	The program completely halts until the user responds to the message near
   //						the monitor's bottom by pressing any key.

   void prompt_np_13h();
   //preconditions:	The monitor is capable of printing out text in screen mode 13h.
   //						The program is likely at a point where the user must press a key
   //						after he/she reads a segment of text or simply views a picture.
   //postconditions: The program completely halts until the user responds to the message near
   //						the monitor's bottom by pressing any key.

	void load_files();
   //preconditions:	The apstring variable of "path" may or may not lead to the game's
   //						stash of files.
   //postconditions:	Every tile that is used within Lard Boy is loaded into its proper
   //						object of type "tile."

	void display_template();
   //preconditions:	The monitor is ready to receive graphics in mode 13h, and the game's
   //						tiles are fully loaded into their objects.
   //postconditions:	Every cell within the 2-D integer array named "photo," which can
   //						store a snapshot of the current tiles on the screen, is reset
   //                to its default value of 0.  Many of the global variables that control
   //						gameplay in each level, including several arrays that store the data
   //						on bullet movements, are reset to their initial amounts.  In addition,
   //						the array which holds information on the upcoming level's enemies
   //						contains a full set of enemy data, including the location, direction,
   //						and type of each fiend.  The starting number of enemies in the
   //						level is also established.  The user has been informed of the
   //						stage that he/she is entering, the first scene of the map is printed
   //						out, and the "display_panels" function has been called (see below).

	void display_panels();
   //preconditions:	The monitor is ready to receive graphics in mode 13h, and the player
   //						is on the edge of embarking into the world.
   //postconditions:	The "SAVE," "QUIT," and "Return to Game" options are visible to the
   //						user for later use in the actual gameplay.  The user's current score,
   //						energy quantity, lives remaining, food that still exists in the stage,
   //						and amount of ammunition that can be fired from Lard Boy's gun are
   //						outputted to the monitor.

	int title_screen();
   //preconditions:	The application's files should be loaded into primary memory, and the
   //						graphics can exist in either C++'s generic BGI mode or Wonder Workers'
   //						supreme version of mode 13h.
   //postconditions:	The main menu has been displayed to the user, and he/she has finally
   //						chosen to load a saved game, start a new game, or quit to Windows.  The
   //						gamer may have accessed the instructions and/or the "food catalog"
   //						several times before "title_screen" terminates.

	void instructions();
   //preconditions:	The monitor is prepped for the BGI graphics library, and the game's
   //						tiles have been successfully loaded into primary memory.
   //postconditions:	Six pages of instructions that are given in a hybrid of BGI graphics
   //						form and mode 13h have passed by the user.  The gamer is now aware
   //						of the project's story, its objectives, the game's atmosphere,
   //						the enemies in the game, and the proper controls for operating the
   //						program.  The computer now returns to the main menu.

	void foodcat();
   //preconditions:	The program is in graphics mode 13h or in C++'s BGI form.  All of the
   //						food tiles have been loaded successfully into dynamic memory.
   //postconditions:	The monitor is switched to mode 13h.  The gamer had the ability
   //						to view the points and energy that Lard Boy can gain from picking
   //						up each of the 33 different food items.  The program returns to
   //						the main menu of the application. 

	int pause();
   //preconditions:	The graphics card is prepped for mode 13h, and the menu on the
   //						far-right of the screen has been displayed in a combination of
   //						oranges and reds.  The gamer is currently playing a stage; he/she
   //						is not outside gameplay.
   //postconditions:	The user has the ability to move the green rectangle from choice to
   //						choice within the small menu, and the gamer made the decision to
   //						save the current game, quit the game and return to the main menu, or
   //						continue playing the action-filled application.
   
	void energy_bars();
   //preconditions:	The player's energy quantity can be represented by any integer,
   //						the monitor is in mode 13h, and the location where the energy
   //						bars must be placed is free of other graphics except for a solid
   //						black background.
   //postconditions:	If the character's energy exceeds 396 units, then the energy level
   //						is brought down to only 396 units.  When Lard Boy's energy is greater
   //						than 0 units, the energy bars are drawn out to their proper lengths.
   //						A black strip then covers the energy bars that are not being used.  If
   //						the gamer's energy is below 0 units, then the "die" function is called
   //						and the player loses a life, possibly leading to a game over.

	void display_ammo();
   //preconditions:	The gamer's ammunition remaining is at or above zero bullets.  The
   //						video card is operating on graphics mode 13h, and the location where
   //						the extra shells must be printed is clear of other graphics.
   //postconditions: Each bullet that the player can still fire at enemies is displayed
   //						as a small, vertical, yellow bar in the lower-right portion of the screen.
   //						If the player has more than 116 bullets left, then Lard Boy's ammunition
   //						is reduced to 116 rounds.

	void hit_item(int itemval);
   //preconditions:	The player has walked upon a healthy food item in the map that
   //						has a data value stretching between the 300's and 800's.
   //postconditions:	The computer awards the gamer for picking up the food with
   //						additional points and energy units.  The amount of food remaining
   //						on the map drops by one item, and the quantity of food that still
   //						exists in the world is displayed to the user with the aid of the
	//						"display_fleft" function.  The player's new energy level and score
   //						are outputted to the monitor.

	void die();
   //preconditions:	Lard Boy's energy has dropped below 0 units and/or the player has
   //						walked into the water.  The player has between zero and positive
   //						infinity lives remaining.  Additionally, the screen is adjusted
   //						for mode 13h graphics.
   //postconditions:	Lard Boy has spun around in a circle four times, the screen faded
   //						to a blood-red shade, and the gamer lost a life.  If the global
   //						variable of "lives" fell under zero lives, then the game over
   //						scenario appears to the gamer.  Otherwise, the gameplay continues
   //						from the very beginning of the current level with the call to
   //						the "display_template" function.

	void gameover();
   //preconditions:	The video card is operating on graphics mode 13h, and the player's
   //						lives are completely extinguished.
   //postconditions: The player has viewed a short "movie" showing Lard Boy's bloody
   //						destruction, the graphics mode transforms into C++'s BGI graphics
   //						library, the gamer's score earned during the game is shown, and the
   //						program returns to the main menu.

	void update_char_bullets();
   //preconditions:	The video card is operating on graphics mode 13h.  Additionally, the
   //						2-D "photo" array that stores a picture of current activity on the map
   //						must be usable.
   //postconditions:	A photo of the screen is taken to make the map-displaying function
   //						more efficient.  All of the character's bullets that are "on" and
   //						moving are advanced in their direction of action.  For instance, bullets
   //						that have a direction of 1 (this value means that the bullet is
   //						traveling to the right) move one additional slot to the right.  On the
   //						other hand, a bullet of direction 4 (this quantity signifies that
   //						the projectile is moving downwards) shall shift one extra map cell
   //						to the south.  The old slots of bullets in the map receive the value of
   //						100 (or flooring), and bullets only appear on the screen if the
   //						projectiles are within the present photo range.  Nonetheless, bullets
   //						will continue to move off the screen, regardless of whether they are
   //						visible to the gamer.  Bullets that strike walls halt immediately.
   //						Similarly, bullets that sink into mortal enemies disappear from
   //						existence on the map and permit the player to receive points based
   //						on the type of enemy that was killed.  The updated version of the map
   //						then appears on the monitor.

	void fire_ebullet(int brow, int bcol, int bdir);
   //preconditions:	The character and the enemy that is firing the bullet are in the
   //						same column or the identical row.  The 1-D array named "efire" can
   //						be modified and has at least one open slot for the creation of the
   //						new projectile.
   //postconditions:	An index in "efire" that is not occupied with a fiend's shell is
   //						located.  The direction, row, column, and "on" state for the bullet
   //						at that index are established based off the firing fiend's position.
   //						The direction of the bullet becomes the direction of motion for the
   //						enemy, the bullet's row takes on the fiend's row, and the column
   //						for the projectile initially becomes the enemy's column.  The number
   //						of enemy-based bullets floating in the air, represented with
   //						"ebullets_in_air," is incremented by 1, and the positions of every
   //						sinister bullet is updated.

	void update_ebullets();
   //preconditions:	The video card is operating on graphics mode 13h.  Additionally, the
   //						2-D "photo" array that stores a picture of current activity on the map
   //						must be usable.
   //postconditions:	A picture of the current scene on the screen is taken with
   //						"take_photo."  Between 0 and 20 enemy bullets have been updated.
   //						Bullets that hit Lard Boy took down his energy and possibly led
   //						to his death, while bullets hitting solid, immovable objects
   //						vanish from the map.  The newer version of the level's map is
   //						shown on the screen.

	void display_score();
   //preconditions:	The video card is operating on graphics mode 13h or on the C++ BGI
   //						graphics library, allowing simple text to be printed.
   //postconditions:	The player's score is outputted onto the monitor.

	void display_lives();
   //preconditions:	The video card is operating on graphics mode 13h or on the C++ BGI
   //						graphics library, allowing simple text to be printed.
   //postconditions:	The gamer's lives that remain are shown.

	void display_fleft();
   //preconditions:	The video card is operating on graphics mode 13h or on the C++ BGI
   //						graphics library, allowing simple text to be printed.
   //postconditions:	The food that the user can still collect in the current level in
   //						an attempt to gain the 25,000-point bonus is displayed in text.

	void save_game_menu();
    //preconditions:	The monitor is in graphics mode 13h.
   //postconditions:	The graphics began to rely on the BGI library.
   //						The user chose a slot in which to save his/her game, or the gamer
   //						decided to exit the save option by pressing the <ESCAPE> key.  If
   //						the player wanted to save the current game, then the game's data
   //						is written to the selected file.  The gameplay resumes in its
   //						previous condition in mode 13h without any changes in the map
   //						or enemies.

	void save_game(apstring filename);
   //preconditions:	The slot (or file) that the computer must write to can be created;
   //						the application is not attempting to write onto a CD.
   //postconditions:	An output file stream was connected to "filename," and the
   //						player's current level, number of lives remaining, and score were
   //						written to the file.

	int load_game_menu();
   //preconditions:	The monitor is in graphics mode 13h.
   //postconditions:	The graphics mode for the application is temporarily based
   //						on C++'s simple BGI library.
   //						The user chose a slot in which to load his/her game, or the gamer
   //						decided to exit the loading option by pressing the <ESCAPE> key.  If
   //						the player wanted to load a particular slot, then the game's data
   //						is pulled from the selected file and deposited into the player's
   //						new game.  The gamer's lives, score, and level are adopted from
   //						the file.  In addition, the graphics mode reverts to 13h.

	void load_game(apstring filename, int &level2, int &lives2, long int &score2);
   //preconditions:	An input file stream can be linked to "filename," and the file
   //						contains the level, lives, and score for that game.
   //postconditions:	An input file stream hooks up to the file represented by "filename,"
   //						the saved game's level, lives, and score are pulled from the file,
   //						and the file stream is closed.  "level2," "lives2," and "score2"
   //						receive the corresponding values which exist in the file, and the
   //						variables are automatically returned to the caller via reference
   //						parameters.

	void print_file_info(int &choice, int &madechoice);
   //preconditions:	The computer is using the BGI graphics library.  The three files
   //						of type ".sav" exist in the "path" directory, and the computer
   //						is capable of extending input file streams to the three clusters
   //						of data.
   //postconditions:	The level, lives, and score that each of the three saved games
   //						contains are displayed vividly on the monitor.
	//					   The user has chosen a particular file to either load from or save to,
   //						or he/she has decided to exit the screen that displays the information
   //						on files by pressing <ESCAPE>.

   void slot_data();
   //preconditions:	The computer is using the standard BGI graphics library.  The user's
   //						machine can read from an input file stream.
   //postconditions:	The data from each of the three ".sav"-type files is loaded from "path"
   //						and outputted onto the screen. 

	void display_map(int topl_row, int topl_col, int camon);
   //preconditions:	The video card is operating on graphics mode 13h.  The "photo" array
   //						is operating and is updated if the user wants the camera to be on
   //						(i.e., "camon" is 1), and the main map of "map1" has been properly
   //						initialized with integer-based values.
   //postconditions: The function runs through the entire map (in this game, the primary
   //						map has 2,500 cells) from top row to bottom row and from left to right--
   //						similar to the manner in which one would read a book.  Every element
   //						of the map that is currently on the screen is displayed in stamp form.
   //						(Only cells in the map that have row-coordinates spanning between
   //						"topl_row" and "topl_row" + 6, inclusively, and have column-
   //						coordinates between "topl_col" and "topl_col" + 10, inclusively,
   //						shall be printed on the screen.)  Each datum in the map that must
   //						be printed on the monitor is matched with its proper tile, and the
   //						picture is then outputted onto the monitor at its correct position.

   void update_enemies();
   //preconditions:	The video card is operating on graphics mode 13h.  The main map has
   //						been appropriately initialized and filled, and the 2-D
   //						integer array called "photo" can be changed.  Between 0 and 65
   //						enemies, inclusively, are present within the map.  Every enemy
   //						within the level has a valid row, column, and dirction.
   //postconditions:	A snapshot of the current scene is stashed away in "photo."
   //						All of the enemies within the stage have been moved, causing
   //						harm to Lard Boy if they crash into the character.  In addition,
   //						bunkers, zombie-like Lard Boys, and the evil hovercrafts fired
   //						at the player if the fiend and player lie in the same row or column.
   //						The new version of the map is printed on the screen with the "camers" on.

   void finish_game();
   //preconditions:	The video card is operating on graphics mode 13h.  The user may or may
   //						not have pressed several keys while the program was accessing the
   //						positive conclusion to the game.  Many of the game's tiles have been
   //						loaded into dynamic memory, and the player has just completed level five.
   //postconditions:	A fancy show that involves the character rushing into the government
   //						men's headquarters on the sixth-floor basement of the complex is shown
   //						to the successful gamer.  Lard Boy slays two of the leader's guards
   //						in slow motion with his handgun, and he shatters the "king's" mobile
   //						pill jar with his gun.  The leader dies, while the leader's six
   //						"scientists" flee from the scene.  The screen mode reverts to the BGI
   //						graphics library, and the gamer's high score is shown on the screen.
   //						The program will now return to the main menu.

   void level_done();
   //preconditions:	The video card is operating on graphics mode 13h, and the user may
   //						or may not have pressed a plethora of keys.  The user's energy level
   //						spans between 0 and 396 units, inclusively.  The player consumed between
   //						zero food items and every food item in the stage, and Lard Boy has
   //						between 0 and 116 rounds of ammo remaining, inclusively.  The player
   //						has recently walked upon the "EXIT" symbol on the map.
   //postconditions:	Any keys that the gamer struck as the "level_done" function was being
   //						accessed by the computer are cleared from the keyboard cache.
   //						The player received proper bonuses from eating food, conserving ammo,
   //						and having extra energy at the time that the level ends.  The player's
   //						score is increased by the sum of the bonuses that he/she received.

   
//Structures
struct               	//The structure for the 2-D array of flying stars contains
	{                    //fields for the horizontal position of a star (integer x), the vertical	int x, y;				//location of a star (integer y), and the star's plane (character "Plane").
	char Plane;
	} Star[500];       	//"Star's" structure contains 500 copies of the three fields.



//*************************Global Variable Declaration Sector*******************
//Please note that a majority of the game's variables are global to make the transfer
//of the data between functions, function pages, classes, and the main program less
//complex.  For example, if the "display_map" function received all 60+ tiles as
//parameters, the declaration, header, and calls for the function might take up several
//lines of code and create confusion for future management teams.  Although the various
//global tiles and other arrays hog dynamic memory and can often overflow the heap, their
//format makes most functions of type "void."  Furthermore, when the functions are "void"
//and accept few or no parameters, they become more like "goto" segments.

//Food Tiles
tile turnip;
tile cake1;
tile carrot;
tile cone1;
tile cone2;
tile lemon;
tile lime;
tile popsblue;
tile popsgren;
tile sevenup;
tile sundae;
tile tomato;
tile tonicblu;
tile tonicyel;
tile butter;
tile pizza;
tile vegoil;
tile lard;
tile bacon;
tile sausage;
tile fregg;
tile pepper1;
tile grapes;
tile orange;
tile fries;
tile cherry;
tile pepper2;
tile pepper3;
tile pepper4;
tile steak;
tile pear;
tile lolipop;
tile coffee;

//Atmospheric Tiles
tile floor1;
tile block1;
tile block2;
tile crate2;
tile barrel;
tile fence1;
tile block3;
tile water;

//Character Tiles
tile cright;
tile cleft;
tile cup;
tile cdown;
tile shootr;
tile shootl;
tile shootu;
tile shootd;

//Enemy Tiles
tile spike1;
tile cbullet;
tile e1right;
tile e1left;
tile e1up;
tile e1down;
tile bunker;
tile evileye;
tile pills;
tile pillking;
tile pilldead;

//Other Items
tile ammobox;
tile exit1;

//**********************GLOBAL VARIABLE DECLARATIONS****************************
int ingame, inapp = 1;
apstring path;              //"path" contains the directory of every file in the game.
map map1(50, 50, 7, 11, 0, 0);
		//The main map for gameplay is initialized with a size of 50 rows by 50 columns
      //with 7 rows and 11 columns of the map being visible on the screen at any time.
int photo[7][11];
		//The 2-D integer array of "photo" that has 7 rows and 11 columns is capable of
      //storing a snapshot of the current screen.
int chardir, char_row, char_col;
		//"chardir" stores the direction in which Lard Boy is facing.
				//1 = right
            //2 = up
            //3 = left
            //4 = down
int energy;       //Holds Lard Boy's energy, which can range from 0 (dead) to 396 (extremely fat)
long int score;           //"score" shall contain the number of points that the player racked up, which can range from 0 to above 1,000,000.
int lives;           //Number of lives
int level;           //Player's current level
int flashstage = 1;
int finishgame = 0, finishlevel;
int ammo;           //Holds the player's ammo that is waiting to be fired.
int bullets_in_air, bupdate;
int eupdate, ebullets_in_air, ebupdate;
bullet offenfire[15];    	//This 1-D array of type "bullet" holds 15 copies of the character's bullets.
bullet efire[20];          //"efire" consists of 20 bullets that enemies may launch.
enemy fiends[65];          //The 1-D array named "fiends" can store up to 65 enemies that are based off the "enemy" class.
int foodleft, origfood;

//Initialize the BGI Graphics Library
int graphdriver = DETECT, graphmode;

unsigned char far *video_buffer = (char far *)0xA0000000L;		//Video memory is reserved for mode 13h.
int DirX = -1, DirY = 0;


//******************************************************************************************
//****************************Function Page Begins******************************************
//******************************************************************************************

void init_mode13h()
	{
   Video_Mode(MODE13H);
   }

//******************************************************************************************

void Video_Mode(int vmode)
	{
  	asm mov ah, 0
  	asm mov al, BYTE PTR vmode
  	asm int 10h
	}

//******************************************************************************************

void Plot_Pixel(int x, int y, unsigned char color)
	{
  	video_buffer[((y<<8) + (y<<6)) + x] = color;
	}

//******************************************************************************************

void Set_PalReg(int index, unsigned char red, unsigned char green, unsigned char blue)
	{
  	// Tell VGA card that a palette register will be updated
  	outportb(PALETTE_MASK, 0xff);
  	// Tell VGA card which register to update
  	outportb(PALETTE_REGISTER_WR, index);
  	// Write the red, green, and blue values for the specified index
  	// to the VGA card (the same I/O port is used each time)
  	outportb(PALETTE_DATA, red);
  	outportb(PALETTE_DATA, green);
  	outportb(PALETTE_DATA, blue);
	}

//******************************************************************************************

int Get_PalReg(int index, int color)
	{
  	int r, g, b;
  	outportb(PALETTE_MASK, 0xff);
  	outportb(PALETTE_REGISTER_RD, index);
  	r = inportb(PALETTE_DATA);
  	g = inportb(PALETTE_DATA);
  	b = inportb(PALETTE_DATA);
  	if     (color==1)
   	return r;
  	else if(color==2)
   	return g;
  	else if(color==3)
   	return b;
  	else
   	return 0;
	}

//******************************************************************************************

void draw_line(int x1, int y1, int x2, int y2, int color)
	{
  	int i;
   if(x1 == x2)
   	{
      if(y1 < y2)
	      for(i=y1; i <= y2; ++i)
         	Plot_Pixel(x1, i, color);
   	else
      	for(i=y2; i <=y1; ++i)
         	Plot_Pixel(x1, i, color);
      }
   else
   	{
      double m, b;
	   m = ((y2-y1)*1.0)/(x2-x1);
  		b = y1 - m*x1;
	  	if(abs(x2-x1) > abs(y2-y1))
   		{  // draw along x-axis
    		if(x1 < x2)
      		for(i=x1; i<=x2; ++i)
         		Plot_Pixel(i, ((m*i)+b), color);
	    	else
   	   	for(i=x2; i<=x1; ++i)
      	  		Plot_Pixel(i, ((m*i)+b), color);
	  		}
  		else
   		{  // draw along y-axis
	    	if(y1 < y2)
   	   	for(i=y1; i<=y2; ++i)
      	      Plot_Pixel(((i-b)/m), i, color);
	    	else
   	   	for (i=y2; i<=y1; ++i)
      	  		Plot_Pixel(((i-b)/m), i, color);
    		}
      }
	}

//******************************************************************************************

void draw_circle(int x, int y, int r, int color)
	{
  	int i;
   double ty;
   for(i=-r; i<=r; ++i)
   	{
    	ty = sqrt(r*r - i*i);
      Plot_Pixel((x+i), (y+ty), color);
      Plot_Pixel((x+i), (y-ty), color);
      Plot_Pixel((x+ty), (y+i), color);
      Plot_Pixel((x-ty), (y+i), color);
  		}
	}

//******************************************************************************************

void box_filled(int x1, int y1, int x2, int y2, int color)
	{
   if(y1 < y2)
	   for(int i = x1; i < x2; ++i)
   		for(int j = y1; j < y2; ++j)
      		Plot_Pixel(i, j, color);
   else
		for(int i = x1; i < x2; ++i)
   		for(int j = y2; j < y1; ++j)
      		Plot_Pixel(i, j, color);
   }

//******************************************************************************************

void box_outlined(int x1, int y1, int x2, int y2, int color)
	{
   draw_line(x1, y1, x2, y1, color);
   draw_line(x1, y2, x2, y2, color);
   draw_line(x1, y1, x1, y2, color);
   draw_line(x2, y1, x2, y2, color);
   }

//******************************************************************************************

void box_in_box(int x1, int y1, int x2, int y2, int startc, int finishc)
	{
   if(startc < finishc)
   	for(int currentc = startc; currentc <= finishc; ++currentc, --x1, --y1, ++x2, ++y2)
      	box_outlined(x1, y1, x2, y2, currentc);
   else
   	for(int currentc = startc; currentc >= finishc; --currentc, --x1, --y1, ++x2, ++y2)
      	box_outlined(x1, y1, x2, y2, currentc);
   }

//******************************************************************************************

void black_screen()
	{
   box_filled(0,0,320,200,0);
   }

//******************************************************************************************

void erase_vert(int color)
	{
   int y1, y2;
   for(y1=0, y2=200; y1 <= 100; ++y1, --y2)
   	{
      draw_line(0, y1, 320, y1, color);
      draw_line(0, y2, 320, y2, color);
      delay(10);
      }
   }

//******************************************************************************************

void fade_to_red(int slowness)
	{
   int newred;
   for(int k=0; k <= 64; ++k)
   	{
	   for(int i=1; i <= 256; ++i)
   		{
         if(Get_PalReg(i, 1) < 60)
         	newred = Get_PalReg(i, 1) + 1;
         else
         	newred = Get_PalReg(i, 1);
	      Set_PalReg(i, newred, 0, 0);
   		}
      delay(slowness);
      }
   box_filled(0,0,320,200,4);
   delay(slowness * 18);
   init_mode13h();
   }
   
//******************************************************************************************

void twod_stars(int slowness, int NBR_STARS, int MinX, int MaxX, int MinY, int MaxY)
	{	InitStars(NBR_STARS, MinX, MaxX, MinY, MaxY);
	do
   	{
  		DeleteStars(NBR_STARS);  		MoveStars(NBR_STARS, MinX, MaxX, MinY, MaxY);      DrawStars(NBR_STARS);  		WR();      delay(slowness); 		} while( !kbhit() );  	getch();	}
//******************************************************************************************

void InitStars(int NBR_STARS, int MinX, int MaxX, int MinY, int MaxY)	{
	for( int i = 0; i < NBR_STARS; i++ )
		{
		Star[ i ].x = ( rand() % (MaxX-MinX) ) + MinX;
		Star[ i ].y = ( rand() % (MaxY-MinY) ) + MinY;
		Star[ i ].Plane = rand() % 16;
	}
}

//******************************************************************************************

void DeleteStars(int NBR_STARS)	{
	for( int i = 0; i < NBR_STARS; i++ )
   	Plot_Pixel(Star[ i ].x, Star[ i ].y, 0);
	}

//******************************************************************************************

void MoveStars(int NBR_STARS, int MinX, int MaxX, int MinY, int MaxY)	{
	for( int i = 0; i < NBR_STARS; i++ )
		{
		Star[ i ].x += ( Star[ i ].Plane >> 1 ) * DirX + DirX;
		Star[ i ].y += ( Star[ i ].Plane >> 1 ) * DirY + DirY;
		if( Star[ i ].x > MaxX || Star[ i ].x < MinX ||
			Star[ i ].y > MaxY || Star[ i ].y < MinY )
  			{
			switch( DirX )
				{
				case -1:
					Star[ i ].x = MaxX;
					break;
				case 1:
					Star[ i ].x = MinX;
					break;
				case 0:
					Star[ i ].x = ( rand() % (MaxX-MinX) ) + MinX;
				}
         switch( DirY )
				{
				case -1:
					Star[ i ].y = MaxY;
					break;
				case 1:
					Star[ i ].y = MinY;
					break;
            case 0:
					Star[ i ].y = ( rand() % (MaxY-MinY) ) + MinY;
            }
			Star[ i ].Plane = rand() % 16;
			}
		}
	}

//******************************************************************************************

void DrawStars(int NBR_STARS)	{
	for( int i = 0; i < NBR_STARS; i++ )
      Plot_Pixel(Star[ i ].x, Star[ i ].y, Star[ i ].Plane + 16);
	}

//******************************************************************************************

void WR()	{
	asm mov dx, 3dah;
	WR_1:
		asm
      	{
         in al, dx
			test al, 8
			jnz WR_1
			}
	WR_2:
		asm
      	{
			in al, dx
			test al, 8
			jz WR_2
			}
	}

//******************************************************************************************

int find_speed()
	{
   int speed;
	cout<<"What is the speed of your processor\n(in Megahertz (or MHz.))?   ";
   cin>>speed;
   return speed;
   }

//******************************************************************************************

void hit_enemy()
	{
   if(map1.cell((char_row-1), char_col) == 904)
   	//If the obstacle is water, then the player dies.
   	die();
   else
   	//Otherwise, Lard Boy loses 12 energy points.
   	energy-=12;
   }

//******************************************************************************

void move_success()
	{
   if(map1.cell(char_row, char_col) == 204)
   	{
      //If the character's new slot is a box of ammunition, then Lard Boy
      //receives 15 bullets and 750 points.
      ammo+=15;
      display_ammo();
      score+=750;
      display_score();
      }
   else if(map1.cell(char_row, char_col) == 205)
   	//The level is complete once Lard Boy hits the exit.
      finishlevel = 1;
   else if(((map1.cell(char_row, char_col) / 100) > 2) && ((map1.cell(char_row, char_col) / 100) < 9))
   //When the player strikes a food item (all foods have slot values
   //ranging from the 300's up to the 800's), the "hit_item" function
   //is called to remove the item from the board, increase the gamer's
   //energy, and raise his/her score by the proper amounts.
   hit_item(map1.cell(char_row, char_col));
   }

//******************************************************************************

void clear_keys()
	{
   while(kbhit())
   	getch();
   }

//******************************************************************************

void fix_path(apstring &path)
	{
   for(int letter=0; letter < (path.length()); ++letter)
   	if(path[letter] == '\'')
      	path[letter] = '/';
   if(path[(path.length() - 1)] != '/')
   	path = path + '/';
   }

//******************************************************************************

void prompt_np()
	{
   cout<<"\t\t\tPRESS ANY KEY TO CONTINUE ON";
   getch();
   }

//******************************************************************************

void prompt_np_13h()
	{
   gotoxy(8, 25);
   cout<<"PRESS ANY KEY TO CONTINUE ON";
   getch();
   }

//******************************************************************************************

void load_files()
	{
   black_screen();
   gotoxy(8, 3);
   cout<<"Wonder Workers Presents...";
   //Print Out Left W
   draw_line(15, 165, 35, 195, 35);
   draw_line(15, 165, 30, 165, 35);
   draw_line(35, 195, 50, 195, 35);
   draw_line(30, 165, 44, 185, 35);
   draw_line(44, 185, 50, 177, 35);
   draw_line(50, 195, 58, 182, 35);
   draw_line(58, 182, 66, 195, 35);
   draw_line(50, 177, 66, 177, 35);
   draw_line(66, 177, 72, 185, 35);
   draw_line(72, 185, 86, 165, 35);
   draw_line(86, 165, 97, 165, 35);
   draw_line(66, 195, 81, 195, 35);
   draw_line(81, 195, 98, 165, 35);

   //Print Out Right W
   draw_line(222, 165, 242, 195, 35);
   draw_line(222, 165, 237, 165, 35);
   draw_line(242, 195, 257, 195, 35);
   draw_line(237, 165, 251, 185, 35);
   draw_line(251, 185, 257, 177, 35);
   draw_line(257, 195, 265, 182, 35);
   draw_line(265, 182, 273, 195, 35);
   draw_line(257, 177, 273, 177, 35);
   draw_line(273, 177, 279, 185, 35);
   draw_line(279, 185, 293, 165, 35);
   draw_line(293, 165, 304, 165, 35);
   draw_line(273, 195, 288, 195, 35);
   draw_line(288, 195, 305, 165, 35);
   box_in_box(100, 181, 220, 181, 34, 39);
   box_in_box(49, 49, 271, 150, 49, 44);
   twod_stars(25, 300, 50, 270, 50, 149);
   gotoxy(14, 22);
   cout<<"Copyright 2001";
   draw_line(85, 57, 85, 95, 42);		//L
   draw_line(85, 57, 95, 57, 42);
   draw_line(95, 57, 95, 85, 42);
   draw_line(85, 95, 110, 95, 42);
   draw_line(95, 85, 110, 85, 42);
   draw_line(110, 95, 110, 85, 42);

   draw_line(118, 95, 128, 95, 42);		//A
   draw_line(118, 95, 130, 57, 42);
   draw_line(130, 57, 142, 57, 42);
   draw_line(142, 57, 154, 95, 42);
   draw_line(154, 95, 144, 95, 42);
   draw_line(144, 95, 136, 80, 42);
   draw_line(136, 80, 128, 95, 42);
   draw_line(130, 76, 142, 76, 42);
   draw_line(130, 76, 136, 65, 42);
   draw_line(142, 76, 136, 65, 42);

   draw_line(162, 57, 162, 95, 42);		//R
   draw_line(162, 95, 172, 95, 42);
   draw_line(172, 95, 172, 82, 42);
   draw_line(162, 57, 195, 57, 42);
   draw_line(195, 57, 195, 72, 42);
   draw_line(195, 72, 172, 72, 42);
   draw_line(172, 72, 195, 95, 42);
   draw_line(172, 82, 185, 95, 42);
   draw_line(195, 95, 185, 95, 42);
   draw_line(172, 62, 190, 62, 42);
   draw_line(190, 62, 190, 67, 42);
   draw_line(190, 67, 172, 67, 42);
   draw_line(172, 67, 172, 62, 42);

   draw_line(203, 57, 203, 95, 42);		//D
   draw_line(203, 57, 222, 66, 42);
   draw_line(203, 95, 222, 85, 42);
   draw_line(222, 66, 222, 85, 42);
   draw_line(208, 63, 208, 87, 42);
   draw_line(208, 63, 217, 76, 42);
   draw_line(208, 87, 217, 76, 42);

   draw_line(105, 105, 105, 143, 42);		//B
   draw_line(105, 105, 115, 105, 42);
   draw_line(105, 143, 115, 143, 42);
   draw_line(115, 105, 130, 118, 42);
   draw_line(115, 143, 130, 129, 42);
   draw_line(130, 118, 115, 124, 42);
   draw_line(130, 129, 115, 124, 42);

	draw_circle(156, 124, 19, 42);		//O
   draw_circle(156, 124, 9, 42);

   draw_line(183, 105, 193, 105, 42);	//Y
   draw_line(205, 105, 215, 105, 42);
   draw_line(193, 105, 199, 120, 42);
   draw_line(205, 105, 199, 120, 42);
   draw_line(183, 105, 194, 130, 42);
   draw_line(215, 105, 204, 130, 42);
   draw_line(194, 130, 194, 143, 42);
   draw_line(204, 130, 204, 143, 42);
   draw_line(194, 143, 204, 143, 42);

   getch();
   fade_to_red(20);
   gotoxy(16, 2);
   cout<<"Lard Boy";
   gotoxy(2, 5);
   cout<<"Enter the path for the game's files:\n ";
   cin>>path;
   fix_path(path);
   box_filled(0, 20, 319, 60, 0);
   box_filled(41, 35, 238, 42, 4);
   gotoxy(2, 4);
   cout<<"Loading Foods: ";
   cone1.load_stamp(path + "cone1.til");
   box_filled(41, 35, 46, 42, 43);
   pepper4.load_stamp(path + "pepper4.til");
   box_filled(47, 35, 52, 42, 43);
   cake1.load_stamp(path + "cake1.til");
   box_filled(53, 35, 58, 42, 43);
   carrot.load_stamp(path + "carrot.til");
   box_filled(59, 35, 64, 42, 43);
   turnip.load_stamp(path + "turnip.til");
   box_filled(65, 35, 70, 42, 43);
   cone2.load_stamp(path + "cone2.til");
   box_filled(71, 35, 76, 42, 43);
   lemon.load_stamp(path + "lemon.til");
   box_filled(77, 35, 82, 42, 43);
   lime.load_stamp(path + "lime.til");
   box_filled(83, 35, 88, 42, 43);
   popsblue.load_stamp(path + "popsblue.til");
   box_filled(89, 35, 94, 42, 43);
   popsgren.load_stamp(path + "popsgren.til");
   box_filled(95, 35, 100, 42, 43);
   steak.load_stamp(path + "steak.til");
   box_filled(101, 35, 106, 42, 43);
   sevenup.load_stamp(path + "sevenup.til");
   box_filled(107, 35, 112, 42, 43);
   sundae.load_stamp(path + "sundae.til");
   box_filled(113, 35, 118, 42, 43);
   tomato.load_stamp(path + "tomato.til");
   box_filled(119, 35, 124, 42, 43);
   tonicblu.load_stamp(path + "tonicblu.til");
   box_filled(125, 35, 130, 42, 43);
   tonicyel.load_stamp(path + "tonicyel.til");
   box_filled(131, 35, 136, 42, 43);
   cherry.load_stamp(path + "cherry.til");
   box_filled(137, 35, 142, 42, 43);
   coffee.load_stamp(path + "coffee.til");
   box_filled(143, 35, 148, 42, 43);
   fries.load_stamp(path + "fries.til");
   box_filled(149, 35, 154, 42, 43);
   orange.load_stamp(path + "orange.til");
   box_filled(155, 35, 160, 42, 43);
   grapes.load_stamp(path + "grapes.til");
   box_filled(161, 35, 166, 42, 43);
   pepper1.load_stamp(path + "pepper1.til");
   box_filled(167, 35, 172, 42, 43);
   fregg.load_stamp(path + "fregg.til");
   box_filled(173, 35, 178, 42, 43);
   pear.load_stamp(path + "pear.til");
   box_filled(179, 35, 184, 42, 43);
   sausage.load_stamp(path + "sausage.til");
   box_filled(185, 35, 190, 42, 43);
   bacon.load_stamp(path + "bacon.til");
   box_filled(191, 35, 196, 42, 43);
   lard.load_stamp(path + "lard.til");
   box_filled(197, 35, 202, 42, 43);
   vegoil.load_stamp(path + "vegoil.til");
   box_filled(203, 35, 208, 42, 43);
   lolipop.load_stamp(path + "lolipop.til");
   box_filled(209, 35, 214, 42, 43);
   pizza.load_stamp(path + "pizza.til");
   box_filled(215, 35, 220, 42, 43);
   butter.load_stamp(path + "butter.til");
   box_filled(221, 35, 226, 42, 43);
   pepper2.load_stamp(path + "pepper2.til");
   box_filled(227, 35, 232, 42, 43);
   pepper3.load_stamp(path + "pepper3.til");
   box_filled(233, 35, 238, 42, 43);
   cout<<"Complete";

   box_filled(41, 60, 154, 67, 4);
   gotoxy(2, 7);
   cout<<"Loading Characters/Enemies: ";
   cright.load_stamp(path + "cright.til");
   box_filled(41, 60, 46, 67, 43);
   cleft.load_stamp(path + "cleft.til");
   box_filled(47, 60, 52, 67, 43);
   cup.load_stamp(path + "cup.til");
   box_filled(53, 60, 58, 67, 43);
   cdown.load_stamp(path + "cdown.til");
   box_filled(59, 60, 64, 67, 43);
   shootd.load_stamp(path + "shootd.til");
   box_filled(65, 60, 70, 67, 43);
   cbullet.load_stamp(path + "cbullet.til");
   box_filled(71, 60, 76, 67, 43);
   spike1.load_stamp(path + "spike1.til");
   box_filled(77, 60, 82, 67, 43);
   shootr.load_stamp(path + "shootr.til");
   box_filled(83, 60, 88, 67, 43);
   shootl.load_stamp(path + "shootl.til");
   box_filled(89, 60, 94, 67, 43);
   shootu.load_stamp(path + "shootu.til");
   box_filled(95, 60, 100, 67, 43);
   e1right.load_stamp(path + "e1right.til");
   box_filled(101, 60, 106, 67, 43);
   e1left.load_stamp(path + "e1left.til");
   box_filled(107, 60, 112, 67, 43);
   e1up.load_stamp(path + "e1up.til");
   box_filled(113, 60, 118, 67, 43);
   e1down.load_stamp(path + "e1down.til");
   box_filled(119, 60, 124, 67, 43);
   bunker.load_stamp(path + "bunker.til");
   box_filled(125, 60, 130, 67, 43);
   evileye.load_stamp(path + "evileye.til");
   box_filled(131, 60, 136, 67, 43);
   pills.load_stamp(path + "pills.til");
   box_filled(137, 60, 142, 67, 43);
   pillking.load_stamp(path + "pillking.til");
   box_filled(143, 60, 148, 67, 43);
   pilldead.load_stamp(path + "pilldead.til");
   box_filled(149, 60, 154, 67, 43);
   cout<<"Complete";

   box_filled(41, 85, 100, 92, 4);
   gotoxy(2, 10);
   cout<<"Loading Atmosphere: ";
   ammobox.load_stamp(path + "ammobox.til");
   box_filled(41, 85, 46, 92, 43);
   block1.load_stamp(path + "block1.til");
   box_filled(47, 85, 52, 92, 43);
   block2.load_stamp(path + "block2.til");
   box_filled(53, 85, 58, 92, 43);
   water.load_stamp(path + "water.til");
   box_filled(59, 85, 64, 92, 43);
   crate2.load_stamp(path + "crate2.til");
   box_filled(65, 85, 70, 92, 43);
   barrel.load_stamp(path + "barrel.til");
   box_filled(71, 85, 76, 92, 43);
   floor1.load_stamp(path + "floor1.til");
   box_filled(77, 85, 82, 92, 43);
   fence1.load_stamp(path + "fence1.til");
   box_filled(83, 85, 88, 92, 43);
   block3.load_stamp(path + "block3.til");
   box_filled(89, 85, 94, 92, 43);
   exit1.load_stamp(path + "exit.til");
   box_filled(95, 85, 100, 92, 43);
   cout<<"Complete";
	getch();
   fade_to_red(30);
   }

//******************************************************************************

void display_template()
	{
   int r, c, index;
   int enemies_in_map=0;
	clear_keys();
   for(r=0; r < 7; ++r)
   	for(c=0; c < 11; ++c)
      	photo[r][c] = 0;
   bullets_in_air = 0;
	bupdate = 0;
   eupdate = 0;
   ebullets_in_air = 0;
   ebupdate = 0;
   finishlevel = 0;
   for(index=0; index < 15; ++index)
   	offenfire[index].change_on(0);
   for(index=0; index < 65; ++index)
   	fiends[index].change_on(0);
   for(index=0; index < 20; ++index)
   	efire[index].change_on(0);
   energy = 320;
   initgraph(&graphdriver, &graphmode, path.c_str());
   gotoxy(15, 10);
   setcolor(13);
   settextstyle(9, 0, 4);
   outtextxy(170, 150, "Stage ");
   switch (level)
   	{
      case 1:	outtextxy(340, 150, "One");
      			map1.load_map((path + "level1.map"), foodleft, origfood);
               break;
      case 2:  outtextxy(340, 150, "Two");
               map1.load_map((path + "level2.map"), foodleft, origfood);
   	         break;
      case 3:  outtextxy(340, 150, "Three");
               map1.load_map((path + "level3.map"), foodleft, origfood);
               break;
      case 4:  outtextxy(340, 150, "Four");
               map1.load_map((path + "level4.map"), foodleft, origfood);
   	         break;
      case 5:  outtextxy(340, 150, "Five");
               map1.load_map((path + "level5.map"), foodleft, origfood);
      }
   for(r=0; r < 50; ++r)
   	for(c=0; c < 50; ++c)
      	if(map1.cell(r, c) > 910)
         	{
            fiends[enemies_in_map].change_on(1);
            if(map1.cell(r, c) < 920)
            	{
	            fiends[enemies_in_map].change_type(1);
	            fiends[enemies_in_map].change_dir(map1.cell(r, c) - 910);
               }
            else if(map1.cell(r, c) < 930)
	            fiends[enemies_in_map].change_type(2);
            else if(map1.cell(r, c) < 940)
	            fiends[enemies_in_map].change_type(3);
            else if(map1.cell(r, c) < 950)
	            fiends[enemies_in_map].change_type(4);
            fiends[enemies_in_map].change_col(c);
            fiends[enemies_in_map].change_row(r);
            ++enemies_in_map;
         	}
   settextstyle(8, 0, 5);
   while(! kbhit())
   	{
      if(flashstage == 1)
        	{
         flashstage = 2;
         setcolor(1);
         }
      else
      	{
         flashstage = 1;
         setcolor(4);
         }
      outtextxy(80, 410, "Press Enter to Start!");
      delay(150);
      }
   getch();
   cleardevice();
   init_mode13h();
   finishlevel = 0;
   map1.ch_row_start(43);
   map1.ch_col_start(0);
   display_map(43, 0, 1);		//The map is displayed in its default position (i.e., the version of the map that the level always begins with) with the camera on.
   chardir = 1;
   char_row = 46;
   char_col = 5;
   ammo = 40;
   display_panels();
   }

//******************************************************************************************

void display_panels()
	{
   box_in_box(9, 9, 230, 150, 30, 21);
   gotoxy(35, 3);
   cout<<"Save";
   gotoxy(35, 6);
   cout<<"Quit";
   gotoxy(33, 9);
   cout<<"Return";
   gotoxy(33, 10);
   cout<<"To Game";
   box_in_box(267, 12, 306, 25, 40, 43);
   box_in_box(267, 37, 306, 50, 40, 43);
   box_in_box(252, 61, 313, 81, 40, 43);
   gotoxy(34, 16);  
   cout<<"SCORE";
   gotoxy(4, 22);
   cout<<"ENERGY";
   gotoxy(4, 25);
   cout<<"LIVES:";
   gotoxy(17, 25);
   cout<<"FOOD LEFT:";
   gotoxy(31, 21);
   cout<<"AMMO";
   energy_bars();
   display_score();
   display_ammo();
   display_lives();
   display_fleft();
   }

//******************************************************************************************

int title_screen()
	{
   int madechoice, current_choice;
   int exitmenu = 0;
   int keycode;
   black_screen();
   while(exitmenu == 0)
   	{
      initgraph(&graphdriver, &graphmode, path.c_str());
      madechoice = 0;
	   current_choice = 0;
		setcolor(10);
		settextstyle(10,0,3);
		outtextxy(220, 30, "Main Menu");
   	setcolor(5);
	   rectangle(100, 100, 600, 385);
   	rectangle(103, 103, 597, 382);
	   rectangle(106, 106, 594, 379);
		setcolor(2);
		settextstyle(7,0,7);
      outtextxy(190, 400, "Lard Boy");
		setcolor(15);
		settextstyle(2,0,9);
      outtextxy(150, 380, "Created By: Ryan Lloyd");
		setcolor(9);
		settextstyle(6,0,5);
		outtextxy(160, 110, "Play Full Game");
		outtextxy(160, 150, "Load Game");
		outtextxy(160, 190, "Instructions");
		outtextxy(160, 230, "Catalog of Items");
   	outtextxy(160, 270, "Quit to Windows");
	   setcolor(14);
   	outtextxy(130, 110, ">");
	   while(madechoice == 0)
   		{
     	 	if(kbhit())
      		{
	         keycode = getch();
   	      if(keycode == 56)
      	   	{
         	   setcolor(0);
            	outtextxy(130, (110 + (current_choice * 40)), ">");
	            if(current_choice == 0)
   	            current_choice = 4;
      	      else
         	   	--current_choice;
            	setcolor(14);
	            outtextxy(130, (110 + (current_choice * 40)), ">");
   	         }
      	   else if(keycode == 50)
         		{
            	setcolor(0);
	            outtextxy(130, (110 + (current_choice * 40)), ">");
   	         if(current_choice == 4)
      	      	current_choice = 0;
         	   else
            		++current_choice;
	            setcolor(14);
   	         outtextxy(130, (110 + (current_choice * 40)), ">");
      	      }
         	else if((keycode == 13) || (keycode == 32))
            	madechoice = 1;
	         }
     	   }
      switch(current_choice)
      	{
         case 0:	exitmenu = 1;
         			break;
         case 1:	if(load_game_menu() == 1)
							exitmenu = 1;
         			break;
         case 2:  instructions();
         			break;
         case 3:  foodcat();
         			break;
         case 4:	exitmenu = 1;
         			inapp = 0;
         }
		}
   init_mode13h();
   black_screen();
   return current_choice;
   }

//******************************************************************************************

void instructions()
	{
   ////////////////////////////Instructions for Lard Boy////////////////////////////////
   cleardevice();
   ///////////////////////////////////Story/////////////////////////////////////////////
   setcolor(12);
   settextstyle(10, 0, 3);
   outtextxy(60, 20, "GAME INSTRUCTIONS: Story");
	cout<<"\n\n\n\n\n\n\n     Lard Boy--a heavyset, Southern farmer--strolls into his barn one day while\nsearching for a rake.  He walks past the U.S. Government's biological\nexperiments on the DNA of humans and goods produced on his farm.\n";
   cout<<"     The government pays Lard Boy over $250,000.00 per year to simply lend out\nhis barn and various farming tools to the scientists, assuming that the\ndirty Southern man keeps quiet about the outcome of any experiments.  The\nthree to seven psychotic government men who ran the tests dealing with\nheavy doses of radiation and highly advanced chemical solutions were attempting\nto create a new category of \"super produce.\"  The sinister men injected\ncows with yard fertilizers to double their sizes within days, and the\nworkers played with small nuclear bombs of low-grade uranium in a series of\nbunkers under the barn to create 500-pound tomatoes.  The scientists even spliced Lard Boy's DNA strands with those of sheep to form gray-shaded\nrednecks with violent impulses.  The zombie-like copies of Lard Boy, with\n\n\n\n";
	prompt_np();
   clrscr();
   cleardevice();
   ///////////////////////////////////Story, Continued...///////////////////////////////
   outtextxy(60, 20, "GAME INSTRUCTIONS: Story");
   cout<<"\n\n\n\n\n\n\nthe help of the American Government's robotic hovercrafts, recently tried\nto capture several of Lard Boy's children for test subjects in human-to-\nmachine trials.  Fortunately, the African American youths gashed at the fiends\nwith a pitchfork and fled from the grasp of the murderous creatures.\nAfter seven years of non-stop work, the biologists had developed dozens of\nvegetables and livestock hybrids that could be grown in the average\nfield.  The government workers had suddenly disappeared from the complex over\nthree weeks ago.\n";
	cout<<"    Lard Boy squeezes through a string of horse stalls and pushes his gut past a table covered with test tubes, rotting food, and jars of pills,\nknocking over the table.  As he ventures down into a steamy nuclear fallout\nshelter beneath the barn that he built during the 1960's, the heat and\nradiation-proof door that covers the shelter snaps shut.  The Southern man\nflicks on a bare light bulb and clumsily loads his handgun.  The floor under\nLard Boy suddenly collapses, and he finds himself in a vast, underground\nlab that the scientists must have constucted.  Armed with only his rusty\ngun and aware of the rumors that the government men turned into jars of red,\nblue, and yellow-colored pills, Lard Boy sets out to find the missing\ngovernment workers.  The scientists, however, have other plans...\n\n\n";
	prompt_np();
   clrscr();
   cleardevice();
   ///////////////////////////////////Objectives/////////////////////////////////////////
   outtextxy(30, 20, "GAME INSTRUCTIONS: Objectives");
	cout<<"\n\n\n\n\n\n\n     To successfully finish the game, you must guide Lard Boy through five\nfloors of the secret laboratory.  The leader of the governmental scientists--\nan evil jar of pills with a crown on its head, along with the other biologists\n(or jars of pills), lie heavily guarded on the sixth level of the\nsubterranean building.  While on his quest, Lard Boy will encounter hundreds\nof enemies, some of which are extremely smart.  All of the enemies, with\nthe exception of water and spikes, can be killed with a single shot from\nthe hick's gun.  Once the Southern redneck reaches the door to the next\nstage and thus completes the current level, he will have the opportunity to\nreceive bonuses.  Lard Boy receives 12 points for every cell of energy\nthat remains, 150 points for each food item that he gathered, and 50 points\nfor every remaining shell of ammunition.  If Lard Boy collects every food\nitem in the level, then he will receive a 25,000-point bonus.\n\n\n";
	prompt_np();
   clrscr();
   cleardevice();
   ///////////////////////////////////Enemies///////////////////////////////////////////
   init_mode13h();
   gotoxy(7, 2);
   cout<<"GAME INSTRUCTIONS: Enemies";
	e1right.display_stamp(20, 30);
	bunker.display_stamp(20, 55);
	evileye.display_stamp(20, 80);
	spike1.display_stamp(20, 105);
	pills.display_stamp(20, 130);
	pillking.display_stamp(20, 155);
	cbullet.display_stamp(20, 180);
   gotoxy(7, 5);
   cout<<"Sheep-Human Copy of Lard Boy";
   gotoxy(7, 6);
   cout<<"300 Points per Kill";
   gotoxy(7, 9);
   cout<<"Sandbag-reinforced Bunker";
   gotoxy(7, 10);
   cout<<"250 Points per Kill";
   gotoxy(7, 12);
   cout<<"Robotic Hovercraft";
   gotoxy(7, 13);
   cout<<"1,000 Points per Kill";
   gotoxy(7, 15);
   cout<<"Metal Spike--Immortal";
   gotoxy(7, 18);
   cout<<"Government Scientist in Jar Form";
   gotoxy(7, 19);
   cout<<"500 Points per Kill";
   gotoxy(7, 21);
   cout<<"Leader of the Scientists/Pill King";
   gotoxy(7, 22);
   cout<<"50000 Points per Kill";
   gotoxy(7, 25);
   cout<<"Bullet of Lard Boy and Enemies";
   getch();
	black_screen();
   ///////////////////////////////////Atmosphere///////////////////////////////////////
   gotoxy(3, 2);
   cout<<"GAME INSTRUCTIONS: Game's Atmosphere";
   ammobox.display_stamp(20, 40);
   gotoxy(8, 6);
   cout<<"Box of Ammunition -- 15 Extra";
   gotoxy(8, 7);
	cout<<"Rounds -- 750 Points";
   exit1.display_stamp(20, 80);
   gotoxy(8, 11);
   cout<<"Level's Exit -- Located far from";
   gotoxy(8, 12);
   cout<<"Lard Boy's starting position";
   gotoxy(16, 14);
   cout<<"OBSTACLES";
   block1.display_stamp(10, 120);
   block2.display_stamp(10, 145);
   water.display_stamp(10, 170);
   gotoxy(5, 17);
   cout<<"Metal Brick";
   gotoxy(5, 20);
   cout<<"Concrete Brick";
   gotoxy(5, 23);
   cout<<"Water";
   crate2.display_stamp(155, 120);
   barrel.display_stamp(155, 145);
   fence1.display_stamp(155, 170);
   gotoxy(23, 17);
   cout<<"Crate";
   gotoxy(23, 20);
   cout<<"Barrel";
   gotoxy(23, 23);
   cout<<"Fence";
   block3.display_stamp(230, 120);
   gotoxy(33, 17);
   cout<<"Plastic";
	gotoxy(33, 18);
   cout<<"Brick";
	prompt_np_13h();
	black_screen();
   ///////////////////////////////////Controls///////////////////////////////////////
   initgraph(&graphdriver, &graphmode, path.c_str());
   setcolor(12);
   settextstyle(10, 0, 3);
   outtextxy(80, 20, "GAME INSTRUCTIONS: Keys");
   setcolor(2);
   settextstyle(6, 0, 3);
   outtextxy(10, 100, "Space Bar = Fire Weapon/Confirm Option");
   outtextxy(10, 130, "Enter = Confirm Option");
   outtextxy(10, 160, "Escape = Access Pause Sector");
   outtextxy(10, 190, "P / p = Pause Game Play");
   setcolor(14);
   settextstyle(8, 0, 3);
   outtextxy(10, 250, "Directional Controls");
   setcolor(4);
   rectangle(320, 260, 500, 460);
   rectangle(380, 260, 440, 460);
   rectangle(320, 327, 500, 394);
   setcolor(1);
   outtextxy(337, 275, "7    8    9");
   outtextxy(337, 341, "4    5    6");
   outtextxy(337, 407, "1    2    3");
   setcolor(2);
   settextstyle(6, 0, 3);
   outtextxy(60, 300, "8 = Move UP");
   outtextxy(60, 340, "2 = Shift DOWN");
   outtextxy(60, 380, "4 = Move LEFT");
   outtextxy(60, 420, "6 = Shift RIGHT");
   getch();
   cleardevice();
   }

//******************************************************************************************

void foodcat()
	{
   cleardevice();
   init_mode13h();
   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	cherry.display_stamp(50, 40);
	grapes.display_stamp(50, 70);
	orange.display_stamp(50, 100);
	tomato.display_stamp(50, 130);
	lemon.display_stamp(50, 160);
	gotoxy(10, 7);
	cout<<"Cherries   300        6";
	gotoxy(10, 11);
	cout<<"Grapes      25        2";
	gotoxy(10, 15);
	cout<<"Orange     100        2";
	gotoxy(10, 18);
	cout<<"Tomato      15        2";
	gotoxy(10, 22);
	cout<<"Lemon       50        2";
	prompt_np_13h();
	black_screen();

   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	lime.display_stamp(50, 40);
	pear.display_stamp(50, 70);
	pepper1.display_stamp(50, 100);
	turnip.display_stamp(50, 130);
	carrot.display_stamp(50, 160);
	gotoxy(10, 7);
	cout<<"Lime        70        2";
	gotoxy(10, 11);
	cout<<"Pear       270        6";
	gotoxy(10, 15);
	cout<<"Hot Pepper 300        6";
	gotoxy(10, 18);
	cout<<"Turnip     100        2";
	gotoxy(10, 22);
	cout<<"Carrot      10        2";
	prompt_np_13h();
	black_screen();

   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	pepper2.display_stamp(50, 40);
	pepper3.display_stamp(50, 70);
	pepper4.display_stamp(50, 100);
	cake1.display_stamp(50, 130);
	cone1.display_stamp(50, 160);
	gotoxy(10, 7);
	cout<<"B. Pepper  100        2";
	gotoxy(10, 11);
	cout<<"B. Pepper  300        6";
	gotoxy(10, 15);
	cout<<"B. Pepper  500        10";
	gotoxy(10, 18);
	cout<<"Cake       750        8";
	gotoxy(10, 22);
	cout<<"Cone #1    800        8";
	prompt_np_13h();
	black_screen();

   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	cone2.display_stamp(50, 40);
	popsblue.display_stamp(50, 70);
	popsgren.display_stamp(50, 100);
	lolipop.display_stamp(50, 130);
	sevenup.display_stamp(50, 160);
	gotoxy(10, 7);
	cout<<"Cone #2   1000        10";
	gotoxy(10, 11);
	cout<<"Popsicle   900        9";
	gotoxy(10, 15);
	cout<<"Popsicle  1100        11";
	gotoxy(10, 18);
	cout<<"Lollipop   850        8";
	gotoxy(10, 22);
	cout<<"7-Up Can   150        2";
	prompt_np_13h();
	black_screen();

   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	tonicblu.display_stamp(50, 40);
	tonicyel.display_stamp(50, 70);
	coffee.display_stamp(50, 100);
	sundae.display_stamp(50, 130);
	pizza.display_stamp(50, 160);
	gotoxy(10, 7);
	cout<<"Tonic #1   600        6";
	gotoxy(10, 11);
	cout<<"Tonic #2   520        5";
	gotoxy(10, 15);
	cout<<"Coffee      30        1";
	gotoxy(10, 18);
	cout<<"Sundae    1500        15";
	gotoxy(10, 22);
	cout<<"Pizza     2000        20";
	prompt_np_13h();
	black_screen();

   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	sausage.display_stamp(50, 40);
	fregg.display_stamp(50, 70);
	fries.display_stamp(50, 100);
	steak.display_stamp(50, 130);
	butter.display_stamp(50, 160);
	gotoxy(10, 7);
	cout<<"Sausage   1200        12";
	gotoxy(10, 11);
	cout<<"F. Egg     700        7";
	gotoxy(10, 15);
	cout<<"Fries     1400        14";
	gotoxy(10, 18);
	cout<<"Steak     1600        16";
	gotoxy(10, 22);
	cout<<"Butter    3000        30";
	prompt_np_13h();
	black_screen();

   gotoxy(8, 4);
	cout<<"ITEM"<<setw(12)<<"POINTS"<<setw(12)<<"ENERGY";
	vegoil.display_stamp(50, 40);
	lard.display_stamp(50, 70);
	bacon.display_stamp(50, 100);
	gotoxy(10, 7);
	cout<<"V. Oil    4000        40";
	gotoxy(10, 11);
	cout<<"Lard      5000        50";
	gotoxy(10, 15);
	cout<<"Bacon     3700        37";
	prompt_np_13h();
	black_screen();
   }

//******************************************************************************************

int pause()
	{
   int currentopt = 0, madechoice = 0;
   int keycode;
   box_in_box(267, 12, 306, 25, 48, 45);
   box_outlined(245, 4, 319, 90, 35);
   while(madechoice == 0)
   	{
      if(kbhit())
      	{
         keycode = getch();
         if((keycode == 32) || (keycode == 13))
         	madechoice = 1;
         else if(keycode == 27)
         	{
            madechoice = 1;
            currentopt = 3;
            }
         else if((keycode == 56) && (currentopt > 0))
         	--currentopt;
         else if((keycode == 50) && (currentopt < 2))
         	++currentopt;
         if((keycode == 50) || (keycode == 56))
         	{
            box_in_box(267, 12, 306, 25, 40, 43);
			   box_in_box(267, 37, 306, 50, 40, 43);
			   box_in_box(252, 61, 313, 81, 40, 43);
            switch (currentopt)
            	{
               case 0: box_in_box(267, 12, 306, 25, 48, 45);
               	     break;
               case 1: box_in_box(267, 37, 306, 50, 48, 45);
                       break;
               case 2: box_in_box(252, 61, 313, 81, 48, 45);
               }
            }
         }
      }
   if(currentopt == 0)
      save_game_menu();
   else if(currentopt == 1)
   	ingame = 0;
   else
   	{
   	box_in_box(267, 12, 306, 25, 40, 43);
	   box_in_box(267, 37, 306, 50, 40, 43);
   	box_in_box(252, 61, 313, 81, 40, 43);
      box_outlined(245, 4, 319, 90, 0);
      }
	return currentopt;
   }

//******************************************************************************************

void energy_bars()
	{
   if(energy > 396)
   	energy = 396;
   if(energy > 0)
   	{
	   draw_line(2, 180, (energy / 2), 180, 15);
	   draw_line(2, 179, (energy / 2), 179, 12);
	   draw_line(2, 181, (energy / 2), 181, 12);
	   draw_line(2, 178, (energy / 2), 178, 4);
	   draw_line(2, 182, (energy / 2), 182, 4);
   	}
   box_filled(((energy / 2) + 1), 178, 199, 183, 0);
   if(energy < 0)
   	die();
   }

//******************************************************************************************

void display_ammo()
	{
   int bcounter, ammox, ammoy;
   if(ammo > 116)
   	ammo = 116;
   for(bcounter=1, ammox=200, ammoy=170; bcounter<=ammo; ++bcounter, ammox=ammox+4)
   	{
   	if(ammox>315)
      	{
         ammox=200;
         ammoy=ammoy+6;
         }
      box_outlined(ammox, ammoy, (ammox+1), (ammoy+3), 43);
      }
   ammox-=4;
   while(bcounter <= 100)
   	{
      ammox+=4;
      ++bcounter;
      if(ammox>315)
      	{
         ammox=200;
         ammoy=ammoy+6;
         }
      box_outlined(ammox, ammoy, (ammox+1), (ammoy+3), 0);
      }
   }

//******************************************************************************************

void hit_item(int itemval)
{
int tilecat;
--foodleft;
display_fleft();
tilecat = itemval / 100;
if(tilecat == 3)		//Fruits
	switch (itemval)
   	{
      case 300:	score+=300;
      				energy+=6;
      				break;
   	case 301:	score+=25;
      				energy+=2;
            		break;
      case 302:	score+=100;
      				energy+=2;
            		break;
      case 303:	score+=15;
      				energy+=2;
      				break;
      case 304:	score+=50;
      				energy+=2;
      				break;
      case 305:	score+=70;
      				energy+=2;
      				break;
      case 306:   score+=270;
      				energy+=6;
      }
else if(tilecat == 4)		//Vegetables
	switch (itemval)
   	{
      case 400:	score+=300;
      				energy+=6;
      				break;
      case 401:	score+=100;
      				energy+=2;
   					break;
      case 402:	score+=10;
      				energy+=2;
      				break;
      case 403:	score+=100;
      				energy+=2;
      				break;
      case 404:	score+=300;
      				energy+=6;
      				break;
      case 405:	score+=500;
      				energy+=10;
      }
else if(tilecat == 5)		//Candy / Baked Goods
	switch (itemval)
   	{
      case 500:	score+=750;
      				energy+=8;
      				break;
      case 501:	score+=800;
      				energy+=8;
      				break;
      case 502:	score+=1000;
      				energy+=10;
      				break;
      case 503:	score+=900;
      				energy+=9;
      				break;
      case 504:	score+=1100;
      				energy+=11;
      				break;
      case 505:	score+=850;
      				energy+=8;
      }
else if(tilecat == 6)		//Drinks
	switch (itemval)
   	{
      case 600:	score+=150;
      				energy+=2;
      				break;
      case 601:	score+=600;
      				energy+=6;
      				break;
      case 602:	score+=520;
      				energy+=5;
      				break;
      case 603:	score+=30;
      				energy+=1;
      }
else if(tilecat == 7)		//Fast Food
	switch (itemval)
   	{
      case 700:	score+=1500;
      				energy+=15;
      				break;
      case 701:	score+=2000;
      				energy+=20;
      				break;
      case 702:	score+=1200;
      				energy+=12;
      				break;
      case 703:	score+=700;
      				energy+=7;
      				break;
      case 704:	score+=1400;
      				energy+=14;
      				break;
      case 705:	score+=1600;
      				energy+=16;
      }
else if(tilecat == 8)		//Total Fat
	switch (itemval)
   	{
      case 800:	score+=3000;
      				energy+=30;
      				break;
      case 801:	score+=4000;
      				energy+=40;
            		break;
      case 802:	score+=5000;
      				energy+=50;
            		break;
      case 803:	score+=3700;
      				energy+=37;
      }
display_score();
energy_bars();
}

//******************************************************************************************

void die()
	{
   for(int rev=0; rev < 4; ++rev)
   	{
		cright.display_stamp(110, 70);
   	delay(180);
		cdown.display_stamp(110, 70);
   	delay(180);
		cleft.display_stamp(110, 70);
   	delay(180);
		cup.display_stamp(110, 70);
   	delay(180);
      }
   fade_to_red(27);
   --lives;
   if(lives < 0)
   	gameover();
   else
      display_template();
   }

//******************************************************************************************

void gameover()
	{
   int r, c, frame;
   int cirx, ciry, radius;
   clear_keys();
   for(r=0; r < 10; ++r)
   	for(c=0; c < 16; ++c)
      	floor1.display_stamp((c*20), (r*20));
   for(r=7; r < 10; ++r)
		for(c=0; c < 5; ++c)
      	{
      	water.display_stamp((c*20), (r*20));
      	water.display_stamp(((16-c)*20), (r*20));
         }
   for(r=7; r < 10; ++r)
   	{
   	spike1.display_stamp(120, (r*20));
   	spike1.display_stamp(200, (r*20));
      }
   pills.display_stamp(120, 80);
   pills.display_stamp(120, 60);
   pills.display_stamp(120, 40);
   pills.display_stamp(200, 80);
   pills.display_stamp(200, 60);
   pills.display_stamp(200, 40);
   pillking.display_stamp(160, 20);
   for(frame=0; frame < 6; ++frame)
   	{
      cup.display_stamp(160, 160 - (frame * 20));
      evileye.display_stamp(140, 160 - (frame * 20));
      evileye.display_stamp(180, 160 - (frame * 20));
      evileye.display_stamp(160, 180 - (frame * 20));
      floor1.display_stamp(140, 180 - (frame * 20));
      floor1.display_stamp(180, 180 - (frame * 20));
      if(frame > 0)
	      floor1.display_stamp(160, 200 - (frame * 20));
      delay(800);
      }
   floor1.display_stamp(140, 60);
   floor1.display_stamp(180, 60);
   for(frame=4; frame >= 0; --frame)
   	{
      floor1.display_stamp(140, 160 - (frame * 20));
      floor1.display_stamp(160, 160 - (frame * 20));
      floor1.display_stamp(180, 160 - (frame * 20));
      evileye.display_stamp(140, 160 - ((frame - 1) * 20));
	   evileye.display_stamp(160, 160 - ((frame - 1)* 20));
      evileye.display_stamp(180, 160 - ((frame - 1)* 20));
      delay(650);
      }
   floor1.display_stamp(140, 160 - (frame * 20));
   floor1.display_stamp(160, 160 - (frame * 20));
   floor1.display_stamp(180, 160 - (frame * 20));

   floor1.display_stamp(120, 80);
   floor1.display_stamp(120, 60);
   floor1.display_stamp(120, 40);
   floor1.display_stamp(200, 80);
   floor1.display_stamp(200, 60);
   floor1.display_stamp(200, 40);
   floor1.display_stamp(160, 20);
   pills.display_stamp(140, 80);
   pills.display_stamp(140, 60);
   pills.display_stamp(140, 40);
   pills.display_stamp(180, 80);
   pills.display_stamp(180, 60);
   pills.display_stamp(180, 40);
   pillking.display_stamp(160, 40);
   clear_keys();
   while(! kbhit())
   	{
  		radius = rand() % 10;
      cirx = rand() % 20;
      ciry = rand() % 20;
      draw_circle((cirx + 163), (ciry + 58), radius, 4);
      delay(350);
      }
   getch();
   erase_vert(40);
   erase_vert(0);
   erase_vert(4);
   erase_vert(0);
   initgraph(&graphdriver, &graphmode, path.c_str());
   delay(500);
   ingame = 0;
   cleardevice();
   setcolor(11);
   settextstyle(10, 0, 7);
   outtextxy(25,100, "GAME OVER");
   setcolor(1);
   settextstyle(8, 0, 7);
   outtextxy(160,240, "Top Score");
   gotoxy(39,22);
   cout<<score;
   getch();
   }

//******************************************************************************************

void update_char_bullets()
	{                 
   int index, k;
	take_photo(map1, photo);		//A snapshot of the tiles that are currently on the screen is taken.
   for(index=0; index < 15; ++index)
   	if(offenfire[index].on_off() == 1)
      	{
         if(!((offenfire[index].column() == char_col) && (offenfire[index].row() == char_row)))
         	map1.change_cell(offenfire[index].row(), offenfire[index].column(), 100);
         switch(offenfire[index].direction())
         	{
            case 1:  offenfire[index].change_col(offenfire[index].column() + 1);
            			break;
            case 2:  offenfire[index].change_row(offenfire[index].row() - 1);
            			break;
            case 3:	offenfire[index].change_col(offenfire[index].column() - 1);
            			break;
            case 4:  offenfire[index].change_row(offenfire[index].row() + 1);
            }
         if((map1.cell(offenfire[index].row(), offenfire[index].column()) != 100) && (map1.cell(offenfire[index].row(), offenfire[index].column()) != 903))
            {
            offenfire[index].change_on(0);
            --bullets_in_air;
            if(map1.cell(offenfire[index].row(), offenfire[index].column()) > 910)
            	{
               for(k=0; !((fiends[k].row() == offenfire[index].row()) && (fiends[k].col() == offenfire[index].column())); ++k);
               fiends[k].change_on(0);
               if(map1.cell(offenfire[index].row(), offenfire[index].column()) < 920)
               	score+=300;
               else if(map1.cell(offenfire[index].row(), offenfire[index].column()) < 930)
               	score+=250;
               else if(map1.cell(offenfire[index].row(), offenfire[index].column()) < 940)
               	score+=1000;
               else if(map1.cell(offenfire[index].row(), offenfire[index].column()) < 950)
               	score+=500;
               map1.change_cell(offenfire[index].row(), offenfire[index].column(), 100);
               display_score();
               }
            }
         else if(!((offenfire[index].column() < map1.col_start()) || (offenfire[index].column() > (map1.col_start() + map1.numcols_os())) || (offenfire[index].row() < map1.row_start()) || (offenfire[index].row() > (map1.row_start() + map1.numrows_os()))))
            map1.change_cell(offenfire[index].row(), offenfire[index].column(), 903);
         }
	display_map(map1.row_start(), map1.col_start(), 1);  	//The current map is displayed with the camera on.
   }

//******************************************************************************************

void fire_ebullet(int brow, int bcol, int bdir)
	{
   int i;
   for(i=0; efire[i].on_off() == 1; ++i);
   efire[i].change_dir(bdir);
   efire[i].change_row(brow);
   efire[i].change_col(bcol);
   efire[i].change_on(1);
   ++ebullets_in_air;
   update_ebullets();
	}

//******************************************************************************************

void update_ebullets()
	{
   int index;
	take_photo(map1, photo);		//A snapshot of the tiles that are currently on the screen is taken.
   for(index=0; index < 20; ++index)
   	if(efire[index].on_off() == 1)
      	{
         map1.change_cell(efire[index].row(), efire[index].column(), 100);
         switch(efire[index].direction())
         	{
            case 1:	efire[index].change_col(efire[index].column() + 1);
            			break;
            case 2:	efire[index].change_row(efire[index].row() - 1);
            			break;
            case 3:	efire[index].change_col(efire[index].column() - 1);
            			break;
            case 4:	efire[index].change_row(efire[index].row() + 1);
            }
         if(map1.cell(efire[index].row(), efire[index].column()) != 100)
            {
            efire[index].change_on(0);
            --ebullets_in_air;
            if((map1.cell(efire[index].row(), efire[index].column()) / 100) == 2)
               {
            	energy-=35;
               energy_bars();
               }
            }
         else
            map1.change_cell(efire[index].row(), efire[index].column(), 903);
         }
   display_map(map1.row_start(), map1.col_start(), 1);   	//The current map is displayed with the camera on.
   }

//******************************************************************************************

void display_score()
	{
   gotoxy(32, 17);
   cout<<score;
   }

//******************************************************************************************

void display_lives()
	{
   gotoxy(11, 25);
   cout<<lives;
   }

//******************************************************************************************

void display_fleft()
	{
   box_filled(205, 192, 250, 199, 0);
   gotoxy(28, 25);
   cout<<foodleft;
   }

//******************************************************************************************

void save_game_menu()
   {
   int choice=0, madechoice=0;
   black_screen();
   initgraph(&graphdriver, &graphmode, path.c_str());
   setcolor(3);
   settextstyle(4, 0, 5);
	outtextxy(35, 50, "Choose a Slot for Your Game");
   print_file_info(choice, madechoice);
   if(madechoice == 1)
   	{
		switch(choice)
   		{
         case 0:	save_game(path + "slot1.sav");
         			break;
         case 1:  save_game(path + "slot2.sav");
         			break;
         case 2:  save_game(path + "slot3.sav");
         }
      slot_data();
      settextstyle(7, 0, 4);
      setcolor(15);
      outtextxy(180, 400, "SAVE COMPLETE");
      getch();
      }
   cleardevice();
   init_mode13h();
   display_panels();
   display_map(map1.row_start(), map1.col_start(), 0);         //The current map is displayed with the camera off.
   }

//******************************************************************************************

void save_game(apstring filename)
	{
   ofstream outfile;
   outfile.open(filename.c_str());
   outfile<<level<<endl;
   outfile<<lives<<endl;
   outfile<<score<<endl;
   outfile.close();
   }

//******************************************************************************************

int load_game_menu()
	{
   int choice=0, madechoice=0;
   black_screen();
   initgraph(&graphdriver, &graphmode, path.c_str());
   setcolor(3);
   settextstyle(4, 0, 6);
	outtextxy(30, 50, "Choose a Game to Play");
   print_file_info(choice, madechoice);
   if(madechoice == 1)
   	{
		switch(choice)
   		{
         case 0:	load_game(path + "slot1.sav", level, lives, score);
         			break;
         case 1:  load_game(path + "slot2.sav", level, lives, score);
         			break;
         case 2:  load_game(path + "slot3.sav", level, lives, score);
         }
      }
   cleardevice();
   init_mode13h();
   return madechoice;
   }

//******************************************************************************************

void load_game(apstring filename, int &level2, int &lives2, long int &score2)
	{
   ifstream infile;
   infile.open(filename.c_str());
   infile>>level2;
   infile>>lives2;
   infile>>score2;
   infile.close();
   }

//******************************************************************************************

void print_file_info(int &choice, int &madechoice)
	{
   int key;
   setcolor(12);
   settextstyle(2, 0, 5);
	outtextxy(80, 160, "Slot #1:");
	outtextxy(80, 190, "Slot #2:");
	outtextxy(80, 223, "Slot #3:");
	slot_data();
   setcolor(5);
   outtextxy(65, 160, ">");
	while(madechoice == 0)
      if(kbhit())
      	{
         key = getch();
         if((key == 32) || (key == 13))
         	madechoice = 1;
         else if(key == 27)
         	madechoice = 2;
         else
         	{
         	if((key == 50) && (choice < 2))
         		++choice;
	         else if((key == 56) && (choice > 0))
   	      	--choice;
      	   setcolor(0);
         	outtextxy(65, 160, ">");
			   outtextxy(65, 191, ">");
   			outtextxy(65, 222, ">");
      	   setcolor(5);
         	outtextxy(65, (160 + (choice * 31)), ">");
            }
         }
   }

//******************************************************************************************

void slot_data()
   {
   int level2, lives2;
   long int score2;
	load_game(path + "slot1.sav", level2, lives2, score2);
   gotoxy(20, 11);
   cout<<"Level: "<<setw(3)<<level2<<"     Lives: "<<setw(3)<<lives2<<"     Score: "<<setw(10)<<score2;
   load_game(path + "slot2.sav", level2, lives2, score2);
   gotoxy(20, 13);
   cout<<"Level: "<<setw(3)<<level2<<"     Lives: "<<setw(3)<<lives2<<"     Score: "<<setw(10)<<score2;
   load_game(path + "slot3.sav", level2, lives2, score2);
   gotoxy(20, 15);
   cout<<"Level: "<<setw(3)<<level2<<"     Lives: "<<setw(3)<<lives2<<"     Score: "<<setw(10)<<score2;
   }

//******************************************************************************

void display_map(int topl_row, int topl_col, int camon)
	{
   int tilecat;
   int r, c;
   for(r=0; r < 7; ++r)
   	for(c=0; c < 11; ++c)
      	{
			if(((photo[r][c] != map1.cell((topl_row + r), (topl_col + c))) && (camon == 1)) || (camon == 0))
         	{
	         tilecat = map1.cell((topl_row + r), (topl_col + c)) / 100;
   	      if(tilecat == 1)			//Building Structures
					switch (map1.cell((topl_row + r), (topl_col + c)))
         			{
            	   case 100:	floor1.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
      	      	case 102:	block1.display_stamp(10 + c * 20, 10 + r * 20);
         	   					break;
            		case 103:	block2.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
      	      	case 105:	crate2.display_stamp(10 + c * 20, 10 + r * 20);
         	   					break;
            		case 106:	barrel.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
	            	case 107:	fence1.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 108:	block3.display_stamp(10 + c * 20, 10 + r * 20);
      	      	}
	         else if(tilecat == 2)		//Character
   	      	switch (map1.cell((topl_row + r), (topl_col + c)))
      	     		{
                  case 200:	cright.display_stamp(10 + c * 20, 10 + r * 20);
                  				break;
                  case 201:	cleft.display_stamp(10 + c * 20, 10 + r * 20);
         	    					break;
	           	   case 202:	cup.display_stamp(10 + c * 20, 10 + r * 20);
   	        						break;
	   	         case 203:	cdown.display_stamp(10 + c * 20, 10 + r * 20);
   	   	     					break;
                  case 204:	ammobox.display_stamp(10 + c * 20, 10 + r * 20);
   	   	     					break;
                  case 205:   exit1.display_stamp(10 + c * 20, 10 + r * 20);
      	         }
      	   else if(tilecat == 3)		//Fruits
	         	switch (map1.cell((topl_row + r), (topl_col + c)))
   	        		{
	      	      case 300:	cherry.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	      	      case 301:	grapes.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
      	     	   case 302:	orange.display_stamp(10 + c * 20, 10 + r * 20);
         	  						break;
	               case 303:	tomato.display_stamp(10 + c * 20, 10 + r * 20);
   	        						break;
	      	      case 304:	lemon.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
      	     	   case 305:	lime.display_stamp(10 + c * 20, 10 + r * 20);
         	  						break;
               	case 306:   pear.display_stamp(10 + c * 20, 10 + r * 20);
		            }
         	else if(tilecat == 4)		//Vegetables
         		switch (map1.cell((topl_row + r), (topl_col + c)))
            		{
               	case 400:	pepper1.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
	               case 401:	turnip.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
            	   case 402:	carrot.display_stamp(10 + c * 20, 10 + r * 20);
	            					break;
   	            case 403:	pepper2.display_stamp(10 + c * 20, 10 + r * 20);
      	      					break;
         	      case 404:	pepper3.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
	               case 405:	pepper4.display_stamp(10 + c * 20, 10 + r * 20);
   	            }
        	 	else if(tilecat == 5)		//Candy / Baked Goods
	         	switch (map1.cell((topl_row + r), (topl_col + c)))
   	         	{
      	         case 500:	cake1.display_stamp(10 + c * 20, 10 + r * 20);
         	   					break;
            	   case 501:	cone1.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
	               case 502:	cone2.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
      	         case 503:	popsblue.display_stamp(10 + c * 20, 10 + r * 20);
         	   					break;
            	   case 504:	popsgren.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
      	         case 505:	lolipop.display_stamp(10 + c * 20, 10 + r * 20);
            	   }
	         else if(tilecat == 6)		//Drinks
   	      	switch (map1.cell((topl_row + r), (topl_col + c)))
      	      	{
         	      case 600:	sevenup.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
               	case 601:	tonicblu.display_stamp(10 + c * 20, 10 + r * 20);
	            					break;
   	            case 602:	tonicyel.display_stamp(10 + c * 20, 10 + r * 20);
      	      					break;
         	      case 603:	coffee.display_stamp(10 + c * 20, 10 + r * 20);
               	}
	         else if(tilecat == 7)		//Fast Food
   	      	switch (map1.cell((topl_row + r), (topl_col + c)))
      	      	{
         	      case 700:	sundae.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
	               case 701:	pizza.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
      	         case 702:	sausage.display_stamp(10 + c * 20, 10 + r * 20);
         	   					break;
   	            case 703:	fregg.display_stamp(10 + c * 20, 10 + r * 20);
      	      					break;
         	      case 704:	fries.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
      	         case 705:	steak.display_stamp(10 + c * 20, 10 + r * 20);
   	            }
      	   else if(tilecat == 8)		//Total Fat
         		switch (map1.cell((topl_row + r), (topl_col + c)))
            		{
	               case 800:	butter.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
            	   case 801:	vegoil.display_stamp(10 + c * 20, 10 + r * 20);
	            					break;
   	            case 802:	lard.display_stamp(10 + c * 20, 10 + r * 20);
      	      					break;
         	      case 803:	bacon.display_stamp(10 + c * 20, 10 + r * 20);
	               }
   	      else if(tilecat == 9)		//Enemies
      	   	switch (map1.cell((topl_row + r), (topl_col + c)))
         	   	{
    	            case 901:	spike1.display_stamp(10 + c * 20, 10 + r * 20);
      	      					break;
         	      case 903:	cbullet.display_stamp(10 + c * 20, 10 + r * 20);
            						break;
	            	case 904:	water.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 911:	e1right.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 912:	e1up.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 913:	e1left.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 914:	e1down.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 921:	bunker.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 931:	evileye.display_stamp(10 + c * 20, 10 + r * 20);
   	         					break;
	            	case 941:	pills.display_stamp(10 + c * 20, 10 + r * 20);
	               }
            }
			}
   }

//******************************************************************************

void update_enemies()
	{
   int index, r, c;
   int firedir;
   for(r=0; r < 7; ++r)
   	for(c=0; c < 11; ++c)
      	photo[r][c] = map1.cell((map1.row_start() + r), (map1.col_start() + c));
   for(index = 0; index < 65; ++index)
   	if(fiends[index].on() == 1)
      	{
         if(fiends[index].type() == 1)
         	{
            map1.change_cell(fiends[index].row(), fiends[index].col(), 100);
      		if((fiends[index].row() == char_row) || (fiends[index].col() == char_col))
            	{
               if(fiends[index].col() < char_col)
               	firedir = 1;
               else if(fiends[index].col() > char_col)
               	firedir = 3;
               else if(fiends[index].row() < char_row)
               	firedir = 4;
               else
               	firedir = 2;
               if((fiends[index].col() >= map1.col_start()) && (fiends[index].col() <= (map1.col_start() + (map1.numcols_os() - 1))) && (fiends[index].row() >= map1.row_start()) && (fiends[index].row() <= (map1.row_start() + (map1.numrows_os() - 1))))
                  {
               	switch(firedir)
               		{
                  	case 1:	e1right.display_stamp((10 + (20 * (fiends[index].col() - map1.col_start()))), (10 + (20 * (fiends[index].row() - map1.row_start()))));
                          	 	break;
                  	case 2:  e1up.display_stamp((10 + (20 * (fiends[index].col() - map1.col_start()))), (10 + (20 * (fiends[index].row() - map1.row_start()))));
                           	break;
                  	case 3:  e1left.display_stamp((10 + (20 * (fiends[index].col() - map1.col_start()))), (10 + (20 * (fiends[index].row() - map1.row_start()))));
                           	break;
                  	case 4:  e1down.display_stamp((10 + (20 * (fiends[index].col() - map1.col_start()))), (10 + (20 * (fiends[index].row() - map1.row_start()))));
                  	}
                  delay(200);
                  }
               display_map(map1.row_start(), map1.col_start(), 1);     //The current map is displayed with the camera on.
	            fire_ebullet(fiends[index].row(), fiends[index].col(), firedir);
               }
            switch(fiends[index].dir())
            	{
               case 1:	fiends[index].change_col(fiends[index].col() + 1);
               			break;
               case 2:	fiends[index].change_row(fiends[index].row() - 1);
               			break;
               case 3:	fiends[index].change_col(fiends[index].col() - 1);
               			break;
               case 4:	fiends[index].change_row(fiends[index].row() + 1);
               }
         	if(map1.cell(fiends[index].row(), fiends[index].col()) != 100)
            	{
               if((fiends[index].col() == char_col) && (fiends[index].row() == char_row))
               	{
      		   	energy-=24;
                  energy_bars();
                  }
               switch(fiends[index].dir())
            		{
	               case 1:	fiends[index].change_dir(3);
                  			fiends[index].change_col(fiends[index].col() - 1);
   	            			break;
      	         case 2:	fiends[index].change_dir(4);
                  			fiends[index].change_row(fiends[index].row() + 1);
         	      			break;
            	   case 3:	fiends[index].change_dir(1);
                  			fiends[index].change_col(fiends[index].col() + 1);
	               			break;
   	            case 4:	fiends[index].change_dir(2);
                  			fiends[index].change_row(fiends[index].row() - 1);
      	         }
               }
            map1.change_cell(fiends[index].row(), fiends[index].col(), (910 + fiends[index].dir()));
            }
         else if(fiends[index].type() == 2)
         	{
            if((fiends[index].row() == char_row) || (fiends[index].col() == char_col))
            	{
               if(fiends[index].col() < char_col)
               	firedir = 1;
               else if(fiends[index].col() > char_col)
               	firedir = 3;
               else if(fiends[index].row() < char_row)
               	firedir = 4;
               else
               	firedir = 2;
         	   if((fiends[index].col() >= map1.col_start()) && (fiends[index].col() <= (map1.col_start() + (map1.numcols_os() - 1))) && (fiends[index].row() >= map1.row_start()) && (fiends[index].row() <= (map1.row_start() + (map1.numrows_os() - 1))))
      	      	bunker.display_stamp((10 + (20 * (fiends[index].col() - map1.col_start()))), (10 + (20 * (fiends[index].row() - map1.row_start()))));
	            fire_ebullet(fiends[index].row(), fiends[index].col(), firedir);
               map1.change_cell(fiends[index].row(), fiends[index].col(), 921);
   	         display_map(map1.row_start(), map1.col_start(), 0);    	//The current map is displayed with the camera off.
            	}
            }
			else if(fiends[index].type() >= 3)
         	{
            if(
					((map1.cell(fiends[index].row(), (fiends[index].col() + 1)) > 199) && (map1.cell(fiends[index].row(), (fiends[index].col() + 1)) < 204) && (fiends[index].dir() == 1)) ||
			 		((map1.cell(fiends[index].row(), (fiends[index].col() - 1)) > 199) && (map1.cell(fiends[index].row(), (fiends[index].col() - 1)) < 204) && (fiends[index].dir() == 3)) ||
			 		((map1.cell((fiends[index].row() - 1), fiends[index].col()) > 199) && (map1.cell((fiends[index].row() - 1), fiends[index].col()) < 204) && (fiends[index].dir() == 2)) ||
			 		((map1.cell((fiends[index].row() + 1), fiends[index].col()) > 199) && (map1.cell((fiends[index].row() + 1), fiends[index].col()) < 204) && (fiends[index].dir() == 4)))
            	{
               energy-=30;
               energy_bars();
               }
            map1.change_cell(fiends[index].row(), fiends[index].col(), 100);
            if(fiends[index].col() < char_col)
            	{
               if(map1.cell(fiends[index].row(), (fiends[index].col() + 1)) == 100)
	            	fiends[index].change_col(fiends[index].col() + 1);
               fiends[index].change_dir(1);
               }
            else if(fiends[index].col() > char_col)
               {
               if(map1.cell(fiends[index].row(), (fiends[index].col() - 1)) == 100)
	            	fiends[index].change_col(fiends[index].col() - 1);
               fiends[index].change_dir(3);
               }
            if(fiends[index].row() < char_row)
               {
               if(map1.cell((fiends[index].row() + 1), fiends[index].col()) == 100)
	            	fiends[index].change_row(fiends[index].row() + 1);
               fiends[index].change_dir(4);
               }
            else if(fiends[index].row() > char_row)
               {
               if(map1.cell((fiends[index].row() - 1), fiends[index].col()) == 100)
	            	fiends[index].change_row(fiends[index].row() - 1);
               fiends[index].change_dir(2);
               }
            if((fiends[index].type() == 3) && ((fiends[index].row() == char_row) || (fiends[index].col() == char_col)))
            	{
               if(fiends[index].col() < char_col)
               	firedir = 1;
               else if(fiends[index].col() > char_col)
               	firedir = 3;
               else if(fiends[index].row() < char_row)
               	firedir = 4;
               else
               	firedir = 2;
               if((fiends[index].col() >= map1.col_start()) && (fiends[index].col() <= (map1.col_start() + (map1.numcols_os() - 1))) && (fiends[index].row() >= map1.row_start()) && (fiends[index].row() <= (map1.row_start() + (map1.numrows_os() - 1))))
               	evileye.display_stamp((10 + (20 * (fiends[index].col() - map1.col_start()))), (10 + (20 * (fiends[index].row() - map1.row_start()))));
               display_map(map1.row_start(), map1.col_start(), 1);       //The current map is displayed with the camera on.
	            fire_ebullet(fiends[index].row(), fiends[index].col(), firedir);
               }
            if(fiends[index].type() == 3)
	         	map1.change_cell(fiends[index].row(), fiends[index].col(), 931);
            else
	         	map1.change_cell(fiends[index].row(), fiends[index].col(), 941);
            }
      	}
   display_map(map1.row_start(), map1.col_start(), 1);      //The current map is displayed with the camera on.
   }

//******************************************************************************

void finish_game()
	{
   int r, c, frame;
   clear_keys();
   for(r=0; r < 10; ++r)
   	for(c=0; c < 16; ++c)
      	floor1.display_stamp((c*20), (r*20));
   for(r=7; r < 10; ++r)
		for(c=0; c < 5; ++c)
      	{
      	water.display_stamp((c*20), (r*20));
      	water.display_stamp(((16-c)*20), (r*20));
         }
   for(r=7; r < 10; ++r)
   	{
   	spike1.display_stamp(120, (r*20));
   	spike1.display_stamp(200, (r*20));
      }
   pills.display_stamp(120, 80);
   pills.display_stamp(120, 60);
   pills.display_stamp(120, 40);
   pills.display_stamp(200, 80);
   pills.display_stamp(200, 60);
   pills.display_stamp(200, 40);
   pillking.display_stamp(160, 20);
   evileye.display_stamp(20, 120);
   evileye.display_stamp(280, 120);
   cup.display_stamp(160, 180);
   for(frame=1; frame < 4; ++frame)
   	{
      delay(800);
      cup.display_stamp(160, 180 - (frame * 20));
      floor1.display_stamp(160, 180 - ((frame - 1) * 20));
      }
	cleft.display_stamp(160, 120);
   delay(700);
   shootl.display_stamp(160, 120);
   cbullet.display_stamp(140, 120);
   for(frame=1; frame < 7; ++frame)
   	{
      delay(500);
      cbullet.display_stamp((140 - (frame * 20)), 120);
      floor1.display_stamp((160 - (frame * 20)), 120);
      }
	floor1.display_stamp(20, 120);
   cup.display_stamp(160, 120);
   delay(500);
   cright.display_stamp(160, 120);
   delay(700);
   shootr.display_stamp(160, 120);
   cbullet.display_stamp(180, 120);
   for(frame=1; frame < 6; ++frame)
   	{
      delay(500);
      cbullet.display_stamp((180 + (frame * 20)), 120);
      floor1.display_stamp((160 + (frame * 20)), 120);
      }
   floor1.display_stamp(280, 120);
   cright.display_stamp(160, 120);
   for(frame=0; frame < 3; ++frame)
   	{
      delay(600);
	   cup.display_stamp(160, 120 - (frame * 20));
	   floor1.display_stamp(160, 140 - (frame * 20));
		}
   delay(600);
   shootu.display_stamp(160, 80);
   cbullet.display_stamp(160, 60);
   for(frame=1; frame < 3; ++frame)
   	{
      delay(500);
      cbullet.display_stamp(160, 60 - (frame * 20));
      floor1.display_stamp(160, 60 - ((frame - 1) * 20));
      }
   pilldead.display_stamp(160, 20);
   for(frame=0; frame < 7; ++frame)
   	{
      delay(400);
      pills.display_stamp(120 - (frame * 20), 80);
	   pills.display_stamp(120 - (frame * 20), 60);
   	pills.display_stamp(120 - (frame * 20), 40);
	   pills.display_stamp(200 + (frame * 20), 80);
   	pills.display_stamp(200 + (frame * 20), 60);
	   pills.display_stamp(200 + (frame * 20), 40);
      floor1.display_stamp(140 - (frame * 20), 80);
	   floor1.display_stamp(140 - (frame * 20), 60);
   	floor1.display_stamp(140 - (frame * 20), 40);
	   floor1.display_stamp(180 + (frame * 20), 80);
   	floor1.display_stamp(180 + (frame * 20), 60);
	   floor1.display_stamp(180 + (frame * 20), 40);
   	}
   floor1.display_stamp(0, 80);
   floor1.display_stamp(0, 60);
   floor1.display_stamp(0, 40);
   floor1.display_stamp(300, 80);
   floor1.display_stamp(300, 60);
   floor1.display_stamp(300, 40);
	cdown.display_stamp(160, 80);
	delay(500);
	shootd.display_stamp(160, 80);
	delay(500);
   erase_vert(40);
   initgraph(&graphdriver, &graphmode, path.c_str());
   delay(500);
   ingame = 0;
   score+=50000;
   cleardevice();
   setcolor(14);
   settextstyle(10, 0, 7);
   outtextxy(48,100, "GAME WON");
   setcolor(4);
   settextstyle(8, 0, 7);
   outtextxy(160,240, "Top Score");
   gotoxy(39,22);
   cout<<score;
   getch();
   }

//******************************************************************************

void level_done()
	{
   long int energyb=0, foodb=0, ammob=0;
   int column;
   clear_keys();
   black_screen();
   box_in_box(13,13,307,187, 44, 32);
   gotoxy(13, 4);
   cout<<"!Level Complete!";
   getch();
   gotoxy(4, 8);
   cout<<"Energy";
   gotoxy(4, 9);
   cout<<"Bonus:";
   draw_line(75, 60, (energy / 2) + 75, 60, 15);
   draw_line(75, 59, (energy / 2) + 75, 59, 12);
   draw_line(75, 61, (energy / 2) + 75, 61, 12);
   draw_line(75, 58, (energy / 2) + 75, 58, 4);
   draw_line(75, 62, (energy / 2) + 75, 62, 4);
   for(column=energy; column >= 0; --column)
   	{
      draw_line((75 + (column / 2)), 58, (75 + (column / 2)), 62, 0);
      energyb+=12;
      gotoxy(12, 9);
      cout<<energyb;
      delay(9);
      }
   gotoxy(4, 12);
   cout<<"Food Eaten:  "<<(origfood - foodleft)<<" out of "<<origfood;
   gotoxy(4, 13);
   if(foodleft == 0)
   	foodb = 25000;
   else
	   foodb = (origfood - foodleft) * 150;
   cout<<"Bonus:  "<<foodb;
   gotoxy(4, 16);
   cout<<"Ammo Left:  "<<50<<" x "<<ammo<<" Rounds";
   gotoxy(4, 17);
   ammob = 50 * ammo;
   cout<<"Bonus:  "<<ammob;
   gotoxy(4, 21);
   cout<<"Total Bonus:  "<<(energyb + foodb + ammob);
   score+=(energyb + foodb + ammob);
   getch();
   }
