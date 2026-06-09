# -------------------------------------------------------
# Makefile – Historia da Computacao (raylib + C99)
# -------------------------------------------------------

CC     = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2

TARGET = historia_computacao

# Ajuste se sua raylib estiver em outro lugar
RAYLIB_INC = /usr/local/include
RAYLIB_LIB = /usr/local/lib

SRCS = main.c game.c quiz_data.c renderer.c
OBJS = $(SRCS:.c=.o)

# Linux
LDFLAGS = -L$(RAYLIB_LIB) -lraylib -lm -lpthread -ldl -lrt -lX11

# macOS (descomente e comente a linha acima)
# LDFLAGS = -L$(RAYLIB_LIB) -lraylib \
#           -framework OpenGL -framework Cocoa \
#           -framework IOKit -framework CoreAudio -framework CoreVideo

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "Compilado: ./$(TARGET)"

%.o: %.c
	$(CC) $(CFLAGS) -I$(RAYLIB_INC) -c $< -o $@

# Dependências explícitas entre arquivos
main.o:      main.c      types.h game.h renderer.h
game.o:      game.c      game.h  types.h quiz_data.h
quiz_data.o: quiz_data.c quiz_data.h types.h
renderer.o:  renderer.c  renderer.h types.h quiz_data.h

clean:
	rm -f $(OBJS) $(TARGET)
