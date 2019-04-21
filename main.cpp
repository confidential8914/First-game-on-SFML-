#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const int SizeWindowX = 900;
const int SizeWindowY = 640; 

float offsetX;
float offsetY;

#include "Player.h"

RenderWindow window(VideoMode(SizeWindowX, SizeWindowY), "SFML GAME");

PLAYER Player;


//////////////////////////////////////////////////////////////////////////////////////////////////////

const int H = 18;
const int W = 100;

String Map[H] = {
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"W                                																    W",
"W   		 																                        W",
"W            EEEE     E      E                 													W",
"W           E         E      E          															W",
"W      	 E 		 EEEEE  EEEEE	 															    W",
"W           E         E      E           															W",
"W            EEEE     E      E            															W",
"W        																							W",
"W                                 																	W",
"W             																						W",
"W        			            																    W",
"W             		     													                        W",
"W        							   																W",
"W      						      																W",
"W   PPP   																						    W",
"W      																						    W",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
}; 

void DrawS()
{	
	RectangleShape rectangle( Vector2f(32, 32));
	
	for (int i=0; i<H; i++)
		for (int j=0; j<W ; j++)
		{	
			if (Map[i][j] == 'W') rectangle.setFillColor(Color::Red);
			
			if (Map[i][j] == 'P') rectangle.setFillColor(Color::White);
		    
		    if (Map[i][j] == 'E') rectangle.setFillColor(Color::Green);
		    
			if (Map[i][j] == '0' || Map[i][j] == ' ') rectangle.setFillColor(Color::Black);
		    
		    rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY) ; 
		    window.draw(rectangle);
	    }
}

void DrawMap()
{	
	Texture tileSet;
	tileSet.loadFromFile("Tail\\First.png");
	Sprite tile(tileSet);
	
	for(int counterA = 0; counterA < H; counterA++)
		for (int counterB = 0; counterB < W; counterB++)
		{ 
			if (Map[counterA][counterB] == 'B')  tile.setTextureRect(IntRect(162, 128, 223, 190));

			if ((Map[counterA][counterB] == ' ') || (Map[counterA][counterB] == '0')) continue;

  			tile.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
			window.draw(tile);
		}
		
}

void Collision(bool dir)
{
	for(int i = Player.rect.top / 32; i < (Player.rect.top + Player.rect.height) / 32; i++)
		for (int j = Player.rect.left / 32; j < (Player.rect.left + Player.rect.width) / 32; j++)
		{ 
	  		if (Map[i][j]=='P') 
		   	{ 
	        	if ((Player.x > 0) && (dir == false)) Player.rect.left =  j * 32 -  Player.rect.width; 
		    	
				if ((Player.x < 0) && (dir == false)) Player.rect.left =  j * 32/* + 32*/;
				
				if ((Player.y > 0) && (dir == true)) 
				{ 
					Player.rect.top = i * 32 - Player.rect.height;  
					Player.y = 0;   
					Player.onGround = true; 
				}
				
				if ((Player.y < 0) && (dir == true))  
				{ 
					Player.rect.top = i * 32/* + 32*/;   
					Player.y=0;
				}
		    }	
		 
		 	
			if(Map[i][j] == 'E') 
				Map[i][j] = ' ';
	        	
    	}
   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////*/


void Update(float time)
{	
	Collision(false);
	Player.Update(time);	
	Collision(true);
}

int main()
{	
	/*	
	Music music;
    music.openFromFile("Music\\Main music.ogg");
    music.play();
	*/
	
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
		DrawS();
		window.draw(Player.sprite);
		window.display();
		
	}
	
    return 0;
}





