#pragma once
#include <Dwigatel/IGame.h>

class FlappyJew : public IGame
{
public:
	void init() override;
	void update(double dt) override;
	void fixedUpdate(double dt) override;
	void close() override;
	
	void tryToStop() override;
	bool isRunning() override;
private:
	bool running = true;
};