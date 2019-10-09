#include "Gameplay.h"

#include "raylib.h"

#include "Global.h"
#include "Ball.h"
#include "Player.h"
#include "Bricks.h"

bool ballOnRectangle = true;
bool startKey = false;

int playerPoints = 0;

static float negativeSpeed = -1.0f;
static int brickLifeDown = 1;
static int brickDead = 0;
static float teleportBrick = -500.0f;

void DrawWindow()
{
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
	if (ballOnRectangle == true)
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
		MoveBall();
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
			bricks[i].life -= brickLifeDown;
			speedBall.y *= negativeSpeed;
			speedBall.x *= negativeSpeed;
		}
		if (bricks[i].life == brickDead)
		{
			bricks[i].rect.x = teleportBrick;
			bricks[i].rect.y = teleportBrick;
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
	WindowCollisions();
	ResetBallOnRectangle();
	CheckCollisionBallBricks();
	CollisionBallWithPlayer();
	LimitMove();
}

void Draw()
{
	DrawBall();
	DrawPlayer();
	DrawBricks();
}