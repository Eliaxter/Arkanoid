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
	static int bricksDestroyed = 0;
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

	static float playerSpeed = 750.0f;
	static int halfPlayer = 75;

	static int resetVariable = 0;

	static bool isAudioPlaying = true;

	static float incrementHeight = 5.0f;

	static int fontSize = 30;

	static int coordTxtX = 10;
	static int coordTxtY = 10;

	static int coordTxt4X = 450;
	static int coordTxt4Y = 10;

	static int coordTxt3X = 200;
	static int coordTxt3Y = 10;

	static int coordTxt2X = 650;
	static int coordTxt2Y = 20;

	Sound collisionWave1;
	Sound collisionWave2;

	void DrawWindow()
	{
		ClearBackground(BLACK);
	}

	void InitWindowArkanoid()
	{
		InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), "Arkanoid Elias");
		InitAudioDevice();
	}

	void InitMusic()
	{
		backgroundMusic = LoadMusicStream("assets/music/backgroundMusic.ogg");
	}

	void InitSounds() 
	{
		collisionWave1 = LoadSound("assets/sounds/collisionSound01.wav");
		collisionWave2 = LoadSound("assets/sounds/collisionSound02.wav");
	}

	void MuteSounds()
	{
		if (IsKeyDown(KEY_M))
		{
			SetMasterVolume(0);
		}
		if (IsKeyDown(KEY_T))
		{
			SetMasterVolume(1);
		}
	}

	void DrawTexts()
	{
		DrawText(TextFormat("Tries: %i", tries), coordTxtX, coordTxtY, fontSize, WHITE);
		DrawText(TextFormat("Points: %i", playerPoints), coordTxt2X, coordTxt2Y, fontSize, WHITE);
		DrawText("Mute Audio: M", coordTxt3X, coordTxt3Y, fontSize, WHITE);
		DrawText("Unmute Audio: T", coordTxt4X, coordTxt4Y, fontSize, WHITE);
	}

	void PosBallOnRectangle()
	{
		if (ballOnRectangle == true)
		{
			ballPosition.x = player1.x + halfPlayer;
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
			ballPosition.y = player1.y - player1.height + incrementHeight;
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
			if (bricks[i].isAlive == true)
			{
				if (CheckCollisionCircleRec(ballPosition, ballRadius, bricks[i].rect))
				{
					bricks[i].life -= brickLifeDown;
					playerPoints++;
					speedBall.y *= negativeSpeed;
					speedBall.x *= negativeSpeed;
					PlaySound(collisionWave1);
					if (bricks[i].life <= brickDead)
					{
						bricksDestroyed++;
						bricks[i].rect.x = teleportBrick;
						bricks[i].rect.y = teleportBrick;
						bricks[i].isAlive = false;
					}
				}
			}
		}
	}

	void DrawBricks() 
	{
		for (int i = 0; i < brickSize; i++)
		{
			if (bricks[i].life == firstLife)
			{
				DrawRectangle(static_cast<int>(bricks[i].rect.x), static_cast<int>(bricks[i].rect.y), static_cast<int>(bricks[i].rect.width), static_cast<int>(bricks[i].rect.height), WHITE);
			}
			if (bricks[i].life == secondLife)
			{
				DrawRectangle(static_cast<int>(bricks[i].rect.x), static_cast<int>(bricks[i].rect.y), static_cast<int>(bricks[i].rect.width), static_cast<int>(bricks[i].rect.height), GREEN);
			}
			if (bricks[i].life == thirdLife)
			{
				DrawRectangle(static_cast<int>(bricks[i].rect.x), static_cast<int>(bricks[i].rect.y), static_cast<int>(bricks[i].rect.width), static_cast<int>(bricks[i].rect.height), PURPLE);
			}
			if (bricks[i].life == fourthLife)
			{
				DrawRectangle(static_cast<int>(bricks[i].rect.x), static_cast<int>(bricks[i].rect.y), static_cast<int>(bricks[i].rect.width), static_cast<int>(bricks[i].rect.height), GRAY);
			}
			if (bricks[i].life == fifthLife)
			{
				DrawRectangle(static_cast<int>(bricks[i].rect.x), static_cast<int>(bricks[i].rect.y), static_cast<int>(bricks[i].rect.width), static_cast<int>(bricks[i].rect.height), BLUE);
			}
		}
	}

	void MovePlayer()
	{
		if (IsKeyDown(KEY_RIGHT))
		{
			player1.x += playerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			player1.x -= playerSpeed * GetFrameTime();
		}
	}

	void CheckPlayerWin()
	{
		if (bricksDestroyed >= brickSize)
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
		InitMusic();
		InitSounds();
		PlayMusicStream(backgroundMusic);
		InitPlayer();
		InitBall();
		InitBricks();
		SetPlayerSizes();
		InitSpeedBall();
		ResetPoints();
		ResetTries();
		bricksDestroyed = resetVariable;
		startKey = false;
		ballOnRectangle = true;
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
		UpdateMusicStream(backgroundMusic);
		CheckPlayerWin();
		LimitMove();
		MuteSounds();
	}

	void Draw()
	{
		DrawTexts();
		DrawBall();
		DrawPlayer();
		DrawBricks();
	}
}