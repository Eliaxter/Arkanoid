#include "Ball.h"

#include "raylib.h"

#include "Global.h"
#include "Gameplay.h"

namespace Game
{
	const float posInitialBallX = screenWidth / 2.0f;
	const float posInitialBallY = 415.0f;
	const float ballRadius = 10.0f;

	Vector2 ballPosition;
	Vector2 speedBall;

	const int minScreenWidth = 0;
	const int minScreenHeight = 0;

	static float initialSpeedX = 0.0f;
	static float initialSpeedY = 500.0f;
	static float negativeSpeed = -1.0f;

	bool previusFrameCollisionBall = false;
	int lastCollisionFramesBall = 0;

	void InitBall()
	{
		ballPosition.x = posInitialBallX;
		ballPosition.y = posInitialBallY;
	}

	void InitSpeedBall()
	{
		speedBall.x = initialSpeedX;
		speedBall.y = initialSpeedY;
	}

	void DrawBall()
	{
		DrawCircleV(ballPosition, ballRadius, WHITE);
	}

	void WindowCollisions()
	{
		if (previusFrameCollisionBall)
		{
			lastCollisionFramesBall++;
			if (lastCollisionFramesBall >= dontCheckCollisionFrames)
			{
				previusFrameCollision = 0;
				lastCollisionFramesBall = false;
			}
		}
	
		if ((ballPosition.x + ballRadius) >= screenWidth)
		{
			if (!previusFrameCollisionBall) 
			{
				speedBall.x *= negativeSpeed;
				ballPosition.x = screenWidth - ballRadius;
			}
		}
		if ((ballPosition.x - ballRadius) <= minScreenWidth)
		{
			if (!previusFrameCollisionBall)
			{
				speedBall.x *= negativeSpeed;
				ballPosition.x = ballRadius;
			}
		}
		if (ballPosition.y < ballRadius)
		{
			speedBall.y *= negativeSpeed;
			ballPosition.y = ballRadius;
		}

	}

	void MoveBall()
	{
		ballPosition.y -= speedBall.y * GetFrameTime();
		ballPosition.x += speedBall.x * GetFrameTime();
	}
}