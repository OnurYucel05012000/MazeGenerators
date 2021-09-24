#pragma once
class MazeCell {

public:
	bool visited = false;	
	int i, j;
	//left,top,right,bottom
	//walls[0]=>left
	bool walls[4] = { true,true,true,true };
	char color = 177;

	MazeCell(int i,int j,bool visited);
	MazeCell();
};
