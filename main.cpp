#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const int SizeWindowX = 1200;
const int SizeWindowY = 832; 

float offsetX;
float offsetY;

#include "Player.h"

RenderWindow window(VideoMode(SizeWindowX, SizeWindowY), "SFML GAME");

PLAYER Player;

int Timer_CLK;

//////////////////////////////////////////////////////////////////////////////////////////////////////

const int H = 27;
const int W = 100;

Clock MClock; 

Music Heart;

void Sounds()
{
	Heart.openFromFile("Music\\heart.ogg");
}

String Map[H] = {
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000H0H000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000WWW000000000000000000000000000000000000000000000000000000000W",
"W000000000000000000000000000000H0000000000000000000000000000000000000000000000000000000000000000000W",
"W0000000000000000000000000000000000WW00000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000WWW000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W000000000000000000000000WWW00000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W0000000FFFFWFFFFFWFFFFWW00000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
}; 

void DrawMap()
{	
	
	Texture tileSet;
	tileSet.loadFromFile("Tile\\stone.png");
	Sprite stone(tileSet);
	
	for(int counterA = 0; counterA < H; counterA++)
		for (int counterB = 0; counterB < W; counterB++)
		{	
			if ((Map[counterA][counterB] == ' ') || (Map[counterA][counterB] == '0')) continue;
			
			if (Map[counterA][counterB] == 'W')  
			{
				stone.setTextureRect(IntRect(0, 0, 32, 32));
				stone.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
				window.draw(stone);
			}	
		
			if (Map[counterA][counterB] == 'F')  
			{
				stone.setTextureRect(IntRect(0, 0, 32, 32));
				stone.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
				window.draw(stone);
			}
			
		}


	tileSet.loadFromFile("Tile\\heart.png");
	Sprite heart(tileSet);

	for(int counterA = 0; counterA < H; counterA++)
		for (int counterB = 0; counterB < W; counterB++)
			if (Map[counterA][counterB] == 'H')
			{
				heart.setTextureRect(IntRect(0, 0, 32, 32));
				heart.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
				window.draw(heart);
			}
				  
}

   				
void Collision(bool dir)
{
	for(int i = Player.rect.top / 32; i < (Player.rect.top + Player.rect.height) / 32; i++)
		for (int j = Player.rect.left / 32; j < (Player.rect.left + Player.rect.width) / 32; j++)
		{ 
	  		if (Map[i][j]=='W') 
		   	{ 
	        	if ((Player.x > 0) && (dir == false)) Player.rect.left =  j * 32 - Player.rect.width; 
		    	
				if ((Player.x < 0) && (dir == false)) Player.rect.left =  j * 32 + 32;
				
				if ((Player.y > 0) && (dir == true))  
				{ 
					Player.rect.top = i * 32 - Player.rect.height;  
					Player.y = 0;   
					Player.onGround = true; 
				}
				
				if ((Player.y < 0) && (dir == true))  
				{ 
					Player.rect.top = i * 32 + 32;   
					Player.y = 0;
				}
		    }	
		 	
			if(Map[i][j] == 'F') 
				Map[i][j] = ' ';
			
			if(Map[i][j] == 'H') 
			{	
				Map[i][j] = ' ';
    			
				Heart.play();
				
				if(Player.health < Player.VH)
					Player.health++;
    			
				cout << "Health: " << Player.health << endl;
			}
		}
   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////*/


void Update(float time)
{	
	Collision(false);
	
	if(Player.rect.left > (SizeWindowX / 2))
	offsetX = Player.rect.left - (SizeWindowX / 2);
	offsetY = Player.rect.top  - (SizeWindowY / 2);
	Player.Update(time, offsetX, offsetY);	
	
	Collision(true);		
}

int main()
{
	/*
	Music music;
    music.openFromFile("Music\\Main music.ogg");
    music.play();
	*/
	
	Sounds();
	
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





