#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    int res = 0;

    fh.open(argv[1]);
    while (fh >> line) {
        char max = '0'; // starting point
        size_t max_i = 0;

        // get max
        for (size_t i = 0; i < line.length()-1; ++i) {
            if (line[i] > max) {
                max = line[i];
                max_i = i;
            }
        }

        // get next max
        char max2 = '0';
        for (size_t i = max_i+1; i < line.length(); i++) {
            if (line[i] > max2) {
                max2 = line[i];
            }
        }

        // '0' is 48 at ascii table
        res += (max - 48)*10 + (max2 - 48);
        
        // std::cout << line << " " << res << "\n";

    }
    std::cout << res << "\n";    
    
    return 0;
}
