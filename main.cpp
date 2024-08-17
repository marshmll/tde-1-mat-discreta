// Nome: Renan da Silva Oliveira Andrade

/* 
ENUNCIADO

    O programa que você desenvolverá irá receber como entrada um arquivo de texto (.txt)
contendo vários conjuntos de dados e várias operações. Estas operações e dados estarão representadas
em um arquivo de textos contendo apenas os dados referentes as operações que devem ser realizadas
segundo a seguinte regra fixa: a primeira linha do arquivo de texto de entrada conterá o número de
operações que estão descritas no arquivo, este número de operações será um inteiro; as linhas
seguintes seguirão sempre o mesmo padrão de três linhas: a primeira linha apresenta o código da
operação (U para união, I para interseção, D para diferença e C produto cartesiano), a segunda e
terceira linhas conterão os elementos dos conjuntos separados por virgulas. A seguir está um exemplo
das linhas que podem existir em um arquivo de testes para o programa que você irá desenvolver:

4
U
3, 5, 67, 7
1, 2, 3, 4
I
1, 2, 3, 4, 5
4, 5
D
1, A, C, 34
A, C, D, 23
C
3, 4, 5, 5, A, B, R
1, B, C, D, 1

    Neste exemplo temos 4 operações uma união (U), uma interseção (I), um diferença (D) e um
produto cartesiano (C). A união, definida por U, deverá ser executada sobre os conjuntos {𝟑, 𝟓, 𝟔𝟕, 𝟕} e
{𝟏, 𝟐, 𝟑, 𝟒}, cujos elementos estão explicitados nas linhas posteriores a definição da operção (U).
A resposta do seu programa deverá conter a operação realizada, descrita por extenso, os dados
dos conjuntos identificados, e o resultado da operação. No caso da união a linha de saída deverá conter
a informação e a formatação mostrada a seguir:

União: conjunto 1 {3, 5, 67, 7}, conjunto 2 {1, 2, 3, 4}. Resultado: {3, 5, 67, 7, 1, 2, 4}

    Seu programa deverá mostrar a saída no terminal, ou em um arquivo de textos. Em qualquer
um dos casos, a saída será composta por uma linha de saída para cada operação constante no arquivo
de textos de entrada formatada segundo o exemplo de saída acima. Observe as letras maiúsculas e
minúsculas, e os pontos utilizados na formatação da linha de saída apresenta acima.
No caso do texto de exemplo, teremos 4 linhas, e apenas 4 linhas de saída, formatadas e
pontuadas conforme o exemplo de saída acima. O uso de linhas extras na saída, ou erros de formatação,
implicam em perda de pontos como pode ser visto na rubrica de avaliação constante neste documento.

    Para que seu programa possa ser testado você deve criar, no mínimo, três arquivos de entrada
contendo um número diferente de operações, operações com dados diferentes, e operações em ordem
diferentes. Os arquivos de entrada criados para os seus testes devem estar disponíveis tanto no
ambiente repl.it quanto no ambiente Github.
Observe que o professor irá testar seu programa com os arquivos de testes que você criar e com,
no mínimo um arquivo de testes criado pelo próprio professor.
*/

#include "conjuntos.h"

int MAX_NUM_OF_OPS = 0; // Variável global para armazenar o número máximo de operações lido.

int main(int argc, char **argv)
{
    // Verifica se o executável possui apenas 1 argumento, se não, finaliza com código de erro.
    if (argc != 2)
    {
        std::cerr << "Modo de uso: ./conjuntos <arquivo>" << "\n";
        exit(ERR_BAD_ARGS);
    }

    // Cópia do argumento de caminho do arquivo
    std::string file_path = argv[1];

    // Stream de arquivo da biblioteca fstream
    std::ifstream in_file(file_path);

    // Verifica se o arquivo pôde ser aberto, se não, finaliza com código de erro.
    if (!in_file.is_open())
    {
        std::cerr << "Erro ao abrir arquivo: " << file_path << "\n";
        exit(ERR_OPEN_FILE);
    }

    // Lê a primeira linha do arquivo, que deve especificar o número de operações máximo.
    in_file >> MAX_NUM_OF_OPS;

    // Caso seja um valor inválido (qualquer símbolo que não seja número ou um número <= 0)
    // finaliza com código de erro.
    if (MAX_NUM_OF_OPS <= 0)
    {
        std::cout << "Erro: número de operações inválido (lido: " << MAX_NUM_OF_OPS << ")\n";
        exit(ERR_BAD_MAX_NUM_OF_OPS);
    }

    // Contador de operações.
    int current_op_count = 0;

    // Buffer para leitura do arquivo.
    std::string buffer;

    // Lê linha a linha do arquivo
    while (std::getline(in_file, buffer))
    {
        // Ignora espaços e tabs.
        if (buffer.size() == 0)
        {
            continue;
        }
        // Verifica se foi ultrapassado o limite de operações.
        else if (current_op_count == MAX_NUM_OF_OPS)
        {
            std::cerr << "Erro: número de operações excedida (esperado: " << MAX_NUM_OF_OPS << ")" << "\n"
                      << "Encerrando." << "\n";
            exit(ERR_OPS_LIMIT);
        }
        // Verifica se é uma operação de união
        else if (buffer == UNION_OP)
        {
            // Incrementa o contador.
            ++current_op_count;

            std::vector<std::string> set_one = read_set(in_file); // Lê o primeiro conjunto.
            std::vector<std::string> set_two = read_set(in_file); // Lê o segundo conjunto.

            // Calcula a união dos dois conjuntos lido.
            std::vector<std::string> union_set = calc_union(set_one, set_two);

            // Mostra o resultado formatado como o especificado no enunciado.
            std::cout << "União: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " <<
                stringfy_set(set_two) << ". Resultado: " << stringfy_set(union_set) << "\n";
        }
        // Verifica se é uma operação de intersecção
        else if (buffer == INTERSECTION_OP)
        {
            ++current_op_count;

            std::vector<std::string> set_one = read_set(in_file); // Lê o primeiro conjunto.
            std::vector<std::string> set_two = read_set(in_file); // Lê o segundo conjunto.
            
            // Calcula a intersecção dos dois conjuntos lido.
            std::vector<std::string> intersection_set = calc_intersection(set_one, set_two);

            // Mostra o resultado formatado como o especificado no enunciado.
            std::cout << "Intersecção: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " <<
                stringfy_set(set_two) << ". Resultado: " << stringfy_set(intersection_set) << "\n";
        }
        // Verifica se é uma operação de diferença
        else if (buffer == DIFFERENCE_OP)
        {
            ++current_op_count;

            std::vector<std::string> set_one = read_set(in_file); // Lê o primeiro conjunto.
            std::vector<std::string> set_two = read_set(in_file); // Lê o segundo conjunto.
            
            // Calcula a diferença dos dois conjuntos lido.
            std::vector<std::string> difference_set = calc_difference(set_one, set_two);

            // Mostra o resultado formatado como o especificado no enunciado.
            std::cout << "Diferença: conjunto 1 " << stringfy_set(set_one) << ", conjunto 2 " <<
                stringfy_set(set_two) << ". Resultado: " << stringfy_set(difference_set) << "\n";
        }
        // Verifica se é uma operação de produto cartesiano
        else if (buffer == CARTESIAN_OP)
        {
            ++current_op_count;

            std::vector<std::string> set_one = read_set(in_file); // Lê o primeiro conjunto.
            std::vector<std::string> set_two = read_set(in_file); // Lê o segundo conjunto.
            
            // Calcula a produto cartesiano dos dois conjuntos lido.
            std::vector<std::pair<std::string, std::string>> cartesian_set = calc_cartesian_product(set_one, set_two);

            // Mostra o resultado formatado como o especificado no enunciado.
            std::cout << "Produto Cartesiano: conjunto 1 " << stringfy_set(set_one) <<
                ", conjunto 2 " << stringfy_set(set_two) << ". Resultado: " << stringfy_set(cartesian_set) << "\n";
        }
        // Significa que leu um identificador estranho. Finaliza o programa com código de erro.
        else
        {
            std::cerr << "Erro: operador desconhecido: " << buffer << "\n"
                      << "Encerrando." << "\n";
            exit(ERR_UNKNOWN_TOKEN);
        }
    }

    // Fecha o stream de arquivo
    in_file.close();

    // Verifica ao terminar de ler o arquivo se o número de operações lidas é menor que o número
    // de operações esperado. Se sim, finaliza o programa com código de erro.
    if (current_op_count < MAX_NUM_OF_OPS)
    {
        std::cerr << "Erro: número de operações abaixo do esperado (esperado: " << MAX_NUM_OF_OPS << ", encontrado: " << current_op_count << ")\n"
                  << "Encerrando." << "\n";
        exit(ERR_OPS_LIMIT);
    }

    // Finalização do programa com código 0;
    exit(EXIT_SUCCESS);
}