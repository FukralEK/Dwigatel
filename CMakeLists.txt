cmake_minimum_required(VERSION 3.16)
project(Dwigatel CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glad)

add_subdirectory(Engine)
add_subdirectory(FlappyJew)