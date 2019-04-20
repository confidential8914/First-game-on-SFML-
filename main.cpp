#include <windows.h>
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;
using namespace std;

#define VFrame 7
#define SizeWindowX 640
#define SizeWindowY 640 

class PLAYER
{
private:
	
	#define VFrame 7
	
	int SizeX;
	int SizeY;
	
	Texture TPlayer;

	float time;
	float NumberFrame;	
	
public:
	
	float Speed;
	
	Sprite sprite;
	
	PLAYER()
	{	
		Speed = 1.1;
		
	    SizeX = 75; 
		SizeY = 85;
		
		TPlayer.loadFromFile("Spritse\\sprite.png");
		sprite.setTexture(TPlayer);
		sprite.setTextureRect(IntRect(85, 10, SizeX, SizeY));
		sprite.setPosition(0, 500);
	}
	
	~PLAYER()
	{}
		
private:
	
public:
	
	void Update(float time)
	{
		this->time = time;
	}
	
	void Control()
	{
		//////////////// Control ///////////////////
			
		if(Keyboard::isKeyPressed(Keyboard::Left))
		{
			sprite.move(-0.15 * time, 0);	
			
			NumberFrame += 0.006 * time;
			
		    if(NumberFrame > VFrame)
				NumberFrame -= VFrame;	
			
			sprite.setTextureRect(IntRect(85 + (80 * int(NumberFrame)) + 80, 10, -75, 65));
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Right))
		{
			sprite.move(0.15 * time, 0);
			
			NumberFrame += 0.006 * time;
			
		    if(NumberFrame > VFrame)
				NumberFrame -= VFrame;	
			
			sprite.setTextureRect(IntRect(85 + (80 * int(NumberFrame)), 10, 75, 65));	
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Up))
		{
			sprite.move(0, -0.1);	
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.move(0, 0.1);	
		}
		
		//////////////// Control ///////////////////
	}
	
}Player;

void Update(float time)
{
	Player.Update(time);	
}


int main()
{
	RenderWindow window(VideoMode(SizeWindowX, SizeWindowY), "First game");
	
	float NumberFrame;	
	
	Clock clock;
		
	while(window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		
		time = time / 800;
		time *= Player.Speed;
		
		Event event;
		
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();
		}
		
		Player.Control();
		
		Update(time);
		
		window.clear();
		window.draw(Player.sprite);
		window.display();
		
	}
	
	
	
    return 0;
}





