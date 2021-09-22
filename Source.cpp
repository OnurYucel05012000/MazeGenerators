#include<iostream>

#include "RecursiveBackTracker.h"



int main() {
	RecursiveBackTracker mazeGenerator(20, 20, 0, 0);
	//3g-1=W  
	mazeGenerator.Start();
	char Choice;
	int w;
	bool running = true;
	while (running) {
		std::cout << "________________" << "\n";
		std::cout << "q yeni labirent" << "\n";
		std::cout << "e cikis" << "\n";
		std::cout << "w genislik" << "\n";
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
			mazeGenerator.width = w;
			mazeGenerator.Start();
			break;
		}
	}
	
	std::getchar();
}
