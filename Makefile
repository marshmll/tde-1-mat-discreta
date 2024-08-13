all: conjuntos

conjuntos : conjuntos.cpp
	g++ $< -o $@