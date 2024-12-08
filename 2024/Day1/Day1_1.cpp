#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


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
  std::sort(column1.begin(), column1.end());
  std::sort(column2.begin(), column2.end());
  int columns_size = column1.size();
  int totalvalue = 0;
  for(size_t i=0; i<columns_size; i++){
    totalvalue += std::abs(column1[i] - column2[i]);
  }
  std::cout << totalvalue;
}
