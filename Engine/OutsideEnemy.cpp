#include "OutsideEnemy.h"

void OutsideEnemy::Move(Board::Type(&grid)[60][80], float dt)
{
	x += vx * dt;
	const int right = int(x) + size;
	if (grid[int(y) / size][int(x) / size] == Board::Type::empty ||
		grid[int(y) / size][right / size] == Board::Type::empty ||
		x < 0 || right > Graphics::ScreenWidth)
	{
		vx = -vx;
		x += vx * dt;
	}
	y += vy * dt;
	const int bottom = int(y) + size;
	if (grid[int(y) / size][int(x) / size] == Board::Type::empty ||
		grid[bottom / size][int(x) / size] == Board::Type::empty ||
		y < 0 || bottom > Graphics::ScreenHeight)
	{
		vy = -vy;
		y += vy * dt;
	}
}

void OutsideEnemy::Draw(Graphics & gfx) const
{
	gfx.DrawRect(int(x), int(y), size, size, edgeColor);
	gfx.DrawRect(int(x) + padding, int(y) + padding, size - (padding * 2),
		size - (padding * 2), bodyColor);
}

float OutsideEnemy::GetX() const
{
	return x;
}

float OutsideEnemy::GetY() const
{
	return y;
}

void OutsideEnemy::Reset()
{
	y = 0.0f;
	x = 450.0f;
	vy = 240.0f;
	vx = 240.0f;
}
