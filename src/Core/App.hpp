#pragma once

#include "Interpreter.hpp"

#include "../Renderer/IRenderer.hpp"

namespace Core
{
	class App
	{
	public:
		App();
		~App();

		void Init();
		void Release();

		void Run();
	
	private:
		Renderer::IRenderer* mRenderer = nullptr;
		Interpreter mInterpreter;
	};
}