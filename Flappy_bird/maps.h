#include <SFML\Graphics.hpp>



using namespace sf;

const int H = 23; // высота
const int W = 54; // длина

const int num_maps = 1;

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
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr                                                                                                                                                     lr                                                B",
		"B             lr          lr																																				      lr						                        B",
		"B             lr          lr                                                                                                                                                     lr                                                B",
		"B             lr          lr																																					  lr							                    B",
		"B             LR          lr                                                                                                                                                                                                       B",
		"B                         lr                                                                                                                                                                                                       B",
		"B                         lr                                                                                                                                                                                                       B",
		"B                         LR                                                                                                                                                                                                       B",
		"B                                                                                                                                                                                                                                  B",
		"B                                                                                                                                                                                                                                  B",
		"B                                                                                                                                                                                                                                  B",
		"B                         ZX                                                                                                                                                                                                       B",
		"B             ZX          lr                                                                                                                                                                                                       B",
		"B             lr          lr                                                                                                                                                                                                       B",
		"B             lr          lr                                                                                                                                                                                                       B",
		"B             lr          lr                                                                                                                                                                                                       B",
		"B             lr          lr                                                                                                                                                                                                       B",
		"B             lr          lr                                                                                                                                                                                                       B",
		"B             lr          lr                                                                                                                                                                                                       B",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};



class map {
public:
	String *Tile;

	map(String *m){
		Tile = m;
	}

} 
// в фигурных скобках перечень карт, их количесво должно соответсвовать с num_maps
// num_maps можно увеличивать
level[num_maps] = {TileMap};
