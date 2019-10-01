#include "raylib.h"
const int screenWidth = 800;
const int screenHeight = 450;
const int posInitialPlayer1X = 330;
const int posInitialPlayer1Y = 440;
const int player1Width = 150;
const int player1Height = 20;
const int posInitialBallX = screenWidth / 2;
const int posInitialBallY = 430;
const int ballRadius = 10;
const int lineOfBricks = 5;
const int bricksPerLine = 20;

bool ballOnRectangle = true;
bool startKey = false;

int initialDownPosition = 50;

Rectangle player1;
Vector2 ballPosition;
Vector2 speedBall;
Vector2 brickSize;

struct Brick 
{
	Vector2 pos;
	bool active;
};

Brick brick[lineOfBricks][bricksPerLine] = {0};

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(screenWidth, screenHeight, "Arkanoid Elias");

	ballPosition.x = posInitialBallX;
	ballPosition.y = posInitialBallY;
	speedBall.x = 400.0f;
	speedBall.y = 400.0f;

	player1.x = posInitialPlayer1X;
	player1.y = posInitialPlayer1Y;
	player1.width = player1Width;
	player1.height = player1Height;

	//Init Bricks

	brickSize.x = screenWidth / bricksPerLine;
	brickSize.y = 40;

	for (int i = 0; i < lineOfBricks; i++)
	{
		for (int j = 0; j < bricksPerLine; j++)
		{
			brick[i][j].pos.x = j*brickSize.x + brickSize.x/2;
			brick[i][j].pos.y = i * brickSize.y + initialDownPosition;
			brick[i][j].active = true;
		}
	}

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_RIGHT))
		{
			player1.x += 500.0f * GetFrameTime();
		}	
		if (IsKeyDown(KEY_LEFT))
		{
			player1.x -= 500.0f * GetFrameTime();
		}

		if (ballOnRectangle)
		{
			ballPosition.x = player1.x + 75;
		}

		if (player1.x + player1.width >= screenWidth)
		{
			player1.x = screenWidth - player1.width;
		}
		if (player1.x <= 0)
		{
			player1.x = 1;
		}
	
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
		DrawCircleV(ballPosition, ballRadius, WHITE);
		DrawRectangle(player1.x, player1.y, player1.width, player1.height, WHITE);

		if (IsKeyDown(KEY_SPACE))
		{
			startKey = true;
		}
		if (startKey == true)
		{
			ballPosition.y -= speedBall.y * GetFrameTime();
			ballOnRectangle = false;
		}

		//Conditions
		if (((ballPosition.x + ballRadius) >= screenWidth) || ((ballPosition.x - ballRadius) <= 0))
		{
			speedBall.x *= -1;
		}
		if ((ballPosition.y - ballRadius) <= 0) 
		{
			speedBall.y *= -1;
		} 
		if ((ballPosition.y + ballRadius) >= screenHeight)
		{
			speedBall.x = 0;
			ballPosition.y = -100;
			speedBall.y = 0;
		}

		//Draw Rectangles

		for (int i = 0; i < lineOfBricks; i++) 
		{
			for (int j = 0; j < bricksPerLine; j++) 
			{
				if (brick[i][j].active == true) 
				{
					if ((i + j) % 2 == 0)
					{
						DrawRectangle(brick[i][j].pos.x - brickSize.x/2, brick[i][j].pos.y - brickSize.y/2, brickSize.x, brickSize.y, GRAY);
					}
					else 
					{
						DrawRectangle(brick[i][j].pos.x - brickSize.x / 2, brick[i][j].pos.y - brickSize.y / 2, brickSize.x, brickSize.y, DARKGRAY);
					}
				}
			}
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}