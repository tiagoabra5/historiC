# historiC - Um quiz sobre a história da computação

---

## Descrição

Jogo educativo de quiz 2D sobre a **história da computação**, desenvolvido
em linguagem C pura utilizando a biblioteca **raylib**.

O jogador viaja por 8 eras da computação. Em cada fase:
1. **Pílula de Conhecimento** – um fato educativo real é exibido (pessoa,
   invenção ou conceito daquela era).
2. **Pergunta de múltipla escolha** – o jogador responde usando as teclas
   `1`, `2`, `3` ou `4`.
3. **Feedback imediato** – a resposta correta é destacada em verde; a errada
   em vermelho.

O jogo termina quando todas as questões são respondidas (vitória) ou quando
as 3 vidas acabam (game over).

---

## Eras cobertas

| Era | Período | Tema principal |
|-----|---------|----------------|
| Era Mecânica | Séc. XVII–XIX | Tear de Jacquard & Babbage |
| Primeira Programadora | 1843 | Ada Lovelace |
| Era Eletromecânica | 1930–40 | Enigma & Alan Turing |
| Primeiro Computador Eletrônico | 1945 | ENIAC |
| Transistor & Circuito Integrado | 1947–1958 | Lei de Moore |
| Era do PC | 1970–1980 | Altair 8800 & Apple |
| A Internet | 1969–1991 | ARPANET & WWW |
| Era Moderna | 2000–hoje | Computação Quântica |

---

## Controles

| Tecla | Ação |
|-------|------|
| `ENTER` / `SPACE` | Avançar no menu e nas pílulas |
| `1` `2` `3` `4` | Selecionar alternativa |
| `R` | Reiniciar (na tela de vitória/game over) |
| `ESC` | Fechar o jogo |

---

## Compilação

### Pré-requisitos

- GCC (ou Clang)
- raylib 5.x instalada (`libraylib-dev` ou compilada do código-fonte)

### Linux

```bash
# 1. Instale raylib:
sudo apt install libraylib-dev

# 2. Ajuste RAYLIB_INC e RAYLIB_LIB no Makefile se necessário, depois:
make

# 3. Execute:
./historia_computacao
```

### Compilação manual (sem make)

```bash
gcc -std=c99 -Wall -O2 \
    -I/usr/local/include \
    main.c game.c \
    -o historia_computacao \
    -lraylib -lm -lpthread -ldl -lrt -lX11
```

---

| EQUIPE |
|------|
| Tiago Abraão |
| Matheus Paulo |
| Lucas Canto |

---
