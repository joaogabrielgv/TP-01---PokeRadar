# Para compilar o programa, execute: make
# Para executar o programa sem arquivo de entrada (entrada por teclado), execute: make run
# Para executar o programa com arquivo de entrada específico, execute: make run ARGS=nome_do_arquivo.txt
# Para remover os arquivos gerados, execute: make clean

CC = gcc
CFLAGS = -Wall -g -I.

BIN = programa

SRCS = Main.c Centro_de_Pesquisa.c Pokelista.c Pokemon.c Treinador.c
OBJS = $(SRCS:.c=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN) $(ARGS)

clean:
	rm -f *.o $(BIN)