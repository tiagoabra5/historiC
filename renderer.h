#ifndef RENDERER_H
#define RENDERER_H

#include "types.h"
#include "raylib.h"

void DrawTextWrapped(const char *text, int x, int y,
                     int maxWidth, int fontSize, Color color);

void DrawHeader(const char *era, const char *year, Color accent,
                int questionIndex, int score, int lives);

void DrawProgressBar(int current);

void DrawMenu(void);
void DrawKnowledge(const Game *g);
void DrawQuestion(const Game *g);
void DrawFeedback(const Game *g);
void DrawWin(const Game *g);
void DrawGameOver(const Game *g);

void Render(const Game *g);

#endif
