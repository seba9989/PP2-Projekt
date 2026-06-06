/**
 * @file pause.c
 * @brief Implementacja menu pauzy.
 */
#include "raylib.h"
#include <stdio.h>

bool PAUSE = false;

/**
 * @brief Przełącza stan pauzy na SPACJA i rysuje napis "PAUSED" na środku ekranu.
 */
void PauseMenu(void) {
  if (IsKeyPressed(KEY_SPACE)) PAUSE = !PAUSE;

  if (PAUSE) DrawText("PAUSED", 350, 200, 30, GRAY);
}
