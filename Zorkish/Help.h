#pragma once
#include "GameState.h"

namespace Zorkish {
	class Help :
		public GameState
	{
	public:
		Help();
		~Help();

		void display();
		void logic();
		int handle_event();
	};
}