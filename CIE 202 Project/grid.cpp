#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include"shape.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <cmath>


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::match()
{
	int x, y, f, z;
	bool match = false;

	for (int i = 0; i < shapeCount; i++)
	{
		x = activeShape->getRefPoint().x;
		y = activeShape->getRefPoint().y;
		f = shapeList[i]->getRefPoint().x;
		z = shapeList[i]->getRefPoint().y;

		if (activeShape->getType() == shapeList[i]->getType())
		{
			std::cout << 1;

			if (activeShape->getwidth() == shapeList[i]->getwidth() && activeShape->getheight() == shapeList[i]->getheight())
			{
				std::cout << 2;

				if (activeShape->getwidth() == shapeList[i]->getwidth() && activeShape->getheight() == shapeList[i]->getheight())
				{
					if ((abs(x - f) <= 300) && (abs(y - z) <= 300))
					{
						std::cout << 3;

						delete activeShape;
						activeShape = nullptr;

						delete shapeList[i];
						shapeList[i] = nullptr;
						pGame->setTimer(false);
						match = true;
						break;
					}
				}
			}
		}
	}

	if (shapeList == nullptr)
	{
		pGame->incrementLevel();
	}

	if (match == true)
	{
		pGame->incrementScore();
		pGame->incrementScore();
	}
	else 
	{ 
		pGame->DecrementScore();
	}
	

}

void grid::Hint()
{
	
	
	
	if (hint == false)
	{
		
		x = 1 + rand() % shapeCount;
		shapeList[x]->setColor(BLUE);

		hint = true;
		pGame->HintWait();
	}
	else
	{
		shapeList[x]->setColor(RED);
		hint = false;
	}
	



}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}


	
shape* grid::getActiveShape() 
{

	return activeShape;
}

shape* grid::getShapesList()
{

	return *shapeList;
}

void grid::deleteShapesList()
{
	for (int i = 0; i < shapeCount; i++)
	{
		delete shapeList[i];
		shapeList[i] = nullptr;
	}
}

void grid::drawAllButActiveShape() 
{
	if (activeShape)
	{
		delete activeShape;
		activeShape = nullptr;
	}
}


void grid::drawAllButRandomShape() 
{
	// Draw ALL shapes
	for (int i = 0; i < shapeCount; i++) {
		delete shapeList[i];
		shapeList[i] = nullptr;
		
	}

}

bool grid::chechBoundary(shape* psh)
{
	if (psh->getRefPoint().x - (psh->getwidth() * 0.75) < 0)
	{
		return false;
	}
	if (psh->getRefPoint().x + (psh->getwidth() * 0.75) > (config.windWidth*2/3))
	{
		return false;
	}
	if (psh->getRefPoint().y - (psh->getheight() * 0.75) - config.toolBarHeight < 0)
	{
		return false;
	}
	if (psh->getRefPoint().y + (psh->getheight() * 0.75) > config.windHeight)
	{
		return false;
	}
	return true;
}

	
	void grid::draw() const {
		clearGridArea(); // Clear the grid area first
		window* pWind = pGame->getWind();

		pWind->SetPen(config.gridDotsColor, 1);
		pWind->SetBrush(config.gridDotsColor);

		// Draw dots showing the grid reference points
		for (int r = 1; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			}
		}

		// Draw ALL shapes
		for (int i = 0; i < shapeCount; i++) {
			if (shapeList[i] != nullptr) {
				shapeList[i]->draw(); // Draw each shape
			}
		}

		
		if (activeShape) {
			activeShape->draw();
		}
	}
	shape* grid::DrawRandomShape()
	{
		window* pw = pGame->getWind();
		srand(time(0));
		int ct = 0;
		// generates random shapes and then generates random size and rotation angle
		while (ct < 2*( pGame->getCurrentGameLevel()) - 1)
		{
			int RndX = rand() % ((config.windWidth / 2) - (config.windWidth / 2) % 10);
			int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - config.RefX % config.gridSpacing);
			int RndShape = rand() % (6);
			int RndSize = 1 + rand() % 5;
			int RndRotationNo = rand() % 4;
			shape* psh;

			if (RndShape == 0)
			{
				int RndX = rand() % ((config.windWidth / 2) - (config.windWidth / 2) % 10);
				int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - (config.windHeight - config.toolBarHeight) % 10);
				point f = { RndX,RndY };
				psh = new Sign(pGame, f);
			}
			else if (RndShape == 1)
			{
				int RndX = rand() % ((config.windWidth / 2) - (config.windWidth / 2) % 10);
				int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - (config.windHeight - config.toolBarHeight) % 10);
				point f = { RndX,RndY };
				psh = new Car(pGame, f);
			}
			else if (RndShape == 2)
			{
				int RndX = rand() % ((config.windWidth / 2) - (config.windWidth / 2) % 10);
				int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - (config.windHeight - config.toolBarHeight) % 10);
				point f = { RndX,RndY };
				psh = new fanoos(pGame, f);
			}
			else if (RndShape == 3)
			{
				int RndX = rand() % ((config.windWidth / 2) - (config.windWidth / 2) % 10);
				int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - (config.windHeight - config.toolBarHeight) % 10);
				point f = { RndX,RndY };
				psh = new Tree(pGame, f);
			}
			else if (RndShape == 4)
			{
				int RndX = rand() % ((config.windWidth / 2) - (config.windWidth / 2) %10);
				int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - (config.windHeight - config.toolBarHeight) % 10);
				point f = { RndX,RndY };
				psh = new House(pGame, f);
			}
			else if (RndShape == 5)
			{
				int RndX = rand() % ((config.windWidth / 2));
				int RndY = config.toolBarHeight + rand() % ((config.windHeight - config.toolBarHeight) - (config.windHeight - config.toolBarHeight) % 10);
				point f = { RndX,RndY };
				psh = new iceCream(pGame, f);
			}

			ct++;
			psh->resize(RndSize);
			//psh->setResize(RndSize);
			for (int i = 0; i < RndRotationNo; i++)
			{
				psh->rotate();
			}

			if (chechBoundary(psh))
			{
				addShape(psh);
			}
			
		}
		return nullptr;
	}
	
	int grid::getshapecount() {
		return shapeCount;
	}

	void grid::DrawRandomShapeLoad(point ref, int rotNum, int reSize, int shpType, int Color)
	{

		shape* psh;
		switch (shpType)
		{
		case 5:
			psh = new Sign(pGame, ref);
			break;
		case 6:
			psh = new iceCream(pGame, ref);
			break;
		case 7:
			psh = new fanoos(pGame, ref);
			break;
		case 8:
			psh = new House(pGame, ref);
			break;
		case 9 :
			psh = new Car(pGame, ref);
			break;
		case 10:
			psh = new Tree(pGame, ref);
		}

		if (psh->getResizeCount() < 0)
		{
			for (int i = 0; i < abs(psh->getResizeCount()); i++)
			{
				psh->resize(2);
			}
		}
		else if (psh->getResizeCount() > 0)
		{
			for (int i = 0; i < psh->getResizeCount(); i++)
			{
				psh->resize(4);
			}
		}
		psh->resize(2);
		for (int i = 0; i < rotNum; i++)
			psh->rotate();


		addShape(psh);

	}


	void grid::saveshapes(ofstream& o) const
	{
		for (int i = 0; i < shapeCount; i++)
		{
			if (shapeList[i] != nullptr)
			{
				shapeList[i]->save(o);
			}
		}
	}
