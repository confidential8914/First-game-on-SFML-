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

const int H = 26;
const int W = 120;

Clock MClock; 

/*
String Map[H] = {
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"W00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000W",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
}; */

char PTile[9] = {'-', 'f', '1', '2', '3', '4', '5', '6', 'b'}; 

String Map[H] = {
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WWWWWWWWWWWWWWWFFWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFWWWWWWWWWWWW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"WffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffW",
"Wfffffff6666666666666666666666666666666666666666WWFFFFWWW66666666666666666666666666666666666666ffff5fffffffffffW",
"Wffffff65555555555555555555555555555555555555555FFFFFFFFF555555555555555555555555555555555555556fffffffffffffffW",
"Wfffff6bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb6ffffffffffffffW",
"Wffff66bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb56fffffffffffffW",
"Wffffbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb56fffffffff5fffW",
"WffffbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbfffffffffffffffW",
"WffffbbbbMbMbMbMbMbMbMbMbMbMbMbMbMbMbMbbMbMbbbbWLLLLLLLLWbHbbHbbbHbbbbHbbbHbbbbHbbbHbbbbbbbbbbbffffffffffffffffW",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
};

struct OBJECTS
{
	
	void Heart(int i, int j)	
	{	
		Map[i][j] = ' ';
				
		if(Player.health < Player.VH)
			Player.health++;
    	
    	if(Player.HP < 100)
    		if(Player.HP <= 70)
				Player.HP += 30;
			else
				Player.HP = 100;
			
		cout << "HP: " << Player.HP << endl;
	}
			
				
	void Coin(int i, int j)
	{	
		Map[i][j] = ' ';
		
		Player.coins++;
    	
		cout << "Coins: " << Player.coins << endl;
	}
	
	void Lava(int i, int j)
	{	
		if(Player.HP > 0)
			Player.HP -= 0.1;
		
		cout << "HP: " << Player.HP << endl;
	}
	
}Objects;


void DrawMap()
{	
	
	Texture tileSetheart;
	tileSetheart.loadFromFile("Tile\\heart.png");
	Sprite heart(tileSetheart);	
	
	Texture tileSetcoin;
	tileSetcoin.loadFromFile("Tile\\coin.png");
	Sprite coin(tileSetcoin);
	
	Texture tileSetstone;
	tileSetstone.loadFromFile("Tile\\stone.png");
	Sprite stone(tileSetstone);
	
	Texture tileSetground;
	tileSetground.loadFromFile("Tile\\ground.png");
	Sprite ground(tileSetground);
	
	
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
			
			if (Map[counterA][counterB] == 'H')
			{
				heart.setTextureRect(IntRect(0, 0, 32, 32));
				heart.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
				window.draw(heart);
			}
			
			if (Map[counterA][counterB] == 'M')
			{
				coin.setTextureRect(IntRect(0, 0, 32, 32));
				coin.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
				window.draw(coin);
			}
			
			if (Map[counterA][counterB] == 'L')
			{
				ground.setTextureRect(IntRect(160, 1, 32, 32));
				ground.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
				window.draw(ground);
			}
			
			/////////////////////////////
			
			for(int counter = 0; counter < strlen(PTile); counter++)
				if (Map[counterA][counterB] == PTile[counter])
				{
					ground.setTextureRect(IntRect((32 * counter), 1, 32, 32));
					ground.setPosition(counterB * 32 - offsetX, counterA * 32 - offsetY); 
					window.draw(ground);
				}
			
		}
				  
}

   				
void Collision(bool dir)
{
	for(int i = Player.rect.top / 32; i < (Player.rect.top + Player.rect.height) / 32; i++)
		for (int j = Player.rect.left / 32; j < (Player.rect.left + Player.rect.width) / 32; j++)
		{ 
	  		if (Map[i][j] == 'W' || Map[i][j] == 'L' 
			                || Map[i][j] == PTile[0] || Map[i][j] == PTile[4] 
						    || Map[i][j] == PTile[2] || Map[i][j] == PTile[6] 
							|| Map[i][j] == PTile[3] || Map[i][j] == PTile[7] 
							|| Map[i][j] == PTile[4]) 
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
				Map[i][j] = 'f';
			
			if(Map[i][j] == 'H') 
				Objects.Heart(i, j);
		
			if(Map[i][j] == 'M') 
				Objects.Coin(i, j);	
				
			if(Map[i][j] == 'L') 
				Objects.Lava(i, j);	
		
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





