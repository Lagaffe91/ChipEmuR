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
		//
		//Fetch next intruction
		// 
	
		unsigned int instruction = mState.memory[mState.programCounter];
		
		instruction = instruction << 8;

		instruction += mState.memory[mState.programCounter + 1];

		//
		//Decode - Execute
		// 

		int instructionCode = instruction >> 12;

		this->instructionsFunctions[instructionCode](instruction);

		//
		//Decrease timers
		//

		if(mState.delayTimer > 0)
			mState.delayTimer--;

		if (mState.soundTimer > 0)
			mState.soundTimer--;
	
		//depends on the instruction, move this in instruction specific functions
		mState.programCounter += 2;
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
#pragma region
	void Interpreter::Instructions0x0xxx(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0x1nnn(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0x2nnn(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0x3xkk(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0x4xkk(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0x5xy0(const int& pInstruction)
	{

	}

	void Interpreter::Instructions0x6xkk(const int& pInstruction)
	{

	}

	void Interpreter::Instructions0x7xkk(const int& pInstruction)
	{

	}

	void Interpreter::Instructions0x8xxx(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0x9xy0(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0xAnnn(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0xBnnn(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0xCxkk(const int& pInstruction)
	{

	}

	void Interpreter::Instruction0xDxyn(const int& pInstruction)
	{

	}

	void Interpreter::Instructions0xExxx(const int& pInstruction)
	{

	}

	void Interpreter::Instructions0xFxxx(const int& pInstruction)
	{

	}

#pragma endregion Instructions Functions
}