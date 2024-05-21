#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"
#include "ctime"



//Main class that coordinates the game operation
class game
{
	bool hintActive = false;
	std::time_t hintStartTime = 0;
	int hintWaitDuration = 2;

	/// Add more members if needed

	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	int Current_gameLevel= 3;
	int Lives = 5;
	bool updateToolbarFlag;
	int Current_score = 0;
	int step1 = 0;
	int remTime = 0;
	bool timerActive = false;
	int countdownDuration = 100;
	int intTime = 0;
	int timeE = 0;
	int bounes;
	int stepsRemaining = 9;
	int Chargedsteps ;
public:
	game();
	~game();
	void setTimer(bool t);
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
	int getRem();
	void incrementLives();
	void incrementStep1();
	void DecrementLives();
	void DecrementLevel();
	void DecrementScore();
	void Setlevel(int level);
	void SetLives(int Livs);
	void SetScore(int Score);
	int getCurrentGameLevel() const;
	int getCurrentLives() const;
	int getCurrentScore() const;
	void countdown();
	window* getWind() const;		//returns a pointer to the graphics window
	void HintWait();
	grid* getGrid() const;		//returns a pointer to the shapes grid
	toolbar* getToolBar() const;
	int getstep1();
	bool performOperation();
	int getbounesscore();
	int getRemainingsteps();
	void getchargedSteps();
	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);
	void run();	//start the game

};

