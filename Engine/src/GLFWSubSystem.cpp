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

int GLFWSubSystem::toGlfwKey(KeyboardKey key)
{
    switch (key)
    {
    case KeyboardKey::A: return GLFW_KEY_A;
    case KeyboardKey::B: return GLFW_KEY_B;
    case KeyboardKey::C: return GLFW_KEY_C;
    case KeyboardKey::D: return GLFW_KEY_D;
    case KeyboardKey::E: return GLFW_KEY_E;
    case KeyboardKey::F: return GLFW_KEY_F;
    case KeyboardKey::G: return GLFW_KEY_G;
    case KeyboardKey::H: return GLFW_KEY_H;
    case KeyboardKey::I: return GLFW_KEY_I;
    case KeyboardKey::J: return GLFW_KEY_J;
    case KeyboardKey::K: return GLFW_KEY_K;
    case KeyboardKey::L: return GLFW_KEY_L;
    case KeyboardKey::M: return GLFW_KEY_M;
    case KeyboardKey::N: return GLFW_KEY_N;
    case KeyboardKey::O: return GLFW_KEY_O;
    case KeyboardKey::P: return GLFW_KEY_P;
    case KeyboardKey::Q: return GLFW_KEY_Q;
    case KeyboardKey::R: return GLFW_KEY_R;
    case KeyboardKey::S: return GLFW_KEY_S;
    case KeyboardKey::T: return GLFW_KEY_T;
    case KeyboardKey::U: return GLFW_KEY_U;
    case KeyboardKey::V: return GLFW_KEY_V;
    case KeyboardKey::W: return GLFW_KEY_W;
    case KeyboardKey::X: return GLFW_KEY_X;
    case KeyboardKey::Y: return GLFW_KEY_Y;
    case KeyboardKey::Z: return GLFW_KEY_Z;

    case KeyboardKey::Digit0: return GLFW_KEY_0;
    case KeyboardKey::Digit1: return GLFW_KEY_1;
    case KeyboardKey::Digit2: return GLFW_KEY_2;
    case KeyboardKey::Digit3: return GLFW_KEY_3;
    case KeyboardKey::Digit4: return GLFW_KEY_4;
    case KeyboardKey::Digit5: return GLFW_KEY_5;
    case KeyboardKey::Digit6: return GLFW_KEY_6;
    case KeyboardKey::Digit7: return GLFW_KEY_7;
    case KeyboardKey::Digit8: return GLFW_KEY_8;
    case KeyboardKey::Digit9: return GLFW_KEY_9;

    case KeyboardKey::Escape: return GLFW_KEY_ESCAPE;
    case KeyboardKey::Enter: return GLFW_KEY_ENTER;
    case KeyboardKey::Tab: return GLFW_KEY_TAB;
    case KeyboardKey::Space: return GLFW_KEY_SPACE;
    case KeyboardKey::Backspace: return GLFW_KEY_BACKSPACE;

    case KeyboardKey::LeftShift: return GLFW_KEY_LEFT_SHIFT;
    case KeyboardKey::RightShift: return GLFW_KEY_RIGHT_SHIFT;
    case KeyboardKey::LeftControl: return GLFW_KEY_LEFT_CONTROL;
    case KeyboardKey::RightControl: return GLFW_KEY_RIGHT_CONTROL;
    case KeyboardKey::LeftAlt: return GLFW_KEY_LEFT_ALT;
    case KeyboardKey::RightAlt: return GLFW_KEY_RIGHT_ALT;
    case KeyboardKey::LeftMeta: return GLFW_KEY_LEFT_SUPER;
    case KeyboardKey::RightMeta: return GLFW_KEY_RIGHT_SUPER;

    case KeyboardKey::F1: return GLFW_KEY_F1;
    case KeyboardKey::F2: return GLFW_KEY_F2;
    case KeyboardKey::F3: return GLFW_KEY_F3;
    case KeyboardKey::F4: return GLFW_KEY_F4;
    case KeyboardKey::F5: return GLFW_KEY_F5;
    case KeyboardKey::F6: return GLFW_KEY_F6;
    case KeyboardKey::F7: return GLFW_KEY_F7;
    case KeyboardKey::F8: return GLFW_KEY_F8;
    case KeyboardKey::F9: return GLFW_KEY_F9;
    case KeyboardKey::F10: return GLFW_KEY_F10;
    case KeyboardKey::F11: return GLFW_KEY_F11;
    case KeyboardKey::F12: return GLFW_KEY_F12;

    case KeyboardKey::ArrowUp: return GLFW_KEY_UP;
    case KeyboardKey::ArrowDown: return GLFW_KEY_DOWN;
    case KeyboardKey::ArrowLeft: return GLFW_KEY_LEFT;
    case KeyboardKey::ArrowRight: return GLFW_KEY_RIGHT;

    case KeyboardKey::Insert: return GLFW_KEY_INSERT;
    case KeyboardKey::Delete: return GLFW_KEY_DELETE;
    case KeyboardKey::Home: return GLFW_KEY_HOME;
    case KeyboardKey::End: return GLFW_KEY_END;
    case KeyboardKey::PageUp: return GLFW_KEY_PAGE_UP;
    case KeyboardKey::PageDown: return GLFW_KEY_PAGE_DOWN;

    case KeyboardKey::Grave: return GLFW_KEY_GRAVE_ACCENT;
    case KeyboardKey::Minus: return GLFW_KEY_MINUS;
    case KeyboardKey::Equals: return GLFW_KEY_EQUAL;
    case KeyboardKey::LeftBracket: return GLFW_KEY_LEFT_BRACKET;
    case KeyboardKey::RightBracket: return GLFW_KEY_RIGHT_BRACKET;
    case KeyboardKey::Backslash: return GLFW_KEY_BACKSLASH;
    case KeyboardKey::Semicolon: return GLFW_KEY_SEMICOLON;
    case KeyboardKey::Quote: return GLFW_KEY_APOSTROPHE;
    case KeyboardKey::Comma: return GLFW_KEY_COMMA;
    case KeyboardKey::Period: return GLFW_KEY_PERIOD;
    case KeyboardKey::Slash: return GLFW_KEY_SLASH;
    }
    return GLFW_KEY_UNKNOWN;
}

bool GLFWSubSystem::getKeyState(KeyboardKey key)
{
    int glfwKey = toGlfwKey(key);
    if (glfwKey == GLFW_KEY_UNKNOWN)
        return false;

    int state = glfwGetKey(window, glfwKey);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}