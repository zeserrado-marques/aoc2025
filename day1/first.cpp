#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define MAX 100


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

        start = (start + dir*step) % MAX;
        start = (start + MAX) % MAX;
        
        // count number of time zero appears
        if (start == 0)
            code++;

        std::cout << line << " " << start << "\n";     
            
    }
        
    std::cout << code << "\n"; 
    
    return 0;
}
