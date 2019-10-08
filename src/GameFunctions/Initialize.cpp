#include "Initialize.h"

#include "raylib.h"

#include "Global.h"
#include "Ball.h"
#include "Player.h"

void InitWindow() 
{
	InitWindow(screenWidth, screenHeight, "Arkanoid Elias");
}

void InitBall() 
{
	ballPosition.x = posInitialBallX;
	ballPosition.y = posInitialBallY;
}

void InitSpeedBall() 
{
	speedBall.x = 600.0f;
	speedBall.y = 600.0f;
}

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

void SetFPS()
{
	SetTargetFPS(60);
}