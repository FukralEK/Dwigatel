#pragma once
#include "IRenderer.h"
#include "ISubSystem.h"
#include "IGame.h"

class CoreSystems {
public:
    static CoreSystems& Get() {
        static CoreSystems instance;
        return instance;
    }

    IRenderer* renderer = nullptr;
    ISubSystem* subSystem = nullptr;
    IGame* game = nullptr;

private:
    CoreSystems() = default; 
};