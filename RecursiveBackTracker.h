#pragma once
#include "Painter.h"
#include "MazeCell.h"
#include <vector>
#include <stack>



class RecursiveBackTracker
{

public:

	RecursiveBackTracker(int width,int height,int Start_i,int Start_j);
	~RecursiveBackTracker();
	
	void Run(MazeCell** cell);
	void Start();
	MazeCell** cell;
	int MAXCELL = 9;
	int width, height;
 private:
	 bool CalculateMazeCellArea();
	 
	 int Starting_i, Starting_j;	 	 
	 


	 void CreateCells();

	

	/*void Console::gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	}
	void Console::HideCurcor() {
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorinfo;

		GetConsoleCursorInfo(out, &cursorinfo);
		cursorinfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorinfo);
	}*/
};

