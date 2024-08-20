# Conjuntos Numéricos em C++

![Conjuntos Numéricos](https://s4.static.brasilescola.uol.com.br/be/2020/06/interseccao-a-b.jpg)

## Modo de Uso

Certifique-se de __ter o compilador g++ instalado.__ Para compilar, rode `make` no diretório do projeto.

Caso deseje utilizar outro compilador, como `cl` ou `clang`, compile manualmente utilizando os arquivos `main.cpp` e `conjuntos.cpp` como arquivos de entrada e arquivo de saída como `main` (ou qualquer nome desejado.).

Para executar o programa, entre no diretório do projeto pelo terminal ou CMD. Execute `./main <arquivo>`, onde o arquivo é o caminho de um dos arquivos `.txt` (*1.txt, 2.txt, 3.txt*).

***No Replit, entre no Shell (canto inferior esquerdo: Tools->Shell) e execute os passos listados acima.***

## Objetivo

Este projeto se trata de um programa que lê um arquivo `.txt` contendo operações entre conjuntos matemáticos (união, intersecção, diferença e produto cartesiano) e imprime os resultados das operações no terminal.

## Formatação dos arquivos de entrada

Os arquivos de entrada deverão possuir a extensão ***.txt***.

Os arquivos de entrada sempre deverão ter na primeira linha o número de operações a serem realizadas (i.e, quantas uniões/intersecções/diferenças/produtos a serem calculados).

Nas linhas a seguir, o seguinte padrão deve se aplicar: Primeiro, um operador denominando qual operação deverá ser realizada, seja:

* **U**: União;
* **I**: Intersecção;
* **D**: Diferença;
* **C**: Produto cartesiano.

***Nota: O operador deve estar em maiúsculo.***

Nas duas linhas seguintes, deverão estar especificados os elementos dos dois conjutos a serem utilizados. Cada elemento deverá estar separado por virgula, sendo ignorado espaços em branco entre os elementos e qualquer elemento em branco. Ex:

    1, 2, 3, 4
    A, B, C, D

___

Exemplo de arquivo válido:

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