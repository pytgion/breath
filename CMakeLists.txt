cmake_minimum_required(VERSION 3.10)

project(breath)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

# Compiler flags
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Werror)
elseif (MSVC)
    add_compile_options(/W4 /WX)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Source files
file(GLOB SRC_FILES src/*.cpp src/*.h src/*.cc)

add_executable(breath ${SRC_FILES} src/glad.c)

find_package(assimp REQUIRED)
target_link_libraries(breath PRIVATE assimp)

find_package(glm CONFIG REQUIRED)
target_link_libraries(breath PRIVATE glm::glm)

set(IMGUI_DIR thirdparty/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC ${IMGUI_DIR})

target_link_libraries(breath PRIVATE OpenGL::GL imgui glfw dl)

include_directories(${OPENGL_INCLUDE_DIRS} src)

