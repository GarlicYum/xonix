#pragma once

#include "Graphics.h"
#include "Board.h"

class OutsideEnemy
{
public:
	void Move(Board::Type(&grid)[60][80]);
	void Draw(Graphics& gfx) const;
	int GetX() const;
	int GetY() const;
	void Reset();

private:
	int y = 0;
	int x = 450;
	int vy = 4;
	int vx = 4;
	static constexpr int padding = 3;
	static constexpr int size = 10;
	Color edgeColor = Colors::Black;
	Color bodyColor = Color(0, 170, 169);
};