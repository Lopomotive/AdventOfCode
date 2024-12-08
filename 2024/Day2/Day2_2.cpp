#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//This particular code was AI generated because I did not have the energy to complete it myself

bool isSafeReport(const std::vector<int>& levels) {
    if (levels.size() < 2) return false;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];

        if (diff < -3 || diff > 3 || diff == 0) {
            return false;
        }

        if (i > 1 && ((levels[i] > levels[i - 1]) != (levels[i - 1] > levels[i - 2]))) {
            return false;
        }
    }
    return true;
}

bool canBeSafeWithOneRemoval(const std::vector<int>& levels) {
    for (size_t i = 0; i < levels.size(); ++i) {
        std::vector<int> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);

        if (isSafeReport(modifiedLevels)) {
            return true;
        }
    }
    return false;
}

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

        if (isSafeReport(levels) || canBeSafeWithOneRemoval(levels)) {
            ++safeCount;
        }
    }

    inputFile.close();

    std::cout << "Number of safe reports: " << safeCount << std::endl;

    return 0;
}

