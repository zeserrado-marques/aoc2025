#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>


int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    std::vector<std::pair<long, long>> ranges; // first = lb and second = ub
    int total_fresh_ingredients = 0;


    fh.open(argv[1]);
    while (fh >> line) {
        // std::cout << line << "\n";
        size_t dash_i;

        // catch the ranges
        if ((dash_i = line.find('-')) == std::string::npos)
            break;
        
        auto lb_curr = std::stol(line.substr(0, dash_i));
        auto ub_curr = std::stol(line.substr(dash_i+1, line.length()-dash_i-1));
        
        ranges.push_back(std::make_pair(lb_curr, ub_curr));
    }

    
    for (auto p : ranges)
        std::cout << p.first << " and " << p.second << "\n";
    
    std::cout << total_fresh_ingredients << "\n";    
    
    return 0;
}
