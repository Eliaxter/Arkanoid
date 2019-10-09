#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Game
{
	extern bool ballOnRectangle;
	extern bool startKey;

	extern int playerPoints;

	void DrawWindow();
	void InitWindowArkanoid();
	void DrawTexts();
	void PosBallOnRectangle();
	void StartGame();
	void ResetBallOnRectangle();
	void CheckCollisionBallBricks();
	void InitGame();
	void MovePlayer();
	void Update();
	void Draw();
}

#endif