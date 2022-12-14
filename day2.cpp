/* simple.c or simple.cpp */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

char isWin(const char player1, const char player2)
{
  char resultWin;
  if (player1 == 'A')
  {
    if (player2 == 'Y')
    {
      resultWin = 'W';
    }
    else if (player2 == 'X')
    {
      resultWin = 'D';
    }
    else if (player2 == 'Z')
    {
      resultWin = 'L';
    }
    else
    {
      resultWin = 'I';
    }
  }
  else if (player1 == 'B')
  {
    if (player2 == 'Y')
    {
      resultWin = 'D';
    }
    else if (player2 == 'X')
    {
      resultWin = 'L';
    }
    else if (player2 == 'Z')
    {
      resultWin = 'W';
    }
    else
    {
      resultWin = 'I';
    }

  }
  else
  {
    if (player2 == 'Y')
    {
      resultWin = 'L';
    }
    else if (player2 == 'X')
    {
      resultWin = 'W';
    }
    else if (player2 == 'Z')
    {
      resultWin = 'D';
    }
    else
    {
      resultWin = 'I';
    }
  }
  return resultWin;
}

char getPlay(const char player1, const char result)
{
  char resultPlay;
  if (player1 == 'A') // Rock
  {
    if (result == 'Y') // Draw
    {
      resultPlay = 'A';
    }
    else if (result == 'X') // Loss
    {
      resultPlay = 'C'; // Scissors
    }
    else if (result == 'Z') // Win
    {
      resultPlay = 'B'; // Paper
    }
    else
    {
      resultPlay = 'I';
    }
  }
  else if (player1 == 'B') // Paper
  {
    if (result == 'Y') // Draw
    {
      resultPlay = 'B'; // Paper
    }
    else if (result == 'X') // Loss
    {
      resultPlay = 'A'; // Rock
    }
    else if (result == 'Z') // Win
    {
      resultPlay = 'C'; // Scissors
    }
    else
    {
      resultPlay = 'I';
    }

  }
  else // Scissors
  {
    if (result == 'Y') // Draw
    {
      resultPlay = 'C'; // Scissors
    }
    else if (result == 'X') // Loss
    {
      resultPlay = 'B'; // Paper
    }
    else if (result == 'Z') // Win
    {
      resultPlay = 'A'; // Rock
    }
    else
    {
      resultPlay = 'I';
    }
  }
  return resultPlay;
}

int getNumber(char play)
{
  int num;
  switch (play)
  {
  case 'X':
  case 'A':
    num = 1;
    break;
  case 'Y':
  case 'B':
    num = 2;
    break;
  case 'Z':
  case 'C':
    num = 3;
    break;
  default:
    num = 0;
    break;
  }
  return num;
}

int getWLD(char res)
{
  int num;
  switch (res)
  {
  case 'W':
  case 'Z':
    num = 6;
    break;
  case 'L':
  case 'X':
    num = 0;
    break;
  case 'D':
  case 'Y':
    num = 3;
    break;
  default:
    num = 0;
    break;
  }
  return num;
}


int main() {
    std::cout << "Hello, World!\n";
    string inputFileName = "D:/AdventOfCode/input2.txt";
    ifstream inputFile;
    std::string line;
    inputFile.open(inputFileName, std::ios::out);
    int finalScore = 0;
    
    //while (inputFile.peek() != EOF)
    //{
      //getline(inputFile, line);
      //char resultRound = isWin(line[0], line[2]);
      //assert((resultRound != 'I') && "Incorrect win loss result");
      //finalScore += getWLD(resultRound) + getNumber(line[2]);
    //}
    while (inputFile.peek() != EOF)
    {
      getline(inputFile, line);
      char resultRound = getPlay(line[0], line[2]);
      assert((resultRound != 'I') && "Incorrect win loss result");
      finalScore += getWLD(line[2]) + getNumber(resultRound);
    }
    inputFile.close();
    cout << "Final score: " << finalScore;
    return 0;
}
