#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream inputFile("Day2_1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    int safeCount = 0;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::vector<int> levels;
        int num;

        while (ss >> num) {
            levels.push_back(num);
        }

        bool isSafe = true;
        for (size_t i = 1; i < levels.size(); ++i) {
            int diff = levels[i] - levels[i - 1];

            if (diff < -3 || diff > 3 || diff == 0) {
                isSafe = false;
                break;
            }

            if (i > 1 && ((levels[i] > levels[i - 1]) != (levels[i - 1] > levels[i - 2]))) {
                isSafe = false;
                break;
            }
        }

        if (isSafe) {
            ++safeCount;
        }
    }

    inputFile.close();

    std::cout  << safeCount << std::endl;

    return 0;
}

