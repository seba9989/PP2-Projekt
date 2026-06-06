/**
 * @file audio.h
 * @brief System dźwiękowy gry – inicjalizacja, odtwarzanie i czyszczenie.
 */
#pragma once
#include "raylib.h"

/**
 * @brief Typy dźwięków używanych w grze.
 */
typedef enum {
  SOUND_HIT_PADDLE,  ///< Odbicie piłki od paletki
  SOUND_HIT_WALL,    ///< Odbicie piłki od ściany
  SOUND_BREAK_BRICK, ///< Zniszczenie cegły
  SOUND_LOSE_LIFE,   ///< Utrata życia
  SOUND_GAME_OVER,   ///< Koniec gry
  SOUND_WIN          ///< Wygrana
} GameSound;

/**
 * @brief Inicjalizuje urządzenie audio i ładuje wszystkie dźwięki z plików WAV.
 */
void AudioInit(void);

/**
 * @brief Odtwarza wybrany dźwięk.
 * @param sound Typ dźwięku do odtworzenia (zob. GameSound).
 */
void AudioPlay(GameSound sound);

/**
 * @brief Zwalnia załadowane dźwięki i zamyka urządzenie audio.
 */
void AudioCleanup(void);
