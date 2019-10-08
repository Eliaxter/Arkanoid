#include "Gameplay.h"

#include "raylib.h"

#include "Global.h"
#include "Ball.h"
#include "Player.h"
#include "Bricks.h"

static const int screenWidth = 800;
static const int screenHeight = 450;

static Vector2 ballPosition;
static Vector2 speedBall;

static Brick bricks[brickSize] = { 0 };


void DrawWindow()
{
	BeginDrawing();

	ClearBackground(BLACK);
}

void InitWindow()
{
	InitWindow(screenWidth, screenHeight, "Arkanoid Elias");
}

void DrawTexts()
{
	DrawText("move the player with arrow keys", 10, 10, 20, DARKGRAY);
}

void PosBallOnRectangle()
{
	if (ballOnRectangle)
	{
		ballPosition.x = player1.x + 75;
	}
}

void StartGame()
{
	if (IsKeyDown(KEY_SPACE))
	{
		startKey = true;
	}
	if (startKey == true)
	{
		ballPosition.y -= speedBall.y * GetFrameTime();
		ballOnRectangle = false;
	}
}

void ResetBallOnRectangle()
{
	if ((ballPosition.y - ballRadius) > screenHeight)
	{
		startKey = false;
		ballOnRectangle = true;
		ballPosition.x = player1.x;
		ballPosition.y = player1.y - player1.height + 10.0f;
	}
}

void CheckCollisionBallBricks()
{
	for (int i = 0; i < brickSize; i++)
	{
		if (CheckCollisionCircleRec(ballPosition, ballRadius, bricks[i].rect))
		{
			bricks[i].life -= 1;
			speedBall.y *= -1.0f;
			speedBall.x *= -1.0f;
		}
		if (bricks[i].life == 0)
		{
			bricks[i].rect.x = -500.0f;
			bricks[i].rect.y = -500.0f;
		}
	}
}

void MovePlayer()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		player1.x += 500.0f * GetFrameTime();
	}
	if (IsKeyDown(KEY_LEFT))
	{
		player1.x -= 500.0f * GetFrameTime();
	}
}

void InitGame()
{
	InitPlayer();
	InitBall();
	SetPlayerSizes();
	InitSpeedBall();
}

void Update()
{
	PosBallOnRectangle();
	StartGame();
	MovePlayer();
	ResetBallOnRectangle();
	CheckCollisionBallBricks();
	CollisionBallWithPlayer();
	WindowCollisions();
	LimitMove();
}

void Draw()
{
	DrawBall();
	DrawPlayer();
	DrawBricks();
}