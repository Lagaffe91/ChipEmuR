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

	Utils::InterpreterState Interpreter::GetCurrentState() const
	{
		return mState;
	}

	bool Interpreter::ShouldStop() const
	{
		return false;
	}

	void Interpreter::LoadProgram(const Utils::ProgramDesc& pProgram)
	{
		const char* bytes = pProgram.programBytes.data();

		for (size_t i = 0 ; i < pProgram.size ; i++)
		{
			mState.memory[Utils::programOffset + i] = bytes[i];
		}
	}
}