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
	
	static float limitInX = 1.0f;

	static float ballDirection = 500.0f;


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
		DrawRectangle(static_cast<int>(player1.x), static_cast<int>(player1.y), static_cast<int>(player1.width), static_cast<int>(player1.height), WHITE);
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
					speedBall.x = (ballPosition.x - player1.x - player1.width / 2.0f) / (player1.width / 2.0f) * ballDirection;
					ballPosition.y = player1.y - ballRadius;
					PlaySound(collisionWave2);
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
		if (player1.x <= minScreenHeight)
		{
			player1.x = limitInX;
		}
	}
}