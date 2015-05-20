#include <SFML\Graphics.hpp>
#include <iostream>



using namespace sf;

const int H = 22; // ������
int W = 53; // �����

const int num_maps = 2;
bool detection_pipe;
bool detection_pipe_old = false;

/*
		Q = 149,105,12,12 - ������� ���������
		W = 149,120,12,12 - ����������� ���������
		l = 149,51,12,12 - ����� ������� �����
		r = 163,51,12,12 - ������ ������� �����
		L = 149,65,12,12 - ����� ������� ������� �����
		R = 163,65,12,12 - ������ ������� ������� �����
		Z = 149,77,12,-12 - ����� ������ ������� �����
		X = 163,77,12,-12 - ������ ������ ������� �����

*/

String TileMap[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             lr          lr            lr          lr           lr           lr           lr       C ",
		"B             LR          lr            lr          lr           LR           lr           lr       C ",
		"B                         LR            lr          LR                        lr           LR       C ",
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
	// C - ������� �������

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

	void get_points(Sprite &s, bool con);

	void dlinna_map() {
		int h;
		for (int i = 0; Tile[2][i] != 'C'; i++) {
			W = i+3; }
		std::cout << "W = " << W << std::endl;
	}

} 
// � �������� ������� �������� ����, �� ��������� ������ �������������� � num_maps
// num_maps ����� �����������
level[num_maps] = {TileMap, TileMap2};
