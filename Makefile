#Nome: Renan da Silva Oliveira Andrade

all: main

main: main.cpp conjuntos.cpp
	g++ main.cpp conjuntos.cpp -o $@

clean:
	rm main
