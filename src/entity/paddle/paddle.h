/**
 * @file paddle.h
 * @brief System paletki gracza – sterowanie, hitbox, wygląd.
 */
#pragma once
#include "raylib.h"

/**
 * @brief Konfiguracja paletki (rozmiar, prędkość, kolor).
 */
typedef struct PaddleConfig {
  Vector2 size; ///< Wymiary paletki (szerokość, wysokość)
  float speed;  ///< Prędkość poruszania się (w pikselach na klatkę)
  Color color;  ///< Kolor paletki
} PaddleConfig;

/**
 * @brief Inicjalizuje paletkę z domyślnymi wartościami.
 */
void PaddleInit(void);

/**
 * @brief Ustawia nową konfigurację paletki.
 * @param config Nowe ustawienia (rozmiar, prędkość, kolor).
 */
void PaddleSetConfig(PaddleConfig config);

/**
 * @brief Aktualizuje pozycję paletki na podstawie wejścia z klawiatury.
 */
void PaddleUpdate(void);

/**
 * @brief Rysuje paletkę na ekranie.
 */
void PaddleDraw(void);

/**
 * @brief Zmienia szerokość paletki (używane przez bonus szerokiej paletki).
 * @param width Nowa szerokość.
 */
void PaddleSetWidth(float width);

/**
 * @brief Zwalnia teksturę paletki.
 */
void PaddleCleanup(void);

/**
 * @brief Zwraca prostokąt hitboxu paletki.
 * @return Rectangle pozycji i rozmiaru paletki.
 */
Rectangle PaddleGetRect(void);
