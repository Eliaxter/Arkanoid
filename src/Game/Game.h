#ifndef GAME_H
#define GAME_H

namespace Game
{
	enum GameState
	{
		StartMenu,
		Game,
		MenuFinal,
		Credits,
		CloseAll
	};

	extern GameState state;

	void GameLoop();
}

#endif