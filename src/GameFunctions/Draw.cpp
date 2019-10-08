#include "Draw.h"

#include "raylib.h"

#include "Ball.h"
#include "player.h"

void DrawWindow()
{
	BeginDrawing();

	ClearBackground(BLACK);
}

void DrawTexts()
{
	DrawText("move the player with arrow keys", 10, 10, 20, DARKGRAY);
}

void DrawBall()
{
	DrawCircleV(ballPosition, ballRadius, WHITE);
}

void DrawPlayer()
{
	DrawRectangle(player1.x, player1.y, player1.width, player1.height, WHITE);
}

