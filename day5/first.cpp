#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>


int check_ranges(std::vector<std::pair<long, long>> ranges, long lb, long ub) {
    for (int i = 0; i < (int)ranges.size(); i++) {
        // compare lb with saved_upper and ub with saved_lower
        if (lb <= ranges[i].second-1 && ub >=ranges[i].first-1)
            return i;
    }

    return -1; // no index found
}

int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    std::vector<std::pair<long, long>> ranges; // first = lb and second = ub
    int fresh_ingredients = 0;


    fh.open(argv[1]);
    while (fh >> line) {
        // std::cout << line << "\n";
        size_t dash_i;
        long id;

        // catch the ranges
        if ((dash_i = line.find('-')) != std::string::npos) {
            auto lb_curr = std::stol(line.substr(0, dash_i));
            auto ub_curr = std::stol(line.substr(dash_i+1, line.length()-dash_i-1));
            int range_i;
            
            // start range collection
            if (ranges.size() == 0) {
                ranges.push_back(std::make_pair(lb_curr, ub_curr));
                continue;
            }

            range_i = check_ranges(ranges, lb_curr, ub_curr);
            if (range_i == -1) {
                // a new range was found
                ranges.push_back(std::make_pair(lb_curr, ub_curr));
                continue;
            }

            // an inclusive range was found. let's get it
            if (lb_curr < ranges[range_i].first)
                ranges[range_i].first = lb_curr;
            
            if (ub_curr > ranges[range_i].second)
                ranges[range_i].second = ub_curr; 
            
            continue;
        }

        id = std::stol(line);
        for (auto p : ranges) {
            if (id >= p.first && id <= p.second) {
                ++fresh_ingredients;
                break;
            }
        }
    }

    // for (auto p : ranges)
    //     std::cout << p.first << " and " << p.second << "\n";
    
    std::cout << fresh_ingredients << "\n";    
    
    return 0;
}
