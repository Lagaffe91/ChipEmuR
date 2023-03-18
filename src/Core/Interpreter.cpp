#include "Interpreter.hpp"

namespace Core
{
	Interpreter::Interpreter()
	{
	}

	Interpreter::~Interpreter()
	{
	}

	void Interpreter::SimulateCycle()
	{

	}

	InterpreterState Interpreter::GetCurrentState()
	{
		return mState;
	}

	bool Interpreter::ShouldStop()
	{
		return false;
	}
}