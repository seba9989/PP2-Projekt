/**
 * @file ball.h
 * @brief System piłek – zarządzanie, fizyka odbić, kolizje z cegłami.
 */
#pragma once
#include "raylib.h"
#include <stddef.h>

#define MAX_BALLS 32 ///< Maksymalna liczba piłek na ekranie

/**
 * @brief Pojedyncza piłka.
 */
typedef struct {
  Vector2 position; ///< Aktualna pozycja piłki
  Vector2 speed;    ///< Prędkość (wektor)
  int radius;       ///< Promień piłki
  Color color;      ///< Kolor piłki
  bool active;      ///< Czy piłka jest aktywna
} Ball;

/**
 * @brief Opcjonalna konfiguracja nadpisująca domyślne wartości piłki.
 *        Pola z wartością NULL pozostawiają wartości domyślne.
 */
typedef struct {
  Vector2* position; ///< Pozycja startowa (lub NULL)
  Vector2* speed;    ///< Prędkość (lub NULL)
  int* radius;       ///< Promień (lub NULL)
  Color* color;      ///< Kolor (lub NULL)
} BallConfig;

/**
 * @brief Domyślne wartości piłek.
 */
typedef struct {
  Vector2 speed; ///< Domyślna prędkość
  int radius;    ///< Domyślny promień
  Color color;   ///< Domyślny kolor
} BallDefaults;

/**
 * @brief Tworzy piłkę z domyślnymi ustawieniami.
 * @param position Pozycja startowa lub NULL – wtedy środek ekranu.
 */
void BallSpawn(Vector2* position);

/**
 * @brief Tworzy piłkę z konfiguracją. Pola NULL przyjmują wartości domyślne.
 * @param cfg Struktura konfiguracyjna z opcjonalnymi polami.
 */
void BallSpawnConfig(BallConfig config);

/**
 * @brief Usuwa ostatnie `count` piłek.
 * @param count Liczba piłek do usunięcia.
 */
void BallRemove(int count);

/**
 * @brief Ustawia wartości wszystkich aktywnych piłek oraz wartości domyślne.
 *        Zachowuje kierunek (znak) prędkości każdej piłki.
 * @param cfg Pola do zmiany – NULL pomija daną właściwość.
 */
void BallSetAll(BallConfig config);

/**
 * @brief Aktualizuje pozycje wszystkich aktywnych piłek i obsługuje odbicia.
 * @param paddleRect Wskaźnik na prostokąt paletki lub NULL (brak kolizji).
 */
void BallUpdateAll(Rectangle* paddleRect);

/**
 * @brief Rysuje wszystkie aktywne piłki.
 */
void BallDrawAll(void);

/**
 * @brief Zwraca aktualną liczbę piłek.
 * @param activeOnly Czy zliczać tylko aktywne piłki.
 * @return Liczba piłek.
 */
int BallGetCount(bool activeOnly);

/**
 * @brief Zwraca domyślne wartości piłek.
 * @return Struktura BallDefaults.
 */
BallDefaults BallGetDefaults(void);

/**
 * @brief Sprawdza kolizje wszystkich aktywnych piłek z cegłami.
 *        Niszczy trafione cegły i zwraca zdobyte punkty.
 * @return Liczba zdobytych punktów.
 */
int BallsCollideWithBricks(void);

/**
 * @brief Zwalnia teksturę piłki.
 */
void BallCleanup(void);
