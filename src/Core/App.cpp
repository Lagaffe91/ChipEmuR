#include "App.hpp"

#include "../Renderer/RaylibRenderer.hpp"

namespace Core
{
	App::App()
	{
	}

	App::~App()
	{
	}

	void App::Init()
	{
		mRenderer = new Renderer::RaylibRenderer();
		mRenderer->Init();

		//TODO : Remove hardcoded path (arguments handeling).
		mInterpreter.LoadProgram(Utils::OpenProgram("D:\\dev\\chip8-roms\\programs\\Random Number Test.ch8"));
	}

	void App::Release()
	{
		mRenderer->Release();
		delete mRenderer;
	}

	void App::Run()
	{
		if (mRenderer == nullptr)
		{
			//TODO : Error message : app not initialisated
			return;
		}

		//Main loop
		while (!mRenderer->RenderShouldStop() || mInterpreter.ShouldStop())
		{
			mInterpreter.SimulateCycle();
			mRenderer->RenderInterpreterState(mInterpreter.GetCurrentState());
		}
	}
}