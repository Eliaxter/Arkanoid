#ifndef GAME_H
#define GAME_H

namespace Game
{
	enum GameState
	{
		StartMenu,
		Game,
		MenuFinal,
		Lose,
		CloseAll
	};

	extern GameState state;

	void GameLoop();
}

#endif