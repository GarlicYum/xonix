#pragma once

#include "Graphics.h"
#include "Board.h"

class Enemy
{
public:
	Enemy(float x_in, float y_in, float vx_in, float vy_in)
		:
		x(x_in),
		y(y_in),
		vx(vx_in),
		vy(vy_in)
	{}
	Enemy() = default;
	void Move(Board::Type(&grid)[60][80], int tileSize, float dt);
	void Draw(Graphics& gfx) const;
	float GetX() const;
	float GetY() const;

private:
	float y;
	float x;
	float vy;
	float vx;
	static constexpr int padding = 2;
	static constexpr int size = 5;
	Color edgeColor = Color(195, 195, 195);
	Color bodyColor = Color(0, 170, 169);
};