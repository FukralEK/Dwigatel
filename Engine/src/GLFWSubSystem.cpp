#include "Dwigatel/GLFWSubSystem.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <stdio.h>


void GLFWSubSystem::init()
{
	if (glfwInit() == GLFW_FALSE)
	{
		throw std::runtime_error("GLFW was not initialized");
	}

	glfwWindowHint(GLFW_RESIZABLE, config.resizable);


	window = glfwCreateWindow(config.width, config.height, config.windowTitle.c_str(), config.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
	if (window == nullptr)
	{
		throw std::runtime_error("Window was not created");
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(config.vsync ? 1 : 0);

	
}

void GLFWSubSystem::update()
{
	glfwPollEvents();

	glfwSwapBuffers(window);
}

void GLFWSubSystem::close()
{
	glfwDestroyWindow(window);

	glfwTerminate();
}

bool GLFWSubSystem::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void GLFWSubSystem::getConfig(SubSystemConfig* config)
{
	*config = this->config;
}
void GLFWSubSystem::setConfig(SubSystemConfig config)
{
	this->config = config;
}

void GLFWSubSystem::apply()
{

}

dwiVec::Vec2 GLFWSubSystem::getCursor()
{
	dwiVec::Vec2 position;
	
	glfwGetCursorPos(window, &position.x, &position.y);

	position.x -= config.width * 0.5;
	position.y -= config.height * 0.5;

	position.x /= (double)config.height * 0.5;
	position.y /= (double)config.height * 0.5;

	position.y *= -1.0;


	return position;
}

bool GLFWSubSystem::getMouseClick(MouseButton button)
{
	int buttonID = 0;
	switch (button)
	{
	case LEFT:
		buttonID = GLFW_MOUSE_BUTTON_LEFT;
		break;
	case RIGHT:
		buttonID = GLFW_MOUSE_BUTTON_RIGHT;
		break;
	case MIDDLE:
		buttonID = GLFW_MOUSE_BUTTON_MIDDLE;
		break;
	case BACK:
		buttonID = GLFW_MOUSE_BUTTON_4;
		break;
	case FORWARD:
		buttonID = GLFW_MOUSE_BUTTON_5;
		break;
	default:
		buttonID = -1;
	}
	int state = glfwGetMouseButton(window, buttonID);
	if (state == GLFW_PRESS)
	{
		return true;
	}
	else return false;
}