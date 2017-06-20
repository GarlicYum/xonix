#include "Enemy.h"

void Enemy::Move(Board::Type(&grid)[30][40], int tileSize)
{
	x += vx;
	const int right = x + tileSize;
	if (grid[y / tileSize][x / tileSize] == Board::Type::filled ||
		grid[y / tileSize][right / tileSize] == Board::Type::filled)
	{
		vx = -vx;
		x += vx;
	}
	y += vy;
	const int bottom = y + tileSize;
	if (grid[y / tileSize][x / tileSize] == Board::Type::filled ||
		grid[bottom / tileSize][x / tileSize] == Board::Type::filled)
	{
		vy = -vy;
		y += vy;
	}
}

void Enemy::Draw(Graphics & gfx) const
{
	gfx.DrawCircle(x, y, size, Colors::White);
}

int Enemy::GetX() const
{
	return x;
}

int Enemy::GetY() const
{
	return y;
}
