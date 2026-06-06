/**
 * @file brick.h
 * @brief System cegieł – siatka, kolory, animacja niszczenia.
 */
#pragma once
#include "raylib.h"
#include <stdbool.h>

#define BRICK_ROWS 5        ///< Liczba rzędów cegieł
#define BRICK_COLUMNS 10    ///< Liczba kolumn cegieł
#define MAX_BRICKS (BRICK_ROWS * BRICK_COLUMNS) ///< Całkowita liczba cegieł (50)

/**
 * @brief Pojedyncza cegła na planszy.
 */
typedef struct Brick {
  Rectangle rect;   ///< Prostokąt pozycji i rozmiaru cegły
  Color color;      ///< Kolor cegły (zależny od rzędu)
  bool active;      ///< Czy cegła jest aktywna
  bool isDying;     ///< Czy cegła jest w trakcie animacji niszczenia
  int alpha;        ///< Przezroczystość (255 = widoczna, 0 = niewidoczna)
} Brick;

/**
 * @brief Inicjalizuje siatkę cegieł 5x10 na górze ekranu.
 */
void BricksInit(void);

/**
 * @brief Aktualizuje animację niszczenia cegieł (fade-out, przesunięcie, skalowanie).
 */
void BricksUpdate(void);

/**
 * @brief Rysuje wszystkie aktywne cegły.
 */
void BricksDraw(void);

/**
 * @brief Zwalnia teksturę cegieł.
 */
void BricksCleanup(void);

/**
 * @brief Sprawdza, czy wszystkie cegły zostały zniszczone (warunek wygranej).
 * @return true jeśli żadna cegła nie jest aktywna, false w przeciwnym razie.
 */
bool BricksAreAllDestroyed(void);

/**
 * @brief Zwraca wskaźnik do tablicy wszystkich cegieł.
 * @return Wskaźnik do statycznej tablicy Brick[MAX_BRICKS].
 */
Brick* BricksGetAll(void);

/**
 * @brief Zwraca całkowitą liczbę cegieł.
 * @return MAX_BRICKS (50).
 */
int BricksGetCount(void);
