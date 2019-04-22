#include <windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace sf;
using namespace std;

#include "Player.h"

const short int W = 100;

const int SizeWindowX = 1200;
const int SizeWindowY = 832; 

const short int DischargeTimeS = 60;

/*
HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsoleHandle, 10);
*/

PLAYER::PLAYER()
{	
	Speed    = 1.5;
	SizeJump = 0.4;
	
	VH = 3;
	HP = 100;
	
	AOG = 0.0005;

    SizeX = 75; 
	SizeY = 85;
	
	health = VH;
	charges = 100;
	
	rect = FloatRect(200, SizeWindowY - 192, SizeX - 25, SizeY - 20);

	TPlayer.loadFromFile("Spritse\\sprite.png");
	sprite.setTexture(TPlayer);
	sprite.setTextureRect(IntRect(90, 650, SizeX, SizeY - 12));
	sprite.setPosition(100, SizeWindowY - 100);
}
	
PLAYER::~PLAYER(){}

void PLAYER::GravityAndMotion()
{
	rect.left += x * time;
	
	if(!onGround)
		y += AOG * time;
	
	rect.top += y * time;
	
	onGround = false;	
	
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

void PLAYER::Charges()
{
	float Time = Clock.getElapsedTime().asSeconds();
	
	if(Time >= DischargeTimeS && charges > 0)
	{
		if(charges < 10)
			charges = 0;
		else
			charges -= 10;
		
		Clock.restart();	
		cout << "Charges: " << charges << endl;
	}	
}
 

void PLAYER::Update(float time, float offsetX, float offsetY)
{		
	this->time = time;
	
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	
	PLAYER::GravityAndMotion();
	PLAYER::Charges();
	
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

	
