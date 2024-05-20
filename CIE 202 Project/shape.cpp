#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include"fstream"
using namespace std;


shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
	rotationcount=0;
     resizecount=0;
}
int shape::getwidth()
{
	return 0;
}

int shape::getheight()
{
	return 0;
}


int shape::getType()
{
	return 0;
}

void shape::resize(int size) {
}

 void shape::move(float smallX, float smallY)
{
	RefPoint.x += smallX;
	RefPoint.y += smallY;
}

 int shape::getRotationCount() const
 {
	 return rotationcount % 4;
 }

 void shape::setResize(int rsz)
 {
	 this->resizecount = rsz;
 }

 int shape::getResizeCount() const
 {
	 return resizecount;
 }

point shape:: getRefPoint()  {
	return RefPoint;
}

void shape:: setRefPoint(const point& newPoint) {
	RefPoint = newPoint;
}

void shape::save(ofstream& o)
{

	o << getType() << " " << RefPoint.x << " " << RefPoint.y << " "
		<< rotationcount << " "
		<< resizecount << endl;


}


