/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Tue May 31 2022
 */

// Accepted
// REFERENCE: https://leetcode.com/problems/ugly-number/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
  void primeFactors(int n)
  {
    int primeFactor = 2;
    while(primeFactor > 1)
    {
        if(n % primeFactor == 0){
          cout<<primeFactor<<" *";
          n /= primeFactor;
        }
        else {
          primeFactor++;
        }
    }
    printf("\n");
  }
public:
  bool isUgly(int n) {

    int num = n;
    if(num < 1) {
      return false;
    }

    if(num == 1) {
      return true;
    }

    bool isUgly = true;
    int primeFactor = 2;
    
    while(num>1)
    {
      if(num % primeFactor == 0){

        // cout << primeFactor <<" *";
        num /= primeFactor;
      }
      else {
        primeFactor++;
      }

      if(primeFactor > 5) {
        isUgly = false;
        break;
      }
    }
    // printf("\n");
    return isUgly;
  }
};

int main() {
  Solution sl;

  while(1) {
    int num;
    scanf("%d", &num);
    int output = sl.isUgly(num);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}

// Test cases

// n=6, output = true
// n=1, output = true
// n=14, output = false
// n=-2147483648, output = false
// n=1305744254, output = false