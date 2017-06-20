#pragma once

#include "Graphics.h"
#include "Board.h"

class OutsideEnemy
{
public:
	void Move(Board::Type(&grid)[60][80], float dt);
	void Draw(Graphics& gfx) const;
	float GetX() const;
	float GetY() const;
	void Reset();

private:
	float y = 0.0f;
	float x = 10.0f;
	float vy = 240.0f;
	float vx = 240.0f;
	static constexpr int padding = 3;
	static constexpr int size = 10;
	Color edgeColor = Colors::Black;
	Color bodyColor = Color(0, 170, 169);
};

//0, 450