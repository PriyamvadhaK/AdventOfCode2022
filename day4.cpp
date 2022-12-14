/* simple.c or simple.cpp */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

bool checkIfDupl(int elf1min, int elf1max, int elf2min, int elf2max)
{
  bool result = false;
  if ((elf2min >= elf1min) && (elf2max <= elf1max))
  {
    result = true;
  }
  else if ((elf1min >= elf2min) && (elf1max <= elf2max))
  {
    result = true;
  }
  return result;
}

bool checkIfOverlap(int elf1min, int elf1max, int elf2min, int elf2max)
{
  bool result = false;
  if((elf2min >= elf1min) && (elf2min <= elf1max))
  {
    result = true;
  }
  else if ((elf1min >= elf2min) && (elf1min <= elf2max))
  {
    result = true;
  }
  return result;
}

void main()
{
  std::cout << "Hello, World!\n";
  string inputFileName = "D:/AdventOfCode/input4.txt";
  ifstream inputFile;
  string line;
  inputFile.open(inputFileName, std::ios::out);
  vector<char> result;
  int counterDuplicate = 0;
  int counterOverlap = 0;
  int posComma = 0;
  int pos1min = 0;
  int elf1min, elf2min, elf1max, elf2max;
  int pos1max = 0;
  int pos2min = 0;
  int pos2max = 0;
  string firstElf, secondElf;

  while (inputFile.peek() != EOF)
  {
    // Read line by line
    getline(inputFile, line);
    posComma = line.find(',');
    firstElf = line.substr(0, posComma);
    secondElf = line.substr(posComma + 1, line.length());
    pos1min = firstElf.find('-');
    pos2min = secondElf.find('-');
    elf1min = stoi(firstElf.substr(0, pos1min));
    elf1max = stoi(firstElf.substr(pos1min+1, firstElf.length()));
    elf2min = stoi(secondElf.substr(0, pos2min));
    elf2max = stoi(secondElf.substr(pos2min + 1, secondElf.length()));
    const bool isDuplicate = checkIfDupl(elf1min, elf1max, elf2min, elf2max);
    const bool isOverlap = checkIfOverlap(elf1min, elf1max, elf2min, elf2max);
    // Check if contained in other
    if (isDuplicate)
    {
      //Increment counter
      ++counterDuplicate;
    }
    if (isOverlap)
    {
      //Increment counter
      ++counterOverlap;
    }
  }
  cout << counterDuplicate << " " << counterOverlap;
}
