#ifndef BRICKS_H
#define BRICKS_H

#include "raylib.h"

namespace Game
{
	extern const int lineOfBricks;
	const int brickSize = 28;


	struct Brick
	{
		Rectangle rect;
		int life;
	};

	extern Brick bricks[brickSize];

	void InitBricks();
	void DrawBrick();
	//void DrawBricks();
}

#endif