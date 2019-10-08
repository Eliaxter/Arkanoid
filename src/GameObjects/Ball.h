#ifndef BALL_H
#define BALL_H

#include "raylib.h"

#include "Global.h"

const int posInitialBallX = screenWidth / 2;
const int posInitialBallY = 430;
const int ballRadius = 10;

extern Vector2 ballPosition;
extern Vector2 speedBall;

void InitBall();
void InitSpeedBall();
void DrawBall();
void WindowCollisions();

#endif