/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawFace(int x, int y);
	void DrawPoo(int x, int y);
	void DrawContraSmallRight(int x, int y);
	void DrawContraSmallLeft(int x, int y);
	void DrawGhost(int x, int y);
	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);
	int BounceScreenX(int pooXv, int x, int width);
	int BounceScreenY(int pooYv, int y, int height);
	bool IsColliding(int xP1, int yP1, int widthP1, int heightP1, 
		             int x0, int y0, int width0, int height0);
	void DrawGameOver(int x, int y);
	void DrawTitleScreen(int x, int y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	// character models
	int dudeX = 400;
	int dudeY = 300;
	int dudeWidth = 25;
	int dudeHeight = 34;
	int pooWidth = 24;
	int pooHeight = 24;
	// collision bools
	bool poo0IsEaten = false;
	bool poo1IsEaten = false;
	bool poo2IsEaten = false;
	// bool to tell which direction the character is facing so we can draw him facing the direction of the last input
	bool ContraRight = true;
	// title screen started bool
	bool isStarted = false;
	// poo positions
	int poo0X;
	int poo0Y;
	int poo1X;
	int poo1Y;
	int poo2X;
	int poo2Y;
	// poo starting velocities
	int poo0Xv;
	int poo0Yv;
	int poo1Xv;
	int poo1Yv;
	int poo2Xv;
	int poo2Yv;
	/********************************/
};