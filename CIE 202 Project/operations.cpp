#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <fstream>
#include<iostream>
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}
operAddTriangle::operAddTriangle(game* r_pGame):operation(r_pGame)
{
}
operAddcircle::operAddcircle(game* r_pGame) :operation(r_pGame)
{
}
operAddRectangle::operAddRectangle(game* r_pGame):operation(r_pGame)
{
}
operAddIceCream::operAddIceCream(game* r_pGame):operation(r_pGame)
{
}
operAddFanoos::operAddFanoos(game* r_pGame) : operation(r_pGame)
{
}
operAddHouse::operAddHouse(game* r_pGame) :operation(r_pGame)
{
}
operAddCar::operAddCar(game* r_pGame) :operation(r_pGame) 
{
}
operAddTree::operAddTree(game* r_pGame) :operation(r_pGame) 
{
}
operIncResize::operIncResize(game* r_pGame) :operation(r_pGame)
{
}
operDecResize::operDecResize(game* r_pGame) :operation(r_pGame)
{
}
operRotate::operRotate(game* r_pGame) :operation(r_pGame)
{
}
operFlip::operFlip(game* r_pGame) : operation(r_pGame)
{
}
operDelete::operDelete(game* r_pGame) : operation(r_pGame)
{
}
operRefresh::operRefresh(game* r_pGame) : operation(r_pGame)
{
}





void operDecResize::Act()
{

	grid * pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	point ref = psh->getRefPoint();
	psh->resize(1/1.1);
	
}

void operIncResize::Act()
{

	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	point ref = psh->getRefPoint();
	psh->resize(1.1);

}

void operFlip::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	point ref = psh->getRefPoint();
	psh->flip();
}



void operRotate::Act()
{

	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();
	if (activeShape) {
		activeShape->rotate();
		pGrid->draw();
	}
}


void operAddSign::Act()
{
	window* pw = pGame->getWind();


	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };
	
	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddTriangle::Act()
{
	window* pw = pGame->getWind();


	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new  Triangle(pGame, signShapeRef, 80);
	

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



void operAddcircle::Act()
{
	{
		window* pw = pGame->getWind();

		//TODO:
		// Don't allow adding new shape if there is alreday an active shape

		//align reference point to the nearest grid point
		int xGrid = config.RefX - config.RefX % config.gridSpacing;
		int yGrid = config.RefY - config.RefX % config.gridSpacing;

		//take the aligned point as the sign shape ref point
		point signShapeRef = { xGrid,yGrid };


		//create a sign shape
		shape* psh = new circle(pGame, signShapeRef, 50);
		//Add the shape to the grid
		grid* pGrid = pGame->getGrid();
		pGrid->setActiveShape(psh);

	}
}
void operAddRectangle::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Rect(pGame, signShapeRef,60,50);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddIceCream::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point icreamShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new iceCream(pGame, icreamShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

void operAddFanoos::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point signShapeRef = { xGrid,yGrid };
	shape* psh = new fanoos(pGame, signShapeRef);

	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

void operAddHouse::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	double xGrid = config.RefX - config.RefX % config.gridSpacing;
	double yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point HouseShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new House(pGame, HouseShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

void operAddTree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point HouseShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Tree(pGame, HouseShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


void operAddCar::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point CarShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Car(pGame, CarShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

void operDelete::Act()
{
	grid* pGrid = pGame->getGrid();
	//pGrid->clearGridArea();
	pGrid->drawAllButActiveShape();

	

}
void operRefresh::Act()
{
	grid* shapesGrid = pGame->getGrid();
	shapesGrid->drawAllButRandomShape();
	shapesGrid->DrawRandomShape();
	pGame->DecrementScore();
	toolbar* tolbar = pGame->getToolBar();
	tolbar->GameLevelScoreLives(this->pGame);

}



operSave::operSave(game* r_pGame) : operation(r_pGame) {

}

void operSave::Act()
{
	grid* shapesGrid = pGame->getGrid();
	ofstream GameProgress("GameProgress.txt");
	FILE* progress = fopen("GameProgress.txt", "w");
	/*if (!GameProgress) {
		cout << "Error opening file for writing" << endl;
		return;
	}*/

	int lives = pGame->getCurrentLives();
	int score = pGame->getCurrentScore();
	int level = pGame->getCurrentGameLevel();

	GameProgress << lives << endl;
	GameProgress << score << endl;
	GameProgress << level << endl;
	
	shape* sh = shapesGrid->getActiveShape();
	sh->save(GameProgress);
	
	shape* shapes=shapesGrid->getShapesList();
	for (int i = 0; i < shapesGrid->getshapecount(); i++)
	{
		shapes[i].save(GameProgress);
	}

	

	GameProgress.close();
}
