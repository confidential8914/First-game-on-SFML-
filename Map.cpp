#include <windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace sf;
using namespace std;

#include "Map.h"

const int SizeWindowX = 900;
const int SizeWindowY = 640; 

MAP::MAP()
{
	
	MAP::Background[0]  = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
	MAP::Background[1]  = "W                                                          W";
	MAP::Background[2]  = "W                                                          W";
	MAP::Background[3]  = "W                                                          W";
	MAP::Background[4]  = "W                                                          W";
	MAP::Background[5]  = "W                                                          W";
	MAP::Background[6]  = "W                                                          W";
	MAP::Background[7]  = "W                                                          W";
	MAP::Background[8]  = "W                                                          W";
	MAP::Background[9]  = "W                                                          W";
	MAP::Background[10] = "W                                                          W";
	MAP::Background[11] = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
	
	MAP::Map[0]  = "";
	MAP::Map[1]  = "";
	MAP::Map[2]  = "";
	MAP::Map[3]  = "";
	MAP::Map[4]  = "";
	MAP::Map[5]  = "";
	MAP::Map[6]  = "";
	MAP::Map[7]  = "";
	MAP::Map[8]  = "";
	MAP::Map[9]  = "";
	MAP::Map[10] = "";
	MAP::Map[11] = "";
	
}

MAP::~MAP(){}

void MAP::DrawBackground()
{
/*	for(int counterA = 0; counterA < H; counterA++)
		for(int counterB = 0; counterB < W; counterB++)
		{
			if(Background[counterA][counterB] == 'W')
				rectangle.setFillColor(Color::Green);
		}*/
}

void MAP::DrawMap()
{

}


