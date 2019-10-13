#ifndef BALL_H
#define BALL_H

#include "raylib.h"

namespace Game
{
	extern const int posInitialBallX;
	extern const int posInitialBallY;
	extern const int ballRadius;

	extern Vector2 ballPosition;
	extern Vector2 speedBall;

	void InitBall();
	void InitSpeedBall();
	void DrawBall();
	void WindowCollisions();
	void MoveBall();
}

#endif