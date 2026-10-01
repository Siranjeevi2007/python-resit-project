# Runner — Session 4 (Raylib graphics)

A red player on the ground jumps over grey obstacles scrolling from the right.
1024×576 window, 60 fps, 3 lives, GAME OVER after 3 collisions.

![Runner](screenshot.png)

## Controls

| Key   | Action          |
|-------|-----------------|
| Space | Jump            |
| Esc   | Quit the window |

## Build and run

Raylib 5.5 is downloaded by CMake (`FetchContent`) the first time you configure.
That step needs Internet access and takes about a minute.

```bash
cmake -S . -B build
cmake --build build
./build/runner          # Windows: build\Debug\runner.exe (or build\runner.exe)
```

On Linux, Raylib needs the X11/OpenGL headers:

```bash
sudo apt install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev
```

## Structure

| File                   | Role                                                                                              | Lab steps      |
|------------------------|---------------------------------------------------------------------------------------------------|----------------|
| `CMakeLists.txt`       | FetchContent block for Raylib 5.5, `runner` target linked to `raylib`                             | A2, A3         |
| `Board.h` / `Board.cpp`   | Window constants, `Position` in floats, pixel constants, `displayState` / `displayGameOver` (rendering) | B1, C1–C4      |
| `Player.h` / `Player.cpp` | `handleInput` (`IsKeyPressed(KEY_SPACE)`), `updateJump` (gravity + landing), `checkCollision`  | D1, D2, D5     |
| `main.cpp`             | Raylib loop, obstacle scrolling (px/s), spawning every 1.5 s, collisions, score, lives            | B2, C5, D3, D4 |

Score: +1 for every obstacle that leaves the screen without hitting the player.
