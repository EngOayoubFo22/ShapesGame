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
	int rotationcount=0;
	int resizecount=0;
}

void shape::resize(int size) {
}

 void shape::move(float smallX, float smallY)
{
	RefPoint.x += smallX;
	RefPoint.y += smallY;
}

point shape:: getRefPoint()  {
	return RefPoint;
}

void shape:: setRefPoint(const point& newPoint) {
	RefPoint = newPoint;
}

void shape::save(ofstream& o)
{
	o << RefPoint.x << " " << RefPoint.y << endl;
	o << rotationcount << endl;
	o << resizecount << endl;
	/*o << fillColor.toInt() << endl;
	o << borderColor.toInt() << endl;*/

}



