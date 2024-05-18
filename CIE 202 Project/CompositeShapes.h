#pragma once
#include "Basicshapes.h"
#include "gameConfig.h"

class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref, float rndwdth = config.sighShape.topWdth, float rndheight = config.sighShape.topHeight, float rndwdth1 = config.sighShape.baseWdth, float rndhght1 = config.sighShape.baseHeight);
	virtual void resize(float size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override;
	virtual void flip();

};

class iceCream : public shape {
	circle* circ;
	fTriangle* triang;
	circle* circ1;
public:
	iceCream(game* r_pGame, point ref, float circl = config.IceCream.circleRadius, float circl1 = config.IceCream.circleRadius,float ftriaingle = config.IceCream.triangleSide);
	virtual void resize(float size);
	virtual void draw()const;
	virtual void rotate();
	void move(float X, float Y) override; virtual void flip();
};

class fanoos : public shape
{
	Triangle* top;
	fTriangle* mid;
	Triangle* bottom;
public : 
	fanoos(game* r_pGame, point ref, float side1 = config.fanoosShape.topside, float side2 = config.fanoosShape.midside, float side3 = config.fanoosShape.bottomside);
	virtual void resize(float size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override; virtual void flip();
};

class House :public shape {


	Rect* down;
	Triangle* up;
	
	Triangle* t1;
public:
	House(game* r_pGame, point ref, float rectwidth = config.HouseShape.rectWidth,float rectheight = config.HouseShape.rectLength, float traingle1 = config.HouseShape.topTriangleSide, float triangle2 = config.HouseShape.topTriangleSide);
	virtual void resize(float size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override; virtual void flip();

};

class Tree :public shape {


	Rect* r1;
	Triangle* t1;
	Triangle* t2;
	circle* c1;
public:
	Tree(game* r_pGame, point ref,float rectWidth = config.TreeShape.rectangleWidth, float rectheight = config.TreeShape.rectangleHeight, float triangle1 = config.TreeShape.topTriangleSide,float trianlge2 = config.TreeShape.bottomTriangleSide, float circlerad = config.TreeShape.circleRad);
	virtual void resize(float size);
	virtual void flip();
	virtual void rotate();
	virtual void draw() const;
	void move(float deltaX, float deltaY) override;
};

class Car :public shape {

	Rect* rect;
	circle* cir1;
	circle* cir2;
	Triangle* t1;
public:
	Car(game* r_pGame, point ref, float sidee = config.CarShape.triangleside, float radius = config.CarShape.circletRadius, float length = config.CarShape.rectangleheight, float widht = config.CarShape.rectanglewidth);
	virtual void flip();
	virtual void resize(float size);
	virtual void rotate();
	virtual void draw() const;
	void move(float X, float Y) override;



};
