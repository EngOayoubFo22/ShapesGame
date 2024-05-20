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
		 {
			printMessage("You Clicked on Create A Sign");
		}	
			
		break;
	
	case ITM_Save_and_Load:
		op = new operLoad(this);
		printMessage("You Cliked on Load");
		break;
	case ITM_Select_GAME_LEVEl:
	{
		printMessage("Please enter the game level:");
		//string newlevel =getSrting(); // Encapsulate this line in a block
		//if (!newlevel.empty()) {
		//	int level1 = std::stoi(newlevel); // Convert input to an integer.
		//	setlevel(level1); // Change to the requested game level.
		//	printMessage("Game level selected."+newlevel);
		//}
		
		
		 }
		break;
				
			break;
	case ITM_Decrease:
		op = new operDecResize(this);
		
			printMessage("you decreased size");
		
		break;
	case ITM_Delete:
		op = new operDelete(this);
		/*if (stepsRemaining > 0) {
			
		}
		else*/
		printMessage("You Deleted this Item");
			break;
	case ITM_Hint:
		printMessage("You Used A hint");
		op = new operHint(this);
		break;
	case ITM_Increase:
		op = new operIncResize(this);
		/*if (stepsRemaining > 0) {
			
		}
		else*/
		printMessage("You Increased this items size");
		break;
	case ITM_Rotate:
	
		op = new operRotate(this);
		performOperation();
		/*if (stepsRemaining > 0) {
			
		}
		else*/
		//printMessage("You Rotated this Item");
		
		break;
	case ITM_Refresh:		
		
		op = new operRefresh(this);
		/*if (stepsRemaining>0) {
			printMessage("You Refreshed The Random shapes");
		}
		else*/
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
		/*if (stepsRemaining >0) {
			printMessage("You clicked on Flip");
		}
		else*/
		printMessage("You clicked on Flip");
		break;
	case ITM_EXIT:
		op = new operSaveExit(this);
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
bool game::performOperation() {
	bool x = true;
	while (x==true) {
		Chargedsteps =6 - step1;
		string level = std::to_string(getCurrentGameLevel());
		if (Chargedsteps ==0) {
			printMessage(" With 100 chargteps you reached to level :" + level+"   Level");
			break;
			return false;
		}
		else {
			return true ;
		}
	}
}
int game::getbounesscore()
{
	int bounesScore = 20 +500 / step1;
	Current_score += bounesScore;

	return Current_score;
}


int game::getRemainingsteps()
{
	
	if (Chargedsteps < 0) {
		Chargedsteps = 0;
	}
	return 0;
}

void game::getchargedSteps()
{
	if (Chargedsteps == 0) {
		printMessage("you reached to level" + getCurrentGameLevel()+ getCurrentScore());
}
	
}



////////////////////////////////////////////////////////////////////////

void game::handleKeyPress(char K) {
	if (!shapesGrid) return;

	 int Step = 50; 
	shape* activeShape = shapesGrid->getActiveShape(); 

	switch (K) {
	case 8: //up
		activeShape->move(0, -Step);
		step1++;

		if (stepsRemaining <= 0) {
			printMessage("Not enough steps remaining to perform this operation!");
		}
		gameToolbar->GameLevelScoreLives(this);
		break;
	case 2://down 
		activeShape->move(0,Step);
		step1++;
		gameToolbar->GameLevelScoreLives(this);
		break;
	case 4: //right 
		activeShape->move(-Step, 0);
		step1++;
		gameToolbar->GameLevelScoreLives(this);
		break;
	case 6://left 
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
		performOperation();
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
				gameToolbar->drawtoolbar(this);
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

void game::Setlevel(int level)
{
	this->Current_gameLevel = level;
}

void game::SetLives(int Livs)
{
	this->Lives = Livs;
}

void game::SetScore(int Score)
{
	this->Current_score = Score;
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

		