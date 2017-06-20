#include "OutsideEnemy.h"

void OutsideEnemy::Move(Board::Type(&grid)[60][80])
{
	x += vx;
	const int right = x + size;
	if (grid[y / size][x / size] == Board::Type::empty ||
		grid[y / size][right / size] == Board::Type::empty ||
		x < 0 || right > Graphics::ScreenWidth)
	{
		vx = -vx;
		x += vx;
	}
	y += vy;
	const int bottom = y + size;
	if (grid[y / size][x / size] == Board::Type::empty ||
		grid[bottom / size][x / size] == Board::Type::empty ||
		y < 0 || bottom > Graphics::ScreenHeight)
	{
		vy = -vy;
		y += vy;
	}
}

void OutsideEnemy::Draw(Graphics & gfx) const
{
	gfx.DrawRect(x, y, size, size, edgeColor);
	gfx.DrawRect(x + padding, y + padding, size - (padding * 2),
		size - (padding * 2), bodyColor);
}

int OutsideEnemy::GetX() const
{
	return x;
}

int OutsideEnemy::GetY() const
{
	return y;
}

void OutsideEnemy::Reset()
{
	y = 0;
	x = 450;
	vy = 4;
	vx = 4;
}
