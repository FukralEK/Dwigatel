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
	A, B, C, D, E, F, G, H, I, J, K, L, M,
	N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

	Digit0, Digit1, Digit2, Digit3, Digit4,
	Digit5, Digit6, Digit7, Digit8, Digit9,

	Escape,
	Enter,
	Tab,
	Space,
	Backspace,

	LeftShift,
	RightShift,
	LeftControl,
	RightControl,
	LeftAlt,
	RightAlt,
	LeftMeta,
	RightMeta,
	CapsLock,
	Fn,

	F1, F2, F3, F4, F5, F6,
	F7, F8, F9, F10, F11, F12,
	F13, F14, F15,

	ArrowUp,
	ArrowDown,
	ArrowLeft,
	ArrowRight,

	Insert,
	Delete,
	Home,
	End,
	PageUp,
	PageDown,

	Grave,
	Minus,
	Equals,
	LeftBracket,
	RightBracket,
	Backslash,
	Semicolon,
	Quote,
	Comma,
	Period,
	Slash,

	NumLock,
	Numpad0,
	Numpad1,
	Numpad2,
	Numpad3,
	Numpad4,
	Numpad5,
	Numpad6,
	Numpad7,
	Numpad8,
	Numpad9,
	NumpadAdd,
	NumpadSubtract,
	NumpadMultiply,
	NumpadDivide,
	NumpadDecimal,
	NumpadEnter,

	PrintScreen,
	ScrollLock,
	Pause,
	ContextMenu,

	VolumeUp,
	VolumeDown,
	Mute,
	MediaPlay,
	MediaPause,
	MediaStop,
	MediaNext,
	MediaPrevious

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
	virtual bool getKeyState(KeyboardKey key) = 0;

public:
	virtual bool shouldClose() = 0;
};