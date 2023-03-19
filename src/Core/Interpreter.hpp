#pragma once

#include "Utils.hpp"

#include <unordered_map>

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

		std::unordered_map<char, Utils::Instruction> instructionsFunctions =
		{
			{0x0, &Interpreter::Instructions0x0xxx},
			{0x1, &Interpreter::Instruction0x1nnn},
			{0x2, &Interpreter::Instruction0x2nnn},
			{0x3, &Interpreter::Instruction0x3xkk},
			{0x4, &Interpreter::Instruction0x4xkk},
			{0x5, &Interpreter::Instruction0x5xy0},
			{0x6, &Interpreter::Instructions0x6xkk},
			{0x7, &Interpreter::Instructions0x7xkk},
			{0x8, &Interpreter::Instructions0x8xxx},
			{0x9, &Interpreter::Instruction0x9xy0},
			{0xA, &Interpreter::Instruction0xAnnn},
			{0xB, &Interpreter::Instruction0xBnnn},
			{0xC, &Interpreter::Instruction0xCxkk},
			{0xD, &Interpreter::Instruction0xDxyn},
			{0xE, &Interpreter::Instructions0xExxx},
			{0xF, &Interpreter::Instructions0xFxxx}
		};

#pragma region
	private :
		static void Instructions0x0xxx(const int &pInstruction, Utils::InterpreterState& pState); //Will Need more branching
		static void Instruction0x1nnn(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0x2nnn(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0x3xkk(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0x4xkk(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0x5xy0(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instructions0x6xkk(const int& pInstruction, Utils::InterpreterState& pState);
		static void Instructions0x7xkk(const int& pInstruction, Utils::InterpreterState& pState);
		static void Instructions0x8xxx(const int& pInstruction, Utils::InterpreterState& pState); //Will Need more branching
		static void Instruction0x9xy0(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0xAnnn(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0xBnnn(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0xCxkk(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instruction0xDxyn(const int& pInstruction,	Utils::InterpreterState& pState);
		static void Instructions0xExxx(const int& pInstruction, Utils::InterpreterState& pState); //Will Need more branching
		static void Instructions0xFxxx(const int& pInstruction, Utils::InterpreterState& pState); //Will Need more branching
#pragma endregion Instructions Functions
	};
}