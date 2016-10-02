#pragma once
#include "GameState.h"
#include "Player.h"
#include "GameMode.h"

namespace Zorkish {
	class NewHighScore :
		public GameState
	{
	public:
		NewHighScore(Player* aPlayer, GameMode* aGameMode);
		~NewHighScore();

		void display();
		void logic();
		int handle_event();
	private:
		Player* fPlayer;
		GameMode* game = new GameMode();
	};
}