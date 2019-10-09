#include "Game.h"

#include "raylib.h"

#include "Menu.h"
#include "Gameplay.h"
#include "FinalMenu.h"
#include "Player.h"
#include "Ball.h"

namespace Game
{
	GameState state = GameState::StartMenu;

	void GameLoop()
	{
		InitWindowArkanoid();

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);
			if (state == GameState::StartMenu)
			{
				Menu();
			}
			if (state == GameState::Game)
			{
				Update();
				Draw();
			}
			if (state == GameState::Lose)
			{
				FinalMenu();
			}
			EndDrawing();
		}
		CloseWindow();
	}
}