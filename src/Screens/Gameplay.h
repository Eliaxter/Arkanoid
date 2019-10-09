#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Game
{
	extern bool ballOnRectangle;
	extern bool startKey;

	extern int playerPoints;
	extern int tries;

	void DrawWindow();
	void InitWindowArkanoid();
	void DrawTexts();
	void PosBallOnRectangle();
	void StartGame();
	void ResetBallOnRectangle();
	void CheckCollisionBallBricks();
	void InitGame();
	void MovePlayer();
	void AngleOfBall();
	void CheckPlayerWin();
	void ResetPoints();
	void ResetTries();
	void Update();
	void Draw();
}

#endif