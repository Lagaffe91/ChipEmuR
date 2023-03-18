#pragma once

#include "Utils.hpp"

namespace Core
{
	class Interpreter
	{
	public:
		Interpreter();
		~Interpreter();

		void SimulateCycle();

		InterpreterState GetCurrentState();

		bool ShouldStop();

	private:
		InterpreterState mState;
	};
}