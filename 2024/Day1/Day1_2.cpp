#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main(){
  std::vector<int> column1;
  std::vector<int> column2;

  std::ifstream inputFile("Day1_1.txt");
  std::string line;
  while(std::getline(inputFile, line)){
    std::stringstream ss(line);
    int num1, num2;
    if(ss >> num1 >> num2){
      column1.push_back(num1);
      column2.push_back(num2);
    }
  }
  std::sort (column1.begin(), column1.end());
  std::sort (column2.begin(), column2.end());
  int totalValue = 0;

  for(int num : column1){
    int frequency = std::count(column2.begin(), column2.end(), num);
    totalValue += num * frequency;
  }
  std::cout << totalValue;
  return 0;
}
