#include "shape.h"
#include "game.h"
#include "gameConfig.h"



shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::resize(float size) {
}

 void shape::move(float smallX, float smallY)
{
	RefPoint.x += smallX;
	RefPoint.y += smallY;
}

point shape:: getRefPoint() const {
	return RefPoint;
}

void shape:: setRefPoint(const point& newPoint) {
	RefPoint = newPoint;
}