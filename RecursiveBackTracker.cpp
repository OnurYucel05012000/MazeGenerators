#include "RecursiveBackTracker.h"
#include<random>
#include <typeinfo>

	 std::vector<MazeCell> RandomNeigbor;
	 std::stack<MazeCell> CellStack;
	 

	 //DIKKAT WIDTH = HEIGHT
RecursiveBackTracker::RecursiveBackTracker(int width,int heigth,int Starting_i,int Starting_j) {
	this->width = width;
	this->height = height;
	this->Starting_i = Starting_i;
	this->Starting_j = Starting_j;


}
RecursiveBackTracker::~RecursiveBackTracker() {
	/*for (int i = 0;i < MAXCELL;i++) {
		delete cell[i];
	}
	delete cell;*/
}
void RecursiveBackTracker::Start() {

	if (CalculateMazeCellArea())
	{

		Painter painter;

		painter.setMAZE_I(width);
		painter.setMAZE_J(width);

		

		CreateCells();

		Run(cell);


		

		painter.PutDatainMaze(cell);
		painter.Draw();
	}
}

bool RecursiveBackTracker::CalculateMazeCellArea() {
	//2*2+1=5  5-1=4 4/2=2 MazeCell*p = 2x2

	
		
	//Maxcell tam sayi degilse 
	MAXCELL = (width + 1) / 3;
	if (*typeid(MAXCELL).name() == 'i')return true;
			
	return false;
}

void RecursiveBackTracker::CreateCells() {
	int x = 0, y = 0;
	
	cell = new MazeCell*[MAXCELL];
	for (int i = 0;i < MAXCELL;i++) {
		cell[i] = new MazeCell[MAXCELL];
	}

	for (int i = 0;i < MAXCELL;i++) {
		for (int j = 0; j < MAXCELL;j++) {


			//cell[i][j] = new MazeCell(x, y, false);
			cell[i][j].i = x;
			cell[i][j].j = y;
			cell[i][j].visited = false;
			y++;

		}
		x++;
		y = 0;

	}
}

//Normalde rekursif fonksiyon olucak ama beceremedim **p le nasil deger p[0][0] gondericem bilmiyom
void RecursiveBackTracker::Run(MazeCell** cell) {

	std::random_device dev;
	std::mt19937 rng(dev());
	

	short RND_MAX = 0;

	//Baslangici gidildi isaretle
	cell[Starting_i][Starting_j].visited = true;

	int i=0,j=0;
	//Baslangi stacke atilir bunu yapmak yerine do while yazip onun icinde yapilabilirdi
	CellStack.push(cell[Starting_i][Starting_j]);

	while (!CellStack.empty()) {
         
		//rastgele gidilecek (gidilmeyen) komsular icin vector olustur 
		//std::vector<MazeCell> RandomNeigbor;
		//std::stack<MazeCell> CellStack;

		//Komsulara bak gidildimi diye	
	
		//yukari
		if (Starting_i - 1 >= 0 && !cell[Starting_i - 1][Starting_j].visited) {
			RandomNeigbor.push_back(cell[Starting_i - 1][Starting_j]);
			RND_MAX++;
		}
		//asagi
		if (Starting_i + 1 < MAXCELL   &&!cell[Starting_i + 1][Starting_j].visited ) {
			RandomNeigbor.push_back(cell[Starting_i + 1][Starting_j]);
			RND_MAX++;
		}
		//sol
		if (Starting_j - 1 >= 0  &&!cell[Starting_i][Starting_j - 1].visited ) {
			RandomNeigbor.push_back(cell[Starting_i][Starting_j - 1]);
			RND_MAX++;
		}
		//sag
		if (Starting_j + 1 < MAXCELL   &&!cell[Starting_i][Starting_j + 1].visited ) {
			RandomNeigbor.push_back(cell[Starting_i][Starting_j+1]);
			RND_MAX++;
		}

		//Gidilcek komsu yoksa Yýgýn bosalt
		if (RandomNeigbor.empty()) {
			CellStack.pop();
			if (CellStack.empty())break;
			Starting_i = CellStack.top().i;
			Starting_j = CellStack.top().j;
		}
		else {
			//Yýgýnýn basindaki elemani fonksiyona gonder

			//********

			std::uniform_int_distribution<std::mt19937::result_type> dist6(0, RND_MAX-1); // distribution in range [0, 4]
			//Listeden Rastgele birini sec , i ve j sini al
			int randomnumber = dist6(rng);
			i = RandomNeigbor[randomnumber].i;
			j = RandomNeigbor[randomnumber].j;

			//Duvarlari sil 

		

			//sol,ust,sag,alt
	        //walls[0]=>sol
			//sol
			if (j + 1 == Starting_j && i == Starting_i)
				cell[Starting_i][Starting_j].walls[0] = false;
			//ust
			if (i + 1 == Starting_i && j == Starting_j)
				cell[Starting_i][Starting_j].walls[1] = false;
			//sag
			if (j - 1 == Starting_j && i == Starting_i)
				cell[Starting_i][Starting_j].walls[2] = false;			
			//alt
			if (i - 1 == Starting_i && j == Starting_j)
				cell[Starting_i][Starting_j].walls[3] = false;

			

			//RandomNeigbor[RandomNeigbor];

			//Gidildi isaretle		
			cell[i][j].visited = true;

			//Yýgýna at
			Starting_i = i;
			Starting_j = j;
			CellStack.push(cell[i][j]);
			

			//Gidilcek yer merkez olsun
			
			RND_MAX = 0;
			//Oraya git
			
			
			


			//Yýgýn boslasiya kadar devam et
		}//ELSE END
		RandomNeigbor.clear();
	}//WHILE END

}//METHOD END

