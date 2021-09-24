#include<iostream>

#include "RecursiveBackTracker.h"

//there is problem with dynamic painter.maze array

int main() {
	RecursiveBackTracker mazeGenerator(20, 20, 0, 0);
	//3g-1=W  
	mazeGenerator.Start();
	char Choice;
	int w;
	bool running = true;
	while (running) {
		std::cout << "________________" << "\n";
		std::cout << "q new maze" << "\n";
		std::cout << "e exit" << "\n";
		std::cout << "w width" << "\n";
		std::cout << "________________" << "\n";
		std::cin >> Choice;
		switch (Choice)
		{
		case 'q':
			mazeGenerator.Start();
			break;
		case 'e':
			running = false;
			break;
		case 'w':
			std::cin >> w;
			  if(w>0 && w<100)
			  {
			     mazeGenerator.width = w;
			     mazeGenerator.Start();
		          }
			break;
		}
	}
	
	std::getchar();
}
