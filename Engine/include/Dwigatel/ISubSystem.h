#pragma once
#include "dwiVec.h"
#include <string>

enum MouseButton
{
	LEFT,
	RIGHT,
	MIDDLE,
	FORWARD,
	BACK,
	SCROLL_UP,
	SCROLL_DOWN
};

enum KeyboardKey
{

};

struct SubSystemConfig
{
	std::string name = "Dwigatel Game";
	std::string windowTitle = "Dwigatel Window";
	std::string platformName = "Default Platform";

	bool fullscreen = false;
	int width = 1280;
	int height = 720;
	bool resizable = false;
	bool vsync = true;
	int monitorIndex = 0;
};

class ISubSystem
{
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void close() = 0;

	virtual void getConfig(SubSystemConfig* config) = 0;
	virtual void setConfig(SubSystemConfig config) = 0;

	virtual void apply() = 0;

	virtual dwiVec::Vec2 getCursor() = 0;

	virtual bool getMouseClick(MouseButton button) = 0;
	virtual bool getKeyState(MouseButton button) = 0;

public:
	virtual bool shouldClose() = 0;
};