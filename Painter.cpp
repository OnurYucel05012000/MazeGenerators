#include "Painter.h"
#include "MazeCell.h"

#include<iostream>
#include<windows.h>
/*
   *----------->Y
   |
   |
   |
   |
   X
      
   */
//void Painter::Painter(int MAZE_I,int MAZE_J) {
	//this->MAZE_I = MAZE_I;
	//this->MAZE_J = MAZE_J;
//}
Painter::Painter() {
	CreateMaze_Char_Array();
}
void Painter::Clear() {
	//clear->draw->RBT->datain->...

	CreateMaze_Char_Array();

	//Burda hucrelerin sinirini belirlerken ayný islem iki kez yapiliyor bakiniz (W)
	//xxqxx
	//xxqxx
	//qq(W)qq    
	for (int i = 0;i < MAZE_I;i++) {
		for (int j = 0; j < MAZE_J; j++)
		{
			if ((j + 1) % 3 == 0 && i + 1 < MAZE_I) {

				Maze[i][j] = 178;
				Maze[i + 1][j] = 178;
			}
			if ((i + 1) % 3 == 0) {

				Maze[i][j] = 178;
			}
		}
	}
}

void Painter::JustPutdata(MazeCell** cells){
int Cell_i = 0;
int Cell_j = 0;



for (int i = 0;i < MAZE_I;i += 3) {
	for (int j = 0;j < MAZE_J;j += 3) {

		Maze[i][j] = cells[Cell_i][Cell_j].color;
		Maze[i][j + 1] = cells[Cell_i][Cell_j].color;
		Maze[i + 1][j] = cells[Cell_i][Cell_j].color;
		Maze[i + 1][j + 1] = cells[Cell_i][Cell_j].color;


		//TRUE-->Duvar var 
		//FALSE-->Duvar yok

		////sol
		if (!cells[Cell_i][Cell_j].walls[0] && j - 1 >= 0) {
			Maze[i][j - 1] = cells[Cell_i][Cell_j].color;
			Maze[i + 1][j - 1] = cells[Cell_i][Cell_j].color;
		}
		////ust
		if (!cells[Cell_i][Cell_j].walls[1] && i - 1 >= 0) {
			Maze[i - 1][j] = cells[Cell_i][Cell_j].color;
			Maze[i - 1][j + 1] = cells[Cell_i][Cell_j].color;
		}
		////sag
		if (!cells[Cell_i][Cell_j].walls[2] && j + 1 <= MAZE_J) {
			Maze[i][j + 2] = cells[Cell_i][Cell_j].color;
			Maze[i + 1][j + 2] = cells[Cell_i][Cell_j].color;
		}
		////alt
		if (!cells[Cell_i][Cell_j].walls[3] && i + 1 <= MAZE_I) {
			Maze[i + 2][j] = cells[Cell_i][Cell_j].color;
			Maze[i + 2][j + 1] = cells[Cell_i][Cell_j].color;
		}

		Cell_j++;
	}//for j END
	Cell_j = 0;
	Cell_i++;

 }//For i END
Sleep(100);
gotoxy(0, 0);
}//Method END

void Painter::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void Painter::PutDatainMaze(MazeCell** cells) {
	
	CreateMaze_Char_Array();

	

	//Burda hucrelerin sinirini belirlerken ayný islem iki kez yapiliyor bakiniz (W)
	//xxqxx
	//xxqxx
	//qq(W)qq    
	for (int i = 0;i < MAZE_I;i++) {
		for (int j = 0; j < MAZE_J; j++)
		{
			if ((j + 1) % 3 == 0 && i+1<MAZE_I) {
				
				Maze[i][j] = 178;
				Maze[i+1][j] = 178;
			}
			if ((i + 1) % 3 == 0) {
				
				Maze[i][j] = 178;
			}
		}
	}

	int Cell_i = 0;
	int Cell_j = 0;

	for (int i = 0;i < MAZE_I;i += 3) {
		for (int j = 0;j < MAZE_J;j+=3) {
              						
			Maze[i][j] = cells[Cell_i][Cell_j].color;
			Maze[i][j+1] = cells[Cell_i][Cell_j].color;
			Maze[i+1][j] = cells[Cell_i][Cell_j].color;
			Maze[i+1][j+1] = cells[Cell_i][Cell_j].color;


			//TRUE-->Duvar var 
			//FALSE-->Duvar yok

			////sol
			if (!cells[Cell_i][Cell_j].walls[0] && j-1>=0) {
				Maze[i][j-1] = cells[Cell_i][Cell_j].color;
				Maze[i+1][j-1] = cells[Cell_i][Cell_j].color;
			}
			////ust
			if (!cells[Cell_i][Cell_j].walls[1] && i-1>=0) {
				Maze[i-1][j] = cells[Cell_i][Cell_j].color;
				Maze[i-1][j +1] = cells[Cell_i][Cell_j].color;
			}
			////sag
			if (!cells[Cell_i][Cell_j].walls[2] && j+1<=MAZE_J) {
				Maze[i][j+2] = cells[Cell_i][Cell_j].color;
			    Maze[i+1][j+2] = cells[Cell_i][Cell_j].color;
			}
			////alt
			if (!cells[Cell_i][Cell_j].walls[3] && i+1<=MAZE_I) {
				Maze[i+2][j] = cells[Cell_i][Cell_j].color;
				Maze[i+2][j+1] = cells[Cell_i][Cell_j].color;
			}

			Cell_j++;
		}//for j END
		Cell_j = 0;
		Cell_i++;
		
	}//For i END
}//Method END

void Painter::Draw() {
	for (int i = 0;i < MAZE_I;i++) {
		for(int j = 0; j < MAZE_J; j++)
		{
			if (Maze[i][j] == 178) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				std::cout << Maze[i][j];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				std::cout << Maze[i][j];
			}
			

			
		}
		std::cout<<"\n";
	}
}

void Painter::CreateMaze_Char_Array() {


	Maze = new char*[MAZE_I];
	for (int i = 0;i < MAZE_I;i++) {
		Maze[i] = new char[MAZE_J];
	}
}

void Painter::setMAZE_I(int MAZE_I) {
	this->MAZE_I = MAZE_I;
}

void Painter::setMAZE_J(int MAZE_J) {
	this->MAZE_J = MAZE_J;
}

int Painter::getMAZE_I() {
	return MAZE_I;
}

int Painter::getMAZE_J() {
	return MAZE_J;
}