#include "renderer.h"
#include "quiz_data.h"
#include <stdio.h>
#include <string.h>

void DrawTextWrapped(const char *text, int x, int y,
                     int maxWidth, int fontSize, Color color)
{
    if (!text) return;

    char buf[2048];
    strncpy(buf, text, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    int  curY = y;
    char word[256];
    int  wi   = 0;
    char line[512];
    int  li   = 0;
    line[0]   = '\0';

    for (int i = 0; ; i++) {
        char c = buf[i];

        if (c == '\0' || c == ' ' || c == '\n') {
            word[wi] = '\0';
            wi = 0;

            char test[512];
            if (li > 0)
                snprintf(test, sizeof(test), "%s %s", line, word);
            else
                snprintf(test, sizeof(test), "%s", word);

            if (MeasureText(test, fontSize) > maxWidth && li > 0) {
                DrawText(line, x, curY, fontSize, color);
                curY += fontSize + 4;
                snprintf(line, sizeof(line), "%s", word);
            } else {
                snprintf(line, sizeof(line), "%s", test);
            }
            li = (int)strlen(line);

            if (c == '\n') {
                DrawText(line, x, curY, fontSize, color);
                curY += fontSize + 4;
                line[0] = '\0';
                li = 0;
            }

            if (c == '\0') {
                if (li > 0) DrawText(line, x, curY, fontSize, color);
                break;
            }
        } else {
            word[wi++] = c;
        }
    }
}

void DrawHeader(const char *era, const char *year, Color accent,
                int questionIndex, int score, int lives)
{
    DrawRectangle(0, 0, SCREEN_W, 50, accent);
    DrawText(era,  20, 14, 20, WHITE);
    DrawText(year, SCREEN_W - MeasureText(year, 20) - 20, 14, 20, WHITE);

    char hud[64];
    snprintf(hud, sizeof(hud), "Questao %d/%d   * %d   Vidas: %d",
             questionIndex + 1, MAX_QUESTIONS, score, lives);
    DrawText(hud, SCREEN_W / 2 - MeasureText(hud, 18) / 2, 15, 18, WHITE);
}

void DrawProgressBar(int current)
{
    int barX = 20, barY = SCREEN_H - 20;
    int barW = SCREEN_W - 40, barH = 8;
    int fill = (current * barW) / MAX_QUESTIONS;

    DrawRectangle(barX, barY, barW, barH, LIGHTGRAY);
    DrawRectangle(barX, barY, fill, barH, GREEN);
    DrawRectangleLines(barX, barY, barW, barH, DARKGRAY);
}

void DrawMenu(void)
{
    const char *title = "historiC";
    DrawText(title,
             SCREEN_W / 2 - MeasureText(title, 38) / 2, 110, 38,
             (Color){100, 200, 255, 255});

    const char *sub = "Um Quiz pelo tempo das maquinas";
    DrawText(sub,
             SCREEN_W / 2 - MeasureText(sub, 22) / 2, 165, 22,
             LIGHTGRAY);

    const char *eras[] = {
        "Era Mecanica",
        "Primeiros Computadores Eletronicos",
        "Era do PC",
        "Internet e Mundo Digital",
        "Computacao Quantica"
    };
    for (int i = 0; i < 5; i++) {
        DrawText(eras[i],
                 SCREEN_W / 2 - MeasureText(eras[i], 18) / 2,
                 230 + i * 36, 18,
                 (Color){200, 200, 200, 200});
    }

    const char *prompt = "Pressione ENTER para comecar";
    float t     = (float)GetTime();
    float pulse = t - (int)t;               // 0.0 -> 1.0 por segundo
    unsigned char alpha = (unsigned char)(180 + 75 * pulse);
    DrawText(prompt,
             SCREEN_W / 2 - MeasureText(prompt, 20) / 2, 445, 20,
             (Color){255, 255, 100, alpha});

    const char *hint = "Responda com as teclas  1  2  3  4";
    DrawText(hint,
             SCREEN_W / 2 - MeasureText(hint, 17) / 2, 485, 17,
             GRAY);
}

void DrawKnowledge(const Game *g)
{
    const QuizItem *q   = &QUESTIONS[g->current];
    Color           acc = ERA_COLORS[g->current];

    DrawHeader(q->era, q->year, acc, g->current, g->score, g->lives);
    DrawProgressBar(g->current);

    DrawRectangleRounded((Rectangle){30, 65, SCREEN_W - 60, 480},
                         0.05f, 8, (Color){30, 30, 50, 255});
    DrawRectangleRoundedLinesEx((Rectangle){30, 65, SCREEN_W - 60, 480},
                                0.05f, 8, 2.0f, acc);

    DrawText("PILULA DE CONHECIMENTO", 50, 88, 18, (Color){255, 220, 60, 255});
    DrawText(q->pill_title, 50, 128, 26, WHITE);
    DrawTextWrapped(q->pill_text, 50, 170, WRAP_WIDTH, 20,
                    (Color){210, 210, 230, 255});

    const char *cont = "Pressione ENTER para a pergunta";
    DrawText(cont,
             SCREEN_W / 2 - MeasureText(cont, 18) / 2, 510, 18,
             (Color){180, 255, 180, 220});
}

void DrawQuestion(const Game *g)
{
    const QuizItem *q   = &QUESTIONS[g->current];
    Color           acc = ERA_COLORS[g->current];

    DrawHeader(q->era, q->year, acc, g->current, g->score, g->lives);
    DrawProgressBar(g->current);

    DrawRectangleRounded((Rectangle){30, 65, SCREEN_W - 60, 175},
                         0.05f, 8, (Color){30, 30, 50, 255});
    DrawRectangleRoundedLinesEx((Rectangle){30, 65, SCREEN_W - 60, 175},
                                0.05f, 8, 2.0f, acc);

    DrawText("PERGUNTA", 50, 78, 18, acc);
    DrawTextWrapped(q->question, 50, 108, WRAP_WIDTH, 21, WHITE);

    const Color BG_OPTION = {40, 40, 65, 255};
    for (int i = 0; i < MAX_OPTIONS; i++) {
        int ox = 30, oy = 260 + i * 76, ow = SCREEN_W - 60, oh = 64;

        DrawRectangleRounded((Rectangle){ox, oy, ow, oh},
                             0.12f, 8, BG_OPTION);
        DrawRectangleRoundedLinesEx((Rectangle){ox, oy, ow, oh},
                                    0.12f, 8, 2.0f, acc);

        // Número da alternativa em destaque
        char label[4];
        snprintf(label, sizeof(label), "%d", i + 1);
        DrawRectangleRounded((Rectangle){ox + 12, oy + 14, 36, 36},
                             0.4f, 8, acc);
        DrawText(label,
                 ox + 12 + 18 - MeasureText(label, 20) / 2,
                 oy + 14 + 8, 20, WHITE);

        DrawText(q->options[i], ox + 60, oy + 20, 20, WHITE);
    }
}

void DrawFeedback(const Game *g)
{
    const QuizItem *q       = &QUESTIONS[g->current];
    Color           acc     = ERA_COLORS[g->current];
    bool            correct = (g->selected == q->correct);

    DrawHeader(q->era, q->year, acc, g->current, g->score, g->lives);
    DrawProgressBar(g->current);

    DrawRectangleRounded((Rectangle){30, 65, SCREEN_W - 60, 155},
                         0.05f, 8, (Color){25, 25, 45, 255});
    DrawText("PERGUNTA", 50, 78, 18, acc);
    DrawTextWrapped(q->question, 50, 105, WRAP_WIDTH, 20,
                    (Color){180, 180, 200, 255});

    for (int i = 0; i < MAX_OPTIONS; i++) {
        int   ox = 30, oy = 235 + i * 72, ow = SCREEN_W - 60, oh = 60;
        Color bg     = (Color){40, 40, 65, 255};
        Color border = acc;

        if (i == q->correct) {
            bg     = (Color){20,  90, 40, 255};
            border = GREEN;
        } else if (i == g->selected && !correct) {
            bg     = (Color){100, 20, 20, 255};
            border = RED;
        }

        DrawRectangleRounded((Rectangle){ox, oy, ow, oh}, 0.12f, 8, bg);
        DrawRectangleRoundedLinesEx((Rectangle){ox, oy, ow, oh},
                                    0.12f, 8, 2.0f, border);

        char label[4];
        snprintf(label, sizeof(label), "%d", i + 1);
        DrawRectangleRounded((Rectangle){ox + 12, oy + 12, 36, 36},
                             0.4f, 8, border);
        DrawText(label,
                 ox + 12 + 18 - MeasureText(label, 20) / 2,
                 oy + 12 + 8, 20, WHITE);

        DrawText(q->options[i], ox + 60, oy + 18, 20, WHITE);
    }

    const char *msg = correct ? "CORRETO!" : "ERRADO!";
    Color        mc = correct ? GREEN : RED;
    int          mw = MeasureText(msg, 30);
    DrawRectangle(SCREEN_W / 2 - mw / 2 - 20, SCREEN_H - 55,
                  mw + 40, 44, (Color){0, 0, 0, 180});
    DrawText(msg, SCREEN_W / 2 - mw / 2, SCREEN_H - 46, 30, mc);
}

void DrawWin(const Game *g)
{
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, (Color){10, 30, 10, 255});

    const char *t1 = "PARABENS! Voce concluiu o quiz!";
    DrawText(t1, SCREEN_W / 2 - MeasureText(t1, 28) / 2, 130, 28, GREEN);

    char sc[64];
    snprintf(sc, sizeof(sc), "Pontuacao final: %d / %d", g->score, MAX_QUESTIONS);
    DrawText(sc, SCREEN_W / 2 - MeasureText(sc, 26) / 2, 200, 26, WHITE);

    const char *msg =
        "Voce viajou pela historia da computacao,\n"
        "dos cartoes perfurados de Jacquard\n"
        "ate os qubits da computacao quantica.";
    DrawTextWrapped(msg, 100, 270, 700, 21, LIGHTGRAY);

    const char *r = "Pressione R para jogar novamente";
    DrawText(r, SCREEN_W / 2 - MeasureText(r, 20) / 2, 430, 20,
             (Color){200, 255, 100, 255});
}

void DrawGameOver(const Game *g)
{
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, (Color){30, 10, 10, 255});

    const char *t1 = "GAME OVER";
    DrawText(t1, SCREEN_W / 2 - MeasureText(t1, 36) / 2, 140, 36, RED);

    char sc[64];
    snprintf(sc, sizeof(sc), "Voce chegou ate a questao %d com %d ponto(s).",
             g->current + 1, g->score);
    DrawText(sc, SCREEN_W / 2 - MeasureText(sc, 20) / 2, 220, 20, LIGHTGRAY);

    const char *tip = "Dica: leia as pilulas de conhecimento com atencao!";
    DrawText(tip, SCREEN_W / 2 - MeasureText(tip, 19) / 2, 270, 19,
             (Color){255, 200, 100, 255});

    const char *r = "Pressione R para tentar novamente";
    DrawText(r, SCREEN_W / 2 - MeasureText(r, 20) / 2, 380, 20,
             (Color){200, 255, 100, 255});
}

void Render(const Game *g)
{
    BeginDrawing();
    ClearBackground((Color){20, 20, 35, 255});

    switch (g->state) {
        case STATE_MENU:      DrawMenu();         break;
        case STATE_KNOWLEDGE: DrawKnowledge(g);   break;
        case STATE_QUESTION:  DrawQuestion(g);    break;
        case STATE_FEEDBACK:  DrawFeedback(g);    break;
        case STATE_WIN:       DrawWin(g);         break;
        case STATE_GAMEOVER:  DrawGameOver(g);    break;
    }

    EndDrawing();
}
