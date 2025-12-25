#pragma once
#include "IGame.h"

class Engine
{
public:
	void run(IGame* game);
private:
	int tickrate = 64;
};