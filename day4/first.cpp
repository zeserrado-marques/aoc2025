#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define PAPERROLL '@'
#define EMPTY '.'


int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream fh;
    std::vector<std::string> field;
    int res = 0;
    
    fh.open(argv[1]);
    while (fh >> line) {

        field.push_back(line);
    }
    
    // go thorugh field
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[i].length(); ++j) {
            if (field[i][j] == EMPTY)
                continue;
            
            std::pair<size_t, size_t> pos[] = {
                                    std::make_pair(i-1, j-1),
                                    std::make_pair(i-1, j),
                                    std::make_pair(i-1, j+1),
                                    std::make_pair(i, j-1),
                                    std::make_pair(i, j+1),
                                    std::make_pair(i+1, j-1),
                                    std::make_pair(i+1, j),
                                    std::make_pair(i+1, j+1),
            };
            
            int roll_count = 0;
            for (auto p : pos) {
                // out of bounds positions
                if (p.first < 0 || p.first >= field.size() || p.second < 0 || p.second >= field[i].length())
                    continue;
                
                // if (field[p.first][p.second] == PAPERROLL)
                roll_count += (field[p.first][p.second] == PAPERROLL);
            }

            if (roll_count < 4) {
                res++;
            }

        }
    }

    
    std::cout << res << "\n";    
    
    return 0;
}
