/***********************************************************************
 * File: Source.cpp
 * Author: Name: 四資工一 B11115037 莊靜雯
 * Create Date: 2023/03/20
 * Editor: Name: 四資工一 B11115037 莊靜雯
 * Update Date: 2023/03/20
 * Description: There is a given arbitrary number X(double), a positive integer M, a positive integer N, and a character C. Please output results with following steps:
//      1. Reformat the decimal part of X(excluding the decimal point) to N characters.The characters over N digits must be unconditionally discarded.If the decimal part of X is less than N digits, please make up with 0.
//      2. After step 1, if X(including negative and decimal points) is still less than M characters, please fill in with character C in front of the number.The amount of Cand the number itself should meet exactly M characters.
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Intent: To calculate how many numbers before the decimal point
// Pre: string input
// Post: The function returns numbers before the decimal point
int getintSize(string input)
{
 // count is used to calculate how many numbers there are before the decimal point
 int count = 0;
 for (char c : input)
 {
  if (c == '.')
  {
   return count;
  }
  count++;
 }
 return count;
}

int main()
{
 // reusable variable ,place this variable outside of the loop
 string input;

 // infinite loop until cin meets EOF
 while (cin >> input)
 {
  // variable declaration part
  // allSize is the requested length
  // dotSize is the required length of the decimal point
  // intSize is the length of the integer part
  // a character pointing to the position of the integer part
  int allSize, dotSize, intSize, index = 0;
  // putChar is the character to be filled
  char putChar;
  // output string
  string output = "";

  // input part
  // cin allSize and dotSize
  cin >> allSize >> dotSize;
  // get the space entered after cin allSize and dotSize
  putChar = getchar();
  // get C: Letter to be filled when the length is not enough. (less than M digits)
  putChar = getchar();

  // get how many numbers in int part  before '.'
  intSize = getintSize(input);

  // determine whether it is a decimal, and then subtract size
  if (dotSize > 0)
  {
   allSize -= (dotSize + 1); // minus the number of bits occupied by the decimal point '.'
  }
  allSize -= intSize;

  // letter to be filled when the length is not enough
  for (int i = 0; i < allSize; i++)
  {
   output += putChar;
  }

  // add integer number part
  for (char c : input)
  {
   if (c == '.')
   {
    break;
   }
   output += c;
   index++;
  }

  // add decimal point
  if (dotSize > 0)
  {
   output += '.';
   index++;
  }

  // digits after the decimal point
  for (int i = 0; i < dotSize; i++, index++)
  {
   // If the index position is greater than the original number, add 0
   if (index >= input.size())
   {
    output += '0';
   }
   else
   {
    output += input[index];
   }
  }

  // cout result
  cout << output << endl;
 }
 return 0;
}
