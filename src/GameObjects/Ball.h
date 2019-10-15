#ifndef BALL_H
#define BALL_H

#include "raylib.h"

namespace Game
{
	extern const float posInitialBallY;
	extern const float posInitialBallX;
	extern const float ballRadius;

	extern Vector2 ballPosition;
	extern Vector2 speedBall;

	void InitBall();
	void InitSpeedBall();
	void DrawBall();
	void WindowCollisions();
	void MoveBall();
}

#endif