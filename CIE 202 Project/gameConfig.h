#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"



struct 		
{
	struct {
		int circleRadius = 50;
		int triangleSide = 30;
	}IceCream;
	
	int	windWidth=1490, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = 900;
	int RefY = 300;

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;
	
	struct {
		int rightWidth = 50, rightheight = 90;
		int leftwidth = 110, leftheight = 30;
	}hammershape;

	struct {
		int topside = 80;
		int midside = 60;
		int bottomside = 40;

	}fanoosShape;
	struct {
		int topTriangleSide = 100;
		int rectLength = 100;
		int rectWidth = 100;
	}HouseShape;
	struct {
		int rectangleHeight = 130;
		int rectangleWidth = 40;
		int topTriangleSide = 100;
		int bottomTriangleSide = 100;
		int circleRad = 13;
	}TreeShape;
	struct {
		int rectangleheight = 50;
		int rectanglewidth = 180;
		int circletRadius = 20;
		int triangleside = 70;


	}CarShape;
}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
		//Sign shape item

	//Exit item
	//ITM_Triangle,
	//ITM_circle,
	//ITM_Rectangle,
	ITM_SIGN,
	ITM_Icecream,
	ITM_Fanoos,
	ITM_House,
	ITM_Car,
	ITM_Tree,
	ITM_Increase,
	ITM_Decrease,
	ITM_Rotate,
	ITM_FLIP,
	ITM_Refresh,
	ITM_Hint,
	ITM_Delete,
	ITM_Select_GAME_LEVEl,
	ITM_EXIT,
	ITM_Save_and_Load,
	

	
	ITM_Actual_Lives,
	ITM_String_Lives,
	ITM_String_Score,
	ITM_Actual_Score,
	ITM_String_Level,
	ITM_Actual_Level,
	ITM_String_Step,
	ITM_Actual_Step,
	ITM_String_RemainStep,
	ITM_Actual_RemainStep,
	ITM_String_RunTime,
	ITM_Actual_RunTime,

	//TODO: Add more items names here
	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};



