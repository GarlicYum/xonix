/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (game)
	{
		const float dt = ft.Mark(); // delta time

		counter += dt;
		if (counter > delay)
		{
			counter = 0;
			player.Update();

			if (brd.grid[player.GetY()][player.GetX()] == 2)
			{
				game = false;
			}

			if (brd.grid[player.GetY()][player.GetX()] == 0)
			{
				brd.grid[player.GetY()][player.GetX()] = 2;
			}
		}

		player.UserInput(wnd.kbd);
		
		enemy.Move(brd.grid, brd.GetTileSize());

		if (brd.grid[player.GetY() ][player.GetX()] == 1)
		{
			brd.Drop(enemy.y / brd.GetTileSize(), enemy.x / brd.GetTileSize());
			brd.Collapse();
		}
		game = brd.GameOver(enemy.y, enemy.x);
	}	
}


void Game::ComposeFrame()
{
	const int tileSize = brd.GetTileSize();
	brd.Draw(gfx);
	enemy.Draw(gfx, tileSize);
	player.Draw(gfx, tileSize);
}
