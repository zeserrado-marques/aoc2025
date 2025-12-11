#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

// funções recursivas ficaram para mais tarde
int check_ranges(std::vector<std::pair<long, long>> ranges, long lb, long ub) {
    for (int i = 0; i < (int)ranges.size()-1; i++) {
        // compare lb with saved_upper and ub with saved_lower
        if (lb <= ranges[i].second+1 && ub >=ranges[i].first-1)
            return i;
    }

    return -1; // no index found
}

void merge_ranges(std::vector<std::pair<long, long>> &ranges, long lb, long ub) {
    
    // get range that's going to be modified
    int i = check_ranges(ranges, lb, ub); 
    
    // stop condition
    if (i == -1)
        return;
    
    // modify the range
    auto range = ranges.back(); 
    
    if (range.first < ranges[i].first)
        ranges[i].first = range.first;
    
    if (range.second > ranges[i].second)
        ranges[i].second = range.second;
    
    ranges.pop_back();
    merge_ranges(ranges, ranges.back().first, ranges.back().second);
}


int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    std::vector<std::pair<long, long>> ranges; // first = lb and second = ub
    long total_fresh_ingredients = 0;


    fh.open(argv[1]);
    while (fh >> line) {
        size_t dash_i;
        // int range_i;

        // catch the ranges
        if ((dash_i = line.find('-')) == std::string::npos)
            break;
        
        auto lb_curr = std::stol(line.substr(0, dash_i));
        auto ub_curr = std::stol(line.substr(dash_i+1, line.length()-dash_i-1));

        // start range collection
        if (ranges.size() == 0) {
            ranges.push_back(std::make_pair(lb_curr, ub_curr));
            continue;
        }
        // range_i = check_ranges(ranges, lb_curr, ub_curr);
        ranges.push_back(std::make_pair(lb_curr, ub_curr));
        
        // merge_ranges(ranges, lb_curr, ub_curr);

    }

    std::sort(ranges.begin(), ranges.end(), [](std::pair<long, long> a, std::pair<long, long> b) 
                                              {
                                                return a.first < b.first;
                                              });
    
    // std::vector<std::pair<long, long>> compacted_ranges;

    for (size_t i = 0; i < ranges.size()-1; i++) {
        if (ranges[i].second >= ranges[i+1].first) {
            ranges[i].second = ranges[i].second > ranges[i+1].second ? ranges[i].second : ranges[i+1].second;
            ranges.erase(ranges.begin() + (i--) + 1);
        }
    }
    

    for (auto p : ranges) {
        std::cout << p.first << "-" << p.second << " " << p.second-p.first+1 << "\n";
        total_fresh_ingredients += p.second - p.first + 1;
    }
    
    std::cout << total_fresh_ingredients << "\n";    
    
    return 0;
}
