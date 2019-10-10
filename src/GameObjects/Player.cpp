#include "Player.h"

#include "Global.h"
#include "Ball.h"
#include "Gameplay.h"

namespace Game
{
	Rectangle player1;

	void InitPlayer()
	{
		player1.x = posInitialPlayer1X;
		player1.y = posInitialPlayer1Y;
	}

	void SetPlayerSizes()
	{
		player1.width = player1Width;
		player1.height = player1Height;
	}

	void DrawPlayer()
	{
		DrawRectangle(player1.x, player1.y, player1.width, player1.height, WHITE);
	}

	void CollisionBallWithPlayer()
	{
		if ((ballPosition.y + ballRadius) >= (screenHeight - player1.height))
		{
			if (CheckCollisionCircleRec(ballPosition, ballRadius, player1))
			{
				speedBall.y *= -1.0f;
				if ((ballPosition.y - ballRadius) >= (player1.x + player1.width / 2))
				{
					AngleOfBall();
				}
			}
		}
	}

	void LimitMove()
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
}