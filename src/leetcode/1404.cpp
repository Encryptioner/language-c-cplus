/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Mon May 30 2022
 */

// Accepted
// REFERENCE: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

#include<bits/stdc++.h>

using namespace std;

const int maxLength = 501;

class Solution {
private:
  // Utility function to subtract two bools and calculate diff
  // and borrow
  bool fullSubtractor(bool b1, bool b2, bool& borrow)
  {
    bool diff;
    if (borrow) {
      diff = !(b1 ^ b2);
      borrow = !b1 || (b1 && b2);
    }
    else {
      diff = b1 ^ b2;
      borrow = !b1 && b2;
    }
    return diff;
  }

  // Function to calculate difference between two bitsets
  bitset<maxLength> bitsetSubtract(bitset<maxLength> x, bitset<maxLength> y)
  {
    bool borrow = false;
    // bitset to store the sum of the two bitsets
    bitset<maxLength> ans;
    for (int i = 0; i < maxLength; i++) {
      ans[i] = fullSubtractor(x[i], y[i], borrow);
    }
    return ans;
  }

  // Utility function to add two bool values and calculate
  // carry and sum
  bool fullAdder(bool b1, bool b2, bool& carry)
  {
    bool sum = (b1 ^ b2) ^ carry;
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
    // cout << "b1 = "<<b1 <<" b2 = "<<b2<<" carry = "<<carry<<" sum = "<< sum << "\n";
    return sum;
  }
  
  // Function to add two bitsets
  bitset<maxLength> bitsetAdd(bitset<maxLength>& x, bitset<maxLength>& y)
  {
    bool carry = false;
    // bitset to store the sum of the two bitsets
    bitset<maxLength> ans;
    for (int i = 0; i < maxLength; i++) {
      int b1 = 0;
      ans[i] = fullAdder(x[i], y[i], carry);
    }
    return ans;
  }
public:
  int numSteps(string s) {
    
    bitset<maxLength> binaryString(s);
    int steps = 0;
    while(1) {
      int setBits = binaryString.count();
      bool isOdd = binaryString.test(0);
      
      // binaryString = 1
      if (setBits == 1 && isOdd) {
        break;;
      }
      if(steps > 10000000) {
        break;
      }

      steps ++;

      if(isOdd) {
        bitset<maxLength> one(1);
        // add 1 to binaryString
        binaryString = bitsetAdd(binaryString, one);
      } else {
        binaryString = binaryString >>= 1;
      }
    }
    return steps;
  }
};

int main() {
  Solution sl;

  while(1) {
    string s;
    int minJump, maxJump;

    getline(cin, s);
    if(s == "" || s[0] == '/') {
      continue;
    }
    if(s == "0") {
      break;
    }

    int output = sl.numSteps(s);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}

// Test cases

// s = "1101", output = 6
// s = "10", output = 1
// s = "1", output = 0