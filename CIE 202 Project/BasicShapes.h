#pragma once
#include "shape.h"

class Rect : public shape
{
	float hght, wdth;	//height and width of the recangle
public:
	void setHeight(float newHeight);
	void setWidth(float newWidth);
	float getHeight() const;
	float getWidth() const;
	virtual void draw() const;
	Rect(game* r_pGame, point ref, float r_hght, float r_wdth);
	void flip();
	void move(float deltaX, float deltaY) override;
	virtual void resize(int size);
	point pref() const;
	void rotate();
	virtual void setColor(color r);

};

class circle :public shape
{
	//Add data memebrs for class circle
	float rad;
public:	
	float getRad() const;
	void setRad(float newRad);
	circle(game* r_pGame, point ref, float r);	//add more parameters for the constructor if needed
	virtual void resize(int size);
	virtual void draw() const;
	virtual void rotate();
	void move(float X, float Y) override;
	point pref() const; void flip();
	virtual void setColor(color r);
	
};

class Triangle :public shape
{
	float side;
	float rotationangle;
	point f, s, t;
public:
	//Triangle(game* r_pGame,int fx,int fy,int sx,int sy,int tx,int ty,double sidet);

	float getSide() const;
	Triangle(game* r_pGame, point ref, float side);
	virtual void resize(int size);
	virtual void draw() const;
	void move(float X, float Y) override;
	void rotate() override;
	point pref() const; void flip();
	virtual void setColor(color r);

};

class fTriangle :public shape
{
	float sideee;
	float rotationangle;
	point f, s, t;
public:

	float getSide() const;
	void setSide(float newSide);
	fTriangle(game* r_pGame, point ref, float side);
	virtual void resize(int size);

	virtual void draw() const;
	void move(float X, float Y) override;
	void update_points();
	void rotate() override;
	point pref() const; void flip();
	virtual void setColor(color r);

};