#include "Ball.h"

#include "raylib.h"

#include "Global.h"
#include "Gameplay.h"

namespace Game
{
	Vector2 ballPosition;
	Vector2 speedBall;

	const int minScreenWidth = 0;
	const int minScreenHeight = 0;

	static float initialSpeed = 500.0f;

	bool previusFrameCollisionBall = false;
	int lastCollisionFramesBall = 0;

	void InitBall()
	{
		ballPosition.x = posInitialBallX;
		ballPosition.y = posInitialBallY;
	}

	void InitSpeedBall()
	{
		speedBall.x = initialSpeed;
		speedBall.y = initialSpeed;
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
	
		if (((ballPosition.x + ballRadius) >= screenWidth) || ((ballPosition.x - ballRadius) <= minScreenWidth))
		{
			if (!previusFrameCollisionBall) 
			{
				speedBall.x *= -1.0f;
			}
		}
		if (ballPosition.y < ballRadius)
		{
			speedBall.y *= -1.0f;
		}

	}

	void MoveBall()
	{
		ballPosition.y -= speedBall.y * GetFrameTime();
		ballPosition.x += speedBall.x * GetFrameTime();
	}
}