#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define SIZE 100


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

            for (long n = lb; n <= ub; n++) {
                std::vector<int> digits;
                
                // skip over numbers with odd number of digits
                if ((int)(log10(n)) % 2 == 0) {
                    n = (long) pow(10, (int)(log10(n)) + 1);
                    continue;
                }

                // create digits array
                long temp = n;
                while ((temp / 10) > 0) {
                    digits.push_back(temp % 10);
                    temp/= 10;
                }
                digits.push_back(temp % 10);
                // std::reverse(digits.begin(), digits.end());
                
                // verify matching numbers
                bool matching = true;
                size_t middle = digits.size() / 2;
                for (size_t i = 0; i < middle; i++) {
                    if (digits[i] != digits[middle + i]) {
                        matching = false;
                    }
                }

                if (matching) {
                    res += n;
                    // std::cout << n << " ";
                }
            }
            // std::cout << "\n";
            prev_i = comma_i + 1;
        }

        std::cout << res << "\n";

    }
        
    
    return 0;
}
