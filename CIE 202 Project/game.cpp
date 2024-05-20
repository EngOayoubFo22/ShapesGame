#include "game.h"
#include "gameConfig.h"
#include <ctime>
#include <iostream>

game::game()
{
	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}

void game::setTimer(bool t)
{
	timerActive = t;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
	shapesGrid->DrawRandomShape();
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		printMessage("You Clicked on Create A Sign");
		break;
	/*case ITM_Triangle:
		op = new operAddTriangle(this);
		printMessage("You Clicked on Create A Triangle");
		break;
	case ITM_circle:
		op = new operAddcircle(this);
		printMessage("You Clicked on Create A Circle");
		break;
	case ITM_Rectangle:
		op = new operAddRectangle(this);
		printMessage("You Clicked on Create A Rectangle");
		break;*/
	case ITM_Save_and_Load:
		op = new operSave(this);
		printMessage("You Cliked on Save And Load");
		break;
	case ITM_Select_GAME_LEVEl:
		printMessage("You Clicked on Select Game level");
			break;
	case ITM_Decrease:
		op = new operDecResize(this);
		step1++;
		printMessage("You Decreased the Size");
		break;
	case ITM_Delete:
		op = new operDelete(this);
		step1++;
		printMessage("You Deleted this Item");
			break;
	case ITM_Hint:
		printMessage("You Used A hint");
		op = new operHint(this);
		break;
	case ITM_Increase:
		op = new operIncResize(this);
		step1++;
		printMessage("You Increased this items size");
		break;
	case ITM_Rotate:
	
		op = new operRotate(this);
		printMessage("You Rotated this Item");
		break;
	case ITM_Refresh:
		step1++;
		
		op = new operRefresh(this);
		
		printMessage("You Refreshed The Random shapes");
		break;
	case ITM_Icecream:
		printMessage("You clicked on Draw Ice Cream");
		op = new operAddIceCream(this);
		break;
	case ITM_Fanoos:
		printMessage("Ramadan kareem Kol sana w enta tyb");
		op = new operAddFanoos(this);
		break;
	case ITM_House:
		op = new operAddHouse(this);
		printMessage("You clicked on Draw House");
		break;

	case ITM_Car:
		op = new operAddCar(this);
		printMessage("You clicked on Draw car");
		break;
	case ITM_Tree:
		op = new operAddTree(this);
		printMessage("You clicked on Draw tree");
		break;
	case ITM_FLIP:
		op = new operFlip(this);
			printMessage("You clicked on Flip");
		break;
	}
	

	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}

void game::countdown()
{

	if (timerActive == false)
	{
		intTime = time(0);
		timerActive = true;
		printMessage("Timer Started!");
	}

	timeE = time(0) - intTime;

	remTime = countdownDuration - timeE;
	if (remTime == 0)
	{
		printMessage("TIME IS UP!");
		timerActive = false;
		DecrementLives();
	}
	std::cout << remTime;
}


window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}

void game::HintWait()
{
	Sleep(2000);
	shapesGrid->Hint();
	
	/*if (time(0) - x == 2)
	{
		shapesGrid->Hint();
	}
	else if (shapesGrid->hint == true)
			
	*/
}

string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}

toolbar* game::getToolBar() const
{
	return gameToolbar;
}

int game::getstep1()
{
	return step1;
}



////////////////////////////////////////////////////////////////////////

void game::handleKeyPress(char K) {
	if (!shapesGrid) return;

	 int Step = 50; 
	shape* activeShape = shapesGrid->getActiveShape(); 

	switch (K) {
	case 'w': //up
		activeShape->move(0, -Step);
		step1++;
		gameToolbar->GameLevelScoreLives(this);
		break;
	case 's'://down 
		activeShape->move(0,Step);
		step1++;
		gameToolbar->GameLevelScoreLives(this);
		break;
	case 'a': //right 
		activeShape->move(-Step, 0);
		step1++;
		gameToolbar->GameLevelScoreLives(this);
		break;
	case 'd'://left 
		activeShape->move(Step, 0);
		step1++;
		gameToolbar->GameLevelScoreLives(this);
		break;
	case ' '://check match 
		printMessage("Checking for match");
		shapesGrid->match();
		break;

	}

	shapesGrid->draw(); 
}


void game::run()
{
	int x, y;
	int w = 0;
	toolbarItem clickedItem = ITM_CNT;

	
	pWind->ChangeTitle("- - - SHAPE HUNT (CIE 101 project)/\(SEC2_T05) - - -");

	char K;
	do {
		
		while (pWind->GetKeyPress(K)) { 
			handleKeyPress(K); 
		}
		
		if (w == 1)
		{
			countdown();
		}
		
		if (pWind->GetMouseClick(x, y)) { 
			if (y >= 0 && y <30) {
				clickedItem = gameToolbar->getItemClicked(x);
				operation* op = createRequiredOperation(clickedItem);
				if (op) {
					op->Act();
					w = 1;
				}

				if(clickedItem)
				shapesGrid->draw(); 
				//shapesGrid->DrawRandomShape();
			}
		}
	} while (clickedItem != ITM_EXIT);
}
		
void game::incrementScore()
{
	Current_score++;
}

void game::incrementLevel()
{
	Current_score++;
}

void game::incrementLives()
{
	Lives++;
}

void game::incrementStep1()
{
	step1++;
}

void game::DecrementLives()
{
	Lives--;
}

void game::DecrementLevel()
{
	Current_gameLevel--;
}

void game::DecrementScore()
{
	Current_score--;
}

int game::getCurrentGameLevel() const
{
	return Current_gameLevel;
}

int game::getCurrentLives() const
{
	return Lives;
}

int game::getCurrentScore() const
{
	return Current_score;
}

		