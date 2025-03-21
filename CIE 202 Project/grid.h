#pragma once
#include "CompositeShapes.h"
#include"shape.h"

class game;

class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int height, width;
	point uprLeft;	//upper left point of the grid

	//ShapeList should hold the RANDOMLY generated shapes
	shape* shapeList[MaxShapeCount];	//2D array of shape pointers
	shape* activeShape;

		//The shape that the user works on to match to the ranom shapes
	
	int shapeCount;		//current number of shapes in the list
	game* pGame;
protected:
	int	x;
	bool hint = false;
public:
	
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	virtual void match();
	virtual void Hint();
	void draw() const;
	void clearGridArea() const;
	bool addShape(shape* newShape);
	void setActiveShape(shape* actShape);
	shape* DrawRandomShape();
	shape* getActiveShape();
	shape* getShapesList();
	void deleteShapesList();
	int getshapecount();
	void DrawRandomShapeLoad(point ref, int rotNum, int reSize , int shpType, int Color = 1);
	void drawAllButActiveShape();
	void drawAllButRandomShape();
	void moveActiveShape(int dx, int dy);
	void saveshapes(ofstream& o) const;
	bool chechBoundary(shape* psh);
};
 

