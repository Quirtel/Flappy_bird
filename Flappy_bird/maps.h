#include <SFML\Graphics.hpp>



using namespace sf;

const int H = 23; // ������
const int W = 53; // �����

const int num_maps = 1;
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
// � �������� ������� �������� ����, �� ��������� ������ �������������� � num_maps
// num_maps ����� �����������
level[num_maps] = {TileMap};
