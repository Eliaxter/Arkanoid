#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"
#include "Gameplay.h"

namespace Game
{
	static int fontSize = 20;

	static int coordTxtX = 300;
	static int coordTxtY = 160;

	static int coordTxt2X = 300;
	static int coordTxt2Y = 200;

	static int coordTxt3X = 300;
	static int coordTxt3Y = 220;

	static int coordTxt4X = 300;
	static int coordTxt4Y = 240;

	void DrawWindowFinalMenu()
	{
		ClearBackground(BLACK);
	}

	void DrawTextFinalMenu()
	{
		DrawText("End of Game!", coordTxtX, coordTxtY, fontSize, RAYWHITE);

		DrawText("Play Again: Y/N", coordTxt2X, coordTxt2Y, fontSize, RAYWHITE);

		DrawText("Return to Main Menu: M", coordTxt3X, coordTxt3Y, fontSize, RAYWHITE);

		DrawText("Credits: C", coordTxt4X, coordTxt4Y, fontSize, RAYWHITE);
	}

	void InputFinalMenu()
	{
		if (IsKeyDown(KEY_M))
		{
			state = GameState::StartMenu;
		}
		if (IsKeyDown(KEY_ESCAPE))
		{
			CloseWindow();
		}
		if (IsKeyDown(KEY_C))
		{
			state = GameState::Credits;
		}
		if (IsKeyDown(KEY_Y))
		{
			InitGame();
			state = GameState::Game;
		}
		if (IsKeyDown(KEY_N))
		{
			state = GameState::CloseAll;
		}
	}

	void FinalMenu()
	{
		DrawWindowFinalMenu();
		DrawTextFinalMenu();
		InputFinalMenu();
	}
}