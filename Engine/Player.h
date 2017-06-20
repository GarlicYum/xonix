#pragma once

#include "Player.h"
#include "Graphics.h"
#include "Keyboard.h"

class Player
{
public:
	void Draw(Graphics& gfx, int size);
	void Update();
	void UserInput(Keyboard& kbd);
	void ClampScreen();
	int GetX() const;
	int GetY() const;
private:
	int x = 0;
	int y = 0;
	int vx = 0;
	int vy = 0;
};