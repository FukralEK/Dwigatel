#pragma once

class IGame
{
public:
	virtual void init() = 0;
	virtual void update(double dt) = 0;
	virtual void fixedUpdate(double dt) = 0;
	virtual void close() = 0;
	virtual void tryToStop() = 0;
	virtual bool isRunning() = 0;
};