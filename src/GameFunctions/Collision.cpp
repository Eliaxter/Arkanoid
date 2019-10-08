#include "Collision.h"

#include "Ball.h"
#include "Player.h"
#include "Global.h"

void WindowLimits()
{
	if (player1.x + player1.width >= screenWidth)
	{
		player1.x = screenWidth - player1.width;
	}
	if (player1.x <= 0)
	{
		player1.x = 1;
	}
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

void CollisionBallWithPlayer()
{
	if ((ballPosition.y + ballRadius) >= screenHeight - player1.height)
	{
		if (CheckCollisionCircleRec(ballPosition, ballRadius, player1))
		{
			speedBall.y *= -1.0f;
		}
	}
}