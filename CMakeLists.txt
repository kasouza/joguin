cmake_minimum_required(VERSION 3.10)

project(JOGUIN VERSION 0.0.1)

find_package(fmt CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(joguin 
    joguin/Main.cpp
    joguin/engine/renderer/Renderer.cpp
    joguin/engine/renderer/RendererFactory.cpp
    joguin/engine/events/EventSystem.cpp
)
target_include_directories(joguin PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_features(joguin PRIVATE cxx_std_20)
target_link_libraries(joguin PRIVATE 
    fmt::fmt
    glad::glad
    glfw
)
