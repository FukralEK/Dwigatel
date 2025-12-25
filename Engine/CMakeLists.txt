add_library(dwigatel
    src/Engine.cpp
    src/GLFWSubSystem.cpp
    src/dwiEvent.cpp
    src/OpenGLRenderer.cpp
)

target_include_directories(dwigatel PUBLIC include)
target_link_libraries(dwigatel PRIVATE glfw glad)