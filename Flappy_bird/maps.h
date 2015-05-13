#include <SFML\Graphics.hpp>



using namespace sf;

const int H = 23; // ������
const int W = 54; // �����

const int num_maps = 1;

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
// � �������� ������� �������� ����, �� ��������� ������ �������������� � num_maps
// num_maps ����� �����������
level[num_maps] = {TileMap};
