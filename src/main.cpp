#include <iostream>

#include "Core/App.hpp"

int main(const int argc, const char* argv[])
{
	Core::App app;

	app.Init();

	app.Run();

	app.Release();
	
	return 0;
}