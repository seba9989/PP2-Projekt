/**
 * @file audio.c
 * @brief Implementacja systemu dźwiękowego.
 */
#include "audio.h"

static Sound sndHitPaddle;
static Sound sndHitWall;
static Sound sndBreakBrick;
static Sound sndLoseLife;
static Sound sndGameOver;
static Sound sndWin;

/**
 * @brief Inicjalizuje urządzenie audio i ładuje wszystkie 6 dźwięków WAV z katalogu assets/.
 */
void AudioInit(void) {
  InitAudioDevice();

  sndHitPaddle = LoadSound("assets/hit_paddle.wav");
  sndHitWall = LoadSound("assets/hit_wall.wav");
  sndBreakBrick = LoadSound("assets/break_brick.wav");
  sndLoseLife = LoadSound("assets/lose_life.wav");
  sndGameOver = LoadSound("assets/game_over.wav");
  sndWin = LoadSound("assets/win.wav");
}

/**
 * @brief Odtwarza dźwięk odpowiadający podanemu typowi.
 */
void AudioPlay(GameSound sound) {
  switch (sound) {
    case SOUND_HIT_PADDLE:
      PlaySound(sndHitPaddle);
      break;
    case SOUND_HIT_WALL:
      PlaySound(sndHitWall);
      break;
    case SOUND_BREAK_BRICK:
      PlaySound(sndBreakBrick);
      break;
    case SOUND_LOSE_LIFE:
      PlaySound(sndLoseLife);
      break;
    case SOUND_GAME_OVER:
      PlaySound(sndGameOver);
      break;
    case SOUND_WIN:
      PlaySound(sndWin);
      break;
  }
}

/**
 * @brief Zwalnia wszystkie załadowane dźwięki i zamyka urządzenie audio.
 */
void AudioCleanup(void) {
  UnloadSound(sndHitPaddle);
  UnloadSound(sndHitWall);
  UnloadSound(sndBreakBrick);
  UnloadSound(sndLoseLife);
  UnloadSound(sndGameOver);
  UnloadSound(sndWin);

  CloseAudioDevice();
}
