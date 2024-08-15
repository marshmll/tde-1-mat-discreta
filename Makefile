all: conjuntos

conjuntos : main.cpp conjuntos.cpp
	g++ main.cpp conjuntos.cpp -o conjuntos