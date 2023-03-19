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

		Utils::InterpreterState GetCurrentState() const;

		bool ShouldStop() const;

		void LoadProgram(const Utils::ProgramDesc& pProgram);

	private:
		Utils::InterpreterState mState;
	};
}