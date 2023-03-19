#pragma once

#include <vector>

namespace Utils
{
	typedef void (*Instruction)(const int&); //Instruction function signature : C++ bullshit

	constexpr char programOffset = 0x200;

	struct InterpreterState
	{
		unsigned char soundTimer = 0;
		unsigned char delayTimer = 0;

		unsigned char framebuffer[256];

		unsigned char registers[16];

		unsigned char memory[4096];

		unsigned char stackPointer;

		unsigned char stack[64];

		unsigned int indexRegister;

		unsigned int programCounter = programOffset;
	};

	struct ProgramDesc
	{
		std::vector<char> programBytes;
		size_t size = 0;
	};

	ProgramDesc OpenProgram(const char* pFilePath);
}