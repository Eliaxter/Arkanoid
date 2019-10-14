#include "Player.h"

#include "Global.h"
#include "Ball.h"
#include "Gameplay.h"

namespace Game
{
	Rectangle player1;

	const int dontCheckCollisionFrames = 20;
	bool previusFrameCollisionPlayer = false;
	int lastCollisionFramesPlayer = 0;
	bool previusFrameCollision = false;
	int lastCollisionFrames = 0;

	static float negativeSpeed = -1.0f;

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
		if (previusFrameCollisionPlayer)
		{
			lastCollisionFramesPlayer++;
			if (lastCollisionFramesPlayer >= dontCheckCollisionFrames)
			{
				previusFrameCollision = 0;
				lastCollisionFramesPlayer = false;
			}
		}
		if ((ballPosition.y + ballRadius) >= (screenHeight - player1.height))
		{
			if (CheckCollisionCircleRec(ballPosition, ballRadius, player1))
			{
				if (!previusFrameCollisionPlayer)
				{
					speedBall.y *= negativeSpeed;
					ballPosition.y = player1.y - ballRadius;
					PlaySound(collisionWave2);
				}
				//speedBall.x = (ballPosition.x - player1.x - player1.width / 2) / (player1.width / 2) * 5;
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