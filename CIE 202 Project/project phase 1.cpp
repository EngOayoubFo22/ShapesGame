#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <time.h>


#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"

using namespace std;
void DrawFanoos(window&, color, int, int, int);
void DrawRocket(window&, color, int, int, int);
void ClearWindow(window&);
void PrintMessage(window&, string);// mes stands for mesage or whatever i want to print 
void DrawHammer(window&, color, int, int, int, int, int, int);
void DrawHouse(window&, color, int, int, int);
void DrawIcecream(window&, color, int, int, int);
void DrawFish(window&, color, int, int, int, int, int, int);




int main()
{
	srand(time(0));
	string mes = "Press 'f' for fanoos , Press 'r' for rocket, Press 'h' for Hammer, Press 'c' for house, Press 'i' for Icecream, Press 'n' for fish, press 'q' to clear window";

	window s(1920, 950, 0, 0);
	color x(BLACK);
	s.ChangeTitle("PROJECT PHASE 1");
	s.SetPen(BLACK, 5);
	PrintMessage(s, mes);
	s.FlushKeyQueue();
	while (true)
	{
		char key;
		keytype userinput = s.GetKeyPress(key);
		s.SetPen(BLACK, 5);
		PrintMessage(s, mes);
		if (userinput == ASCII)
		{
			if (key == 'f')
			{
				s.SetPen(BLACK, 5);
				int size1 = 1 + rand() % (3);
				int sx = (75 * size1) + rand() % ((1700 - (75 * size1)) + 1);
				int sy = 20 + rand() % ((900 - (270 * size1)) - 20 + 1);
				DrawFanoos(s, x, sx, sy, size1);

			}
			else if (key == 'r')
			{
				int size2 = 1 + rand() % (3);
				int rx = (75 * size2) + rand() % (1700 - (75 * size2) + 1);
				int ry = 25 + rand() % (900 - (270 * size2) - 25);
				DrawRocket(s, x, rx, ry, size2);
			}
			else if (key == 'h')
			{
				int hammer_scale = 1 + rand() % (40);
				int width = 10 * hammer_scale;
				int height = 20 * hammer_scale;
				int handle_length = 25 * hammer_scale;
				int x = (1920 - (width + handle_length));
				int y = (900 - height);
				int hamX1 = 1 + rand() % (x);
				int hamY1 = 1 + rand() % (y);
				DrawHammer(s, RED, hammer_scale, handle_length, height, hamX1, hamY1, width);


			}
			else if (key == 'c')
			{
				int size4 = 50 + rand() % (400 - 50 + 1);
				int rx1 = rand() % (1920-(400) + 1);
				int ry1 = 200 + rand() % (490 - 200 + 1);
				
				DrawHouse(s, RED, rx1, ry1, size4);


			}
			else if (key == 'i')
			{
				int ix1 = rand() % (1700 + 1);
				int iy1 = 100 + rand() % (650 + 1);
				int size5 = 50 + rand() % (180 - 10 + 1);
				DrawIcecream(s, x, ix1, iy1, size5);
			}
			else if (key == 'n')
			{
				int scale = 1 + rand() % (15);
				int height = 20 * scale;
				int tail_width = 10 * scale;
				int fish_width = 30 * scale;
				int x = (1920 - (tail_width + fish_width));
				int y = 40 + (900 - height - 40);
				int startingX = 1 + rand() % (x);
				int startingY = 1 + rand() % (y);
				DrawFish(s, RED, scale, height, tail_width, fish_width, startingX, startingY);


			}
			else if (key == 'q')
			{
				ClearWindow(s);
			}
		}
	}

	s.ChangeTitle("PROJECT PHASE 1");
	//DrawFanoos(s, x, sx, sy, size1); 
// DrawRocket(s, x, rx, ry, size2);



}
// n is to be considered the size or the factor that the shape will be multiplied by
void DrawFanoos(window& s, color x, int sx, int sy, int n)
{
	s.SetPen(x, 5);
	s.SetBrush(BROWN);
	s.DrawTriangle(sx, sy, sx - (75 * n), sy + (100 * n), sx + (75 * n), sy + (100 * n));
	///s.SetBrush(BROWN);
	s.SetBrush(YELLOW);
	s.DrawTriangle(sx - (50 * n), sy + (100 * n), sx + (50 * n), sy + (100 * n), sx, sy + (250 * n));
	//s.SetPen(GREEN);
	s.SetBrush(BROWN);
	s.DrawTriangle(sx, sy + (250 * n), sx - (30 * n), sy + (270 * n), sx + (30 * n), sy + (270 * n));
}
void DrawRocket(window& s, color x, int rx, int ry, int n)
{
	//s.SetBrush(YELLOWGREEN);
	s.SetBrush(BLUE);
	s.DrawRectangle(rx - (30 * n), ry + (25 * n), rx + (30 * n), ry + (270 * n));
	s.SetBrush(RED);
	s.DrawTriangle(rx, ry, rx - (30 * n), ry + (25 * n), rx + (30 * n), ry + (25 * n));
	s.SetBrush(YELLOW);
	s.DrawTriangle(rx - (30 * n), ry + (195 * n), rx - (80 * n), ry + (240 * n), rx - (30 * n), ry + (240 * n));
	s.DrawTriangle(rx + (30 * n), ry + (195 * n), rx + (80 * n), ry + (240 * n), rx + (30 * n), ry + (240 * n));
}
void ClearWindow(window& s)
{
	s.SetPen(WHITE);
	s.SetBrush(WHITE);
	s.DrawRectangle(0, 0, s.GetWidth(), s.GetHeight());
}
void PrintMessage(window& s, string mes)
{
	s.SetFont(20, BOLD, BY_NAME);
	s.DrawString(5, 5, mes);
}
void DrawHammer(window& s, color x, int hammer_scale, int handle_length, int height, int hamX1, int hamY1, int width)
{

	int hamX2 = hamX1 + width;
	int hamY2 = hamY1 + height;
	int handle_height = 3 * hammer_scale;
	s.SetPen(BLACK);
	s.SetBrush(GREY);
	s.DrawRectangle(hamX1, hamY1, hamX2, hamY2, FILLED);
	s.SetBrush(BROWN);
	s.DrawRectangle(hamX2, (0.5 * (hamY2 + hamY1) - handle_height / 2), hamX2 + handle_length, (0.5 * (hamY2 + hamY1) + handle_height / 2), FILLED);
}

void DrawHouse(window& w, color x, int rx1, int ry1, int a)
{
	w.SetPen(VIOLET);
	w.SetBrush(x);
	w.DrawRectangle(rx1, ry1, rx1 + a, ry1 + a);
	w.SetBrush(BLUE);
	w.DrawTriangle(rx1, ry1, rx1 + a, ry1, ((2 * rx1 + a) / 2), (ry1 - ((ry1 + a - ry1) / 2)));
}
void DrawIcecream(window& w, color x, int ix1, int iy1, int b)
{
	w.SetPen(x);
	w.SetBrush(BROWN);
	w.DrawCircle(((ix1 + ix1 + b) / 2), iy1, ((ix1 + b - ix1) / 2));
	w.SetBrush(YELLOW);
	w.DrawTriangle(ix1, iy1, ix1 + b, iy1, ((ix1 + ix1 + b) / 2), iy1 + b);
}
void DrawFish(window& s, color x, int scale, int height, int tail_width, int fish_width, int startingX, int startingY)
{
	s.SetPen(BLUE);
	s.SetBrush(CYAN);
	s.DrawTriangle(startingX, startingY, startingX, startingY + height, tail_width + startingX, startingY + height / 2, FILLED);
	s.DrawTriangle(tail_width + startingX, startingY + height / 2, (tail_width + startingX + fish_width / 2), ((startingY + height / 2) + height / 2), (tail_width + startingX + fish_width / 2), ((startingY + height / 2) - height / 2), FILLED);
	s.DrawTriangle((tail_width + startingX + fish_width / 2), (startingY + height / 2) + height / 2, (tail_width + startingX + fish_width / 2), (startingY + height / 2) - height / 2, tail_width + startingX + fish_width, startingY + height / 2, FILLED);

}
// edit