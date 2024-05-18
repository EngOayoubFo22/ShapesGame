#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	int Current_gameLevel = 2;
	int Lives = 5;
	int Current_score = 0;
	int step1 = 0;
public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	void game::handleKeyPress(char Key);
	void deleteRandomShapes();
	void incrementScore();
	void incrementLevel();
	void incrementLives();
	void DecrementLives();
	void DecrementLevel();
	void DecrementScore();
	int getCurrentGameLevel() const;
	int getCurrentLives() const;
	int getCurrentScore() const;
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	toolbar* getToolBar() const;
	int getstep1();
	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);
	void run();	//start the game

};

