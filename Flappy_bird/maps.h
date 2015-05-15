#include <SFML\Graphics.hpp>



using namespace sf;

const int H = 23; // высота
const int W = 53; // длина

const int num_maps = 1;
bool detection_pipe;
bool detection_pipe_old = false;

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
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             LR          lr                        B",
		"B                         LR                        B",
		"B                                                   B",
		"B                                                   B",
		"B                                                   B",
		"B                                                   B",
		"B                                                   B",
		"B                         ZX                        B",
		"B             ZX          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"B             lr          lr                        B",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};



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
		}
		detection_pipe_old = detection_pipe;
	}

	void get_points(Sprite &s);


} 
// в фигурных скобках перечень карт, их количесво должно соответсвовать с num_maps
// num_maps можно увеличивать
level[num_maps] = {TileMap};
