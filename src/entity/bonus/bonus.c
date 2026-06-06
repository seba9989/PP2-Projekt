#include "bonus.h"
#include "../ball/ball.h"
#include "../paddle/paddle.h"

#define MAX_BONUSES 10          ///< Maksymalna liczba bonusów na ekranie
#define WIDE_PADDLE_DURATION 10.0f ///< Czas trwania bonusu szerokiej paletki (sekundy)

/**
 * @brief Struktura wewnętrzna reprezentująca pojedynczy bonus na ekranie.
 */
typedef struct {
  Vector2 position; ///< Aktualna pozycja bonusu
  BonusType type;   ///< Typ bonusu
  bool active;      ///< Czy bonus jest aktywny
} Bonus;

static Bonus bonuses[MAX_BONUSES] = { 0 };
static float widePaddleTimer = 0.0f;
static float originalPaddleWidth = 100.0f;

static Texture2D texMultiball;
static Texture2D texWide;

/**
 * @brief Ładuje tekstury bonusów i czyści tablicę bonusów.
 */
void BonusesInit(void) {
  if (texMultiball.id == 0)
    texMultiball = LoadTexture("assets/bonus_multiball.png");
  if (texWide.id == 0) texWide = LoadTexture("assets/bonus_wide.png");

  for (int i = 0; i < MAX_BONUSES; i++) bonuses[i].active = false;
}

/**
 * @brief Deaktywuje wszystkie bonusy na ekranie.
 */
void BonusesClear(void) {
  for (int i = 0; i < MAX_BONUSES; i++) bonuses[i].active = false;
}

/**
 * @brief Tworzy nowy bonus w podanej pozycji.
 * @param x Współrzędna X.
 * @param y Współrzędna Y.
 * @param type Typ bonusu.
 */
void BonusSpawn(float x, float y, BonusType type) {
  for (int i = 0; i < MAX_BONUSES; i++) {
    if (!bonuses[i].active) {
      bonuses[i].position = (Vector2){ x, y };
      bonuses[i].type = type;
      bonuses[i].active = true;
      break;
    }
  }
}

/**
 * @brief Aktualizuje pozycje bonusów (spadanie) i sprawdza kolizję z paletką.
 *        Po zebraniu aktywuje odpowiedni efekt (multi-piłka lub szeroka paletka).
 * @param paddleRect Prostokąt paletki.
 */
void BonusesUpdate(Rectangle paddleRect) {
  if (widePaddleTimer > 0) {
    widePaddleTimer -= GetFrameTime();
    if (widePaddleTimer <= 0) {
      PaddleSetWidth(originalPaddleWidth);
    }
  }

  for (int i = 0; i < MAX_BONUSES; i++) {
    if (!bonuses[i].active) continue;

    bonuses[i].position.y += 3.0f;
    Rectangle bonusRect = { bonuses[i].position.x, bonuses[i].position.y, 30,
                            15 };

    if (CheckCollisionRecs(bonusRect, paddleRect)) {
      bonuses[i].active = false;

      if (bonuses[i].type == BONUS_MULTIBALL) {
        Vector2 spawnPos = { paddleRect.x + paddleRect.width / 2.0f,
                             paddleRect.y - 20.0f };
        BallSpawn(&spawnPos);
        BallSpawn(&spawnPos);
      } else if (bonuses[i].type == BONUS_WIDE_PADDLE) {
        if (widePaddleTimer <= 0) originalPaddleWidth = paddleRect.width;
        PaddleSetWidth(originalPaddleWidth * 1.5f);
        widePaddleTimer = WIDE_PADDLE_DURATION;
      }
    }

    if (bonuses[i].position.y > GetScreenHeight()) bonuses[i].active = false;
  }
}

/**
 * @brief Rysuje wszystkie aktywne bonusy oraz wskaźnik czasu trwania szerokiej paletki.
 */
void BonusesDraw(void) {
  for (int i = 0; i < MAX_BONUSES; i++) {
    if (!bonuses[i].active) continue;

    Texture2D tex =
        (bonuses[i].type == BONUS_MULTIBALL) ? texMultiball : texWide;

    if (tex.id != 0) {
      Rectangle source = { 0.0f, 0.0f, (float)tex.width, (float)tex.height };
      Rectangle dest = { bonuses[i].position.x, bonuses[i].position.y, 30.0f,
                         15.0f };
      DrawTexturePro(tex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE);
    } else {
      Color col = (bonuses[i].type == BONUS_MULTIBALL) ? GREEN : BLUE;
      const char* text = (bonuses[i].type == BONUS_MULTIBALL) ? "M" : "W";
      DrawRectangle(bonuses[i].position.x, bonuses[i].position.y, 30, 15, col);
      DrawText(text, bonuses[i].position.x + 10, bonuses[i].position.y + 2, 12,
               WHITE);
    }
  }

  if (widePaddleTimer > 0) {
    DrawRectangle(GetScreenWidth() - 110, 60, (int)(widePaddleTimer * 10), 10,
                  BLUE);
    DrawText("WIDE", GetScreenWidth() - 110, 45, 10, BLUE);
  }
}

/**
 * @brief Zwalnia tekstury bonusów.
 */
void BonusesCleanup(void) {
  UnloadTexture(texMultiball);
  UnloadTexture(texWide);
}
