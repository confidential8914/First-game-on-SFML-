#include <windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const int SizeWindowX = 900;
const int SizeWindowY = 640; 

#include "Map.h"
#include "Player.h"

PLAYER Player;
MAP    Map;

RenderWindow window(VideoMode(SizeWindowX, SizeWindowY), "First game");

void INIT()
{

	
}

void Update(float time)
{
	Player.Update(time);	
}

int main()
{
	INIT();
		
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





