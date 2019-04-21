#include <windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace sf;
using namespace std;

#include "Player.h"

const int SizeWindowX = 1200;
const int SizeWindowY = 832; 

/*
HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsoleHandle, 10);
*/

PLAYER::PLAYER()
{	
	Speed    = 1.5;
	SizeJump = 0.4;
	
	AOG = 0.0005;

    SizeX = 75; 
	SizeY = 85;
	
	FloorLevel = (SizeWindowY - 128);
	rect = FloatRect(200, FloorLevel - 64, SizeX, SizeY - 23);

	TPlayer.loadFromFile("Spritse\\sprite.png");
	sprite.setTexture(TPlayer);
	sprite.setTextureRect(IntRect(90, 650, SizeX, SizeY - 12));
	sprite.setPosition(100, SizeWindowY - 100);
}
	
PLAYER::~PLAYER(){}


void PLAYER::Boundaries()
{
	if(rect.left <= 32 - 10)
		rect.left = 32 - 10;
	
	if(rect.top <= 32)
	{
		rect.top++;	
	}
}

void PLAYER::GravityAndMotion()
{
	rect.left += x * time;
	
	if(!onGround)
		y += AOG * time;
	
	rect.top += y * time;
	
	onGround = false;	
	
	if(rect.top > FloorLevel)
	{
		rect.top = FloorLevel;
		y = 0;
		onGround = true;
	}
		if(!Keyboard::isKeyPressed(Keyboard::Down))
		{
			NumberFrame += 0.006 * time;
		
			if(NumberFrame > VFrame)
				NumberFrame -= VFrame;	
				
			if(x > 0) sprite.setTextureRect(IntRect(82 + (80 * int(NumberFrame)),      9,  SizeX, SizeY));	
			if(x < 0) sprite.setTextureRect(IntRect(82 + (80 * int(NumberFrame) + 80), 9, -SizeX, SizeY));
		}
		else
		{
			NumberDownFrame += 0.006 * time;
			
	    	if(NumberDownFrame > VFrame)
				NumberDownFrame -= VFrame;	
				
			if(x > 0) 
			{
				rect.left += 0.125;
				sprite.setTextureRect(IntRect(415 + (80 * int(NumberDownFrame)),      95,  SizeX, SizeY - 30));	
			}
			
			if(x < 0) 
			{
				rect.left -= 0.125;
				sprite.setTextureRect(IntRect(415 + (80 * int(NumberDownFrame)) + 80, 95, -SizeX, SizeY - 30));
			}
		}

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	
}

void PLAYER::Update(float time, float offsetX, float offsetY)
{
	this->time = time;
	
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	
	PLAYER::GravityAndMotion();
	PLAYER::Boundaries();
}
	
void PLAYER::Control()
{
	//////////////// Control ///////////////////
			
	if(Keyboard::isKeyPressed(Keyboard::Left))
	{   
		x = -0.1;
		OldVector = 'L';
		
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Right))
	{	
		x = 0.1;
		OldVector = 'R';
	}
		
	if(Keyboard::isKeyPressed(Keyboard::Up))
		if(onGround)
		{	
			y =- SizeJump;
			onGround = false;
		}		
	
	if(!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Space))
	{	
		x = 0;
		
		switch(OldVector)
		{
			case 'L': sprite.setTextureRect(IntRect(90 + 80, 650, -SizeX, SizeY - 12)); break;
			case 'R': sprite.setTextureRect(IntRect(90,      650,  SizeX, SizeY - 12)); break;		
		}
	}	
		
	//////////////// Control ///////////////////
	
}

	
