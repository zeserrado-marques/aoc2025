#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

#define SIZE 100


int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    std::map<std::string, int> translator {{"L", -1}, {"R", 1}};
    
    int start = 50;
    int code = 0;
    fh.open(argv[1]);
    
    while (fh >> line) {
        int step = std::stoi(line.substr(1, line.length() - 1));
        int dir = translator[line.substr(0, 1)];
        int temp;
        int prev = step;
        
        step %= SIZE;
        temp = start + dir*step;
        if ((temp > SIZE || temp < 0)) {
            code += 1 * (start > 0);
        }
        
        code += prev / SIZE; // number of laps 
        start = (start + dir*step) % SIZE;
        start = (start + SIZE) % SIZE;
        // count number of times the needle stays at zero
        if (start == 0)
            code++;
        

        std::cout << line << " " << start << " " << code << "\n";
            
    }
        
    std::cout << code << "\n"; 
    
    return 0;
}
