#pragma once

#include"MazeCell.h"


class Painter
{
public:	
	//bir ekle 3 bol maxcell e yaz
	

	//Painter(int MAZE_I, int MAZE_J);
	Painter();

	void PutDatainMaze(MazeCell** cells);
	void Draw();
	void Clear();
	void JustPutdata(MazeCell** cells);
	void gotoxy(int x, int y);
	void setMAZE_I(int MAZE_I);
	void setMAZE_J(int MAZE_J);
	int  getMAZE_I();
	int  getMAZE_J();
	
private:
	void CreateMaze_Char_Array();
	char** Maze;
	int MAZE_I = 27;
	int MAZE_J = 27;
	
	
	
	
};

