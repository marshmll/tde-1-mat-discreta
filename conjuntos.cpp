// Nome: Renan da Silva Oliveira Andrade

#include "conjuntos.h"

// Esta função lê a proxima linha do arquivo e extrai um conjunto da primeira linha
// que encontrar. Elementos do conjunto devem estar separados por VIRGULAS, sendo
// permitido qualquer símbolo que não seja um espaço ou tab.
// Elementos em branco são ignorados.
// Espaços em branco entre um único elemento também são ignorados.
std::vector<std::string> read_set(std::ifstream &in_file)
{
    // Armazena a linha
    std::string line;

    // Lê a próxima linha que não esteja em branco.
    while (line.size() == 0)
    {
        // Se chegou ao fim do arquivo, finaliza o programa com código de erro.
        if (!std::getline(in_file, line))
        {
            std::cerr << "Erro: Impossível ler próximo conjunto, chegou ao fim do arquivo." << "\n"
                      << "Encerrando." << "\n";

            exit(ERR_READING_SET);
        }
    }

    // Comprimento da linha
    size_t line_size = line.size();

    // Buffer de leitura para os elementos do conjunto.
    std::string buffer;

    // Instância de um conjunto vazio.
    std::vector<std::string> set;

    // Itera por todos os caracteres da linha
    for (size_t i = 0; i < line_size; i++)
    {
        // Extrai o caractér.
        char c = line.at(i);

        // Se é uma vírgula, insere o elemento lido dentro do conjunto
        // e limpa o buffer.
        if (c == ',')
        {
            if (buffer.size() != 0)
                set.push_back(buffer);

            buffer.clear();
        }
        // Lê qualquer elemento que não seja espaço ou tab para o bufffer.
        else if (!isblank(c))
        {
            buffer.push_back(c);
        }
    }

    // Insere o último elemento lido do buffer, se não for um espaço ou tab.
    if (buffer.size() != 0)
        set.push_back(buffer);

    // Retorna o conjunto lido
    return set;
}

// Esta função formata um conjunto em uma string que pode ser printada.
// Função sobrecarregada para conjunto de strings.
const std::string stringfy_set(std::vector<std::string> &set)
{
    std::string str = "{";

    int elements_count = 0;

    for (auto &element : set)
    {
        str.append(element);
        str.append(", ");
        ++elements_count;
    }

    // Se há elementos no conjunto
    if (elements_count > 0)
    {
        // Apaga o último ", " da string.
        str.erase(str.size() - 2, 2);
    }

    str.push_back('}');

    return str;
}

// Esta função formata um conjunto em uma string que pode ser printada.
// Função sobrecarregada para conjunto de pares de strings.
const std::string stringfy_set(std::vector<std::pair<std::string, std::string>> &set)
{
    std::string str = "{";

    int elements_count = 0;
    for (auto &[value1, value2] : set)
    {
        str.append("(" + value1 + ", " + value2 + "), ");
        ++elements_count;
    }

    // Se há elementos no conjunto
    if (elements_count > 0)
    {
        // Apaga o último ", " da string.
        str.erase(str.size() - 2, 2);
    }

    str.push_back('}');

    return str;
}

// Esta função calcula a união de dois conjuntos e retorna um novo conjunto com o resultado.
std::vector<std::string> calc_union(std::vector<std::string> &set_one, std::vector<std::string> &set_two)
{
    // Inizializa a união com os valores do primeiro conjunto.
    std::vector<std::string> union_set = set_one;

    // Itera pelos elementos do segundo conjunto
    for (auto &element : set_two)
    {
        // Procura se o elemento já está na união
        auto it = std::find(union_set.begin(), union_set.end(), element);

        // Se o elemento não está no conjunto união, insere na união.
        if (it == union_set.end())
        {
            union_set.push_back(element);
        }
    }

    // Retorna o conjunto união.
    return union_set;
}

// Esta função calcula a intersecção de dois conjuntos e retorna um novo conjunto com o resultado.
std::vector<std::string> calc_intersection(std::vector<std::string> &set_one, std::vector<std::string> &set_two)
{
    // Declara um conjunto para a intersecção.
    std::vector<std::string> intersection_set;

    // Itera pelos elementos do primeiro conjunto.
    for (auto &element : set_one)
    {
        // Procura se o elemento está presente no segundo conjunto.
        auto it = std::find(set_two.begin(), set_two.end(), element);

        // Se estiver, insere no conjunto intersecção.
        if (it != set_two.end())
        {
            intersection_set.push_back(element);
        }
    }

    // Retorna o conjunto intersecção.
    return intersection_set;
}

// Esta função calcula a diferença de dois conjuntos e retorna um novo conjunto com o resultado.
std::vector<std::string> calc_difference(std::vector<std::string> &set_one, std::vector<std::string> &set_two)
{
    // Declara um conjunto para a diferença.
    std::vector<std::string> difference_set;

    // Itera por cada elemento do primeiro conjunto.
    for (auto &element : set_one)
    {
        // Procura pelo elemento no segundo conjunto
        auto it = std::find(set_two.begin(), set_two.end(), element);

        // Se o elemento não estiver presente, insere no conjunto diferença.
        if (it == set_two.end())
        {
            difference_set.push_back(element);
        }
    }

    // Retorna o conjunto diferença.
    return difference_set;
}

std::vector<std::pair<std::string, std::string>>
calc_cartesian_product(std::vector<std::string> &set_one, std::vector<std::string> &set_two)
{
    // Declara um conjunto para o produto cartesiano.
    std::vector<std::pair<std::string, std::string>> cartesian_set;

    // Itera pelos elementos do primeiro conjunto
    for (auto &element_one : set_one)
    {
        // Itera pelos elementos do segundo conjunto
        for (auto &element_two : set_two)
        {
            // Insere no conjunto produto cartesiano os pares ordenados de A->B
            cartesian_set.push_back({element_one, element_two});
        }
    }

    // Retorna o conjunto produto cartesiano.
    return cartesian_set;
}
