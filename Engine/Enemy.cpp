#include "Enemy.h"

void Enemy::Move(int (&grid)[30][40], int tileSize)
{
	x += vx;
	const int right = x + tileSize;
	if (grid[y / tileSize][x / tileSize] == 1 ||
		grid[y / tileSize][right / tileSize] == 1)
	{
		vx = -vx;
		x += vx;
	}
	y += vy;
	const int bottom = y + tileSize;
	if (grid[y / tileSize][x / tileSize] == 1 ||
		grid[bottom / tileSize][x / tileSize] == 1)
	{
		vy = -vy;
		y += vy;
	}
}

void Enemy::Draw(Graphics & gfx, int size) const
{
	gfx.DrawRect(x, y, size, size, Colors::White);
}
