#ifndef GAMEPLAY_H
#define GAMEPLAY_H

extern bool ballOnRectangle;
extern bool startKey;

void DrawWindow();
void InitWindow();
void DrawTexts();
void PosBallOnRectangle();
void StartGame();
void ResetBallOnRectangle();
void CheckCollisionBallBricks();
void InitGame();
void MovePlayer();
void Update();
void Draw();

#endif