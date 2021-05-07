cmake_minimum_required(VERSION 3.10)
project(coloracao_mapas)
set (CMAKE_CXX_STANDARD 11)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

set (CMAKE_CXX_FLAGS "-lGL -lglut -lGLU") # libs opengl to linker
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # export compile_commmands.json
file(GLOB SOURCES "src/*.cpp")

add_executable(color_map ${SOURCES})
