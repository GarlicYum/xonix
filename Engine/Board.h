#pragma once

#include "Graphics.h"

class Board
{
public:
	enum Type
	{
		empty, filled, tail, hidden
	};
	void Draw(Graphics& gfx) const;
	int GetTileSize() const;
	void Drop(int y, int x);
	void Collapse();
	bool GameOver(int y, int x) const;
	bool LevelComplete() const;
	void Reset();

private:
	static constexpr int tileSize = 10;
	static constexpr int width = 80;
	static constexpr int height = 60;
	bool levelComplete = false;
	static constexpr int emptyLeft2Win = 1000;
	Color fillColor = Color(0, 170, 169);
	Color tailColor = Color(168, 0, 171);
public:
	Type grid[height][width] = { empty };
};