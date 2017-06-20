#include "Enemy.h"

void Enemy::Move(Board::Type(&grid)[60][80], int tileSize, float dt)
{
	x += vx * dt;
	const int right = int(x) + size;
	if (grid[int(y) / tileSize][int(x) / tileSize] == Board::Type::filled ||
		grid[int(y) / tileSize][right / tileSize] == Board::Type::filled)
	{
		vx = -vx;
		x += vx * dt;
	}
	y += vy * dt;
	const int bottom = int(y) + tileSize;
	if (grid[int(y) / tileSize][int(x) / tileSize] == Board::Type::filled ||
		grid[bottom / tileSize][int(x) / tileSize] == Board::Type::filled)
	{
		vy = -vy;
		y += vy * dt;
	}
}

void Enemy::Draw(Graphics & gfx) const
{
	gfx.DrawCircle(int(x), int(y), size, edgeColor);
	gfx.DrawCircle(int(x), int(y), size - padding, bodyColor);
}

float Enemy::GetX() const
{
	return x;
}

float Enemy::GetY() const
{
	return y;
}
