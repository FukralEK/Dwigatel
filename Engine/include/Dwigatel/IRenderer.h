#pragma once
#include "ISubSystem.h"

struct RendererConfig
{
	int width = 1280;
	int height = 720;
	bool nearest = true;
};


class IRenderer
{
public:
	virtual void init(ISubSystem* subSystem) = 0;
	virtual void draw() = 0;
	virtual void close() = 0;

	virtual void getConfig(RendererConfig* config) = 0;
	virtual void setConfig(RendererConfig config) = 0;

	virtual void apply() = 0;
};