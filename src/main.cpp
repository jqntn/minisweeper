#include <cstdlib>
#include <raylib.h>

constexpr int COLS_EASY = 9;
constexpr int ROWS_EASY = 9;
constexpr int COLS_MEDIUM = 16;
constexpr int ROWS_MEDIUM = 16;
constexpr int COLS_HARD = 30;
constexpr int ROWS_HARD = 16;

constexpr int TILE_W = 16;
constexpr int TILE_H = 16;

constexpr float REF_SCREEN_H = 1080;
constexpr int WINDOW_SCALE = 2;
constexpr const char* WINDOW_TITLE = "minisweeper";

int
main()
{
  int window_w = TILE_W * COLS_MEDIUM * WINDOW_SCALE;
  int window_h = TILE_H * ROWS_MEDIUM * WINDOW_SCALE;

  const char* p_window_title = WINDOW_TITLE;

  SetWindowState(FLAG_VSYNC_HINT);

  InitWindow(window_w, window_h, p_window_title);

  float window_scale = GetMonitorHeight(GetCurrentMonitor()) / REF_SCREEN_H;

  SetWindowSize(window_w * window_scale, window_h * window_scale);

  Image image = LoadImage("resources/images/tileset.png");
  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTextureEx(texture, Vector2{}, 0.0f, 5.0f, WHITE);

    EndDrawing();
  }

  CloseWindow();

  return EXIT_SUCCESS;
}