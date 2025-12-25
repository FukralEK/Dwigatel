#pragma once
#include "ISubSystem.h"
#include <GLFW/glfw3.h>

class GLFWSubSystem : public ISubSystem
{
public:
	void init() override;
	void update() override;
	void close() override;
	
	void getConfig(SubSystemConfig* config) override;
	void setConfig(SubSystemConfig config) override;

	void apply() override;

	bool shouldClose() override;

	dwiVec::Vec2 getCursor() override;
	bool getKeyState(KeyboardKey key) override;

	bool getMouseClick(MouseButton button) override;
private:
	int toGlfwKey(KeyboardKey key);

	GLFWwindow* window = nullptr;

	SubSystemConfig config;
};