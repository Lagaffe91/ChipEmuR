#include <iostream>

#include "Renderer/RaylibRenderer.hpp"

int main(const int argc, const char* argv[])
{
	Renderer::IRenderer* renderer = new Renderer::RaylibRenderer();

	renderer->Init(); 

	while (!renderer->RenderShouldStop()) // || interpreter.ShouldStop())
	{
		renderer->RenderInterpreterState();
	}

	renderer->Release();

	delete renderer;

	return 0;
}