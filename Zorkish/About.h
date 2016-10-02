#pragma once
#include "GameState.h"

namespace Zorkish {
	class About :
		public GameState
	{
	public:
		About();
		~About();

		void display() override;
		void logic() override;
		int handle_event() override;
	};
}