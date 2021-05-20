cmake_minimum_required(VERSION 3.10)
project(coloracao_mapas)
set (CMAKE_CXX_STANDARD 11)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # export compile_commmands.json
file(GLOB SOURCES "src/*.cpp")

add_executable(color_map ${SOURCES})
target_link_libraries(color_map GL glut GLU)
