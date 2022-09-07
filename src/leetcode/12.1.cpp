/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Thu May 19 2022
 */

// NOTE:  Run `g++ -std=c++11 -o test.exe test.cpp` -> `./test.exe` to get the output in terminal

// Accepted
// REFERENCE: https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>

using namespace std;

// unused code

// void get_each_digit(vector<int>& digits, int num)
// {
//   if(num >= 10) {
//     get_each_digit(digits, num / 10);
//   }
//   digits.push_back(num % 10);
// }

void get_each_digit_reversed(vector<int>& digits, int num) {
  while(num!=0){
    digits.push_back(num % 10);
    num /= 10;
  }
}

class Solution {
public:
  string intToRoman(int num) {

    map<int, string> mappedValuesInPosition[4];

    mappedValuesInPosition[0][1] = "I";
    mappedValuesInPosition[0][2] = "II";
    mappedValuesInPosition[0][3] = "III";
    mappedValuesInPosition[0][4] = "IV";
    mappedValuesInPosition[0][5] = "V";
    mappedValuesInPosition[0][6] = "VI";
    mappedValuesInPosition[0][7] = "VII";
    mappedValuesInPosition[0][8] = "VIII";
    mappedValuesInPosition[0][9] = "IX";

    mappedValuesInPosition[1][1] = "X";
    mappedValuesInPosition[1][2] = "XX";
    mappedValuesInPosition[1][3] = "XXX";
    mappedValuesInPosition[1][4] = "XL";
    mappedValuesInPosition[1][5] = "L";
    mappedValuesInPosition[1][6] = "LX";
    mappedValuesInPosition[1][7] = "LXX";
    mappedValuesInPosition[1][8] = "LXXX";
    mappedValuesInPosition[1][9] = "XC";

    mappedValuesInPosition[2][1] = "C";
    mappedValuesInPosition[2][2] = "CC";
    mappedValuesInPosition[2][3] = "CCC";
    mappedValuesInPosition[2][4] = "CD";
    mappedValuesInPosition[2][5] = "D";
    mappedValuesInPosition[2][6] = "DC";
    mappedValuesInPosition[2][7] = "DCC";
    mappedValuesInPosition[2][8] = "DCCC";
    mappedValuesInPosition[2][9] = "CM";

    mappedValuesInPosition[3][1] = "M";
    mappedValuesInPosition[3][2] = "MM";
    mappedValuesInPosition[3][3] = "MMM";

    vector<int>digits;

    // splits the digit of number in array 
    get_each_digit_reversed(digits, num);

    string value = "";
    for(int i =  digits.size()-1 ; i >= 0; i--){
      value += mappedValuesInPosition[i][digits[i]];
    }
    return value;
  }
};


int main() {
    Solution sl;

    int num;

    while(1) {
      scanf("%d", &num);
      if(num > 4000) {
        continue;
      }
      cout << sl.intToRoman(num) << "\n";
    }
    return 0;
}


// Test cases

// CM = 900
// DXVI =  516
// MCLXXXIII =  1183
// MDCCXXXIII =  1733
// MDCCCXLI =  1841
// DCCCLXXI =  871
// MCCCLXXXIII =  1383
// MCCL =  1250
// MDLXVIII =  1568
// MMCXIII =  2113
// MMCCLXXIV =  2274
// MCMLXXXII = 1977
// CMXCIX = 999
// MCMLXXXVIII = 1988
