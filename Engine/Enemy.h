#pragma once

#include "Graphics.h"
#include "Board.h"

class Enemy
{
public:
	Enemy(int x_in, int y_in, int vx_in, int vy_in)
		:
		x(x_in),
		y(y_in),
		vx(vx_in),
		vy(vy_in)
	{}
	Enemy() = default;
	void Move(Board::Type(&grid)[30][40], int tileSize);
	void Draw(Graphics& gfx) const;
	int GetX() const;
	int GetY() const;

private:
	int y;
	int x;
	int vy;
	int vx;
	static constexpr int size = 10;
};