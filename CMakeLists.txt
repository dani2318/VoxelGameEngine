cmake_minimum_required(VERSION 3.10)
project(VoxelGameEngine)

set(CMP0072 NEW)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

find_package(OpenGL REQUIRED)


FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG master
)

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG v2.0.8
)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

FetchContent_MakeAvailable(glm glad glfw)

file(GLOB SOURCES
    src/*.h
    src/*.cpp
)

add_executable(VoxelGameEngine ${SOURCES})


target_link_libraries(VoxelGameEngine glfw glm glad OpenGL::GL)

