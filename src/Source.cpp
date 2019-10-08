#include "raylib.h"
const int screenWidth = 800; //global
const int screenHeight = 450; //gloabl
const int minScreenWidth = 0; //global
const int minScreenHeight = 0; //global
const int posInitialPlayer1X = 330; //player
const int posInitialPlayer1Y = 440; //player
const int player1Width = 150; //player
const int player1Height = 20; //player
const int posInitialBallX = screenWidth / 2; //ball
const int posInitialBallY = 430; //ball
const int ballRadius = 10; //ball
const int lineOfBricks = 5; //bricks
const int brickSize = 35;  //bricks

bool ballOnRectangle = true; //gameplay
bool startKey = false; //gameplay

Rectangle player1; //player
Vector2 ballPosition; //ball
Vector2 speedBall; //ball

Rectangle bricks[brickSize] = {0}; //bricks

struct Brick //bricks
{
	Vector2 pos;
	bool active;
	int life;
};

enum GameState //game
{
	Menu,
	Game,
	Lose
};

GameState state; //game

int main(void)
{
	//--Initialize---
	InitWindow(screenWidth, screenHeight, "Arkanoid Elias");
	ballPosition.x = posInitialBallX;
	ballPosition.y = posInitialBallY;
	speedBall.x = 600.0f;
	speedBall.y = 600.0f;

	player1.x = posInitialPlayer1X;
	player1.y = posInitialPlayer1Y;
	player1.width = player1Width;
	player1.height = player1Height;
	//--Initialize---

	//Init Bricks  --bricks
	for (int i = 0;i < brickSize; i++)
	{
		bricks[i].x = 20.0f + 100.0f * (i % 7) + 20.0f * (i % 7);
		bricks[i].y = 70.0f + 60.0f * (i / 7) + 5.0f * (i / 7);
		bricks[i].width = 50.0f;
		bricks[i].height = 20.0f;
		bricks[i].lifes = GetRandomValue(1, 5);
	}
	//-- bricks

	//init
	SetTargetFPS(60);
	//init

	//--game
	while (!WindowShouldClose())
	{
		//--input
		if (IsKeyDown(KEY_RIGHT))
		{
			player1.x += 500.0f * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			player1.x -= 500.0f * GetFrameTime();
		} 
		// --input

		//--gameplay
		if (ballOnRectangle)
		{
			ballPosition.x = player1.x + 75;
		}
		//--gameplay

		//--gameplay
		if (player1.x + player1.width >= screenWidth)
		{
			player1.x = screenWidth - player1.width;
		}
		if (player1.x <= 0)
		{
			player1.x = 1;
		}
		//--gameplay

		//--draw
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("move the player with arrow keys", 10, 10, 20, DARKGRAY);
		DrawCircleV(ballPosition, ballRadius, WHITE);
		DrawRectangle(player1.x, player1.y, player1.width, player1.height, WHITE);
		//--draw

		//--gameplay
		if (IsKeyDown(KEY_SPACE))
		{
			startKey = true;
		}
		if (startKey == true)
		{
			ballPosition.y -= speedBall.y * GetFrameTime();
			ballOnRectangle = false;
		}
		//--gameplay

		//--Collision
		if (((ballPosition.x + ballRadius) >= screenWidth) || ((ballPosition.x - ballRadius) <= minScreenWidth))
		{
			speedBall.x *= -1.0f;
		}
		if ((ballPosition.y - ballRadius) <= minScreenHeight)
		{
			speedBall.y *= -1.0f;
		}
		//--collision
		//--gameplay
		if ((ballPosition.y - ballRadius) > screenHeight)
		{
			startKey = false;
			ballOnRectangle = true;
			ballPosition.x = player1.x;
			ballPosition.y = player1.y - player1.height + 10.0f;
		}
		//--gameplay
		//--collision
		if ((ballPosition.y + ballRadius) >= screenHeight - player1.height)
		{
			if (CheckCollisionCircleRec(ballPosition, ballRadius, player1))
			{
				speedBall.y *= -1.0f;
			}
		}
		//--collision

		//--Draw Bricks

		for (int i = 0; i < brickSize; i++)
		{
			if (bricks[i].lifes == 1)
			{
				DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, WHITE);
			}
			if (bricks[i].lifes == 2) 
			{
				DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, GREEN);
			}
			if (bricks[i].lifes == 3)
			{
				DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, PURPLE);
			}
			if (bricks[i].lifes == 4)
			{
				DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, GRAY);
			}
			if (bricks[i].lifes == 5)
			{
				DrawRectangle(bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height, BLUE);
			}
		}
		//--Draw Bricks

		//--Collision
		for (int i = 0; i < brickSize; i++)
		{
			if (CheckCollisionCircleRec(ballPosition, ballRadius, bricks[i]))
			{
				bricks[i].lifes -= 1;
				speedBall.y *= -1.0f;
				speedBall.x *= -1.0f;
			}
			if (bricks[i].lifes == 0)
			{
				bricks[i].x = -500.0f;
				bricks[i].y = -500.0f;
			}
		}
		//--collision
	EndDrawing();
	} //--game
	//--EndDrawing
	CloseWindow();
	//--EndDrawing

	return 0;
}