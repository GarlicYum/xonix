#pragma once

#include "Player.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Board.h"

class Player
{
public:
	void Draw(Graphics& gfx, int size, Board::Type(&grid)[60][80]);
	void Update();
	void UserInput(Keyboard& kbd);
	void ClampScreen();
	int GetX() const;
	int GetY() const;
	void Reset();
	void Stop();

private:
	int x = 0;
	int y = 0;
	int vx = 0;
	int vy = 0;
	static constexpr int padding = 3;
	Color edgeColor = Color(168, 0, 171);
	Color bodyColor = Color(195, 195, 195);
};