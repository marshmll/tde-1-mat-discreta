#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

#define ERR_BAD_ARGS 1
#define ERR_OPEN_FILE 2
#define ERR_BAD_MAX_NUM_OF_OPS 3
#define ERR_UNKNOWN_TOKEN 4
#define ERR_OPS_LIMIT 5
#define ERR_READING_SET 6

#define UNION_OP "U"
#define INTERSECTION_OP "I"
#define DIFFERENCE_OP "D"
#define CARTESIAN_OP "C"

std::set<std::string> read_set(std::ifstream &in_file);

const std::string stringfy_set(std::set<std::string> &set);

const std::string stringfy_set(std::set<std::pair<std::string, std::string>> &set);

std::set<std::string> calc_union(std::set<std::string> &set_one, std::set<std::string> &set_two);

std::set<std::string> calc_intersection(std::set<std::string> &set_one, std::set<std::string> &set_two);

std::set<std::string> calc_difference(std::set<std::string> &set_one, std::set<std::string> &set_two);

std::set<std::pair<std::string, std::string>> calc_cartesian_product(std::set<std::string> &set_one, std::set<std::string> &set_two);