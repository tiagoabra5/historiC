#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#define SCREEN_W      900
#define SCREEN_H      600
#define MAX_OPTIONS   4
#define MAX_QUESTIONS 8
#define WRAP_WIDTH    820

typedef enum {
    STATE_MENU = 0,    // Tela inicial
    STATE_KNOWLEDGE,   // Pílula de conhecimento (antes de cada pergunta)
    STATE_QUESTION,    // Pergunta de múltipla escolha
    STATE_FEEDBACK,    // Exibe resposta correta/errada por alguns segundos
    STATE_WIN,         // Jogador respondeu todas as questões
    STATE_GAMEOVER     // Jogador perdeu todas as vidas
} GameState;

typedef struct {
    const char *era;                    // Nome da era historica
    const char *year;                   // Período (ex: "1945")
    const char *pill_title;             // Título da pilula educativa
    const char *pill_text;              // Texto da pílula educativa
    const char *question;               // Enunciado da pergunta
    const char *options[MAX_OPTIONS];   // Quatro alternativas
    int         correct;                // Índice da alternativa correta (0-3)
} QuizItem;

typedef struct {
    GameState state;           // Tela/estado atual
    int       current;         // Índice da questão atual (0..MAX_QUESTIONS-1)
    int       score;           // Quantidade de acertos
    int       lives;           // Vidas restantes
    int       selected;        // Alternativa escolhida pelo jogador (-1 = nenhuma)
    bool      answered;        // Jogador ja respondeu nesta rodada?
    float     feedback_timer;  // Tempo restante para exibir o feedback
} Game;

#endif
