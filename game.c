#include "game.h"
#include "quiz_data.h"
#include "raylib.h"

void GameInit(Game *g)
{
    g->state          = STATE_MENU;
    g->current        = 0;
    g->score          = 0;
    g->lives          = 3;
    g->selected       = -1;
    g->answered       = false;
    g->feedback_timer = 0.0f;
}

void GameUpdate(Game *g)
{
    float dt = GetFrameTime();

    switch (g->state) {

    //Aguarda ENTER para iniciar
    case STATE_MENU:
        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
            g->state = STATE_KNOWLEDGE;
        break;

    //Aguarda ENTER para ir à pergunta
    case STATE_KNOWLEDGE:
        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
            g->selected = -1;
            g->answered = false;
            g->state    = STATE_QUESTION;
        }
        break;

    //Aguarda o jogador pressionar 1, 2, 3 ou 4
    case STATE_QUESTION:
        if (!g->answered) {
            for (int i = 0; i < MAX_OPTIONS; i++) {
                if (IsKeyPressed(KEY_ONE + i) || IsKeyPressed(KEY_KP_1 + i)) {
                    g->selected       = i;
                    g->answered       = true;
                    g->feedback_timer = 2.0f;

                    if (i == QUESTIONS[g->current].correct)
                        g->score++;
                    else
                        g->lives--;

                    g->state = STATE_FEEDBACK;
                    break;
                }
            }
        }
        break;

    //Espera o timer do feedback zerar
    case STATE_FEEDBACK:
        g->feedback_timer -= dt;
        if (g->feedback_timer <= 0.0f) {
            g->current++;
            if (g->lives <= 0)
                g->state = STATE_GAMEOVER;
            else if (g->current >= MAX_QUESTIONS)
                g->state = STATE_WIN;
            else
                g->state = STATE_KNOWLEDGE;
        }
        break;

    //R reinicia o jogo
    case STATE_WIN:
    case STATE_GAMEOVER:
        if (IsKeyPressed(KEY_R))
            GameInit(g);
        break;
    }
}
