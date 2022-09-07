/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Wed May 18 2022
 */

// NOTE:  Run `g++ -std=c++11 -o test.exe test.cpp` -> `./test.exe` to get the output in terminal

// Accepted
// REFERENCE: https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>

using namespace std;

vector<string>possibleRomanValues;

void setAllPossibleStringOfLegthKFromN(char set[], string prefix, int n, int k)
{
  // Base case: k is 0,
  // print prefix
  if (k == 0)
  {
    possibleRomanValues.push_back(prefix);
    return;
  }

  // One by one add all characters
  // from set and recursively
  // call for k equals to k-1
  for (int i = 0; i < n; i++)
  {
    string newPrefix;
    // Next character of input added
    newPrefix = prefix + set[i];
      
    // k is decreased, because
    // we have added a new character
    setAllPossibleStringOfLegthKFromN(set, newPrefix, n, k - 1);
  }
}

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

class Solution {
public:
  string intToRoman(int num) {
    char set[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    string value = "";

    bool found = false;

    int k = 1;

    while(!found) {
      setAllPossibleStringOfLegthKFromN(set, "", sizeof(set), k);

      for(int i = 0; i < possibleRomanValues.size(); i++){
        string roman = possibleRomanValues[i];
        int intOfRoman = romanToInt(roman);

        if(num == intOfRoman) {
          value = roman;
          found = true;
          break;;
        }
      }
      possibleRomanValues.clear();
      k++;
    }

    return value;
  }
};


int main() {
    Solution sl;

    int num;

    while(1) {
      scanf("%d", &num);
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
