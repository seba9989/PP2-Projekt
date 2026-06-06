/**
 * @file pause.h
 * @brief Menu pauzy – wstrzymywanie i wznawianie gry.
 */
#ifndef PAUSE_H
#define PAUSE_H

#include <stdbool.h>

extern bool PAUSE; ///< Flaga pauzy (true = gra wstrzymana)

/**
 * @brief Przełącza stan pauzy po naciśnięciu SPACJA i rysuje napis "PAUSED".
 */
void PauseMenu(void);

#endif
