// Nome: Renan da Silva Oliveira Andrade

#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

#define ERR_BAD_ARGS 1           // Sinaliza erro de argumentos de CLI.
#define ERR_OPEN_FILE 2          // Sinaliza erro ao abrir o arquivo especificado.
#define ERR_BAD_MAX_NUM_OF_OPS 3 // Sinaliza que o número de operações especificado no arquivo é inválido
#define ERR_UNKNOWN_TOKEN 4      // Sinaliza que algum token lido é inválido.
#define ERR_OPS_LIMIT 5          // Sinaliza que o número de operações lido ultrpassou o limite especificado.
#define ERR_READING_SET 6        // Sinaliza que não foi possível ler 2 conjuntos seguidos do arquivo.

#define UNION_OP "U"        // Operador de união de conjuntos.
#define INTERSECTION_OP "I" // Operador de intersecção de conjuntos.
#define DIFFERENCE_OP "D"   // Operador de diferença de conjuntos.
#define CARTESIAN_OP "C"    // Operador de produto cartesiano de conjuntos.

std::set<std::string> read_set(std::ifstream &in_file);

const std::string stringfy_set(std::set<std::string> &set);

const std::string stringfy_set(std::set<std::pair<std::string, std::string>> &set);

std::set<std::string> calc_union(std::set<std::string> &set_one, std::set<std::string> &set_two);

std::set<std::string> calc_intersection(std::set<std::string> &set_one, std::set<std::string> &set_two);

std::set<std::string> calc_difference(std::set<std::string> &set_one, std::set<std::string> &set_two);

std::set<std::pair<std::string, std::string>> calc_cartesian_product(std::set<std::string> &set_one, std::set<std::string> &set_two);