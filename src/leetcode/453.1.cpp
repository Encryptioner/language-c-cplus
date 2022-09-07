/*
 * Ankur Mursalin
 *
 * https://encryptioner.github.io/
 *
 * Created on Thu Jun 02 2022
 */

// Accepted
// REFERENCE: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) {

    int min = INT32_MAX;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int value = nums[i];
      if(value < min) {
        min  = value;
      }
    }

    int minMoves = 0;

    for (int i = 0; i < n; i++) {
      minMoves += nums[i] - min;
    }

    return minMoves;
  }
};

int main() {
  Solution sl;

  while(1) {
    int num, x;
    scanf("%d", &num);
    
    vector<int>nums;

    for (int i = 0; i < num; i++) {
      scanf("%d", &x);
      nums.push_back(x);
    }

    int output = sl.minMoves(nums);
    cout<<"output : "<< output <<"\n";
  }
  return 0;
}



// Test cases

// [1,2,3]
// 3
// [1,1,1]
// 0
// [-1, 5, 1]
// 8
// [0,-1,-1,5,3]
// 11
// [5,0,2,-1,5,5]
// 22
