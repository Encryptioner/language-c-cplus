/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Wed May 18 2022
 */

// NOTE:  Run `g++ -std=c++11 -o test.exe test.cpp` -> `./test.exe` to get the output in terminal

// Accepted
// REFERENCE: https://leetcode.com/problems/roman-to-integer/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> mappedValues = {
      {'I', 1}, 
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
    };

    int decimal = 0;

    for(int i = 0; i < s.length(); i++){
      
      // sum the characters
      decimal += mappedValues[s[i]];

      if(i == 0) {
        continue;
      }
      
      bool isEarlierCharSmall = mappedValues[s[i-1]] < mappedValues[s[i]];

      if(isEarlierCharSmall) {
        // remove the earlier summation and substract that character value
        decimal -= 2 * mappedValues[s[i-1]];
      }
    }
    return decimal;
  }
};


int main() {
    Solution sl;

    string roman;

    while(1) {
      getline(cin, roman);
      cout << sl.romanToInt(roman) << "\n";
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
// MCMLXXXII = 1982
// CMXCIX = 999
// MCMLXXXVIII = 1988
