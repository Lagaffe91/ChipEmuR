#include <iostream>

#include "Core/Interpreter.hpp"

#include "Renderer/RaylibRenderer.hpp"

int main(const int argc, const char* argv[])
{
	Renderer::IRenderer* renderer = new Renderer::RaylibRenderer();

	Core::Interpreter interpreter;

	renderer->Init(); 

	while (!renderer->RenderShouldStop() || interpreter.ShouldStop())
	{
		interpreter.SimulateCycle();
		renderer->RenderInterpreterState(interpreter.GetCurrentState());
	}

	renderer->Release();

	delete renderer;

	return 0;
}