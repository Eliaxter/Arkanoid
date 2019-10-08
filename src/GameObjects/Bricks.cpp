#include "Bricks.h"

#include "raylib.h"

void InitBricks()
{
	for (int i = 0; i < brickSize; i++)
	{
		bricks[i].x = 20.0f + 100.0f * (i % 7) + 20.0f * (i % 7);
		bricks[i].y = 70.0f + 60.0f * (i / 7) + 5.0f * (i / 7);
		bricks[i].width = 50.0f;
		bricks[i].height = 20.0f;
		bricks[i].lifes = GetRandomValue(1, 5);
	}
}

void DrawBricks()
{

	for (int i = 0; i < brickSize; i++)
	{
		if (bricks[i].lifes == 1)
		{
			DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, WHITE);
		}
		if (bricks[i].lifes == 2)
		{
			DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, GREEN);
		}
		if (bricks[i].lifes == 3)
		{
			DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, PURPLE);
		}
		if (bricks[i].lifes == 4)
		{
			DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, GRAY);
		}
		if (bricks[i].lifes == 5)
		{
			DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, BLUE);
		}
	}
}