#include <SFML\Graphics.hpp>
#include <string>

using namespace sf;

int ground = 350;

float offsetX=0, offsetY=0;

const int H = 16;
const int W = 54;

String TileMap[H] = {
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B              B                                     B",
	"B                                                    B",
	"B                                                    B",
	"B                                                    B",
	"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH",
	"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH",
}; 


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
		rect = FloatRect(0,-300,-50,-300);
		dx=0;
		dy=0;
		current_frame = 0;
	}

	void update(float time){
		dx = 0.08; // скорость перемещения
		rect.left += dx*time; // постоянное перемещение вправо
		Collision(0);
		// гравитация
		dy = dy + 0.0005 * time;
		rect.top += dy*time;
		Collision(1);
		// не даёт выйти за платформу
		if(rect.top > ground) {
			rect.top = ground;
			dy = 0;
			on_ground = true;
		}


		// вывод
		sprite.setPosition(rect.left-offsetX+50, rect.top - offsetY+80);
	}

	void Collision(int dir)
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
   
   }


};



void main () {

	RenderWindow window (VideoMode(1000,500), "Flappy Bird");  

	Texture t;
	t.loadFromFile("FLAPPYRED.png");

	player bird(t);

	Clock clock;

	RectangleShape rectangle(Vector2f(32,32));



	while (window.isOpen()){

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/900;

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
			for (int j=0; j<W;j++) {

				if (TileMap[i][j] == 'B'){ 
					rectangle.setFillColor(sf::Color::Green);
				}
				if (TileMap[i][j] == 'H') {
					rectangle.setFillColor(sf::Color::Red);
				}
				if (TileMap[i][j] == ' ') {
					rectangle.setFillColor(sf::Color::White);
				}

				rectangle.setPosition(j*32-offsetX,i*32-offsetY);
				window.draw(rectangle);
			}

		}



		window.draw(bird.sprite);
		window.display();
	}
}