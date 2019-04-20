#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const int SizeWindowX = 900;
const int SizeWindowY = 640; 
/*
const int H = 12;
const int W = 60;*/

float offsetX;
float offsetY;

#include "Player.h"

RenderWindow window(VideoMode(SizeWindowX, SizeWindowY), "SFML GAME");

PLAYER Player;


//////////////////////////////////////////////////////////////////////////////////////////////////////

const int H = 17;
const int W = 20;


String Map[H] = {
"0000000000000000000000",
"0B                   0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0                    0",
"0000000000000000000000",
}; 

DrawMap()
{	
	Texture tileSet;
	tileSet.loadFromFile("Tail\\First.png");
	Sprite tile(tileSet);
	
	for(int counterA = 0; counterA < H; counterA++)
		for (int counterB = 0; counterB < W; counterB++)
		{ 
			if (Map[counterA][counterB] == 'P')  tile.setTextureRect(IntRect(162, 129, 224, 191));

			if ((Map[counterA][counterB] == ' ') || (Map[counterA][counterB] == '0')) continue;

  			tile.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
			window.draw(tile);
		}
		
}

//////////////////////////////////////////////////////////////////////////////////////////////////////*/


void Update(float time)
{
	Player.Update(time);	
}

int main()
{		
	Music music;
    music.openFromFile("Music\\Main music.ogg");
    music.play();
	
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
		
		window.clear(Color::Black);
		DrawMap();
		window.draw(Player.sprite);
		window.display();
		
	}
	
    return 0;
}





