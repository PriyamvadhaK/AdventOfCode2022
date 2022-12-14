/* simple.c or simple.cpp */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int calcPriorities(vector<char> inputVec)
{
  int sumPrio = 0;
  int currPrio = 0;
  for (int i = 0; i < inputVec.size(); ++i)
  {
    if (isupper(inputVec[i]))
    {
      currPrio = int(inputVec[i]) - 65 + 26 + 1;
    }
    else
    {
      currPrio = int(inputVec[i]) - 97 + 1;
    }
    sumPrio += currPrio;
  }
  return sumPrio;
}
void main()
{
    std::cout << "Hello, World!\n";
    string inputFileName = "D:/AdventOfCode/input3.txt";
    ifstream inputFile;
    string line, partOne, partTwo;
    inputFile.open(inputFileName, std::ios::out);
    int finalScore = 0;
    int commonCharIndex = 0;
    vector<char> resultItem, resultBadge;

    /* // PART ONE
    while (inputFile.peek() != EOF)
    {
      // Read line by line
      getline(inputFile, line);

      // Get total number of characters
      int numberObjects = line.length();

      // Store first and second half
      partOne = line.substr(0, numberObjects / 2);
      partTwo = line.substr(numberObjects / 2);

      // Calculate intersection and push to vector
      for (int i = 0; i < numberObjects; ++i)
      {
        commonCharIndex = partTwo.find(partOne[i]);
        if (commonCharIndex != -1)
        {
          break;
        }
      }
      resultItem.push_back(partTwo[commonCharIndex]);
    }*/

    string line1, line2, line3;
    int commonCharIndex1 = -1;
    int commonCharIndex2 = -1;

    while (inputFile.peek() != EOF)
    {
      // Read 3 lines
      getline(inputFile, line1);
      getline(inputFile, line2);
      getline(inputFile, line3);

      // Calculate intersection and push to vector
      for (int i = 0; i < line2.size(); ++i)
      {
        if (line1.find(line2[i]) != -1)
        {
          if (line3.find(line2[i]) != -1)
          {
            resultBadge.push_back(line2[i]);
            break;
          }
        }
      }
    }
    cout << calcPriorities(resultBadge);
}
