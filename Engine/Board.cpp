#include "Board.h"

Board::Board()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
			{
				grid[i][j] = filled;
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
			if (grid[i][j] == empty)
			{
				continue;
			}
			else if (grid[i][j] == filled)
			{
				gfx.DrawRect(j * tileSize, i * tileSize, tileSize, tileSize, Colors::Green);
			}
			else if (grid[i][j] == tail)
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
	if (grid[Y][X] == empty)
	{
		grid[Y][X] = hidden;
	}
	if (grid[Y - 1][X] == empty)
	{
		Drop(Y - 1, X);
	}
	if (grid[Y + 1][X] == empty)
	{
		Drop(Y + 1, X);
	}
	if (grid[Y][X - 1] == empty)
	{
		Drop(Y, X - 1);
	}
	if (grid[Y][X + 1] == empty)
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
			if (grid[i][j] == hidden)
			{
				grid[i][j] = empty;
			}
			else
			{
				grid[i][j] = filled;
			}
		}
	}
}

bool Board::GameOver(int y, int x)
{
	if (grid[y / tileSize][x / tileSize] == tail)
	{
		return false;
	}
	return true;
}
