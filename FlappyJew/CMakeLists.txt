
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(FlappyJew ${MY_SOURCES})
target_link_libraries(FlappyJew PRIVATE dwigatel)