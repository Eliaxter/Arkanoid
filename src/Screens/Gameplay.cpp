#include "Gameplay.h"

#include "raylib.h"

#include "Global.h"
#include "Ball.h"
#include "Player.h"
#include "Bricks.h"
#include "Game.h"

namespace Game
{
	bool ballOnRectangle = true;
	bool startKey = false;

	int playerPoints = 0;
	int tries = 5;

	static float negativeSpeed = -1.0f;
	static int brickLifeDown = 1;
	static int brickDead = 0;
	static float teleportBrick = -500.0f;
	static int loseTries = 0;
	static int pointsToWin = 50;
	static int initialPoints = 0;
	static int initialTries = 5;

	static int firstLife = 1;
	static int secondLife = 2;
	static int thirdLife = 3;
	static int fourthLife = 4;
	static int fifthLife = 5;

	void DrawWindow()
	{
		ClearBackground(BLACK);
	}

	void InitWindowArkanoid()
	{
		InitWindow(screenWidth, screenHeight, "Arkanoid Elias");
	}

	void DrawTexts()
	{
		DrawText(TextFormat("Tries: %i", tries), 10, 10, 30, WHITE);
		DrawText(TextFormat("Points: %i", playerPoints), 650, 20, 30, WHITE);
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
			tries--;
			startKey = false;
			ballOnRectangle = true;
			ballPosition.x = player1.x;
			ballPosition.y = player1.y - player1.height + 10.0f;
			if (tries <= loseTries)
			{
				state = GameState::MenuFinal;
			}
		}
	}

	void CheckCollisionBallBricks()
	{
		for (int i = 0; i < brickSize; i++)
		{
			if (CheckCollisionCircleRec(ballPosition, ballRadius, bricks[i].rect))
			{
				bricks[i].life -= brickLifeDown;
				playerPoints++;
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

	void DrawBricks() 
	{
		for (int i = 0; i < brickSize; i++)
		{
			if (bricks[i].life == firstLife)
			{
				DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, WHITE);
			}
			if (bricks[i].life == secondLife)
			{
				DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, GREEN);
			}
			if (bricks[i].life == thirdLife)
			{
				DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, PURPLE);
			}
			if (bricks[i].life == fourthLife)
			{
				DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, GRAY);
			}
			if (bricks[i].life == fifthLife)
			{
				DrawRectangle(bricks[i].rect.x, bricks[i].rect.y, bricks[i].rect.width, bricks[i].rect.height, BLUE);
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

	void AngleOfBall()
	{
		//ballPosition.x += speedBall.x * GetFrameTime();
	}

	void CheckPlayerWin()
	{
		if (playerPoints >= pointsToWin)
		{
			state = GameState::MenuFinal;
		}
	}

	void ResetPoints()
	{
		playerPoints = initialPoints;
	}

	void ResetTries()
	{
		tries = initialTries;
	}

	void InitGame()
	{
		InitPlayer();
		InitBall();
		InitBricks();
		SetPlayerSizes();
		InitSpeedBall();
		ResetPoints();
		ResetTries();
	}

	void Update()
	{
		PosBallOnRectangle();
		StartGame();
		MovePlayer();
		AngleOfBall();
		WindowCollisions();
		ResetBallOnRectangle();
		CheckCollisionBallBricks();
		CollisionBallWithPlayer();
		CheckPlayerWin();
		LimitMove();
	}

	void Draw()
	{
		DrawTexts();
		DrawBall();
		DrawPlayer();
		DrawBricks();
	}
}