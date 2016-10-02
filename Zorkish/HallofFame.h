#pragma once
#include "GameState.h"

namespace Zorkish {
	class HallofFame :
		public GameState
	{
	public:
		HallofFame();
		~HallofFame();

		void display();
		void logic();
		int handle_event();
	};
}