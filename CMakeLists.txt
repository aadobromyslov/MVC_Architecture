cmake_minimum_required(VERSION 3.12)

project(TextBasedGame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB TextBasedGame_SRC CONFIGURE_DEPENDS "src/*.cpp")
add_executable(TextBasedGame main.cpp ${TextBasedGame_SRC})

install(TARGETS TextBasedGame DESTINATION bin)
