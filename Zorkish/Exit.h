#pragma once
#include "GameState.h"

namespace Zorkish {
	class Exit
		: public GameState
	{
	public:
		Exit();
		~Exit();

		void display() override;
		void logic() override;
		int handle_event() override;
	};
}