#include "Bricks.h"

#include "raylib.h"

namespace Game
{
	const int minScreenWidth = 0;
	const int minScreenHeight = 0;

	const int lineOfBricks = 4;
	const int brickSize = 28;

	static int oneBrick = 1;

	Brick bricks[brickSize] = { 0 };

	void InitBricks()
	{
		for (int i = 0; i < brickSize; i++)
		{
			bricks[i].rect.x = 20.0f + 100.0f * (i % 7) + 20.0f * (i % 7);
			bricks[i].rect.y = 70.0f + 60.0f * (i / 7) + 5.0f * (i / 7);
			bricks[i].rect.width = 50.0f;
			bricks[i].rect.height = 20.0f;
			bricks[i].life = GetRandomValue(1, 5);
			bricks[i].isAlive = true;
		}
	}

	void DrawBrick()
	{
		for (int i = 0; i < oneBrick; i++)
		{
			DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, WHITE);
		}
	}
}