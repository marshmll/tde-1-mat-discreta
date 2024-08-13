/**
 * Nome: Renan da Silva Oliveira Andrade
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

#define ERR_BAD_ARGS 1
#define ERR_OPEN_FILE 2
#define ERR_BAD_NUM_OF_OPS 3

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Modo de uso: ./conjuntos <arquivo>" << "\n";
        exit(ERR_BAD_ARGS);
    }

    std::string file_path = argv[1];
    std::ifstream in_file(file_path);

    if (!in_file.is_open())
    {
        std::cerr << "Erro ao abrir arquivo: " << file_path << "\n";
        exit(ERR_OPEN_FILE);
    }

    int num_of_ops;
    in_file >> num_of_ops;

    if (num_of_ops == 0)
    {
        std::cout << "Erro: número de operações inválido (lido: " << num_of_ops << ")\n";
        exit(ERR_BAD_NUM_OF_OPS);
    }

    in_file.close();
    exit(EXIT_SUCCESS);
}