#include <SFML\Graphics.hpp>

using namespace sf;

int ground = 90;


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
		dx=dy=0;
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

	RenderWindow window (VideoMode(100, 100), "Flappy Red");


	Texture t;
	t.loadFromFile("FLAPPYRED.png");

	player bird(t);

	Clock clock;

	while (window.isOpen()){

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time/700;

		Event event;
		while (window.pollEvent(event)){
			
			if (event.type == Event::Closed){ 
				window.close(); }
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)){
			bird.dx = 0.1;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up)){
			if (bird.on_ground) {bird.dy = -0.4; bird.on_ground = false;}
		}


		bird.update(time);

		window.clear();
		window.draw(bird.sprite);
		window.display();
	}
}