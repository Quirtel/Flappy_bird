#include <SFML\Graphics.hpp>
#include <string>
#include "maps.h"


using namespace sf;

int ground = 231;

float offsetX=0, offsetY=0;

const int bit = 12;

// создание окна
RenderWindow window (VideoMode(1000,500), "Flappy Bird");


class player {

public:
	float dx, dy;
	FloatRect rect;
	bool on_ground; //где игрок: земля - воздух
	Sprite sprite; //текстурка
	float current_frame; //текущий фрейм

	player(Texture &image){
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(3,5,19,15));
		rect = FloatRect(0,0,0,0);
		dx=0;
		dy=0;
		current_frame = 0;
	}

	void update(float time){
		dx = 0.08; // скорость перемещения
		rect.left += dx*time; // постоянное перемещение вправо 
		
		
		
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
		
		// гравитация
		dy = dy + 0.0005 * time;
		rect.top += dy*time;
		

		// не даёт выйти за платформу
		if(rect.top > ground) {
			rect.top = ground;
			dy = 0;
			on_ground = true;
		}


		// вывод
		sprite.setPosition(rect.left-offsetX+50, rect.top - offsetY+80);
	}

	/*void Collision(int dir)
   {
     for (int i = rect.top/32 ; i<(rect.top+rect.height)/32; i++)
	  for (int j = rect.left/32; j<(rect.left+rect.width)/32; j++)
		{ 
	  	 if (TileMap[i][j]=='B') 
		   { 
	        if ((dx>0) && (dir==0)) rect.left =  j*32 -  rect.width; 
		    if ((dx<0) && (dir==0)) rect.left =  j*32 + 32;
			if ((dy>0) && (dir==1))  { rect.top =   i*32 -  rect.height/2;}
			if ((dy<0) && (dir==1))  { rect.top = i*32 + 60; }
		   }
		 
		 if (TileMap[i][j]=='H') 
		                   { 
			                 TileMap[i][j]=' ';
		                   }
	         	
    	}
   
   }*/


};



void main () {

	Texture t;
	t.loadFromFile("FLAPPYRED.png");

	player bird(t);

	Clock clock;

	Sprite tile(t);
	Sprite Fon(t);

	int PosI = 4, PosJ = 50;
	
	while (window.isOpen()){
		
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/900;
		
		/*
		map level[1];
		for (int i = 0; i < H; i++){
			level[0].Map[i] = TileMap[i];
		}*/

		
		Event event;
		while (window.pollEvent(event)){

		if (event.type == Event::Closed){ 
				window.close(); }
		}


		if (Keyboard::isKeyPressed(Keyboard::Up)){
			bird.dy = -0.25;
		}
		
		bird.update(time);

		offsetX = bird.rect.left;

		window.clear(Color::White);
		
		
		for (int i=0; i<H;i++){
			for (int j = 0, J = 0; j < W; j++, J++) {

				/* Потом доделаю
				// загрузка 1 слоя - фона
				if((4+J*bit) < 136){
					Fon.setTextureRect(IntRect(4+J*bit,50+i*bit,12,12));}
				else {J = 0; }
				
				Fon.setPosition(j*bit,i*bit);
				window.draw(Fon);
				*/
				
				// загрузка 2 слоя - объектов(плиток)
				switch (level[0].Tile[i][j]){
					case 'Q': { tile.setTextureRect(IntRect(150,106,12,12)); break;}
					case 'W': { tile.setTextureRect(IntRect(150,121,12,12)); break;}
					case 'L': { tile.setTextureRect(IntRect(149,65,12,12)); break;}
					case 'R': { tile.setTextureRect(IntRect(163,65,12,12)); break;}
					case 'l': { tile.setTextureRect(IntRect(149,51,12,12)); break;}
					case 'r': { tile.setTextureRect(IntRect(163,51,12,12)); break;}
					case 'Z': { tile.setTextureRect(IntRect(149,77,12,-12)); break;}
					case 'X': { tile.setTextureRect(IntRect(163,77,12,-12)); break;}
					default: { tile.setTextureRect(IntRect(0,0,0,0));}
				}
				
				tile.setPosition(j*bit-offsetX,i*bit-offsetY);
				window.draw(tile);
			}
		}
		
		window.draw(bird.sprite);
		window.display(); 
	}
	
}