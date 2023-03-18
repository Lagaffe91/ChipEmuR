#include <iostream>

#include <raylib/raylib.h>

int main(const int argc, const char* argv[])
{
	constexpr int windowWidth = 720;
	constexpr int windowHeight = 480;

	const char* windowTitle = "ChipEmuR";

	InitWindow(windowWidth, windowHeight, windowTitle);

	int _;

	std::cin >> _;

	CloseWindow();

	return 0;
}