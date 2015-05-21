#include <SFML\Graphics.hpp>
#include <iostream>



using namespace sf;

const int H = 22; // ������
int W = 89; // �����

const int num_maps = 1;
bool detection_pipe;
bool detection_pipe_old = false;

	Music wing;
	Music die;
	Music point;

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
		 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		 "B             lr          lr            lr          lr           lr           lr           lr",
		 "B             lr          lr            lr          lr           lr           lr           lr",
		 "B             lr          lr            lr          lr           lr           lr           LR",
		 "B             lr          lr            LR          lr           LR           lr             ",
		 "B             LR          lr                        LR                        lr             ",
		 "B                         lr                                                  lr             ",
		 "B                         lr                                                  LR             ",
		 "B                         lr                                                                 ",
		 "B                         LR                                                                 ",
		 "B                                                                                          ZX",
		 "B                                       ZX                       ZX                        lr",
		 "B             ZX                        lr          ZX           lr                        lr",
		 "B             lr                        lr          lr           lr                        lr",
		 "B             lr                        lr          lr           lr           ZX           lr",
		 "B             lr                        lr          lr           lr           lr           lr",
		 "B             lr          ZX            lr          lr           lr           lr           lr",
		 "B             lr          lr            lr          lr           lr           lr           lr",
		 "B             lr          lr            lr          lr           lr           lr           lr",
		 "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
		 "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		 "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	};



void generate_map(){

	String B = "BBBBBBBBBBB";
	String lr = "         lr";
	String LR = "         LR";
	String ZX = "         ZX";
	String Q = "QQQQQQQQQQQ";
	String W2 = "WWWWWWWWWWW";
	String empty_str = "           ";

	int order = rand() % 7 + 2;

	W += 11;

	TileMap[0]  += B;
	
	int control;


	// ���� ������� �������
	for (int j = 1; j < order; j++){
		TileMap[j] += lr;
		control = j;
	}
	TileMap[order] += LR;
	
	// ���� �������
	for (int j = order+1; j < (control + 7); j++) {
		TileMap[j] += empty_str;
	}
	control += 7;

	// ���� ������ �������
	TileMap[control] += ZX;
	control ++;
	for (int j = control; j <= 18; j++){
		TileMap[j] += lr;
	}

	// ������ ���������
	TileMap[19] += Q;
	TileMap[20] += W2;
	TileMap[21] += W2;
}


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

} 
// � �������� ������� �������� ����, �� ��������� ������ �������������� � num_maps
// num_maps ����� �����������
level[num_maps] = {TileMap};
