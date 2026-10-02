
CC = gcc
CFLAGS = -Wall -g -I.

BIN = programa

SRCS = Main.c Centro_de_Pesquisa.c Pokelista.c Pokemon.c Treinador.c
OBJS = $(SRCS:.c=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -f *.o $(BIN)