#include <SFML\Graphics.hpp>
#include <string>
#include "maps.h"
#include <iostream>


using namespace sf;

int ground = 227;

float offsetX = 0;
int start_p_x = 50;
int start_p_y = 114;
bool key_pressed = false;


const int bit = 12;

// создание окна
RenderWindow window (VideoMode(700,500), "Flappy Bird");


class player {

public:
	float dx, dy;
	FloatRect rect;
	bool death_p; // смерть: True - живой; False - мервыё
	Sprite sprite; //текстурка
	float current_frame; //текущий фрейм


//-------------------------
	player(Texture &image){
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(3,5,19,15));
		rect = FloatRect(0,0,19,15);
		dx=0;
		dy=0;
		current_frame = 0;
		death_p = true;
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
		
		// обработка столкновения по Х
		
				
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

		if (level[0].Tile[Y1][X1] == 'B') {
			std::cout << "CollisionY with 'B' " << std::endl;
		}
		if (level[0].Tile[Y1][X1] == 'l' || level[0].Tile[Y1][X1] == 'r' || level[0].Tile[Y1][X1] == 'L' || 
			level[0].Tile[Y1][X1] == 'R' || level[0].Tile[Y1][X1] == 'Z' || level[0].Tile[Y1][X1] == 'X' ||
			level[0].Tile[Y1][X1] == 'Q'){
				std::cout << "Collision point (X1; Y1) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		if  (level[0].Tile[Y2][X2] == 'l' || level[0].Tile[Y2][X2] == 'r' || level[0].Tile[Y2][X2] =='L' ||
			level[0].Tile[Y2][X2] =='R' ||level[0].Tile[Y2][X2] == 'Z' || level[0].Tile[Y2][X2] == 'X' || 
			level[0].Tile[Y2][X2] =='Q') {
				std::cout << "Collision point (X2; Y2) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		if  (level[0].Tile[Y3][X3] == 'l' || level[0].Tile[Y3][X3] == 'r' || level[0].Tile[Y3][X3] =='L' ||
			level[0].Tile[Y3][X3] =='R' ||level[0].Tile[Y3][X3] == 'Z' || level[0].Tile[Y3][X3] == 'X' || 
			level[0].Tile[Y3][X3] =='Q') {
				std::cout << "Collision point (X3; Y3) " << std::endl;
				rect.top = p;
				death_p = false;
		}
		if  (level[0].Tile[Y4][X4] == 'l' || level[0].Tile[Y4][X4] == 'r' || level[0].Tile[Y4][X4] =='L' ||
			level[0].Tile[Y4][X4] =='R' ||level[0].Tile[Y4][X4] == 'Z' || level[0].Tile[Y4][X4] == 'X' || 
			level[0].Tile[Y4][X4] =='Q') {
				std::cout << "Collision point (X4; Y4) " << std::endl;
				rect.top = p;
				death_p = false;
		}

	};


//****
};

void algorithm_gemas (Texture &t){
	player bird(t);

	Clock clock;

	Sprite tile(t);
	Sprite Fon(t);

	int PosI = 4, PosJ = 50;
	
	while (window.isOpen()){
		
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/1500;
		
		Event event;
		while (window.pollEvent(event)){

			if (event.type == Event::Closed){ 
				window.close(); }
		}

		if (bird.death_p == true) {
			if (Keyboard::isKeyPressed(Keyboard::Up) == true && key_pressed == false ){ 
				bird.dy = -0.25;
				key_pressed = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::Up) == false){ 
				key_pressed = false;
			}
		}
		else {
			bird.dy = 0.25;
		}
		
		offsetX = bird.rect.left;

		bird.update(time); 
		

		window.clear(Color::White);
		
		
		for (int i=0; i<H;i++){
			for (int j = 0, J = 0; j < W; j++, J++) {

				
				// загрузка 1 слоя - фона
				if((4+J*bit) < 136){
					Fon.setTextureRect(IntRect(4+J*bit,50+i*bit,12,12));}
				else {J = 0; }
				
				Fon.setPosition(j*bit-offsetX,i*bit);
				window.draw(Fon);
				
				
				// загрузка 2 слоя - объектов(плиток)
				switch (level[0].Tile[i][j]){
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

		// отображение GAME OVER
		if (bird.death_p == false){
			tile.setTextureRect(IntRect(59,0,93,18));
			tile.setPosition(start_p_x + 50,110);
			window.draw(tile);
		}
		
		window.draw(bird.sprite);
		window.display();

	}
}


void main () {

	Texture t;
	t.loadFromFile("FLAPPYRED.png");

	algorithm_gemas(t);
	
}