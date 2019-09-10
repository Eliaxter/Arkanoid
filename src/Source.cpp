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

bool startKey = false;

Rectangle player1;
Vector2 ballPosition;
Vector2 speedBall;


int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(screenWidth, screenHeight, "Arkanoid Elias");

	ballPosition.x = posInitialBallX;
	ballPosition.y = posInitialBallY;
	speedBall.x = 10.0f;
	speedBall.y = 10.0f;

	player1.x = posInitialPlayer1X;
	player1.y = posInitialPlayer1Y;
	player1.width = player1Width;
	player1.height = player1Height;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_RIGHT)) player1.x += 7.0f;
		if (IsKeyDown(KEY_LEFT)) player1.x -= 7.0f;

		ballPosition.x = player1.x + 75;
	
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
			ballPosition.y -= speedBall.y;
		}

		//Conditions
		if (((ballPosition.x + ballRadius) >= screenWidth) || ((ballPosition.x - ballRadius) <= 0)) speedBall.x *= -1;
		if ((ballPosition.y - ballRadius) <= 0) speedBall.y *= -1;
		if ((ballPosition.y + ballRadius) >= screenHeight)
		{
			speedBall.x = 0;
			ballPosition.y = -100;
			speedBall.y = 0;
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