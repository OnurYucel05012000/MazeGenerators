#pragma once
class MazeCell {

public:
	bool visited = false;	
	int i, j;
	//sol,ust,sag,alt
	//walls[0]=>sol
	bool walls[4] = { true,true,true,true };
	char color = 177;

	MazeCell(int i,int j,bool visited);
	MazeCell();
};