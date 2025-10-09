cmake_minimum_required(VERSION 4.0.2)
project(sorting_algorithms_visualization LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
include(FetchContent)

set(SFML_VERSION "3.0.2")
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG ${SFML_VERSION}
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

set(IMGUI_VERSION "v1.91.1")
FetchContent_Declare(ImGui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG ${IMGUI_VERSION}
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_VERSION "v3.0")
FetchContent_Declare(ImGui-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml
        GIT_TAG ${IMGUI_SFML_VERSION}
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(ImGui-SFML)
file(GLOB SOURCES "src/*.cpp" "src/*.h" "src/sorting_algorithms/*.cpp")

add_executable(sorting_algorithms_visualization ${SOURCES})

target_link_libraries(sorting_algorithms_visualization PRIVATE SFML::Graphics ImGui-SFML::ImGui-SFML)
