/* simple.c or simple.cpp */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    std::cout << "Hello, World!\n";
    string inputFileName = "D:/AdventOfCode/input1.txt";
    ifstream inputFile;
    vector<int> resultCalories; // Store calories per elf
    std::string line;
    inputFile.open(inputFileName, std::ios::out);
    int elfCounter = 0;
    int currentElfSum = 0;
    while (inputFile.peek() != EOF)
    {
      getline(inputFile, line);
      if (line.empty())
      {
        cout << "elfcounter: " << elfCounter << " Sum: " << currentElfSum << "\n" << endl;
        ++elfCounter;
        resultCalories.push_back(currentElfSum);
        currentElfSum = 0;
      }
      else
      {
        // Convert to string number and sum up
        cout << stoi(line) << "....";
        currentElfSum += stoi(line);
      }

    }
    inputFile.close();
    auto it = minmax_element(resultCalories.begin(), resultCalories.end());
    int max_idx = distance(resultCalories.begin(), it.second);
    double max = *max_element(resultCalories.begin(), resultCalories.end());
    cout << "Max value: " << max << endl;
    std::sort(resultCalories.begin(), resultCalories.end(), std::greater<>());
    double max3Elf = max;
    for (int i = 1; i < 3; ++i)
    {
      max3Elf += resultCalories.at(i);
    }
    cout << "Max3 value: " << max3Elf << endl;
    return 0;
}
