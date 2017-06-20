#include "Player.h"

void Player::Draw(Graphics & gfx, int size, Board::Type(&grid)[60][80])
{
	if (grid[y][x] == Board::Type::filled)
	{
		gfx.DrawRect(x * size, y * size, size, size, edgeColor);
		gfx.DrawRect((x * size) + padding, (y * size) + padding, size - (padding * 2),
			size - (padding * 2), bodyColor);
	}
	else
	{
		gfx.DrawRect(x * size, y * size, size, size, bodyColor);
		gfx.DrawRect((x * size) + padding, (y * size) + padding, size - (padding * 2),
			size - (padding * 2), edgeColor);
	}
	
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

		if (!e.IsRelease())
		{
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
}

void Player::ClampScreen()
{
	int size = 10;
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

void Player::Reset()
{
	x = 39;
	y = 0;
	vx = 0;
	vy = 0;
}

void Player::Stop()
{
	vx = 0;
	vy = 0;
}
