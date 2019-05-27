#include <iostream>

#include <Windows.h>

#include "nora.hpp"

int main(int, char**)
{
	Nora::Mge::Application app(800, 600, "Mouse Trap");
	app.run();
	return 0;
}