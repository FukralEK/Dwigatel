#pragma once

#ifndef WIN_MAIN
#define STD_MAIN
#endif

#ifdef DWIGATEL_MAIN_INCLUDE
#include "Dwigatel/dwiLog.h"
#include <stdexcept>
#include <Dwigatel/Engine.h>

#ifdef STD_MAIN
int main(int argc, char** argv)
{
#endif
#ifdef WIN_MAIN
#endif
	try
	{
		DWIGATEL_GAME_CLASS game;
		Engine engine;

		engine.run(&game);
	}
	catch (std::runtime_error e)
	{
		std::printf("ERROR: %s\n", e.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

#endif
#undef DWIGATEL_MAIN_INCLUDE