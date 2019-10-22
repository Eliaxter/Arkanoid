#include "Menu.h"

#include "raylib.h"

#include "Game.h"
#include "Gameplay.h"
#include "Global.h"

namespace Game
{
	static int fontSize1 = 20;
	static int fontSize2 = 30;

	static int coordTxtY = 140;

	static int coordTxt2Y = 200;

	static int coordTxt3Y = 240;

	static int coordTxt4Y = 280;

	void DrawWindowMenu()
	{
		ClearBackground(BLACK);
	}

	void DrawTextMenu()
	{
		DrawText("Elias Arkanoid! V1.0", static_cast<int>(screenWidth / 2), coordTxtY, fontSize2, GRAY);
		DrawText("To Play the game, press the key: ENTER", static_cast<int>(screenWidth / 4), coordTxt2Y, fontSize1, RAYWHITE);
		DrawText("How To play, press the key: H", static_cast<int>(screenWidth / 4), coordTxt3Y, fontSize1, RAYWHITE);
		DrawText("To Exit, press the key: ESCAPE", static_cast<int>(screenWidth / 4), coordTxt4Y, fontSize1, RAYWHITE);
	}

	void InputMenu()
	{
		if (IsKeyDown(KEY_ENTER))
		{
			state = GameState::Game;
			InitGame();
		}
		if (IsKeyDown(KEY_H))
		{
			state = GameState::Instructions;
		}
		if (IsKeyDown(KEY_ESCAPE))
		{
			state = GameState::CloseAll;
		}
	}

	void Menu()
	{
		DrawWindowMenu();
		DrawTextMenu();
		InputMenu();
	}
}