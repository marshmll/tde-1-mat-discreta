// Nome: Renan da Silva Oliveira Andrade

#include "conjuntos.h"

// Esta função lê a proxima linha do arquivo e extrai um conjunto da primeira linha
// que encontrar. Elementos do conjunto devem estar separados por VIRGULAS, sendo
// permitido qualquer símbolo que não seja um espaço ou tab.
// Elementos em branco são ignorados.
// Espaços em branco entre um único elemento também são ignorados.
std::set<std::string> read_set(std::ifstream &in_file)
{
    // Armazena a linha
    std::string line;

    // Lê a próxima linha que não esteja em branco.
    while (line.size() == 0)
    {
        // Se chegou ao fum do arquivo, finaliza o programa com código de erro.
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
    std::set<std::string> set;

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
                set.insert(buffer);

            buffer.clear();
        }
        // Lê qualquer elemento que não seja espaço ou tab para o bufffer.
        else if (!isblank(c))
        {
            buffer.push_back(c);
        }
    }

    // Insere o último elemento lido no buffer, se não for um espaço ou tab.
    if (buffer.size() != 0)
        set.insert(buffer);

    // Retorna o conjunto lido
    return set;
}

// Esta função formata um conjunto em uma string que pode ser printada.
// Função sobrecarregada para conjunto de strings.
const std::string stringfy_set(std::set<std::string> &set)
{
    std::string str = "{";

    for (auto it = set.begin(); it != set.end(); ++it)
    {
        str.append(*it);
        str.append(", ");
    }

    // Apaga o último ", " da string.
    str.erase(str.size() - 2, 2);

    str.push_back('}');

    return str;
}

// Esta função formata um conjunto em uma string que pode ser printada.
// Função sobrecarregada para conjunto de pares de strings.
const std::string stringfy_set(std::set<std::pair<std::string, std::string>> &set)
{
    std::string str = "{";
    std::vector<std::pair<std::string, std::string>> pairs;

    for (auto it = set.begin(); it != set.end(); ++it)
    {
        pairs.push_back(*it);
    }

    for (auto &[value1, value2] : pairs)
    {
        str.append("(" + value1 + ", " + value2 + "), ");
    }

    // Apaga o último ", " da string.
    str.erase(str.size() - 2, 2);
    str.push_back('}');

    return str;
}

// Esta função calcula a união de dois conjuntos e retorna um novo conjunto com o resultado.
std::set<std::string> calc_union(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    // Vetor de strings temporário para armazenar o resultado.
    // Aloca espaço suficiente para a soma das quantidades de elementos dos conjuntos.
    std::vector<std::string> union_vec(set_one.size() + set_two.size());

    // Conjunto a ser retornado.
    std::set<std::string> union_set;

    // Itera sobre todos os elemento dos conjuntos e insere o resultado no vetor de strings.
    // Utiliza std::set_union da biblioteca <set>
    auto it = std::set_union(set_one.begin(), set_one.end(),
                             set_two.begin(), set_two.end(),
                             union_vec.begin());

    // Redimensiona o vetor para o tamanho utilizado.
    union_vec.resize(it - union_vec.begin());

    // Insere os elementos dentro de um conjunto.
    for (auto element : union_vec)
    {
        union_set.insert(element);
    }

    // Retorna o conjunto construído.
    return union_set;
}

// Esta função calcula a intersecção de dois conjuntos e retorna um novo conjunto com o resultado.
std::set<std::string> calc_intersection(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    // Vetor de strings temporário para armazenar o resultado.
    // Aloca espaço suficiente para a soma das quantidades de elementos dos conjuntos.
    std::vector<std::string> intersection_vec(set_one.size() + set_two.size());

    // Conjunto a ser retornado.
    std::set<std::string> intersection_set;

    // Itera sobre todos os elemento dos conjuntos e insere o resultado no vetor de strings.
    // Utiliza std::set_intersection da biblioteca <set>
    auto it = std::set_intersection(set_one.begin(), set_one.end(),
                                    set_two.begin(), set_two.end(),
                                    intersection_vec.begin());

    // Redimensiona o vetor para o tamanho utilizado.
    intersection_vec.resize(it - intersection_vec.begin());

    // Insere os elementos dentro de um conjunto.
    for (auto element : intersection_vec)
    {
        intersection_set.insert(element);
    }

    // Retorna o conjunto construído.
    return intersection_set;
}

// Esta função calcula a diferença de dois conjuntos e retorna um novo conjunto com o resultado.
std::set<std::string> calc_difference(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    // Vetor de strings temporário para armazenar o resultado.
    // Aloca espaço suficiente para a soma das quantidades de elementos dos conjuntos.
    std::vector<std::string> difference_vec(set_one.size() + set_two.size());

    // Conjunto a ser retornado.
    std::set<std::string> difference_set;

    // Itera sobre todos os elemento dos conjuntos e insere o resultado no vetor de strings.
    // Utiliza std::set_difference da biblioteca <set>
    auto it = std::set_difference(set_one.begin(), set_one.end(),
                                  set_two.begin(), set_two.end(),
                                  difference_vec.begin());

    // Redimensiona o vetor para o tamanho utilizado.
    difference_vec.resize(it - difference_vec.begin());

    // Insere os elementos dentro de um conjunto.
    for (auto element : difference_vec)
    {
        difference_set.insert(element);
    }

    // Retorna o conjunto construído.
    return difference_set;
}

std::set<std::pair<std::string, std::string>> calc_cartesian_product(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    // Vetores para armazenar os elementos dos conjuntos fornecidos.
    std::vector<std::string> set_one_vec;
    std::vector<std::string> set_two_vec;

    // Conjunto a ser retornado.
    std::set<std::pair<std::string, std::string>> cartesian_set;

    // Itera pelo primeiro conjunto e armazena os elementos no primeiro vetor.
    for (auto it = set_one.begin(); it != set_one.end(); ++it)
    {
        set_one_vec.push_back(*it);
    }

    // Itera pelo segundo conjunto e armazena os elementos no segundo vetor.
    for (auto it = set_two.begin(); it != set_two.end(); ++it)
    {
        set_two_vec.push_back(*it);
    }

    // Armazena o tamanho dos dois vetores.
    const int set_one_size = set_one_vec.size();
    const int set_two_size = set_two_vec.size();

    // Itera por cada elemento do primeiro vetor
    for (int i = 0; i < set_one_size; ++i)
    {
        // Itera por cada elemento do segundo vetor
        for (int j = 0; j < set_two_size; ++j)
        {
            // Cria os pares ordenados combinando cada elemento de A[i] com cada elemento de B[j]
            std::pair<std::string, std::string> pair = {set_one_vec.at(i), set_two_vec.at(j)};

            // Insere o par ordenado no conjunto.
            cartesian_set.insert(pair);
        }
    }

    // Retorna o conjunto construído.
    return cartesian_set;
}
