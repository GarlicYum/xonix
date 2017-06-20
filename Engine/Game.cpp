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

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
				{
					grid[i][j] = 1;
				}
			}
		}

		counter += dt;
		if (counter > delay)
		{
			counter = 0;
			player.Update();

			if (grid[player.GetY()][player.GetX()] == 2)
			{
				game = false;
			}

			if (grid[player.GetY()][player.GetX()] == 0)
			{
				grid[player.GetY()][player.GetX()] = 2;
			}
		}

		player.UserInput(wnd.kbd);
		
		enemy.Move(grid, tileSize);

		if (grid[player.GetY() ][player.GetX()] == 1)
		{
			Drop(enemy.y / tileSize, enemy.x / tileSize);

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (grid[i][j] == -1)
					{
						grid[i][j] = 0;
					}
					else
					{
						grid[i][j] = 1;
					}
				}
			}
		}
		if (grid[enemy.y / tileSize][enemy.x / tileSize] == 2)
		{
			game = false;
		}
		
	}	
}


void Game::Drop(int Y, int X)
{
	if (grid[Y][X] == 0)
	{
		grid[Y][X] = -1;
	}
	if (grid[Y - 1][X] == 0)
	{
		Drop(Y - 1, X);
	}
	if (grid[Y + 1][X] == 0)
	{
		Drop(Y + 1, X);
	}
	if (grid[Y][X - 1] == 0)
	{
		Drop(Y, X - 1);
	}
	if (grid[Y][X + 1] == 0)
	{
		Drop(Y, X + 1);
	}
}


void Game::ComposeFrame()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (grid[i][j] == 0)
			{
				continue;
			}
			else if (grid[i][j] == 1)
			{
				gfx.DrawRect(j * tileSize, i * tileSize, tileSize, tileSize, Colors::Green);
			}
			else if (grid[i][j] == 2)
			{
				gfx.DrawRect(j * tileSize, i * tileSize, tileSize, tileSize, Colors::Magenta);
			}
		}
	}

	//DrawEnemy
	gfx.DrawRect(enemy.x, enemy.y, tileSize, tileSize, Colors::White);

	player.Draw(gfx, tileSize);
	
}
