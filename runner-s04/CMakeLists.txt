cmake_minimum_required(VERSION 3.16)
project(Runner LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Raylib 5.5, downloaded and built at configure time ---------------------
include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)  # we only need the library
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

# --- Our game ----------------------------------------------------------------
add_executable(runner
    main.cpp
    Board.cpp
    Player.cpp
)

target_link_libraries(runner PRIVATE raylib)
