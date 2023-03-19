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

		char instructionCode = instruction >> 12;

		this->instructionsFunctions[instructionCode](instruction, this->mState);

		//
		//Decrease timers
		//

		if(mState.delayTimer > 0)
			mState.delayTimer--;

		if (mState.soundTimer > 0)
			mState.soundTimer--;
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
	void Interpreter::Instructions0x0xxx(const int& pInstruction, Utils::InterpreterState& pState)
	{
		if ((pInstruction & 0x000F) >> 4 == 0x0 ) //CLS
		{
			memset(pState.framebuffer, 0, Utils::framebufferSize);

			pState.programCounter += Utils::instructionBytesSize;
		}
		else if ((pInstruction & 0x00F) >> 4 == 0xE)
		{
			//00EE - RET
			//Return from a subroutine.The interpreter sets the program counter to the address at the top of the stack,
			//then subtracts 1 from the stack pointer
		}
	}

	void Interpreter::Instruction0x1nnn(const int& pInstruction, Utils::InterpreterState& pState)
	{
		//JP
		pState.programCounter = pInstruction & 0x0FFF;
	}

	void Interpreter::Instruction0x2nnn(const int& pInstruction, Utils::InterpreterState& pState)
	{
		pState.stackPointer++;
		pState.stack[pState.stackPointer] = pState.programCounter;
		pState.programCounter = pInstruction & 0x0FFF;
	}

	void Interpreter::Instruction0x3xkk(const int& pInstruction, Utils::InterpreterState& pState)
	{
		//SE Vx, byte
		if (pState.registers[(pInstruction & 0x0F00) >> 8] == (pInstruction & 0x00FF))
			pState.programCounter += Utils::instructionBytesSize;
		pState.programCounter += Utils::instructionBytesSize;
	}

	void Interpreter::Instruction0x4xkk(const int& pInstruction, Utils::InterpreterState& pState)
	{
		//SNE Vx, byte
		if (pState.registers[(pInstruction & 0x0F00) >> 8] != (pInstruction & 0x00FF))
			pState.programCounter += Utils::instructionBytesSize;
		pState.programCounter += Utils::instructionBytesSize;
	}

	void Interpreter::Instruction0x5xy0(const int& pInstruction, Utils::InterpreterState& pState)
	{
		//SE Vx, Vy
		if (pState.registers[(pInstruction & 0x0F00) >> 8] == pState.registers[(pInstruction & 0x00F0) >> 4])
			pState.programCounter += Utils::instructionBytesSize;
		pState.programCounter += Utils::instructionBytesSize;
	}

	void Interpreter::Instructions0x6xkk(const int& pInstruction, Utils::InterpreterState& pState)
	{
		//LD Vx, byte
		pState.registers[(pInstruction & 0x0F00) >> 8] = (pInstruction & 0x00FF);
		pState.programCounter += Utils::instructionBytesSize;
	}

	void Interpreter::Instructions0x7xkk(const int& pInstruction, Utils::InterpreterState& pState)
	{
		//ADD
		pState.registers[(pInstruction & 0x0F00) >> 8] += (pInstruction & 0x00FF);
		pState.programCounter += Utils::instructionBytesSize;
	}

	void Interpreter::Instructions0x8xxx(const int& pInstruction, Utils::InterpreterState& pState)
	{
		char subInstruction = pInstruction & 0x000F;

		if (subInstruction == 0)
		{
			//LD Vx, Vy
			pState.registers[(pInstruction & 0x0F00) >> 8] = pState.registers[(pInstruction & 0x00F0) >> 4];
		}else if(subInstruction == 1)
		{ 
			//OR
			pState.registers[(pInstruction & 0x0F00) >> 8] = pState.registers[(pInstruction & 0x0F00) >> 8] | pState.registers[(pInstruction & 0x00F0) >> 4];
		}
		else if (subInstruction == 2)
		{
			//AND
			pState.registers[(pInstruction & 0x0F00) >> 8] = pState.registers[(pInstruction & 0x0F00) >> 8] & pState.registers[(pInstruction & 0x00F0) >> 4];
		}
		else if (subInstruction == 3)
		{
			//XOR
			pState.registers[(pInstruction & 0x0F00) >> 8] = pState.registers[(pInstruction & 0x0F00) >> 8] ^ pState.registers[(pInstruction & 0x00F0) >> 4];
		}
		else if (subInstruction == 4)
		{
			//ADD - Carry flag Edition

		}else if(subInstruction == 5)
		{

		}
		else if (subInstruction == 6)
		{

		}
		else if (subInstruction == 7)
		{

		}
		else if (subInstruction == 0xE)
		{

		}

		pState.programCounter += Utils::instructionBytesSize;

		//TODO : Dont forget to implement until 0x800E !
	}

	void Interpreter::Instruction0x9xy0(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

	void Interpreter::Instruction0xAnnn(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

	void Interpreter::Instruction0xBnnn(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

	void Interpreter::Instruction0xCxkk(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

	void Interpreter::Instruction0xDxyn(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

	void Interpreter::Instructions0xExxx(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

	void Interpreter::Instructions0xFxxx(const int& pInstruction, Utils::InterpreterState& pState)
	{

	}

#pragma endregion Instructions Functions
}
