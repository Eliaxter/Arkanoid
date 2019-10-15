#include "Bricks.h"

#include "raylib.h"

namespace Game
{
	const int minScreenWidth = 0;
	const int minScreenHeight = 0;

	static int oneBrick = 1;
	const int lineOfBricks = 4;
	Brick bricks[brickSize] = { 0 };

	static float bricksWidth = 50.0f;
	static float bricksHeight = 20.0f;
	static int minLife = 1;
	static int maxLife = 5;

	static float v1 = 20.0f;
	static float v2 = 100.0f;
	static float v3 = 20.0f;

	static int v4 = 7;
	static int v5 = 7;

	static float v6 = 70.0f;
	static float v7 = 60.0f;
	static float v8 = 5.0f;

	static int v9 = 7;
	static int v10 = 7;

	void InitBricks()
	{
		for (int i = 0; i < brickSize; i++)
		{
			bricks[i].rect.x = v1 + v2 * (i % v4) + v3 * (i % v5);
			bricks[i].rect.y = v6 + v7 * (i / v9) + v8 * (i / v10);
			bricks[i].rect.width = bricksWidth;
			bricks[i].rect.height = bricksHeight;
			bricks[i].life = GetRandomValue(minLife, maxLife);
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