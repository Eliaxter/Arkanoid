#include "Bricks.h"

#include "raylib.h"

const int minScreenWidth = 0;
const int minScreenHeight = 0;

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
	}
}

void DrawBricks()
{

	for (int i = 0; i < brickSize; i++)
	{
		if (bricks[i].life== 1)
		{
			DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, WHITE);
		}
		if (bricks[i].life == 2)
		{
			DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, GREEN);
		}
		if (bricks[i].life == 3)
		{
			DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, PURPLE);
		}
		if (bricks[i].life == 4)
		{
			DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, GRAY);
		}
		if (bricks[i].life == 5)
		{
			DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, BLUE);
		}
	}
}