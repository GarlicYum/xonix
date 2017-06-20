#include "Board.h"

Board::Board()
{
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
}

void Board::Draw(Graphics & gfx) const
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
}

int Board::GetTileSize() const
{
	return tileSize;
}

void Board::Drop(int Y, int X)
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

void Board::Collapse()
{
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

bool Board::GameOver(int y, int x)
{
	if (grid[y / tileSize][x / tileSize] == 2)
	{
		return false;
	}
	return true;
}
