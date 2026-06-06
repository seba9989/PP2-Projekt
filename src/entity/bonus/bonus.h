/**
 * @file bonus.h
 * @brief System bonusów – spawn, zbieranie, efekty (multi-piłka, szeroka paletka).
 */
#pragma once
#include "raylib.h"
#include <stdbool.h>

/**
 * @brief Typy bonusów dostępnych w grze.
 */
typedef enum {
  BONUS_MULTIBALL,   ///< Dodaje dwie dodatkowe piłki
  BONUS_WIDE_PADDLE  ///< Zwiększa paletkę o 50% na 10 sekund
} BonusType;

/**
 * @brief Ładuje tekstury bonusów i czyści tablicę.
 */
void BonusesInit(void);

/**
 * @brief Deaktywuje wszystkie bonusy na ekranie i resetuje timery.
 */
void BonusesClear(void);

/**
 * @brief Tworzy nowy bonus spadający z podanej pozycji.
 */
void BonusSpawn(float x, float y, BonusType type);

/**
 * @brief Aktualizuje pozycje bonusów i sprawdza kolizję z paletką.
 */
void BonusesUpdate(Rectangle paddleRect);

/**
 * @brief Rysuje wszystkie aktywne bonusy oraz timer szerokiej paletki.
 */
void BonusesDraw(void);

/**
 * @brief Zwalnia tekstury bonusów.
 */
void BonusesCleanup(void);
