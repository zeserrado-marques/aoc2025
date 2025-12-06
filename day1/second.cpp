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
    
    int pos = 50;
    int code = 0; 
    fh.open(argv[1]);
    
    while (fh >> line) {
        int step = std::stoi(line.substr(1, line.length() - 1));
        int dir = translator[line.substr(0, 1)];
        int temp = pos;

        temp = (pos + dir*step); 
        // if it's smaller then zero, it means it passed 1 time extra by the 0
        if (temp < 0) 
            temp = abs(temp) + (pos > 0) * SIZE;
        else if (temp >= SIZE)
            temp -= (pos == 0) * SIZE; // discount 1 lap around the dial, if I start from 0
        
        pos = (pos + dir*step) % SIZE;
        pos = (pos + SIZE) % SIZE;

        temp = temp * (temp > SIZE) / SIZE;

        
        code+= temp;
        // count number of time zero appears
        if (pos == 0)
            code++;

        std::cout << line << " " << pos << " " << temp << "\n";
            
    }
        
    std::cout << code << "\n"; 
    
    return 0;
}
