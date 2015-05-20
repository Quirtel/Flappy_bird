#include <SFML\Graphics.hpp>
#include <string>
#include "maps.h"
#include <iostream>


using namespace sf;

int height_win = 600;
int length_win = 800;
int ground = 227;

float offsetX = 0;
int start_p_x = 50;
int start_p_y = 114;
bool key_pressed = false;
int c_lvl = 0;

const int bit = 12;

bool start = false;
bool old_start = true;


// создание окна
RenderWindow window (VideoMode(142,215), "Flappy Bird - Menu");

Texture t;
Texture t2;

void map::get_points(Sprite &s, bool con){

	switch (num_points / 10){
	case 0: {s.setTextureRect(IntRect(181,3,14,20));break;}
	case 1: {s.setTextureRect(IntRect(181,25,14,20));break;}
	case 2: {s.setTextureRect(IntRect(181,47,14,20));break;}
	case 3: {s.setTextureRect(IntRect(181,69,14,20));break;}
	case 4: {s.setTextureRect(IntRect(181,91,14,20));break;}
	case 5: {s.setTextureRect(IntRect(181,113,14,20));break;}
	case 6: {s.setTextureRect(IntRect(181,135,14,20));break;}
	case 7: {s.setTextureRect(IntRect(181,157,14,20));break;}
	case 8: {s.setTextureRect(IntRect(181,179,14,20));break;}
	case 9: {s.setTextureRect(IntRect(181,201,14,20));break;}
	default: std::cout << "ERORR get points 1" << std::endl;
	}
	if (con == true){	s.setPosition(30,20);}
	else{	s.setPosition(75+start_p_x, 70);}
	window.draw(s);

	switch (num_points % 10) {
	case 0: {s.setTextureRect(IntRect(181,3,14,20));break;}
	case 1: {s.setTextureRect(IntRect(181,25,14,20));break;}
	case 2: {s.setTextureRect(IntRect(181,47,14,20));break;}
	case 3: {s.setTextureRect(IntRect(181,69,14,20));break;}
	case 4: {s.setTextureRect(IntRect(181,91,14,20));break;}
	case 5: {s.setTextureRect(IntRect(181,113,14,20));break;}
	case 6: {s.setTextureRect(IntRect(181,135,14,20));break;}
	case 7: {s.setTextureRect(IntRect(181,157,14,20));break;}
	case 8: {s.setTextureRect(IntRect(181,179,14,20));break;}
	case 9: {s.setTextureRect(IntRect(181,201,14,20));break;}
	default: std::cout << "ERORR get points 2" << std::endl;
	}
	if (con == true){	s.setPosition(30+15,20); }
	else {	s.setPosition(75+15+start_p_x, 70);}
	window.draw(s);
}


class player {

public:
	float dx, dy;
	FloatRect rect;
	bool death_p; // смерть: True - живой; False - мервыё
	Sprite sprite; //текстурка
	float current_frame; //текущий фрейм
	bool level_passed; // контроль пройденного уровня


	//-------------------------
	player(Texture &image){
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(3,5,19,15));
		rect = FloatRect(0,0,19,15);
		dx=0;
		dy=0;
		current_frame = 0;
		death_p = true;
		level_passed = false;
		start_p_y = 114;
		offsetX = 0;
	}


	//**************************
	void update(float time){
		if (!(rect.top == 0 && rect.left == 0)){
			start_p_y = 0;
		}

		if (death_p == true){
			dx = 0.08; // скорость перемещения
			rect.left += dx*time; // постоянное перемещение вправо 
		}
		else { dx = 0; }

		// анимация
		current_frame += 0.015;
		if (current_frame > 3) {current_frame = 0;}

		if (dy < 0){
			switch(int(current_frame)){
			case 1: {sprite.setTextureRect(IntRect(21,5,19,15));break;}
			case 2: {sprite.setTextureRect(IntRect(39,5,19,15));break;}
			case 0: {sprite.setTextureRect(IntRect(3,5,19,15));break;}
			}
		}


		// не даёт выйти за верхнию грницу
		if(rect.top < bit){
			rect.top = bit;
			dy = 0;
		}

		// для позиции смерти
		float rect_top_last = rect.top;

		// гравитация
		dy = dy + 0.0005 * time;
		rect.top += dy*time;
		rect.top += start_p_y;

		// обработка стлкновения по Y
		if (death_p == true) {
			CollisionY(rect_top_last);
		}

		// не даёт выйти за нижнюю границу
		if(rect.top > ground) {
			rect.top = ground;
			dy = 0;
			death_p = false;
		}

		
		// вывод
		sprite.setPosition(rect.left-offsetX+start_p_x, rect.top);

	}


	//*********************
	void CollisionY(float p) {

		int X1 = (rect.left+start_p_x) / bit;
		int Y1 = rect.top / bit;
		int X2 = (rect.left  + start_p_x + bit) / bit;
		int Y2 = (rect.top + bit) / bit;
		int X3 = (rect.left  + start_p_x + bit) / bit;
		int Y3 = rect.top / bit;
		int X4 = (rect.left+start_p_x) / bit;
		int Y4 = (rect.top + bit) / bit;

		if (level[c_lvl].Tile[Y1][X1] == 'B') {
			std::cout << "CollisionY with 'B' " << std::endl;
		}
		if (level[c_lvl].Tile[Y1][X1] == 'l' || level[c_lvl].Tile[Y1][X1] == 'r' || level[c_lvl].Tile[Y1][X1] == 'L' || 
			level[c_lvl].Tile[Y1][X1] == 'R' || level[c_lvl].Tile[Y1][X1] == 'Z' || level[c_lvl].Tile[Y1][X1] == 'X' ||
			level[c_lvl].Tile[Y1][X1] == 'Q'){
				std::cout << "Collision point (X1; Y1) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		if  (level[c_lvl].Tile[Y2][X2] == 'l' || level[c_lvl].Tile[Y2][X2] == 'r' || level[c_lvl].Tile[Y2][X2] =='L' ||
			level[c_lvl].Tile[Y2][X2] =='R' ||level[c_lvl].Tile[Y2][X2] == 'Z' || level[c_lvl].Tile[Y2][X2] == 'X' || 
			level[c_lvl].Tile[Y2][X2] =='Q') {
				std::cout << "Collision point (X2; Y2) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		if  (level[c_lvl].Tile[Y3][X3] == 'l' || level[c_lvl].Tile[Y3][X3] == 'r' || level[c_lvl].Tile[Y3][X3] =='L' ||
			level[c_lvl].Tile[Y3][X3] =='R' ||level[c_lvl].Tile[Y3][X3] == 'Z' || level[c_lvl].Tile[Y3][X3] == 'X' || 
			level[c_lvl].Tile[Y3][X3] =='Q') {
				std::cout << "Collision point (X3; Y3) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		if  (level[c_lvl].Tile[Y4][X4] == 'l' || level[c_lvl].Tile[Y4][X4] == 'r' || level[c_lvl].Tile[Y4][X4] =='L' ||
			level[c_lvl].Tile[Y4][X4] =='R' ||level[c_lvl].Tile[Y4][X4] == 'Z' || level[c_lvl].Tile[Y4][X4] == 'X' || 
			level[c_lvl].Tile[Y4][X4] =='Q') {
				std::cout << "Collision point (X4; Y4) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		level[c_lvl].points(X1);

		if (level[c_lvl].Tile[Y4][X4] == 'C'){
			level_passed = true;
		}
	};


	//****
};


bool menu (){
	window.create(VideoMode(142,215), "Flappy Bird - Menu");
	
	Sprite tile_1(t);
	Sprite tile_2(t2);
	bool c_close = true;
	while (window.isOpen()){


		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
				c_close = false; }
			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left){
					c_close = true; 
					window.close();}
        
		
		}

		tile_1.setTextureRect(IntRect(4,50,142,250));
		tile_1.setPosition(0,0);
		window.draw(tile_1);
		
		tile_1.setTextureRect(IntRect(5,20,78,22));
		tile_1.setPosition(0,0);
		window.draw(tile_1);

		tile_2.setTextureRect(IntRect(2,76,39,14));
		tile_2.setPosition(48,50);
		window.draw(tile_2);


		window.display();
	}
	return c_close;
}


void tabl(Sprite &s){
	Sprite tabl(t2);

		tabl.setTextureRect(IntRect(0,0,110,57));
		tabl.setPosition(start_p_x, 50);
		window.draw(tabl);

		tabl.setTextureRect(IntRect(43,60,39,14));
		tabl.setPosition(8+start_p_x,85);
		window.draw(tabl);

		level[c_lvl].get_points(s, false);

}


bool algorithm_gemas (){
	level[c_lvl].dlinna_map();

	player bird(t);

	window.create(VideoMode(length_win, height_win), "Flappy Bird - Game");

	Clock clock;

	Sprite tile(t);
	Sprite Fon(t);
	Sprite g_p(t);
	Sprite ready(t2);

	int PosI = 4, PosJ = 50;

	bool control_get_ready = true;
	bool press_Up;
	bool passed = false;
	bool control_start = false;
	bool skip = false;

	while (window.isOpen() && skip == false){

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/1500;

		if (control_get_ready == true) {
			press_Up = Keyboard::isKeyPressed(Keyboard::Up); 
			if (press_Up == true) {	control_get_ready = false; }
		}

		Vector2f pos = window.mapPixelToCoords(Mouse::getPosition(window));


		Event event;
		while (window.pollEvent(event)){

			if (event.type == Event::Closed){ 
				window.close(); }
			if (event.type == Event::MouseButtonReleased && (bird.death_p == false || bird.level_passed == true))
				if (event.key.code == Mouse::Left && (pos.x >= (8+start_p_x) && pos.x <= (48+start_p_x)
					&& pos.y >= 85 && pos.y <= 99) ){
					skip = true;
					control_start = true; 
					std::cout << "Mouse pressed" << std::endl;}
		}

		if (press_Up == true && bird.level_passed == false){
			if (bird.death_p == true) {
				if (Keyboard::isKeyPressed(Keyboard::Up) == true && key_pressed == false ){ 
					bird.dy = -0.2;
					key_pressed = true;
				}

				if (Keyboard::isKeyPressed(Keyboard::Up) == false){ 
					key_pressed = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::LControl)){
					system("pause");
				}
			}
			else {
				bird.dy = 0.25;
			}


			if (offsetX < 102*bit-length_win) {offsetX = bird.rect.left;}

			bird.update(time); 
		}
		else {	bird.sprite.setPosition(start_p_x, 126);}

		window.clear(Color::White);

		//
		for (int i=0; i<H;i++){
			for (int j = 0, J = 0; j < W; j++, J++) {


				// загрузка 1 слоя - фона
				if((4+J*bit) < 136){
					Fon.setTextureRect(IntRect(4+J*bit,50+i*bit,12,12));}
				else {J = 0; }

				Fon.setPosition(j*bit-offsetX,i*bit);
				window.draw(Fon);


				// загрузка 2 слоя - объектов(плиток)
				switch (level[c_lvl].Tile[i][j]){
				case 'Q': { tile.setTextureRect(IntRect(150,106,bit,bit)); break;}
				case 'W': { tile.setTextureRect(IntRect(150,121,bit,bit)); break;}
				case 'L': { tile.setTextureRect(IntRect(149,65,bit,bit)); break;}
				case 'R': { tile.setTextureRect(IntRect(163,65,bit,bit)); break;}
				case 'l': { tile.setTextureRect(IntRect(149,51,bit,bit)); break;}
				case 'r': { tile.setTextureRect(IntRect(163,51,bit,bit)); break;}
				case 'Z': { tile.setTextureRect(IntRect(149,77,bit,-bit)); break;}
				case 'X': { tile.setTextureRect(IntRect(163,77,bit,-bit)); break;}
				case 'B': { tile.setTextureRect(IntRect(150,117,bit,-bit)); break;}
				default: { tile.setTextureRect(IntRect(0,0,0,0));}
				}

				tile.setPosition(j*bit-offsetX,i*bit);
				window.draw(tile);
			}
		}
		// отображение Get_ready
		if (press_Up == false){
			ready.setTextureRect(IntRect(0,95,37,45));
			ready.setPosition(start_p_x+50,start_p_y-20);
			window.draw(ready);
			ready.setTextureRect(IntRect(3,143,86,21));
			ready.setPosition(start_p_x+20,start_p_y-60);
			window.draw(ready);
		}

		window.draw(bird.sprite);

		// таблица
		if (bird.level_passed == true){
			ready.setTextureRect(IntRect(48,76,85,29));
			ready.setPosition(start_p_x+10,20);
			window.draw(ready);
			tabl(g_p);
		}

		// отображение GAME OVER
		else if (bird.death_p == false){
			tile.setTextureRect(IntRect(59,0,93,18));
			tile.setPosition(start_p_x+10,30);
			window.draw(tile);
			tabl(g_p);
		}

		//вывод очков
		else {	level[c_lvl].get_points(g_p, true); }


		window.display();

		old_start = start;
	}

	level[c_lvl].num_points = 0;

	return control_start;
}


void main () {
	// синхронизация
	window.setVerticalSyncEnabled(true);

	t.loadFromFile("FLAPPYRED.png");
	t2.loadFromFile("FLAPPYRED2.png");


	bool control = menu();
	while(control == true) {
		control = false;
		control = algorithm_gemas();
		// каждый рестарт новая карта
		c_lvl = rand() % num_maps;
		std::cout << "Message from main cycle: step completed" << std::endl;
	}
	system("pause");
}