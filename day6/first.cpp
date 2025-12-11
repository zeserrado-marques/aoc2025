#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

std::vector<std::string> string_split(std::string str, std::string sep) {
    std::vector<std::string> str_lst;
    size_t pos;

    while ((pos = str.find(sep) ) != std::string::npos) {
        std::string element = str.substr(0, pos);
        
        str.erase(0, pos + sep.length()); // trim string to keep searching
        
        // skip aditional spaces
        if (element.length() == 0)
            continue;

        str_lst.push_back(element);

    }
    // in case we reach a new line
    if (str.length())
        str_lst.push_back(str.substr(0, pos));

    return str_lst;
}

long vector_sum(std::vector<long> vec) {
    long res = 0;
    for (long num : vec)
        res += num;
    return res;
}

long vector_product(std::vector<long> vec) {
    long res = 1;
    for (long num : vec)
        res *= num;
    return res;
}

std::vector<std::vector<long>> create_transposed(std::vector<std::vector<long>> matriz, 
    size_t n_rows, size_t n_cols) {

    std::vector<std::vector<long>> transposed;
    for (size_t row = 0; row < n_cols; row++){
        std::vector<long> trans_row;
        
        for (size_t col = 0; col < n_rows; col++)
            trans_row.push_back(matriz[col][row]);
        
        transposed.push_back(trans_row);
    }
    return transposed;
    
}

int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    long res = 0;
    std::vector<std::vector<long>> matriz;
    std::vector<std::string> operations;

    fh.open(argv[1]);
    while (std::getline(fh, line)) {
        std::string separator = " ";
        std::regex digits_regex ("\\d");
        std::vector<long> row;

        // std::cout << line << "\n";
        // get numbers
        if (std::regex_search(line, digits_regex)) {
            auto splited = string_split(line, separator);
            for (auto s : splited) 
                row.push_back(std::stol(s));
            
            matriz.push_back(row);
        } else {
            operations = string_split(line, separator);
        }

    }

    matriz = create_transposed(matriz, matriz.size(), operations.size());
    for (size_t i = 0; i < operations.size(); i++) {
        if (operations[i] == "+") {
            res += vector_sum(matriz[i]);
        } else {
            res += vector_product(matriz[i]);
        }
    }
    
    
    std::cout << res << "\n";    
    
    fh.close();
    return 0;
}
