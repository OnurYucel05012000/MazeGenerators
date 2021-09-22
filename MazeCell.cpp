#include "MazeCell.h"
MazeCell::MazeCell(int i,int j,bool visited) {

	this->i = i;
	this->j = j;
	this->visited = visited;

}
MazeCell::MazeCell() {
	i = 0;
	j = 0;
	visited = false;

}