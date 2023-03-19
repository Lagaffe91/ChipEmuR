#pragma once

#include <vector>

namespace Utils
{
	constexpr unsigned char instructionBytesSize = 2;
	constexpr unsigned char programOffset	= 0x200;
	constexpr unsigned int	memorySize		= 4096;
	constexpr unsigned int	framebufferSize = 64 * 32 / 8; //256

	struct InterpreterState
	{
		unsigned char soundTimer = 0;
		unsigned char delayTimer = 0;

		unsigned char framebuffer[framebufferSize];

		unsigned char registers[16];

		unsigned char memory[memorySize];

		unsigned char stackPointer;

		unsigned char stack[64];

		unsigned int indexRegister;

		unsigned int programCounter = programOffset;
	};

	typedef void (*Instruction)(const int&, InterpreterState&); //Instruction function signature : C++ bullshit

	struct ProgramDesc
	{
		std::vector<char> programBytes;
		size_t size = 0;
	};

	ProgramDesc OpenProgram(const char* pFilePath);
}