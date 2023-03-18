#pragma once

namespace Core
{
	class Interpreter
	{
	public:
		Interpreter();
		~Interpreter();

		void SimulateCycle();

		bool ShouldStop();
	};
}