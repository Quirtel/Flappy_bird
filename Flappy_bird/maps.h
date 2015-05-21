#include <SFML\Graphics.hpp>
#include <iostream>



using namespace sf;

const int H = 22; // высота
int W = 53; // длина

const int num_maps = 10;
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
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                                       LR                                                          C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};


	String TileMap2[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           LR       C ",
		"B             lr          lr            LR          lr           LR           lr                    C ",
		"B             LR          lr                        LR                        lr                    C ",
		"B                         lr                                                  lr                    C ",
		"B                         lr                                                  LR                    C ",
		"B                         lr                                                                        C ",
		"B                         LR                                                                        C ",
		"B                                                                                          ZX       C ",
		"B                                       ZX                       ZX                        lr       C ",
		"B             ZX                        lr          ZX           lr                        lr       C ",
		"B             lr                        lr          lr           lr                        lr       C ",
		"B             lr                        lr          lr           lr           ZX           lr       C ",
		"B             lr                        lr          lr           lr           lr           lr       C ",
		"B             lr          ZX            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap3[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                                       LR                                                          C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap4[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            LR                                    lr           LR       C ",
		"B                                                                             LR                    C ",
		"B                                                                                                   C ",
		"B                                                                                                   C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX            ZX          lr           lr                        ZX       C ",
		"B             lr          lr            lr          lr           lr           ZX           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap5[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          LR            lr          lr           lr           lr           lr       C ",
		"B             lr                        lr          lr           lr           lr           lr       C ",
		"B             lr                        lr          lr           LR           lr           lr       C ",
		"B             LR                        lr          LR                        lr           lr       C ",
		"B                                       lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                         ZX            LR                                                          C ",
		"B                         lr                                                                        C ",
		"B                         lr                                     ZX                                 C ",
		"B             ZX          lr                        ZX           lr                                 C ",
		"B             lr          lr                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap6[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                                       LR                                                          C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap7[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                                       LR                                                          C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap8[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           lr       C ",
		"B                                       lr                                    LR           lr       C ",
		"B                                       lr                                                 lr       C ",
		"B                                       LR                                                 lr       C ",
		"B                                                                                          lr       C ",
		"B                                                                ZX                        LR       C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                                 C ",
		"B             lr          lr                        lr           lr           ZX                    C ",
		"B             lr          lr                        lr           lr           lr                    C ",
		"B             lr          lr            ZX          lr           lr           lr                    C ",
		"B             lr          lr            lr          lr           lr           lr                    C ",
		"B             lr          lr            lr          lr           lr           lr           ZX       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap9[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                                       LR                                                          C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

	String TileMap10[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           LR           lr           lr       C ",
		"B             LR          lr            lr          LR                        lr           lr       C ",
		"B                         LR            lr                                    lr           LR       C ",
		"B                                       lr                                    LR                    C ",
		"B                                       lr                                                          C ",
		"B                                       LR                                                          C ",
		"B                                                                                                   C ",
		"B                                                                ZX                                 C ",
		"B             ZX                                    ZX           lr                                 C ",
		"B             lr          ZX                        lr           lr                        ZX       C ",
		"B             lr          lr                        lr           lr           ZX           lr       C ",
		"B             lr          lr                        lr           lr           lr           lr       C ",
		"B             lr          lr            ZX          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};

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
		}
		detection_pipe_old = detection_pipe;
	}

	void get_points(Sprite &s, bool con);

	void dlinna_map() {
		int h;
		for (int i = 0; Tile[2][i] != 'C'; i++) {
			W = i+3; }
		std::cout << "W = " << W << std::endl;
	}

} 
// в фигурных скобках перечень карт, их количесво должно соответсвовать с num_maps
// num_maps можно увеличивать
level[num_maps] = {TileMap, TileMap2,TileMap3,TileMap4,TileMap5,TileMap6,TileMap7,TileMap8,TileMap9,TileMap10};
