#include "Player.h"

void Player::Draw(Graphics & gfx, int size)
{
	gfx.DrawRect(x * size, y * size, size, size, Colors::Red);
}

void Player::Update()
{
	x += vx;
	y += vy;
	ClampScreen();
}

void Player::UserInput(Keyboard & kbd)
{
	while (!kbd.KeyIsEmpty())
	{
		const Keyboard::Event e = kbd.ReadKey();

		if (e.GetCode() == VK_UP)
		{
			vy = -1;
			vx = 0;
		}
		else if (e.GetCode() == VK_DOWN)
		{
			vy = 1;
			vx = 0;
		}
		else if (e.GetCode() == VK_LEFT)
		{
			vy = 0;
			vx = -1;
		}
		else if (e.GetCode() == VK_RIGHT)
		{
			vy = 0;
			vx = 1;
		}
	}
}

void Player::ClampScreen()
{
	int size = 20;
	if (x < 0)
	{
		x = 0;
	}
	else if (x + 1 >(Graphics::ScreenWidth / size))
	{
		x = Graphics::ScreenWidth / size - 1;
	}
	if (y < 0)
	{
		y = 0;
	}
	else if (y + 1 > Graphics::ScreenHeight / size)
	{
		y = (Graphics::ScreenHeight / size) - 1;
	}
}

int Player::GetX() const
{
	return x;
}

int Player::GetY() const
{
	return y;
}
