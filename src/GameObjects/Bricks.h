#ifndef BRICKS_H
#define BRICKS_H

#include "raylib.h"

namespace Game
{
	extern const int lineOfBricks;
	extern const int brickSize;

	struct Brick
	{
		Rectangle rect;
		int life;
		bool isAlive;
	};

	extern Brick bricks[brickSize];

	
	void InitBricks();
	void DrawBrick();
}

#endif