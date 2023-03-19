#include "Utils.hpp"

#include <fstream>

namespace Utils
{
	ProgramDesc OpenProgram(const char* pFilePath)
	{
		std::ifstream programFile;

		programFile.open(pFilePath, std::ifstream::binary | std::ifstream::ate);

		if (!programFile.is_open())
		{
			//TODO : Error Handeling
			return ProgramDesc();
		}

		size_t fileSize = programFile.tellg();

		programFile.seekg(std::ifstream::beg);

		std::vector<char> buffer(fileSize);

		programFile.read(buffer.data(), fileSize);
		
		programFile.close();

		return ProgramDesc{ buffer, fileSize };
	}
}