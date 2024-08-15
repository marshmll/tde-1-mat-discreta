#include "conjuntos.h"

std::set<std::string> read_set(std::ifstream &in_file)
{
    std::string line;

    while (line.size() == 0)
    {
        if (!std::getline(in_file, line))
        {
            std::cerr << "Erro: Impossível ler próximo conjunto, chegou ao fim do arquivo." << "\n"
                      << "Encerrando." << "\n";

            exit(ERR_READING_SET);
        }
    }

    size_t line_size = line.size();

    std::string buffer;

    std::set<std::string> set;

    for (size_t i = 0; i < line_size; i++)
    {
        char c = line.at(i);

        if (isalnum(c))
        {
            buffer.push_back(c);
        }
        else if (c == ',')
        {
            if (buffer.size() != 0)
                set.insert(buffer);

            buffer.clear();
        }
    }
    if (buffer.size() != 0)
        set.insert(buffer);

    return set;
}

const std::string stringfy_set(std::set<std::string> &set)
{
    std::string str = "{";

    for (auto it = set.begin(); it != set.end(); ++it)
    {
        str.append(*it);
        str.append(", ");
    }

    str.erase(str.size() - 2, 2);

    str.push_back('}');

    return str;
}

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

    str.erase(str.size() - 2, 2);
    str.push_back('}');

    return str;
}

std::set<std::string> calc_union(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    std::vector<std::string> union_vec(set_one.size() + set_two.size());
    std::set<std::string> union_set;

    auto it = std::set_union(set_one.begin(), set_one.end(),
                             set_two.begin(), set_two.end(),
                             union_vec.begin());

    union_vec.resize(it - union_vec.begin());

    for (auto element : union_vec)
    {
        union_set.insert(element);
    }

    return union_set;
}

std::set<std::string> calc_intersection(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    std::vector<std::string> intersection_vec(set_one.size() + set_two.size());
    std::set<std::string> intersection_set;

    auto it = std::set_intersection(set_one.begin(), set_one.end(),
                                    set_two.begin(), set_two.end(),
                                    intersection_vec.begin());

    intersection_vec.resize(it - intersection_vec.begin());

    for (auto element : intersection_vec)
    {
        intersection_set.insert(element);
    }

    return intersection_set;
}

std::set<std::string> calc_difference(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    std::vector<std::string> difference_vec(set_one.size() + set_two.size());
    std::set<std::string> difference_set;

    auto it = std::set_difference(set_one.begin(), set_one.end(),
                                  set_two.begin(), set_two.end(),
                                  difference_vec.begin());

    difference_vec.resize(it - difference_vec.begin());

    for (auto element : difference_vec)
    {
        difference_set.insert(element);
    }

    return difference_set;
}

std::set<std::pair<std::string, std::string>> calc_cartesian_product(std::set<std::string> &set_one, std::set<std::string> &set_two)
{
    std::set<std::pair<std::string, std::string>> cartesian_set;
    std::vector<std::string> set_one_vec;
    std::vector<std::string> set_two_vec;

    for (auto it = set_one.begin(); it != set_one.end(); ++it)
    {
        set_one_vec.push_back(*it);
    }

    for (auto it = set_two.begin(); it != set_two.end(); ++it)
    {
        set_two_vec.push_back(*it);
    }

    const int set_one_size = set_one_vec.size();
    const int set_two_size = set_two_vec.size();

    for (int i = 0; i < set_one_size; ++i)
    {
        for (int j = 0; j < set_two_size; ++j)
        {
            std::pair<std::string, std::string> pair = {set_one_vec.at(i), set_two_vec.at(j)};
            cartesian_set.insert(pair);
        }
    }

    return cartesian_set;
}
