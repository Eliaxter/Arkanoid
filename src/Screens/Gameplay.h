#ifndef GAMEPLAY_H
#define GAMEPLAY_H

extern bool ballOnRectangle = true;
extern bool startKey = false;

void PosBallOnRectangle();
void StartGame();
void ResetBallOnRectangle();
void CheckCollisionBallBricks();

#endif