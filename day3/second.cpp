#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define N_DIGITS 12;

// returns the index for the search of the largest index
size_t get_largest_digit(std::string line, int start, long &line_max, int curr_digit) {
    char max = '0'; // starting point
    size_t max_i = 0;

    // get max, leaving enough space for next digit
    for (size_t i = start; i < line.length()-curr_digit; ++i) {
        if (line[i] > max) {
            max = line[i];
            max_i = i;
        }
    }
    
    // '0' is 48 at ascii table
    line_max += (max - 48) * pow(10, curr_digit);
    return max_i;
}

int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    long res = 0;

    fh.open(argv[1]);
    while (fh >> line) {
        long line_max = 0;
        int curr_i = -1; // no index at the beginning
        int curr_digit = N_DIGITS; // 10^n gives the n+1 digit
        
        while (curr_digit-- > 0) {
            curr_i = get_largest_digit(line, curr_i+1, line_max, curr_digit);
        }
        
        res += line_max;
        
        // std::cout << line << " " << line_max << "\n";

    }
    std::cout << res << "\n";    
    
    return 0;
}
