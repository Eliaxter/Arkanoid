#include "Gameplay.h"

#include "raylib.h"

#include "Ball.h"
#include "Player.h"

void PosBallOnRectangle()
{
	if (ballOnRectangle)
	{
		ballPosition.x = player1.x + 75;
	}
}

void StartGame()
{
	if (IsKeyDown(KEY_SPACE))
	{
		startKey = true;
	}
	if (startKey == true)
	{
		ballPosition.y -= speedBall.y * GetFrameTime();
		ballOnRectangle = false;
	}
}

void ResetBallOnRectangle()
{
	if ((ballPosition.y - ballRadius) > screenHeight)
	{
		startKey = false;
		ballOnRectangle = true;
		ballPosition.x = player1.x;
		ballPosition.y = player1.y - player1.height + 10.0f;
	}
}

void CheckCollisionBallBricks()
{
	for (int i = 0; i < brickSize; i++)
	{
		if (CheckCollisionCircleRec(ballPosition, ballRadius, bricks[i]))
		{
			bricks[i].lifes -= 1;
			speedBall.y *= -1.0f;
			speedBall.x *= -1.0f;
		}
		if (bricks[i].lifes == 0)
		{
			bricks[i].x = -500.0f;
			bricks[i].y = -500.0f;
		}
	}
}

