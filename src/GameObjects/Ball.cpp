#include "Ball.h"

#include "raylib.h"

#include "Global.h"

static Vector2 ballPosition;
static Vector2 speedBall;

const int minScreenWidth = 0;
const int minScreenHeight = 0;

void InitBall()
{
	ballPosition.x = posInitialBallX;
	ballPosition.y = posInitialBallY;
}

void InitSpeedBall()
{
	speedBall.x = 600.0f;
	speedBall.y = 600.0f;
}

void DrawBall()
{
	DrawCircleV(ballPosition, ballRadius, WHITE);
}

void WindowCollisions()
{
	if (((ballPosition.x + ballRadius) >= screenWidth) || ((ballPosition.x - ballRadius) <= minScreenWidth))
	{
		speedBall.x *= -1.0f;
	}
	if ((ballPosition.y - ballRadius) <= minScreenHeight)
	{
		speedBall.y *= -1.0f;
	}
}