#include <SFML\Graphics.hpp>
#include <iostream>



using namespace sf;

const int H = 22; // высота
int W = 102; // длина

const int num_maps = 1;
bool detection_pipe;
bool detection_pipe_old = false;

	Music wing;
	Music die;
	Music point;

/*
		Q = 149,105,12,12 - граница платформы
		W = 149,120,12,12 - продолжение платформы
		l = 149,51,12,12 - левая сторона трубы
		r = 163,51,12,12 - правая сторона трубы
		L = 149,65,12,12 - левая верхняя сторона трубы
		R = 163,65,12,12 - правая верхняя сторона трубы
		Z = 149,77,12,-12 - левая нижняя сторона трубы
		X = 163,77,12,-12 - правая нижняя сторона трубы

*/

String TileMap[H] = {
		L"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		L"B             lr          lr            lr          lr           lr           lr           lr             ",
		L"B             lr          lr            lr          lr           lr           lr           lr             ",
		L"B             lr          lr            lr          lr           lr           lr           LR             ",
		L"B             lr          lr            LR          lr           LR           lr                          ",
		L"B             LR          lr                        LR                        lr                          ",
		L"B                         lr                                                  lr                          ",
		L"B                         lr                                                  LR                          ",
		L"B                         lr                                                                              ",
		L"B                         LR                                                                              ",
		L"B                                                                                          ZX             ",
		L"B                                       ZX                       ZX                        lr             ",
		L"B             ZX                        lr          ZX           lr                        lr             ",
		L"B             lr                        lr          lr           lr                        lr             ",
		L"B             lr                        lr          lr           lr           ZX           lr             ",
		L"B             lr                        lr          lr           lr           lr           lr             ",
		L"B             lr          ZX            lr          lr           lr           lr           lr             ",
		L"B             lr          lr            lr          lr           lr           lr           lr             ",
		L"B             lr          lr            lr          lr           lr           lr           lr             ",
		L"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		L"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		L"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};



void generate_map(){

	String B = L"BBBBBBBBBBB";
	String lr = L"        lr";
	String LR = L"         LR";
	String ZX = L"         ZX";
	String Q = L"QQQQQQQQQQQ";
	String W2 = L"WWWWWWWWWWW";

	int order = rand() % 7 + 2;

	W += 11;

	TileMap[0]  += B.toUtf32();

	for (int i=1; i<21; i++)
	{
		if (i != order || i != 19 || i != 20 || i != 21){
			TileMap[i] += lr.toUtf32();
		} 
		else if (i == order){
			TileMap[order] += LR.toUtf32();
			TileMap[order+7] += ZX.toUtf32();
			i+=7;
		}

		if (i == 19) TileMap[i] += Q.toUtf32();
		if (i == 20 || i == 21) TileMap[i] += W2.toUtf32();
	}
	


}




	// C - уровень пройден

class map {
public:
	String *Tile;
	int num_points;

	map(String *m){
		Tile = m;
		num_points = 0;
	}

	void points (int pos_X) {
		if (Tile[1][pos_X] == 'r' || Tile[19][pos_X] == 'r') {
			detection_pipe = true; }
		else { detection_pipe = false; }
		if (detection_pipe_old == true && (Tile[1][pos_X] == ' ' || Tile[19][pos_X] == ' ')){
			num_points += 1;
			point.play();
			generate_map();
		}
		detection_pipe_old = detection_pipe;
	}

	void get_points(Sprite &s, bool con);

	/*void dlinna_map() {
		int h;
		for (int i = 0; Tile[2][i] != 'C'; i++) {
			W = i+3; }
		std::cout << "W = " << W << std::endl;
	}*/

} 
// в фигурных скобках перечень карт, их количесво должно соответсвовать с num_maps
// num_maps можно увеличивать
level[num_maps] = {TileMap};
