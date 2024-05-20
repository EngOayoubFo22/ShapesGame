#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <fstream>
#include<iostream>
#include <vector>
#include <sstream>

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
operHint::operHint(game* r_pGame) : operation(r_pGame)
{
}
operLoad::operLoad(game* r_pGame) : operation(r_pGame)
{
}






void operDecResize::Act()
{

	grid * pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	point ref = psh->getRefPoint();
	psh->resize(2);
	if (pGrid->getActiveShape())
	{
		pGame->incrementStep1();
		toolbar* tolbar = pGame->getToolBar();
		tolbar->GameLevelScoreLives(this->pGame);
	}
	
}

void operIncResize::Act()
{

	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	point ref = psh->getRefPoint();
	psh->resize(4);
	if (pGrid->getActiveShape())
	{
		pGame->incrementStep1();
		toolbar* tolbar = pGame->getToolBar();
		tolbar->GameLevelScoreLives(this->pGame);
	}

}

void operFlip::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	point ref = psh->getRefPoint();
	psh->flip();
	if (pGrid->getActiveShape())
	{
		pGame->incrementStep1();
		toolbar* tolbar = pGame->getToolBar();
		tolbar->GameLevelScoreLives(this->pGame);
	}
}



void operRotate::Act()
{

	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();
	if (activeShape) {
		activeShape->rotate();
		pGrid->draw();
	}
	if (pGrid->getActiveShape())
	{
		pGame->incrementStep1();
		toolbar* tolbar = pGame->getToolBar();
		tolbar->GameLevelScoreLives(this->pGame);
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
	pGame->getstep1();
	pGame->getRemainingsteps();
	pGrid->drawAllButActiveShape();
	if (pGrid->getActiveShape())
	{
		pGame->incrementStep1();
		toolbar* tolbar = pGame->getToolBar();
		tolbar->GameLevelScoreLives(this->pGame);
	}
	

}
void operRefresh::Act()
{
	grid* shapesGrid = pGame->getGrid();
	shapesGrid->drawAllButRandomShape();
	shapesGrid->DrawRandomShape();
	if (shapesGrid->getActiveShape())
	{
		pGame->incrementStep1();
		toolbar* tolbar = pGame->getToolBar();
		tolbar->GameLevelScoreLives(this->pGame);
	}

}

void operHint::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->Hint();
}


operSaveExit::operSaveExit(game* r_pGame) : operation(r_pGame) {

}

void operSaveExit::Act()
{
	grid* shapesGrid = pGame->getGrid();
	ofstream GameProgress("SaveLoad//GameProgress.txt");
	FILE* progress = fopen("SaveLoad//GameProgress.txt", "w");

	int lives = pGame->getCurrentLives();
	int score = pGame->getCurrentScore();
	int level = pGame->getCurrentGameLevel();

	GameProgress << lives << " ";
	GameProgress << score << " ";
	GameProgress << level << endl;

	shape* sh = shapesGrid->getActiveShape();
	sh->save(GameProgress);

	shapesGrid->saveshapes(GameProgress);



	GameProgress.close();
}

void parseString(vector<string>& v, string s)
{
	string word;
	istringstream iss(s);
	while (iss >> word)
	{
		v.push_back(word);
	}
}

void operLoad::Act()
{

	grid* shapesgrid = pGame->getGrid();
	ifstream File;
	File.open("SaveLoad//GameProgress.txt");
	vector<string> v1;
	string line;
	while (getline(File, line))
	{
		v1.push_back(line);
	}
	vector<string> ScoreLevelLives;
	parseString(ScoreLevelLives, v1[0]);
	pGame->Setlevel(stoi(ScoreLevelLives[2]));
	pGame->SetLives(stoi(ScoreLevelLives[0]));
	pGame->SetScore(stoi(ScoreLevelLives[1]));
	vector<string> ActiveShape;
	parseString(ActiveShape, v1[1]);
	shape* psh = shapesgrid->getActiveShape();
	delete psh;
	psh = nullptr;
	point ref = { stoi(ActiveShape[1]),stoi(ActiveShape[2]) };
	switch (stoi(ActiveShape[0]))
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
	case 9:
		psh = new Car(pGame, ref);
		break;
	case 10:
		psh = new Tree(pGame, ref);
	}

	
	if (stoi(ActiveShape[4]) > 0) {
		for (int i = 0; i < stoi(ActiveShape[4]); i++)
			psh->resize(4);
	}
	else {
		for (int i = 0; i > stoi(ActiveShape[4]); i--)
			psh->resize(2);
	}
	for (int i = 0; i < stoi(ActiveShape[3]); i++)
		psh->rotate();

	shapesgrid->setActiveShape(psh);
	shapesgrid->deleteShapesList();
	for (int i = 2; i < v1.size() - 2; i++)
	{
		vector<string> ShapeList;
		parseString(ShapeList, v1[i]);
		point ref1 = { stoi(ShapeList[1]),stoi(ShapeList[2]) };
		shapesgrid->DrawRandomShapeLoad(ref1, stoi(ShapeList[3]), stoi(ShapeList[4]), stoi(ShapeList[0]));
	}

	File.close();



	
}


