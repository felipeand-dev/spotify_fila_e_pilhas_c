# Makefile do player Spotify (fila + pilha)
#
# Comandos:
#   make          -> compila o programa
#   make run      -> compila (se precisar) e executa
#   make valgrind -> executa com valgrind para checar vazamento de memoria
#   make clean    -> apaga os arquivos compilados

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
TARGET  = output/spotify
OBJDIR  = output/obj

SRCS    = main.c musicas.c fila/fila.c pilha/pilha.c
OBJS    = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
DEPS    = $(OBJS:.o=.d)

.PHONY: all run valgrind clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# -MMD -MP gera os .d para recompilar quando um .h mudar
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)

-include $(DEPS)
