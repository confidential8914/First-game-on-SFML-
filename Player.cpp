#include <windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

#include "Player.h"

const int SizeWindowX = 640;
const int SizeWindowY = 640; 

void PrintToConsole(char *command)
{
	cout << "Player: ";
	
}

PLAYER::PLAYER()
{	
	Speed = 1.5;
	
    SizeX = 75; 
	SizeY = 85;
	
	TPlayer.loadFromFile("Spritse\\sprite.png");
	sprite.setTexture(TPlayer);
	sprite.setTextureRect(IntRect(85, 10, SizeX, SizeY));
	sprite.setPosition(100, SizeWindowY - 100);
}
	
PLAYER::~PLAYER()
{}

void Gravity()
{

}

void PLAYER::Update(float time)
{
	this->time = time;
}
	
void PLAYER::Control()
{
	//////////////// Control ///////////////////
		
	if(Keyboard::isKeyPressed(Keyboard::Left))
	{
		sprite.move(-0.15 * time, 0);	
		
		if(!Keyboard::isKeyPressed(Keyboard::Down))
		{
			NumberFrame += 0.006 * time;
		
	    	if(NumberFrame > VFrame)
				NumberFrame -= VFrame;	
		
			sprite.setTextureRect(IntRect(85 + (80 * int(NumberFrame)) + 80, 10, -SizeX, SizeY));
		}
		else
		{
		
			NumberDownFrame += 0.006 * time;
		
	    	if(NumberDownFrame > VFrame)
				NumberDownFrame -= VFrame;	
		
			sprite.setTextureRect(IntRect(415 + (80 * int(NumberDownFrame)) + 80, 95, -SizeX - 0, SizeY - 30));
		}
		
		OldVector = 'L';
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Right))
	{
		sprite.move(0.15 * time, 0);
		
		if(!Keyboard::isKeyPressed(Keyboard::Down))
		{	
			NumberFrame += 0.006 * time;
		
	    	if(NumberFrame > VFrame)
				NumberFrame -= VFrame;	
		
			sprite.setTextureRect(IntRect(85 + (80 * int(NumberFrame)), 10, SizeX, SizeY));	
		}
		else
		{
			NumberDownFrame += 0.006 * time;
		
	    	if(NumberDownFrame > VFrame)
				NumberDownFrame -= VFrame;	
		
			sprite.setTextureRect(IntRect(415 + (80 * int(NumberDownFrame)), 95, SizeX - 0, SizeY - 30));
		}
		
		OldVector = 'R';
	}
		
	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		sprite.move(0, -0.1);	
	}

	if(!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Up))
	{	
		switch(OldVector)
		{
			case 'L': sprite.setTextureRect(IntRect(90 + 80, 650, -SizeX, SizeY - 10)); break;
			case 'R': sprite.setTextureRect(IntRect(90,      650,  SizeX, SizeY - 10)); break;		
		}
	}	
		
	//////////////// Control ///////////////////
	
}

	
