#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

const int posInitialPlayer1X = 330;
const int posInitialPlayer1Y = 440; 
const int player1Width = 150;
const int player1Height = 20;

extern Rectangle player1;

void InitPlayer();
void SetPlayerSizes();
void DrawPlayer();
void CollisionBallWithPlayer();
void LimitMove();

#endif