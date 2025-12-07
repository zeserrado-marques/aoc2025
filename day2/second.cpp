#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define SIZE 100


long create_pattern(std::vector<int> digits, size_t start, size_t size){
    long pattern = 0;
    for (size_t k = start; k < size; ++k)
        pattern = pattern*10 + digits[k];
    
    return pattern;
}


int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    
    fh.open(argv[1]);
    while (fh >> line) {

        int comma_i;
        int prev_i = 0;
        long lb;
        long ub;
        long res = 0;

        // need to add an extra comma at the end of the input
        while ((comma_i = line.find(",", prev_i)) != (int)std::string::npos) {

            std::string range = line.substr(prev_i, comma_i - prev_i);
            lb = std::stol(range.substr(0, range.find("-")));
            ub = std::stol(range.substr(range.find("-")+1, range.length()));
            
            // std::cout << range << "\n";

            for (long n = lb; n <= ub; ++n) {
                std::vector<int> digits;

                // create digits array
                long temp = n;
                while ((temp / 10) > 0) {
                    digits.push_back(temp % 10);
                    temp/= 10;
                }
                digits.push_back(temp % 10);
                std::reverse(digits.begin(), digits.end());
                
                // more matching patterns, from 1 to middle
                size_t n_digits = digits.size();
                for (size_t j = 1; j <= n_digits/2; ++j) {
                    // construct pattern
                    long pattern = create_pattern(digits, 0, j);
                    bool found = true;

                    // search for pattern in number
                    for (size_t i = j; i < n_digits; i+=j) {
                        if (i + j > n_digits) { // out of bounds
                            found = false;
                            break;
                        }
                        long candidate = create_pattern(digits, i, i+j);
                        if (pattern != candidate) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        res += n;
                        // std::cout << n << " ";
                        break; // stop searching for different patterns
                    }
                }
                

            }
            // std::cout << "\n";
            prev_i = comma_i + 1;
        }

        std::cout << res << "\n";

    }
        
    
    return 0;
}
