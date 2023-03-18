#include <raylib/raylib.h>

#include "RaylibRenderer.hpp"

namespace Renderer
{
	RaylibRenderer::RaylibRenderer()
	{

	}

	RaylibRenderer::~RaylibRenderer()
	{

	}

	//
	//IRenderer implementation
	//

	void RaylibRenderer::Init()
	{
		constexpr int windowWidth = 720;
		constexpr int windowHeight = 480;

		const char* windowTitle = "ChipEmuR - romName";

		InitWindow(windowWidth, windowHeight, windowTitle);
	}

	void RaylibRenderer::Release()
	{
		CloseWindow();
	}

	void RaylibRenderer::RenderInterpreterState()
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		EndDrawing();
	}

	bool RaylibRenderer::RenderShouldStop()
	{
		return WindowShouldClose() || IsKeyDown(KEY_ESCAPE);
	}
}