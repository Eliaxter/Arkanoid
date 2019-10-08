#include "Game.h"

#include "raylib.h"

#include "Menu.h"
#include "Gameplay.h"
#include "FinalMenu.h"

GameState state = GameState::StartMenu;

void GameLoop()
{
	while (!WindowShouldClose)
	{
		if (state == GameState::StartMenu)
		{
			Menu();
		}
		if (state == GameState::Game)
		{
			InitGame();
			MovePlayer();
			Update();
			Draw();
		}
		if (state == GameState::Lose)
		{
			FinalMenu();
		}
	}
}