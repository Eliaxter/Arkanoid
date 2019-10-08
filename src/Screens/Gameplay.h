#ifndef GAMEPLAY_H
#define GAMEPLAY_H

extern bool ballOnRectangle = true;
extern bool startKey = false;

void DrawWindow();
void InitWindow();
void DrawTexts();
void PosBallOnRectangle();
void StartGame();
void ResetBallOnRectangle();
void CheckCollisionBallBricks();
void MovePlayer();
void InitGame();
void Update();
void Draw();

#endif