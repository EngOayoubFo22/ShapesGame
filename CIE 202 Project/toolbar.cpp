#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	

	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\Sign.jpg";
	toolbarItemImages[ITM_Icecream] = "images\\toolbarItems\\Icrecream.jpeg";
	toolbarItemImages[ITM_Fanoos] = "images\\toolbarItems\\Fanoos.jpg";
	toolbarItemImages[ITM_House] = "images\\toolbarItems\\house.jpg";
	toolbarItemImages[ITM_Car] = "images\\toolbarItems\\car.jpg";
	toolbarItemImages[ITM_Tree] = "images\\toolbarItems\\tree.jpg";
	toolbarItemImages[ITM_Increase] = "images\\toolbarItems\\Increase_size.jpeg";
	toolbarItemImages[ITM_Decrease] = "images\\toolbarItems\\Decrease_size.jpeg";
	toolbarItemImages[ITM_Delete] = "images\\toolbarItems\\Delete.jpeg";
	toolbarItemImages[ITM_Hint] = "images\\toolbarItems\\Hint.jpeg";
	toolbarItemImages[ITM_FLIP] = "images\\toolbarItems\\flip.jpg";
	toolbarItemImages[ITM_Rotate] = "images\\toolbarItems\\Rotate_sign.jpeg";
	toolbarItemImages[ITM_Refresh] = "images\\toolbarItems\\Refresh_Sign.jpeg";
	toolbarItemImages[ITM_Save_and_Load] = "images\\toolbarItems\\Save_and_Load.jpeg";
	toolbarItemImages[ITM_Select_GAME_LEVEl] = "images\\toolbarItems\\Game_Level.jpeg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
	{
		
		if (i < 16)
			pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
		//pWind->DrawImage()
		
	}
	GameLevelScoreLives(pG);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

void toolbar::GameLevelScoreLives(game* pG)
{
	window* pWind = pGame->getWind();
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	toolbarItemImages[ITM_Actual_Lives] = to_string(pGame->getCurrentLives());
	toolbarItemImages[ITM_String_Lives] = " Lives)";
	toolbarItemImages[ITM_String_Score] = "Score = ";
	toolbarItemImages[ITM_Actual_Score] = to_string(pGame->getCurrentScore());
	toolbarItemImages[ITM_String_Level] = "Level = ";
	toolbarItemImages[ITM_Actual_Level] = to_string(pGame->getCurrentGameLevel());
	toolbarItemImages[ITM_String_Step] = "Steps = ";
	toolbarItemImages[ITM_Actual_Step] = to_string(pGame->getstep1());
	toolbarItemImages[ITM_String_RemainStep] = "Remaining Steps = ";
	toolbarItemImages[ITM_Actual_RemainStep] = to_string(pGame->getRemainingsteps());
	ClearScoreArea(pG);
	for (int i = 16; i < ITM_CNT; i++)
	{
		
	
			 if (i == 16)
			{
				pWind->SetPen(BLACK, 200);
				pWind->SetFont(20, BOLD, BY_NAME);
				pWind->DrawString(i * config.toolbarItemWidth + 1, 0, toolbarItemImages[i]);
		}
			else if (i == 17)
			{
				pWind->SetPen(BLACK, 20);
				pWind->SetFont(20, BOLD, BY_NAME);
				pWind->DrawString((i - 1) * config.toolbarItemWidth + 20, 0, toolbarItemImages[i]);
		}
			else if (i == 18)
			{
				pWind->SetPen(BLACK, 20);
				pWind->SetFont(20, BOLD, BY_NAME);
				pWind->DrawString((i - 2) * config.toolbarItemWidth + 1, 18, toolbarItemImages[i]);
		}
			else if (i == 19)
			{
				pWind->SetPen(BLACK, 20);
				pWind->SetFont(20, BOLD, BY_NAME);
				pWind->DrawString((i - 3) * config.toolbarItemWidth + 65, 18, toolbarItemImages[i]);
		}
			else if (i == 20)
			{
				pWind->SetPen(BLACK, 20);
				pWind->SetFont(20, BOLD, BY_NAME);
				pWind->DrawString((i - 4) * config.toolbarItemWidth + 1, 35, toolbarItemImages[i]);
		}
			else if (i == 21)
			{
				pWind->SetPen(BLACK, 20);
				pWind->SetFont(20, BOLD, BY_NAME);
				pWind->DrawString((i - 5) * config.toolbarItemWidth + 60, 35, toolbarItemImages[i]);
		}
			else if (i == 22)
			 {
				 pWind->SetPen(BLACK, 20);
				 pWind->SetFont(20, BOLD, BY_NAME);
				 pWind->DrawString((i - 6) * config.toolbarItemWidth + 75, 0, toolbarItemImages[i]);
			 }
			else if (i == 23)
			 {
				 pWind->SetPen(BLACK, 20);
				 pWind->SetFont(20, BOLD, BY_NAME);
				 pWind->DrawString((i - 7) * config.toolbarItemWidth + 150, 0, toolbarItemImages[i]);
			 }
	}
	
}

void toolbar::ClearScoreArea(game* r_pGame)
{
	this->pGame = r_pGame;
	window* pWind = pGame->getWind();
	pWind->SetPen(WHITE);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(16 * config.toolbarItemWidth - 5, 0, 19 * config.toolbarItemWidth - 5, config.toolBarHeight - 5);

}

void toolbar::drawtoolbar(game* pg)
{
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pg;
	window* pWind = pGame->getWind();
	//pWind->SetPen(WHITE);
	//pWind->SetBrush(WHITE);
	//pWind->DrawRectangle(0, 0, config.toolbarItemWidth*16, config.toolBarHeight);

	for (int i = 0; i < ITM_CNT; i++)
	{

		if (i < 16)
			pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
		//pWind->DrawImage()

	}
	GameLevelScoreLives(pg);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height, width, height);
}

