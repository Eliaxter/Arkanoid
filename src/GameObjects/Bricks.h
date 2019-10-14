#ifndef BRICKS_H
#define BRICKS_H

#include "raylib.h"

namespace Game
{
	struct Brick
	{
		Rectangle rect;
		int life;
		bool isAlive;
	};

	extern const int lineOfBricks;
	const int brickSize = 28;
	extern Brick bricks[brickSize];

	void InitBricks();
	void DrawBrick();
}

#endif