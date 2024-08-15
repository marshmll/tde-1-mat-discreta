/**
 * Nome: Renan da Silva Oliveira Andrade
 */

#define ERR_BAD_ARGS 1
#define ERR_OPEN_FILE 2
#define ERR_BAD_NUM_OF_OPS 3
#define ERR_OPS_LIMIT 4

#include "conjuntos.h"

int NUM_OF_OPS = 0;

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

    in_file >> NUM_OF_OPS;

    if (NUM_OF_OPS == 0)
    {
        std::cout << "Erro: número de operações inválido (lido: " << NUM_OF_OPS << ")\n";
        exit(ERR_BAD_NUM_OF_OPS);
    }

    int current_op_count = 1;
    std::string buffer;

    while (std::getline(in_file, buffer))
    {
        if (buffer.size() == 0)
        {
            continue;
        }
        else if (current_op_count > NUM_OF_OPS)
        {
            std::cerr << "Erro: número de operações excedida (esperado: " << NUM_OF_OPS << ")" << "\n"
                      << "Encerrando." << "\n";
            exit(ERR_OPS_LIMIT);
        }
        else if (buffer == UNION_OP)
        {
            ++current_op_count;

            std::set<std::string> set_one = read_set(in_file);
            std::set<std::string> set_two = read_set(in_file);
            std::set<std::string> union_set = calc_union(set_one, set_two);

            std::cout << "União: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " << stringfy_set(set_two) << ". Resultado: " << stringfy_set(union_set) << "\n";
        }
        else if (buffer == INTERSECTION_OP)
        {
            ++current_op_count;

            std::set<std::string> set_one = read_set(in_file);
            std::set<std::string> set_two = read_set(in_file);
            std::set<std::string> intersection_set = calc_intersection(set_one, set_two);

            std::cout << "Intersecção: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " << stringfy_set(set_two) << ". Resultado: " << stringfy_set(intersection_set) << "\n";
        }
        else if (buffer == DIFFERENCE_OP)
        {
            ++current_op_count;

            std::set<std::string> set_one = read_set(in_file);
            std::set<std::string> set_two = read_set(in_file);
            std::set<std::string> difference_set = calc_difference(set_one, set_two);

            std::cout << "Diferença: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " << stringfy_set(set_two) << ". Resultado: " << stringfy_set(difference_set) << "\n";
        }
        else if (buffer == CARTESIAN_OP)
        {
            ++current_op_count;

            std::set<std::string> set_one = read_set(in_file);
            std::set<std::string> set_two = read_set(in_file);
            std::set<std::pair<std::string, std::string>> cartesian_set = calc_cartesian_product(set_one, set_two);

            std::cout << "Produto Cartesiano: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " << stringfy_set(set_two) << ". Resultado: " << stringfy_set(cartesian_set) << "\n";
        }
        else
        {
            std::cerr << "Identificador desconhecido: " << buffer << "\n";
        }
    }

    if (current_op_count < NUM_OF_OPS)
    {
        std::cerr << "Erro: número de operações abaixo do esperado (esperado: " << NUM_OF_OPS << ", encontrado: " << current_op_count << ")\n"
                  << "Encerrando." << "\n";
        exit(ERR_OPS_LIMIT);
    }

    in_file.close();
    exit(EXIT_SUCCESS);
}