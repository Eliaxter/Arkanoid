#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

namespace Game
{
	extern bool ballOnRectangle;
	extern bool startKey;

	extern int playerPoints;
	extern int tries;

	extern const int dontCheckCollisionFrames;
	extern bool previusFrameCollisionBall;
	extern bool previusFrameCollisionPlayer;
	extern int lastCollisionFramesPlayer;
	extern int lastCollisionFramesBall;
	extern bool previusFrameCollision;
	extern int lastCollisionFrames;

	//extern Music backgroundMusic;
	extern Sound collisionWave1;
	extern Sound collisionWave2;

	void DrawWindow();
	void InitWindowArkanoid();
	void InitMusic();
	void InitSounds();
	void MuteSounds();
	void DrawTexts();
	void PosBallOnRectangle();
	void StartGame();
	void ResetBallOnRectangle();
	void CheckCollisionBallBricks();
	void DrawBricks();
	void InitGame();
	void MovePlayer();
	void CheckPlayerWin();
	void ResetPoints();
	void ResetTries();
	void Update();
	void Draw();
}

#endif