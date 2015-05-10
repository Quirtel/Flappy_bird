#include <SFML\Graphics.hpp>

using namespace sf;

int ground = 350;

const int H = 17;
const int W = 149;

class player {

public:
	float dx, dy;
	FloatRect rect;
	bool on_ground; //где игрок: земля - воздух
	Sprite sprite; //текстурка
	float current_frame; //текущий фрейм

	player(Texture &image){
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(3,5,20,17));
		rect = FloatRect(0,0,0,0);
		dx=0;
		dy=0;
		current_frame = 0;
	}

	void update(float time){
		rect.left += dx*time;

		if (!on_ground){ dy = dy + 0.0005 * time;}

		rect.top += dy*time;
		on_ground = false;

		if(rect.top > ground) {
			rect.top = ground;
			dy = 0;
			on_ground = true;
		}

		sprite.setPosition(rect.left, rect.top);

		dx = 0;
	}
};



void main () {

	RenderWindow window (VideoMode(600, 400), "Flappy Bird");

	String TileMap[H] = {
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                                                                                                   0",
	"0             0                                                                                                                                     0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                  P                                                                                                                0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"0                                                                                                                                                   0",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
}; 

	Texture t;
	t.loadFromFile("FLAPPYRED.png");

	player bird(t);

	Clock clock;

	RectangleShape rectangle;

	while (window.isOpen()){

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/900;

		Event event;
		while (window.pollEvent(event)){

			if (event.type == Event::Closed){ 
				window.close(); }
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)){
			bird.dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)){
			bird.dy = -0.2; bird.on_ground = false;
		}

		bird.update(time);
		window.clear(Color::White);


		for (int i=0; i<H;i++){
			for (int j=0; j<W;j++) {

				if (TileMap[i][j] == '0') 
					rectangle.setFillColor(sf::Color::Black);
				if (TileMap[i][j] == 'Р') 
					rectangle.setFillColor(sf::Color::Red);
				if (TileMap[i][j] == ' ') 
					continue;

				rectangle.setPosition(j*32,i*32);
				window.draw(rectangle);
			}

		}
		
		window.draw(bird.sprite);
		window.display();
	}
}