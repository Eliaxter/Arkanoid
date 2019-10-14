#include "Credits.h"

#include "raylib.h"

#include "Game.h"

namespace Game 
{
	void DrawWindowCredits()
	{
		ClearBackground(BLACK);
	}

	void DrawTextCredits()
	{
		DrawText("Credits", 300, 160, 20, GREEN);

		DrawText("Audio & Sounds: Lautaro Brucart", 300, 180, 20, RAYWHITE);

		DrawText("To back to Menu Final, press the key: B", 300, 200, 20, RAYWHITE);

		DrawText("To return Main Menu, press the key: M", 300, 220, 20, RAYWHITE);

		DrawText("To exit, press the key: ESCAPE", 300, 240, 20, RAYWHITE);
	}

	void InputCredits()
	{
		if (IsKeyDown(KEY_B))
		{
			state = GameState::MenuFinal;
		}
		if (IsKeyDown(KEY_ESCAPE))
		{
			CloseWindow();
		}
	}

	void CreditsScreen()
	{
		DrawWindowCredits();
		DrawTextCredits();
		InputCredits();
	}
}

