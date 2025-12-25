#include "Dwigatel/Engine.h"

#include "Dwigatel/OpenGLRenderer.h"

#include "Dwigatel/GLFWSubSystem.h"

#include <chrono>

#include <stdio.h>

#include "Dwigatel/CoreSystems.h"

void Engine::run(IGame* game)
{
	GLFWSubSystem glfw;
	OpenGLRenderer opengl;

	CoreSystems::Get().game = game;
	CoreSystems::Get().subSystem = &glfw;
	CoreSystems::Get().renderer = &opengl;

	SubSystemConfig subSystemConfig;

	subSystemConfig.fullscreen = false;

	CoreSystems::Get().subSystem->setConfig(subSystemConfig);

	CoreSystems::Get().subSystem->init();
	CoreSystems::Get().renderer->init(CoreSystems::Get().subSystem);
	game->init();

	double dt = 1.0/(double)tickrate;
	double frameTime = 0.0;
	double accumulator = 0.0;
	std::chrono::high_resolution_clock::time_point previous = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock::now();

	while (game->isRunning())
	{
		previous = current;
		current = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(current - previous);
		frameTime = time_span.count();
		accumulator += frameTime;
		
		while (accumulator >= dt)
		{
			game->fixedUpdate(dt);
			accumulator -= dt;
		}
		game->update(frameTime);
		CoreSystems::Get().subSystem->update();
		CoreSystems::Get().renderer->draw();

		if (CoreSystems::Get().subSystem->shouldClose() || CoreSystems::Get().subSystem->getKeyState(Escape))
		{
			game->tryToStop();
		}

	}

	game->close();
	CoreSystems::Get().subSystem->close();
	CoreSystems::Get().renderer->close();
}